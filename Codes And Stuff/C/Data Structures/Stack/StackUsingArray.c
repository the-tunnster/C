#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int top;
    int size;
    int* array;
};

struct Stack* createStack(int size1){
    struct Stack* temp = (struct Stack*)malloc(sizeof(struct Stack));
    temp->size = size1;
    temp->top = -1;
    temp->array = (int*)malloc(temp->size * sizeof(int));
    return temp;
}

int isFull(struct Stack* stack){
    return stack->top == stack->size - 1;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

void Push(struct Stack* stack, int item){
    if (isFull(stack)) {
        printf("Overflow condition met.\n");
        return;
    }
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

int Pop(struct Stack* stack){
    if (isEmpty(stack)){
        printf("Underflow Condition met.\n");
        return(0);
    }
    else {
        int toPop=stack->array[stack->top--];
        return (toPop);
    }
}

int Peek(struct Stack* stack){
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

void main(){
    printf("How large do you want the stack to be?\n");
    int size;
    scanf("%d",&size);
    struct Stack* stack = createStack(size);
    int ch;
    do{
        printf("Do you wish to Push or Pop to stack?\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        scanf("%d",&ch);
        if(ch==1){
            printf("Enter a value to Push to stack.\n");
            int value;
            scanf("%d",&value);
            Push(stack, value);
        }
        if(ch==2){
            int value=Pop(stack);
            printf("The popped value is %d.\n",value);
        }
        if(ch!=1&&ch!=2){
            printf("Unexpected value...\nTerminating...\n");
        }
    }while(ch==1||ch==2);
}