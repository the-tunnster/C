#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *left, *right;
};
struct Node* CreateANode(int value){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->info = value;
    temp->left = temp->right = NULL;
    return temp;
}
struct Node* Insert(struct Node* node, int value){
    if(node == NULL){
        return CreateANode(value);
    }
    if(value < node->info) {
        node->left = Insert(node->left, value);
    }
    else if (value > node->info)
        node->right = Insert(node->right, value);
    return node;
}
int Maximum(struct Node* root, int N) {
    if (root == NULL) {
        return -1;
    }
    if (root->info == N) {
        return N;
    }
    else {
        if(root->info < N) {
            int k = Maximum(root->right, N);
            if (k == -1)
                return root->info;
            else
                return k;
        }
        else
            if (root->info > N) {
            return Maximum(root->left, N);
        }
    }
}
    void main(){
    struct Node* root = NULL;
    int ch;
    do{
        printf("Enter a node value?\n");
        printf("Yes=1, No=2\n");
        scanf("%d",&ch);
        switch(ch){
            case 1 :printf("Enter the value.\n");
                    int value;
                    scanf("%d",&value);
                    root=Insert(root, value);
                    break;
            case 2 :break;
            default:printf("Unexpected value...");
                    break;
        }
    }while(ch!=2);
    printf("Enter a value to look for.\n");
    int Value;
    scanf("%d",&Value);
    int closest = Maximum(root, Value);
    printf("The closest value is %d.\n",closest);
}