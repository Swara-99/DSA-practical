#include <stdio.h>

#define SIZE 10
#define MAX 100

int main()
{
    int table[SIZE][MAX];
    int count[SIZE] = {0};
    int n, i, code, index, j;

    printf("Enter number of books: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter book code: ");
        scanf("%d", &code);

        index = code % SIZE;
        table[index][count[index]] = code;
        count[index]++;
    }

    printf("\nFinal Shelf Contents:\n");

    for (i = 0; i < SIZE; i++)
    {
        printf("Shelf %d: ", i);

        if (count[i] == 0)
            printf("Empty");

        for (j = 0; j < count[i]; j++)
            printf("%d ", table[i][j]);

        printf("\n");
    }
 printf("\nSwara Patel 25DCS099\n");
    printf("Program Compiled DATE: %s\n", __DATE__);
    printf("Compilation Time: %s\n\n", __TIME__);
    return 0;
}