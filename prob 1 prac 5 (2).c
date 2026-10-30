#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

/* Insert student */
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
        newNode->prev = head;

        return;
    }

    /* Insert at beginning */
    if (pos == 1)
    {
        newNode->next = head;
        newNode->prev = head->prev;

        head->prev->next = newNode;
        head->prev = newNode;

        head = newNode;

        return;
    }

    temp = head;

    for (i = 1; i < pos - 1; i++)
        temp = temp->next;

    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;
}

/* Delete student */
void delete(int pos)
{
    struct Node *temp;
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

        head->prev->next = head->next;
        head->next->prev = head->prev;

        head = head->next;

        free(temp);
        return;
    }

    temp = head;

    for (i = 1; i < pos; i++)
        temp = temp->next;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);
}

/* Display */
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