#include <stdio.h>

void bubble(int a[], int n)
{
    int i, j, t;

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

void select(int a[], int n)
{
    int i, j, min, t;

    for(i = 0; i < n - 1; i++)
    {
        min = i;

        for(j = i + 1; j < n; j++)
        {
            if(a[j] < a[min])
                min = j;
        }

        t = a[i];
        a[i] = a[min];
        a[min] = t;
    }
}

void insert(int a[], int n)
{
    int i, j, x;

    for(i = 1; i < n; i++)
    {
        x = a[i];
        j = i - 1;

        while(j >= 0 && a[j] > x)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = x;
    }
}

void print(int a[], int n)
{
    int i;

    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int main()
{
    int n, i;
    int a[100], b[100], c[100];

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter marks:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
        c[i] = a[i];
    }

    bubble(a, n);
    printf("\nBubble Sort: ");
    print(a, n);

    select(b, n);
    printf("Selection Sort: ");
    print(b, n);

    insert(c, n);
    printf("Insertion Sort: ");
    print(c, n);

printf("\nSwara Patel 25DCS099\n");
printf("Program Compiled DATE: %s\n", __DATE__);
printf("Compilation Time: %s\n", __TIME__);
    
    return 0;
}