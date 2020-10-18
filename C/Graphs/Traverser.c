#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
    struct TreeNode* left;
    int info;
    struct TreeNode* right;
};
struct TreeNode * CreateANewNode(int value){
    struct TreeNode *ptr = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    ptr->left=NULL;
    ptr->info=value;
    ptr->right=NULL;
    return (ptr);
}

void printPostorderUsingRecursion(struct TreeNode* ptr) {
    if (ptr == NULL)
        return;
    printPostorderUsingRecursion(ptr->left);
    printPostorderUsingRecursion(ptr->right);
    printf("%d ", ptr->info);
}
void printInorderUsingRecursion(struct TreeNode* ptr) {
    if (ptr == NULL)
        return;
    printInorderUsingRecursion(ptr->left);
    printf("%d ", ptr->info);
    printInorderUsingRecursion(ptr->right);
}
void printPreorderUsingRecursion(struct TreeNode* ptr) {
    if (ptr == NULL)
        return;
    printf("%d ", ptr->info);
    printPreorderUsingRecursion(ptr->left);
    printPreorderUsingRecursion(ptr->right);
}

void main(){
    struct TreeNode * root;
    printf("Which type of traversal would you like to perform?\n");
    printf("1. PreOrder\n");
    printf("2. InOrder\n");
    printf("3. PostOrder\n");
    int ch;
    scanf("%d",&ch);
    switch(ch){
        case 1 :printPreorderUsingRecursion(root);
                break;
        case 2 :printInorderUsingRecursion(root);
                break;
        case 3 :printPostorderUsingRecursion(root);
    }
}