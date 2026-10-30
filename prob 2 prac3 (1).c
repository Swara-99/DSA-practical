#include <stdio.h>

int main()
{
    int a[100], n;
    int i, low = 0, mid = 0, high, t;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter 0, 1 and 2:\n");

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    high = n - 1;

    while(mid <= high)
    {
        if(a[mid] == 0)
        {
            t = a[low];
            a[low] = a[mid];
            a[mid] = t;

            low++;
            mid++;
        }
        else if(a[mid] == 1)
        {
            mid++;
        }
        else
        {
            t = a[mid];
            a[mid] = a[high];
            a[high] = t;

            high--;
        }
    }

    printf("Sorted order: ");

    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

printf("\nSwara Patel 25DCS099\n");
printf("Program Compiled DATE: %s\n", __DATE__);
printf("Compilation Time: %s\n", __TIME__);
    
    return 0;
}