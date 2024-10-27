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
    newNode->next = NULL;
    head = newNode;
}

void display() {
    struct Node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insert_begin(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void insert_end(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    newNode->data = val;
    newNode->next = NULL;
    if (!head) head = newNode;
    else {
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

void insert_before(int target, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    if (!head || head->data == target) insert_begin(val);
    else {
        while (temp->next && temp->next->data != target) temp = temp->next;
        if (temp->next) {
            newNode->data = val;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void insert_after(int target, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    while (temp && temp->data != target) temp = temp->next;
    if (temp) {
        newNode->data = val;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void delete_begin() {
    struct Node* temp = head;
    if (head) head = head->next, free(temp);
}

void delete_end() {
    struct Node* temp = head, *prev = NULL;
    if (head) {
        while (temp->next) prev = temp, temp = temp->next;
        if (prev) prev->next = NULL; else head = NULL;
        free(temp);
    }
}

void delete_after(int target) {
    struct Node* temp = head;
    while (temp && temp->data != target) temp = temp->next;
    if (temp && temp->next) {
        struct Node* del = temp->next;
        temp->next = del->next;
        free(del);
    }
}

void delete_list() {
    struct Node* temp;
    while (head) temp = head, head = head->next, free(temp);
}

int main() {
    int choice, val, target;
    do {
        printf("\n1. Create\n2. Display\n3. Insert Begin\n4. Insert End\n5. Insert Before\n6. Insert After\n7. Delete Begin\n8. Delete End\n9. Delete After\n10. Delete Entire List\n0. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &val); create(val); break;
            case 2: display(); break;
            case 3: printf("Enter value: "); scanf("%d", &val); insert_begin(val); break;
            case 4: printf("Enter value: "); scanf("%d", &val); insert_end(val); break;
            case 5: printf("Enter target and value: "); scanf("%d %d", &target, &val); insert_before(target, val); break;
            case 6: printf("Enter target and value: "); scanf("%d %d", &target, &val); insert_after(target, val); break;
            case 7: delete_begin(); break;
            case 8: delete_end(); break;
            case 9: printf("Enter target: "); scanf("%d", &target); delete_after(target); break;
            case 10: delete_list(); break;
        }
    } while (choice != 0);
}
