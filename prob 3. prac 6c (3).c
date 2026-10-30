#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char page[50];
    struct Node *next;
};

struct Node *top = NULL;

void visit(char page[])
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    strcpy(newNode->page, page);
    newNode->next = top;
    top = newNode;

    printf("Current page: %s\n", top->page);
}

void back()
{
    struct Node *temp;

    if (top == NULL)
    {
        printf("No history left.\n");
    }
    else
    {
        temp = top;
        top = top->next;
        free(temp);

        if (top == NULL)
            printf("No page left.\n");
        else
            printf("Current page: %s\n", top->page);
    }
}

int main()
{
    visit("Google");
    visit("YouTube");
    visit("Amazon");

    back();
    back();
    back();
    back();


    
printf("\nSwara Patel 25DCS099\n");
printf("Program Compiled DATE: %s\n", __DATE__);
printf("Compilation Time: %s\n", __TIME__);
    return 0;
}