#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
}Node;

Node *makeNode(int n){
    Node *np = (Node *)malloc(sizeof(Node));
    np->num = n;
    np->next = NULL;
    return np;
}

//unfinish
int main() {
    Node *top = makeNode(10);
}