#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* search(struct Node* root, int value) {
    if (root == NULL) return NULL;
    if (root->info == value) return root;

    struct Node* found = search(root->left, value);
    if (found != NULL) return found;

    return search(root->right, value);
}

void insertNode(struct Node* root) {
    int parentValue, newValue, choice;
    printf("\nEnter parent node value: ");
    scanf("%d", &parentValue);

    struct Node* parent = search(root, parentValue);
    if (parent == NULL) {
        printf("Parent not found!\n");
        return;
    }

    printf("Enter new node value: ");
    scanf("%d", &newValue);

    printf("Insert as (1) Left child or (2) Right child? ");
    scanf("%d", &choice);

    if (choice == 1) {
        if (parent->left == NULL) {
            parent->left = createNode(newValue);
        } else {
            printf("Left child already exists!\n");
        }
    } else if (choice == 2) {
        if (parent->right == NULL) {
            parent->right = createNode(newValue);
        } else {
            printf("Right child already exists!\n");
        }
    } else {
        printf("Invalid choice!\n");
    }
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->info);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice;

    int rootValue;
    printf("Enter root node value: ");
    scanf("%d", &rootValue);
    root = createNode(rootValue);

    while (1) {
        printf("\n1. Insert Node");
        printf("\n2. Display Inorder Traversal");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertNode(root);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
