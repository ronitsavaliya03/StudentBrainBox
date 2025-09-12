#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data[2];
    struct Node *children[3];
    int count;
    bool isLeaf;
};

struct Node* createNode(int data1, int data2) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data[0] = data1;
    newNode->data[1] = data2;
    newNode->children[0] = newNode->children[1] = newNode->children[2] = NULL;
    newNode->count = 2; // Two keys in the node
    newNode->isLeaf = true; // Initially, it is a leaf node
    return newNode;
}

void splitChild(struct Node* parent, int index) {
    struct Node* child = parent->children[index];
    struct Node* newChild = createNode(child->data[1], 0);
    
    // Move the second key to the new child
    newChild->data[0] = child->data[1];
    newChild->count = 1; // New child has one key now
    child->count = 1; // Original child has one key now

    // Adjust the parent's keys and children
    for (int i = parent->count; i > index; i--) {
        parent->data[i] = parent->data[i-1];
        parent->children[i+1] = parent->children[i];
    }
    parent->data[index] = child->data[0];
    parent->children[index+1] = newChild;
    parent->count++;
}

void insertNonFull(struct Node* node, int key) {
    int i = node->count - 1;

    if (node->isLeaf) {
        while (i >= 0 && key < node->data[i]) {
            node->data[i + 1] = node->data[i];
            i--;
        }
        node->data[i + 1] = key;
        node->count++;
    } else {
        while (i >= 0 && key < node->data[i]) {
            i--;
        }
        i++;
        if (node->children[i]->count == 2) {
            splitChild(node, i);
            if (key > node->data[i]) {
                i++;
            }
        }
        insertNonFull(node->children[i], key);
    }
}

void insert(struct Node** root, int key) {
    if (*root == NULL) {
        *root = createNode(key, 0);
        return;
    }

    if ((*root)->count == 2) {
        struct Node* newRoot = createNode((*root)->data[0], 0);
        newRoot->isLeaf = false;
        newRoot->children[0] = *root;
        splitChild(newRoot, 0);
        *root = newRoot;
    }
    insertNonFull(*root, key);
}

void display(struct Node* node) {
    if (node == NULL) return;

    for (int i = 0; i < node->count; i++) {
        if (!node->isLeaf) {
            display(node->children[i]);
        }
        printf("%d ", node->data[i]);
    }
    if (!node->isLeaf) {
        display(node->children[node->count]);
    }
}

int main() {
    struct Node* root = NULL;

    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 5);
    insert(&root, 6);
    insert(&root, 12);
    insert(&root, 30);
    insert(&root, 7);
    insert(&root, 17);

    printf("B-Tree traversal: ");
    display(root);
    printf("\n");

    return 0;
}

