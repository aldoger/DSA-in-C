#include <stdio.h>

typedef struct {
    char ch;
} StackData;

typedef struct stackType {
    StackData data;
    struct stackType *next;
}StackType, *Stack;

int precedence(char c){
    if(c == '(') return 0;
    if(c == '+' || c == '-') return 3;
    if(c == '*' || c == '/') return 5;
}

char getToken(){
    char ch;
    while((ch = getchar()) == ' ');
    return ch;
}

StackData peek()

