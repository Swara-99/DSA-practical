#include <stdio.h>

int main() {
    int stack[5];
    int top = -1;
    int choice, value;

    while (1) {

        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        // Push
        if (choice == 1) {
            if (top == 4) {
                printf("Stack is Full\n");
            } else {
                printf("Enter tray: ");
                scanf("%d", &value);

                top++;
                stack[top] = value;

                printf("Top tray = %d\n", stack[top]);
            }
        }

        // Pop
        else if (choice == 2) {
            if (top == -1) {
                printf("Stack is Empty\n");
            } else {
                printf("Tray taken = %d\n", stack[top]);
                top--;

                if (top != -1)
                    printf("Top tray = %d\n", stack[top]);
            }
        }

        // Exit
        else if (choice == 3) {
            break;
        }

        else {
            printf("Invalid choice\n");
        }
    }

printf("\nSwara Patel 25DCS099\n");
printf("Program Compiled DATE: %s\n", __DATE__);
printf("Compilation Time: %s\n", __TIME__);
    return 0;
}