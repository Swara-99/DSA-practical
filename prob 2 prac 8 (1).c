#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insert(struct Node *root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

void inorder(struct Node *root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {

    int n, value;
    struct Node *root = NULL;

   
    printf("Enter number of books: ");
    scanf("%d", &n);

    printf("Enter book codes:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Inorder sequence: ");
    inorder(root);

    printf("\n");
     printf("\nSwara Patel 25DCS099\n");
    printf("Program Compiled DATE: %s\n", __DATE__);
    printf("Compilation Time: %s\n\n", __TIME__);


    return 0;
}