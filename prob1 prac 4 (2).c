#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

// Insert at rear
void insert(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

// Delete by value
void deleteByValue(int value)
{
    struct Node *temp = front;
    struct Node *prev = NULL;

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value not found\n");
        return;
    }

    // Delete first node
    if (prev == NULL)
    {
        front = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    // If deleting rear
    if (temp == rear)
    {
        rear = prev;
    }

    free(temp);
}

// Forward traversal
void displayForward()
{
    struct Node *temp = front;

    printf("Forward: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Reverse printing using recursion
void displayReverse(struct Node *temp)
{
    if (temp == NULL)
        return;

    displayReverse(temp->next);
    printf("%d ", temp->data);
}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    printf("Original queue:\n");
    displayForward();

    printf("After deleting 30:\n");
    deleteByValue(30);
    displayForward();

    printf("Reverse: ");
    displayReverse(front);
    printf("\n");

    return 0;
}