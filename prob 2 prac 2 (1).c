#include <stdio.h>

int recBinary(int a[], int low, int high, int target)
{
    if(low > high)
        return -1;

    int mid = (low + high) / 2;

    if(a[mid] == target)
        return mid;

    if(target < a[mid])
        return recBinary(a, low, mid - 1, target);

    return recBinary(a, mid + 1, high, target);
}

int main()
{
    int n, i, target, result;

    printf("Enter number of book codes: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter sorted book codes:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter target code: ");
    scanf("%d", &target);

    int low = 0, high = n - 1;
    result = -1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(a[mid] == target)
        {
            result = mid;
            break;
        }
        else if(target < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if(result == -1)
        printf("\niterative: target not found");
    else
        printf("\niterative: target found at position %d", result + 1);

    result = recBinary(a, 0, n - 1, target);

    if(result == -1)
        printf("\nrecursive: target not found");
    else
        printf("\nrecursive: target found at position %d", result + 1);

    printf("\nSwara Patel 25DCS099\n");
    printf("Program Compiled DATE: %s\n", __DATE__);
    printf("Compilation Time: %s\n", __TIME__);
    

    return 0;
}