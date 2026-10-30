#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

/* Insert student at position */
void insert(int value, int pos)
{
    struct Node *newNode, *temp;
    int i;

    newNode = malloc(sizeof(struct Node));
    newNode->data = value;

    /* Empty circle */
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    /* Insert at beginning */
    if (pos == 1)
    {
        temp = head;

        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;

        return;
    }

    temp = head;

    for (i = 1; i < pos - 1; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

/* Delete student */
void delete(int pos)
{
    struct Node *temp, *del;
    int i;

    if (head == NULL)
    {
        printf("Circle is empty\n");
        return;
    }

    /* Only one student */
    if (head->next == head)
    {
        if (pos == 1)
            head = NULL;

        return;
    }

    /* Delete first student */
    if (pos == 1)
    {
        temp = head;

        while (temp->next != head)
            temp = temp->next;

        del = head;
        head = head->next;
        temp->next = head;

        free(del);
        return;
    }

    temp = head;

    for (i = 1; i < pos - 1; i++)
        temp = temp->next;

    del = temp->next;
    temp->next = del->next;

    free(del);
}

/* Display circle */
void display()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("Circle is empty\n");
        return;
    }

    temp = head;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while (temp != head);

    printf("\n");
}

int main()
{
    insert(10, 1);
    display();

    insert(20, 2);
    display();

    insert(30, 3);
    display();

    insert(15, 2);
    display();

    delete(2);
    display();

printf("\nSwara Patel 25DCS099\n");
printf("Program Compiled DATE: %s\n", __DATE__);
printf("Compilation Time: %s\n", __TIME__);
    return 0;
}