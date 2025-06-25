#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* link;
};

struct Node* first = NULL;

void insertAtFront(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = value;
    newNode->link = first;
    first = newNode;
}

void insertAtEnd(int value) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = value;
    newNode->link = NULL;

    if (first == NULL) {
        first = newNode;
    } else {
        struct Node* temp = first;
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = newNode;
    }
}

void deleteFront() {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = first;
    first = first->link;
    free(temp);
    printf("First node deleted.\n");
}

void deleteEnd() {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (first->link == NULL) {
        free(first);
        first = NULL;
        printf("Last node deleted.\n");
        return;
    }

    // struct Node* temp = first; 
    // while (temp->link->link != NULL)
    //     temp = temp->link;

    // free(temp->link);
    // temp->link = NULL;

    struct Node* pred= first;
    struct Node* save= first->link;

    while (save->link!=NULL)
    {
        pred=save;
        save=save->link;
    }

    pred->link=NULL;
    free(save);
    printf("Last node deleted.\n");
}

void deleteAtPosition(int pos) {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (pos == 1) {
        deleteFront();
        return;
    }

    // struct Node* temp = first;
    // for (int i = 1; i < pos - 1 && temp != NULL; i++)
    //     temp = temp->link;

    // if (temp == NULL || temp->link == NULL) {
    //     printf("Invalid position.\n");
    //     return;
    // }

    // struct Node* toDelete = temp->link;
    // temp->link = temp->link->link;
    // free(toDelete);

    struct Node* pred=first;
    struct Node* save=first->link;

    for(int i=1; i<pos-1 && save!=NULL; i++){
        pred=save;
        save=save->link;
    }

    pred->link=save->link;
    free(save); 
    printf("Node at position %d deleted.\n", pos);
}

void display() {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = first;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->link;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, pos;

    while (1) {
        printf("\n--- Linked List Operations ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from End\n");
        printf("5. Delete from Position\n");
        printf("6. Display List\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtFront(value);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtEnd(value);
            break;
        case 3:
            deleteFront();
            break;
        case 4:
            deleteEnd();
            break;
        case 5:
            printf("Enter position: ");
            scanf("%d", &pos);
            deleteAtPosition(pos);
            break;
        case 6:
            display();
            break;
        case 7:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
