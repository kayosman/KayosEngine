#pragma once
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
    struct node *next;
};
struct node *root = NULL;
struct node *queue[10];
struct node *hashTable[10];
struct node *stack[10];
int top = -1;
int front = -1;
int rear = -1;
void insertAtNode(struct node **head, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}
void print(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void deleteNode(struct node **head, int data) {
    struct node *temp = *head;
    struct node *prev = NULL;
    while (temp != NULL) {
        if (temp->data == data) {
            if (prev == NULL) {
                *head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}
void sort(struct node **head) {
    struct node *temp = *head;
    struct node *prev = NULL;
    struct node *next = NULL;
    while (temp != NULL) {
        next = temp->next;
        while (next != NULL) {
            if (temp->data > next->data) {
                int temp_data = temp->data;
                temp->data = next->data;
                next->data = temp_data;
            }
            next = next->next;
        }
        temp = temp->next;
    }
}
void reverse(struct node **head) {
    struct node *prev = NULL;
    struct node *curr = *head;
    struct node *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}
void reverseRecursive(struct node **head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    struct node *next = (*head)->next;
    reverseRecursive(&next);
    (*head)->next->next = *head;
    (*head)->next = NULL;
    *head = next;
}
void deleteDuplicates(struct node **head) {
    struct node *temp = *head;
    struct node *prev = NULL;
    while (temp != NULL) {
        struct node *next = temp->next;
        while (next != NULL) {
            if (temp->data == next->data) {
                if (prev == NULL) {
                    *head = next->next;
                } else {
                    prev->next = next->next;
                }
                free(next);
                next = prev->next;
            } else {
                prev = next;
                next = next->next;
            }
        }
        temp = temp->next;
    }
}
void push(struct node **head, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}
void deleteAll(struct node **head) {
    struct node *temp = *head;
    while (temp != NULL) {
        struct node *next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
}
void insertHash(int data) {
    int index = data % 10;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = hashTable[index];
    hashTable[index] = new_node;
}
void printHash() {
    for (int i = 0; i < 10; i++) {
        struct node *temp = hashTable[i];
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
void deleteHash(int data) {
    int index = data % 10;
    struct node *temp = hashTable[index];
    struct node *prev = NULL;
    while (temp != NULL) {
        if (temp->data == data) {
            if (prev == NULL) {
                hashTable[index] = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}
void deleteAllHash() {
    for (int i = 0; i < 10; i++) {
        struct node *temp = hashTable[i];
        while (temp != NULL) {
            struct node *next = temp->next;
            free(temp);
            temp = next;
        }
    }
}
void enqueue(struct node* data) {
    if (rear == 9) {
        printf("Queue is full\n");
        return;
    }
    rear++;
    queue[rear] = (struct node *)malloc(sizeof(struct node));
    queue[rear]->data = (int)data;
    queue[rear]->next = NULL;
}
struct node* dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return NULL;
    }
    front++;
}
void printQueue() {
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]->data);
    }
    printf("\n");
}
void pushStack(int data) {
    if (top == 9) {
        printf("Stack is full\n");
        return;
    }
    top++;
    stack[top] = (struct node *)malloc(sizeof(struct node));
    stack[top]->data = data;
    stack[top]->next = NULL;
}
void popStack() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    top--;
}
void printStack() {
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]->data);
    }
    printf("\n");
}
void insert(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    if (root == NULL) {
        root = new_node;
    } else {
        struct node *temp = root;
        while (temp != NULL) {
            if (temp->data > data) {
                if (temp->left == NULL) {
                    temp->left = new_node;
                    return;
                } else {
                    temp = temp->left;
                }
            } else {
                if (temp->right == NULL) {
                    temp->right = new_node;
                    return;
                } else {
                    temp = temp->right;
                }
            }
        }
    }
}
void inorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void preorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
void levelorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    struct node *queue[10];
    int front = -1;
    int rear = -1;
    enqueue(root);
    while (front <= rear) {
        struct node *temp = dequeue();
        printf("%d ", temp->data);
        if (temp->left != NULL) {
            enqueue(temp->left);
        }
        if (temp->right != NULL) {
            enqueue(temp->right);
        }
    }
}
void deleteTree(struct node *root) {
    if (root == NULL) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}
void deleteAllTree() {
    deleteTree(root);
}
void printTree(struct node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    printTree(root->left);
    printTree(root->right);
}
void printTreeInorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    printTreeInorder(root->left);
    printf("%d ", root->data);
    printTreeInorder(root->right);
}
void printTreePreorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    printTreePreorder(root->left);
    printTreePreorder(root->right);
}
void printTreePostorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    printTreePostorder(root->left);
    printTreePostorder(root->right);
    printf("%d ", root->data);
}
void printTreeLevelorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    struct node *queue[10];
    int front = -1;
    int rear = -1;
    enqueue(root);
    while (front <= rear) {
        struct node *temp = dequeue();
        printf("%d ", temp->data);
        if (temp->left != NULL) {
            enqueue(temp->left);
        }
        if (temp->right != NULL) {
            enqueue(temp->right);
        }
    }
}