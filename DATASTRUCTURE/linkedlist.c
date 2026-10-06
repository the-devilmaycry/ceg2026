#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
int count = 0;

struct node *createNode(int x) {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = x;
    n->next = NULL;
    return n;
}

void display() {
    struct node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\nTotal nodes: %d\n", count);
}

/* ---------- Insertions ---------- */
void insertAtBeginning(int x) {
    struct node *n = createNode(x);
    n->next = head;
    head = n;
    count++;
}

void insertAtEnd(int x) {
    struct node *n = createNode(x), *temp = head;
    if (head == NULL)
        head = n;
    else {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = n;
    }
    count++;
}

void insertAtPosition(int x, int pos) {
    if (pos < 1 || pos > count + 1) {
        printf("Invalid position!\n");
        return;
    }
    if (pos == 1) {
        insertAtBeginning(x);
        return;
    }
    struct node *n = createNode(x), *temp = head;
    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;
    n->next = temp->next;
    temp->next = n;
    count++;
}

void insertAfterValue(int x, int key) {
    struct node *temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        printf("Value %d not found!\n", key);
        return;
    }
    struct node *n = createNode(x);
    n->next = temp->next;
    temp->next = n;
    count++;
}

/* ---------- Deletions ---------- */
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
    count--;
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct node *temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        free(temp->next);
        temp->next = NULL;
    }
    count--;
}

void deleteAtPosition(int pos) {
    if (pos < 1 || pos > count) {
        printf("Invalid position!\n");
        return;
    }
    if (pos == 1) {
        deleteFromBeginning();
        return;
    }
    struct node *temp = head, *del;
    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;
    del = temp->next;
    temp->next = del->next;
    free(del);
    count--;
}

/* ---------- Search ---------- */
void search(int x) {
    struct node *temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == x) {
            printf("%d found at position %d\n", x, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("%d not found in the list\n", x);
}

int main() {
    int choice, x, pos, key;

    while (1) {
        printf("\n--- LINKED LIST MENU ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Insert after a value\n");
        printf("5. Delete from beginning\n");
        printf("6. Delete from end\n");
        printf("7. Delete at position\n");
        printf("8. Search\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                insertAtBeginning(x);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &x);
                insertAtEnd(x);
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &x, &pos);
                insertAtPosition(x, pos);
                break;
            case 4:
                printf("Enter new value and the value to insert after: ");
                scanf("%d %d", &x, &key);
                insertAfterValue(x, key);
                break;
            case 5:
                deleteFromBeginning();
                break;
            case 6:
                deleteFromEnd();
                break;
            case 7:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 8:
                printf("Enter value to search: ");
                scanf("%d", &x);
                search(x);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice!\n");
                continue;
        }
        if (choice != 8)
            display();
    }
    return 0;
}
