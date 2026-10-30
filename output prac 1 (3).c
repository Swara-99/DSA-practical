#include <stdio.h>
#include <string.h>

int main()
{
    char s[200], w[50], big[50];
    int i = 0, len, max = 0;

    printf("Enter sentence: ");
    fgets(s, sizeof(s), stdin);

    while (sscanf(s + i, "%s%n", w, &len) == 1)
    {
        if ((int)strlen(w) > max)
        {
            max = strlen(w);
            strcpy(big, w);
        }
        i += len;
    }

    printf("Longest word: %s\n", big);
    printf("Number of letters: %d\n", max);

        
printf("\nSwara Patel 25DCS099\n");
printf("Program Compiled DATE: %s\n", __DATE__);
printf("Compilation Time: %s\n", __TIME__);
    
    return 0;
}