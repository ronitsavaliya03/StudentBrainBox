#include <stdio.h>
#include <stdlib.h>

#define RED 0
#define BLACK 1

typedef struct Node {
    int data;
    int color;
    struct Node *left, *right, *parent;
} Node;

Node* root = NULL;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->color = RED; 
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

void leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left)
        y->left->parent = x;
    
    y->parent = x->parent;
    
    if (!x->parent)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}


void rightRotate(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    if (x->right)
        x->right->parent = y;

    x->parent = y->parent;

    if (!y->parent)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;
}


void fixInsert(Node* k) {
    Node* uncle;

    while (k != root && k->parent->color == RED) {
        if (k->parent == k->parent->parent->left) {
            uncle = k->parent->parent->right;

            if (uncle && uncle->color == RED) {
                // Case 1: Uncle is red
                k->parent->color = BLACK;
                uncle->color = BLACK;
                k->parent->parent->color = RED;
                k = k->parent->parent;
            } else {
                // Case 2 and 3
                if (k == k->parent->right) {
                    k = k->parent;
                    leftRotate(k);
                }

                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                rightRotate(k->parent->parent);
            }
        } else {
            uncle = k->parent->parent->left;

            if (uncle && uncle->color == RED) {
                k->parent->color = BLACK;
                uncle->color = BLACK;
                k->parent->parent->color = RED;
                k = k->parent->parent;
            } else {
                if (k == k->parent->left) {
                    k = k->parent;
                    rightRotate(k);
                }

                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                leftRotate(k->parent->parent);
            }
        }
    }
    root->color = BLACK;
}


Node* bstInsert(Node* root, Node* node) {
    if (root == NULL)
        return node;

    if (node->data < root->data) {
        root->left = bstInsert(root->left, node);
        root->left->parent = root;
    } else if (node->data > root->data) {
        root->right = bstInsert(root->right, node);
        root->right->parent = root;
    }

    return root;
}


void insert(int data) {
    Node* node = createNode(data);

    root = bstInsert(root, node);

    fixInsert(node);
}


void inOrder(Node* node) {
    if (node == NULL)
        return;

    inOrder(node->left);
    printf("%d ", node->data);
    inOrder(node->right);
}


int main() {
    int nums[] = {10, 20, 30, 15, 25, 5, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    for (int i = 0; i < n; i++) {
        insert(nums[i]);
    }

    printf("In-order Traversal of Red-Black Tree:\n");
    inOrder(root);
    printf("\n");

    return 0;
}