#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

// Insert at front
void insertFront(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = front;
    front = newNode;

    if (rear == NULL)
        rear = newNode;
}

// Insert at rear
void insertRear(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

// Insert at specific position
void insertAtPosition(int value, int position)
{
    if (position <= 1)
    {
        insertFront(value);
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node *temp = front;

    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    // Position is greater than current length
    if (temp == NULL)
    {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    if (newNode->next == NULL)
        rear = newNode;
}

// Display queue
void display()
{
    struct Node *temp = front;

    printf("Queue: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    insertRear(10);
    display();

    insertRear(20);
    display();

    insertFront(5);
    display();

    insertAtPosition(15, 3);
    display();

    
    printf("\nSwara Patel 25DCS099\n");
    printf("Program Compiled DATE: %s\n", __DATE__);
    printf("Compilation Time: %s\n", __TIME__);
    

    return 0;
}