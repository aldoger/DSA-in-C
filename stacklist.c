#include <stdio.h>
typedef struct {
    int num;
}StackData;
#include "stack.h"

int main(){
    StackData data;
    Stack S = initStack();
    printf("Enter some integer: (end with 0)\n");
    scanf("%d", &data.num);
    while(data.num != 0){
        push(S, data);
        scanf("%d", &data.num);
    }
    StackData top = pop(S);
    printf("%d", top.num);
    return 0;
}