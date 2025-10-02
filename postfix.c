#include <stdio.h>
#include <ctype.h>

typedef struct {
    char ch;
    int num;
} StackData;

#include "stack.h"

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

int readConvert(char post[]){
    char token, c;
    StackData temp;
    int j = 0;
    Stack S = initStack();

    printf("Type an infix expression and press Enter:\n");
    token = getToken();
    while (token != '\n'){
        if(isdigit(token)) post[j++] = token;
        else if(token == '('){
            temp.ch = token;
            push(S, temp);
        }
        else if(token == ')')
            while((c = pop(S).ch) != '(') post[j++] = c;
        else{
            while(!empty(S) && precedence(peek(S).ch) >= precedence(token)) post[j++] = pop(S).ch;
            temp.ch = token;
            push(S, temp);
        }
        token = getToken();
    }

    while(!empty(S)) post[j++] = pop(S).ch;
    return j;
}  

void printPostFix(char post[], int n){
    int j;
    printf("\nThe postfix form is \n");
    for(j = 0; j < n; j++) printf("%c", post[j]);
    printf("\n");
}

int eval(char post[], int n){
    int j, a, b, c;
    StackData temp;

    Stack S = initStack();
    for(j  = 0; j < n; j++){
        if(isdigit(post[j])){
            temp.num = post[j] - '0';
            push(S, temp);
        }else{
            b = pop(S).num;
            a = pop(S).num;
            if(post[j] == '+') c = a + b;
            else if(post[j] == '-') c = a - b;
            else if(post[j] == '*') c = a * b;
            else c = a / b;
            temp.num = c;
            push(S, temp);
        }
    }
    return pop(S).num;
}