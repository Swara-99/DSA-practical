#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int patient;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void arrive(int patient)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->patient = patient;
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

    printf("Front patient: %d\n", front->patient);
}

void attend()
{
    struct Node *temp;

    if (front == NULL)
    {
        printf("Error: Ward is Empty\n");
        return;
    }

    printf("Attended patient: %d\n", front->patient);

    temp = front;
    front = front->next;

    if (front == NULL)
    {
        rear = NULL;
    }

    free(temp);

    if (front != NULL)
        printf("Front patient: %d\n", front->patient);
}

int main()
{
    int choice, patient;

    while (1)
    {
        printf("\n1. Arrive\n");
        printf("2. Attend\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter patient number: ");
            scanf("%d", &patient);
            arrive(patient);
        }
        else if (choice == 2)
        {
            attend();
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
    }
printf("\nSwara Patel 25DCS099\n");
printf("Program Compiled DATE: %s\n", __DATE__);
printf("Compilation Time: %s\n", __TIME__);
    return 0;
}