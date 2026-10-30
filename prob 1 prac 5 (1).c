#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char song[50];
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

/* Add song at beginning */
void addBeginning(char song[])
{
    struct Node *newNode = malloc(sizeof(struct Node));

    strcpy(newNode->song, song);

    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

/* Add song at end */
void addEnd(char song[])
{
    struct Node *newNode = malloc(sizeof(struct Node));
    struct Node *temp;

    strcpy(newNode->song, song);
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

/* Insert song after a given song */
void insertAfter(char given[], char song[])
{
    struct Node *temp = head;
    struct Node *newNode;

    /* Search for given song */
    while (temp != NULL)
    {
        if (strcmp(temp->song, given) == 0)
            break;

        temp = temp->next;
    }

    /* Song not found */
    if (temp == NULL)
    {
        printf("Song not found\n");
        return;
    }

    newNode = malloc(sizeof(struct Node));

    strcpy(newNode->song, song);

    newNode->prev = temp;
    newNode->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

/* Remove first song */
void removeFirst()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("Playlist is empty\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
}

/* Count songs */
int count()
{
    int c = 0;
    struct Node *temp = head;

    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }

    return c;
}

/* Display playlist */
void display()
{
    struct Node *temp = head;

    printf("Playlist: ");

    while (temp != NULL)
    {
        printf("%s ", temp->song);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    addBeginning("Song1");
    display();

    addEnd("Song2");
    display();

    addEnd("Song3");
    display();

    insertAfter("Song2", "Song4");
    display();

    removeFirst();
    display();

    printf("Total songs = %d\n", count());

    
printf("\nSwara Patel 25DCS099\n");
printf("Program Compiled DATE: %s\n", __DATE__);
printf("Compilation Time: %s\n", __TIME__);
    return 0;
}
