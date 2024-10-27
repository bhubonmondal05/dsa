#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = newNode;
    return newNode;
}

// Function to display the list
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Function to insert at the beginning
void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
    }
}

// Function to insert at the end
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }
}

// Function to delete from the beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node* tail = head->prev;
        struct Node* temp = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        free(temp);
    }
    printf("Node deleted from the beginning.\n");
}

// Function to delete from the end
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node* tail = head->prev;
        struct Node* temp = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        free(temp);
    }
    printf("Node deleted from the end.\n");
}

// Function to delete a node after a given node
void deleteAfterNode(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        if (temp->data == key) {
            struct Node* deleteNode = temp->next;
            if (deleteNode == head) {
                printf("No node found after the given node.\n");
                return;
            }
            temp->next = deleteNode->next;
            deleteNode->next->prev = temp;
            free(deleteNode);
            printf("Node deleted after node with data %d.\n", key);
            return;
        }
        temp = temp->next;
    } while (temp != head);
    printf("Node with data %d not found.\n", key);
}

// Function to delete the entire list
void deleteEntireList() {
    if (head == NULL) {
        printf("List is already empty.\n");
        return;
    }
    struct Node* temp = head;
    struct Node* next;
    do {
        next = temp->next;
        free(temp);
        temp = next;
    } while (temp != head);
    head = NULL;
    printf("Entire list deleted.\n");
}

// Main menu
int main() {
    int choice, data, key;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create a circular doubly linked list\n");
        printf("2. Display the elements of the list\n");
        printf("3. Insert a node at the beginning\n");
        printf("4. Insert a node at the end\n");
        printf("5. Delete a node from the beginning\n");
        printf("6. Delete a node from the end\n");
        printf("7. Delete a node after a given node\n");
        printf("8. Delete the entire list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data for the new node: ");
                scanf("%d", &data);
                insertAtEnd(data);
                printf("Circular doubly linked list created with first node.\n");
                break;
            case 2:
                displayList();
                break;
            case 3:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 4:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 5:
                deleteFromBeginning();
                break;
            case 6:
                deleteFromEnd();
                break;
            case 7:
                printf("Enter data of the node after which deletion should occur: ");
                scanf("%d", &key);
                deleteAfterNode(key);
                break;
            case 8:
                deleteEntireList();
                break;
            case 9:
                deleteEntireList();
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
