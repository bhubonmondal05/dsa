#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void create(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = newNode;
    head = newNode;
}

void display() {
    if (!head) return;
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void insert_begin(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    if (!head) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head) temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

void insert_end(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    if (!head) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
}

void delete_begin() {
    if (head) {
        if (head->next == head) {
            free(head);
            head = NULL;
        } else {
            struct Node* temp = head, *last = head;
            while (last->next != head) last = last->next;
            head = head->next;
            last->next = head;
            free(temp);
        }
    }
}

void delete_end() {
    if (head) {
        if (head->next == head) {
            free(head);
            head = NULL;
        } else {
            struct Node* temp = head, *prev = NULL;
            while (temp->next != head) prev = temp, temp = temp->next;
            prev->next = head;
            free(temp);
        }
    }
}

void delete_after(int target) {
    struct Node* temp = head;
    if (head) {
        do {
            if (temp->data == target && temp->next != head) {
                struct Node* del = temp->next;
                temp->next = del->next;
                free(del);
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }
}

void delete_list() {
    struct Node* temp;
    while (head && head->next != head) {
        temp = head;
        head = head->next;
        free(temp);
    }
    free(head);
    head = NULL;
}

int main() {
    int choice, val, target;
    do {
        printf("\n1. Create\n2. Display\n3. Insert Begin\n4. Insert End\n5. Delete Begin\n6. Delete End\n7. Delete After\n8. Delete Entire List\n0. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &val); create(val); break;
            case 2: display(); break;
            case 3: printf("Enter value: "); scanf("%d", &val); insert_begin(val); break;
            case 4: printf("Enter value: "); scanf("%d", &val); insert_end(val); break;
            case 5: delete_begin(); break;
            case 6: delete_end(); break;
            case 7: printf("Enter target: "); scanf("%d", &target); delete_after(target); break;
            case 8: delete_list(); break;
        }
    } while (choice != 0);
}
