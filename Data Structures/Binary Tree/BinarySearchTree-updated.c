#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* CreateANode(int value);
struct Node* Insert(struct Node* node, int value);
int Search(struct Node* root, int value);
void inorder(struct Node* root);
void preorder(struct Node* root);
void postorder(struct Node* root);

struct Node* CreateANode(int value){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* Insert(struct Node* node, int value){
    if(node == NULL){
        return CreateANode(value);
    }
    if(value < node->data) {
        node->left = Insert(node->left, value);
    }
    else if (value > node->data)
        node->right = Insert(node->right, value);
    return node;
}

int Search(struct Node* root, int value){
    if(root==NULL){
        printf("\nTree Fully Traversed...\n");
        return(0);
    }
    if(root->data==value){
        return 1;
    }
    else{
        if(root->data>value){
            return Search(root->left, value);
        }
        else{
            return Search(root->right, value);
        }
    }
}

void inorder(struct Node* root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d\t", root->data);
		inorder(root->right);
	}
}

void preorder(struct Node* root){
    if(root == NULL)
        return;
    printf("%d\t", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root){
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d\t", root->data);
}

void main(){
    struct Node* root = NULL;
    int ch;
    int Value;
    int flag;
    do{
        printf("Enter a node value?\n");
        printf("Yes=1 or No=2 :  ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the value: ");
                int value;
                scanf("%d",&value);
                root=Insert(root, value);
                printf("---------------------------------\n");
                break;
            case 2:
                break;
            default:
                printf("Exiting create node...");
                break;
        }
    }while(ch!=2);
    printf("\n===================================\n\n");
    printf("Enter a value to look for: ");
    scanf("%d",&Value);
    flag=Search(root, Value);
    if(flag==0){
        printf("\nValue not found.\n");
    }
    else{
        printf("\nValue is present.\n");
    }
    printf("\n===================================\n\n");
    printf("How do you want to print it?\n");
    printf("1] Inorder\n2] Preorder\n3] Postorder\n");
    printf("Option: ");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        printf("Inorder : \n");
        inorder(root);
        break;
    case 2:
        printf("Preorder : \n");
        preorder(root);
        break;
    case 3:
        printf("Postorder : \n");
        postorder(root);
        break;
    default:
        break;
    }
}
