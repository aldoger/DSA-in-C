#include <stdio.h>
#include <stdlib.h> 

typedef struct node {
    int num;
    struct node *next;
} Node;

Node *makeNode(int n) {
    Node *np = (Node *)malloc(sizeof(Node));
    np->num = n;
    np->next = NULL;
    return np;
}

void printList(Node *np) {
    while(np != NULL) {
        printf("%d", np->num);
        np = np->next;
    }
}

void insertNode(Node *np, Node *node) {
    Node *prev = np;
    if(prev->num > node->num) {
        node->next = prev;
        np = node;
        return;
    }
    np = np->next;
    while(np != NULL) {
        if(np->num > node->num) {
            node->next = prev->next;
            prev->next = node;
            return;
        }
        prev = prev->next;
        np = np->next;
    }
}

int main() {

    int n;
    Node *top, *np, *last;

    top = NULL;
    if(scanf("%d", &n) != 1) n = 0;
    while(n != 0){
        np = makeNode(n);
        if(top == NULL) top = np;
        else last->next = np;
        last = np;
        if(scanf("%d", &n) != 1) n = 0;
    }

    Node *newNode = makeNode(2);
    insertNode(top, newNode);
    printList(top);
    return 0;
}