#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct Stack{
    int top;
    int size;
    int* array;
};

struct Stack* createStack(int size){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (!stack) return NULL;
    stack->top = -1;
    stack->size = size;
    stack->array = (int*) malloc(stack->size * sizeof(int));
    if (!stack->array) return NULL;
    return stack;
}

int isEmpty(struct Stack* stack){
    return stack->top == -1 ;
}

char Peek(struct Stack* stack){
    return stack->array[stack->top];
}

char Pop(struct Stack* stack){
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '$';
}

void Push(struct Stack* stack, char ch){
    stack->array[++stack->top] = ch;
}

int Calculate(char* expression){
    struct Stack* temp = createStack(strlen(expression));
    int i;
    if (!temp) return -1;
    for (i = 0; expression[i]; ++i){
        if (isdigit(expression[i]))
            Push(temp, expression[i]-'0');
        else{
            int operand1 = Pop(temp);
            int operand2 = Pop(temp);
            char ch=expression[i];
            switch(ch){
                case '+':Push(temp, operand2 + operand1);
                         break;
                case '-':Push(temp, operand2 - operand1);
                         break;
                case '*':Push(temp, operand2 * operand1);
                         break;
                case '/':Push(temp, operand2 / operand1);
                         break;
            }
        }
    }
    return(Pop(temp));
}

void main(){
    printf("Enter a string");
    char Infix[100];
    scanf("%s",Infix);
    printf ("postfix evaluation: %d", Calculate(Infix));
}