#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* search(struct Node* root, int key) {

    if (root == NULL || root->data == key) {
        return root;
    }

    if (key > root->data) {
        return search(root->right, key);
    }

    return search(root->left, key);
}

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int main() {
    struct Node* root = newNode(50);
    root->left = newNode(30);
    root->right = newNode(70);
    root->left->left = newNode(20);
    root->left->right = newNode(40);

    int target = 40;
    struct Node* result = search(root, target);

    if (result != NULL)
        printf("Element %d found in the BST.\n", result->data);
    else
        printf("Element %d not found.\n", target);

    return 0;
}
