#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL || root->data == n1 || root->data == n2) {
        return root;
    }

    struct Node* leftSide = findLCA(root->left, n1, n2);
    struct Node* rightSide = findLCA(root->right, n1, n2);

    if (leftSide != NULL && rightSide != NULL) {
        return root;
    }

    return (leftSide != NULL) ? leftSide : rightSide;
}

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int main() {
 
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int n1 = 4, n2 = 5;
    struct Node* lca = findLCA(root, n1, n2);
    
    if (lca) printf("LCA of %d and %d is %d\n", n1, n2, lca->data);
    else printf("Nodes not found.\n");

    return 0;
}
