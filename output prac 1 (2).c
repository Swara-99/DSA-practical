#include <stdio.h>

int main()
{
    int n, h, k, i;
    char items[100][50];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter item names:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%s", items[i]);
    }

    printf("Enter number of hours: ");
    scanf("%d", &h);

    k = h % n;

    printf("Final display order:\n");

    for (i = k; i < n; i++)
    {
        printf("%s ", items[i]);
    }

    for (i = 0; i < k; i++)
    {
        printf("%s ", items[i]);
    }
printf("\nSwara Patel 25DCS099\n");
printf("Program Compiled DATE: %s\n", __DATE__);
printf("Compilation Time: %s\n", __TIME__);
}