#include <stdio.h>

int rec(int a[], int n, int x, int i)
{
    if (i >= n)
        return -1;

    if (a[i] == x)
        return i;

    return rec(a, n, x, i + 1);
}

int main()
{
    int a[100], n, x, i, p = -1;

    printf("Enter number of plates: ");
    scanf("%d", &n);

    printf("Enter plates:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter target plate: ");
    scanf("%d", &x);

    // Iterative search
    for (i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            p = i;
            break;
        }
    }

    if (p != -1)
        printf("Iterative: Position = %d\n", p);
    else
        printf("Iterative: Not found\n");

    // Recursive search
    p = rec(a, n, x, 0);

    if (p != -1)
        printf("Recursive: Position = %d\n", p);
    else
        printf("Recursive: Not found\n");

    printf("\nSwara Patel 25DCS099\n");
    printf("Program Compiled DATE: %s\n", __DATE__);
    printf("Compilation Time: %s\n", __TIME__);
                
    return 0;
}