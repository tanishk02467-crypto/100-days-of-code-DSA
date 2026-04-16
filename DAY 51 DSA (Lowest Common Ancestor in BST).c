#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;

    if (n1 < root->data && n2 < root->data) {
        return findLCA(root->left, n1, n2);
    }

    if (n1 > root->data && n2 > root->data) {
        return findLCA(root->right, n1, n2);
    }

    return root;
}

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int main() {
    struct Node* root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

    int n1 = 10, n2 = 14;
    struct Node* lca = findLCA(root, n1, n2);
    if (lca) printf("LCA of %d and %d is %d\n", n1, n2, lca->data);

    return 0;
}
