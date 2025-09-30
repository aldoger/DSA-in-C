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
        printf("%d ", np->num);
        np = np->next;
    }
}

void mergeList(Node *back, Node *front) {
    back->next = front;
    return;
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

    int x;
    Node *top2, *np2, *last2;

    top2 = NULL;
    if(scanf("%d", &x) != 1) x = 0;
    while(x != 0){
        np2 = makeNode(x);
        if(top2 == NULL) top2 = np2;
        else last2->next = np2;
        last2 = np2;
        if(scanf("%d", &x) != 1) x = 0;
    }

    mergeList(last, top2);

    printList(top);
    return 0;
}