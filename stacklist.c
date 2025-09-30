#include <stdio.h>
#include <stack.h>

int main(){
    int n;
    Stack S = initStack();
    printf("Enter some integer: (end with 0)\n");
    scanf("%d", &n);
    while(n != 0){
        push(S, n);
        scanf("%d", &n);
    }
    int top = pop(S);
    printf("%d", top);
    return 0;
}