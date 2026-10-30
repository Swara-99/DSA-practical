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

void inorder(struct Node *root) {
 if (root == NULL) return;

inorder(root->left);
 inorder(root->right);
}

void preorder(struct Node *root) {
     if (root == NULL)
 return;

 printf("%d ", root->data);
 preorder(root->left);
 preorder(root->right);
}

void postorder(struct Node *root) {
 if (root == NULL)
 return;

postorder(root->left);
postorder(root->right);
 printf("%d ", root->data);
}

void levelOrder(struct Node *root) {
 if (root == NULL)
 return;

 struct Node *queue[100];
 int front = 0;
int rear = 0;
queue[rear++] = root;

while (front < rear) {
 struct Node *temp = queue[front++];

 printf("%d ", temp->data);

 if (temp->left != NULL)
 queue[rear++] = temp->left;

 if (temp->right != NULL)
queue[rear++] = temp->right;
 }
}

int main() {

 
 struct Node *root = createNode(1);

root->left = createNode(2);
root->right = createNode(3);

root->left->left = createNode(4);
 root->left->right = createNode(5);

 root->right->left = createNode(6);
root->right->right = createNode(7);

printf("Inorder: ");
 inorder(root);

 printf("\nPreorder: ");
preorder(root);

 printf("\nPostorder: ");
postorder(root);

 printf("\nLevel Order: ");
levelOrder(root);
printf("\nSwara Patel 25DCS099\n");
 printf("Program Compiled DATE: %s\n", __DATE__);
printf("Compilation Time: %s\n\n", __TIME__);


return 0;
}