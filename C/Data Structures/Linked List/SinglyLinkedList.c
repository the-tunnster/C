#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node * next;
};


struct node * CreateNewNode(int value);
struct node* DeleteANode(struct node *);
struct node* InsertAtBeginning(struct node *, struct node *);
struct node* InsertAtTheEnd(struct node *, struct node *);
struct node* InsertInTheMiddle(struct node *, struct node *, int);
struct node* DeleteInTheBeginning(struct node *);
struct node* DeleteInTheEnd(struct node *);
struct node* DeleteInTheMiddle(struct node *, int n);
struct node* InsertANode(struct node *);
struct node* DeleteANode(struct node *);

int main() {
    struct node * head = NULL;
    int n;
    do{
        printf("Would you like to add or remove a node?\n");
        printf("1 to add, 2 to remove.\n");
        scanf("%d",&n);
        if(n==1) {
            head=InsertANode(head);
        }
        else{
            DeleteANode(head);
        }
    }while(n==1||n==2);
    return 0;
}

struct node * CreateNewNode(int value){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->info=value;
    ptr->next=NULL;
    return(ptr);
}

struct node* InsertANode(struct node *head) {
    printf("Enter the value to put in the node.\n");
    int value;
    scanf("%d", &value);
    struct node *PTR = CreateNewNode(value);
    if (PTR == NULL) {
        printf("Overflow condition achieved. Exiting...");
    }
    else{
        printf("Where would you like to insert a node?\n1. The beginning.\n2. The end.\n3. The middle.\n");
        int ch;
        scanf("%d", &ch);
        switch (ch) {
            case 1: {
                head=InsertAtBeginning(head, PTR);
                break;
            }
            case 2: {
                head=InsertAtTheEnd(head, PTR);
                break;
            }
            case 3: {
                printf("At what position would you like it to be?\n");
                int n;
                scanf("%d", &n);
                head=InsertInTheMiddle(head, PTR, n);
            }
        }
    }
    return(head);
}
struct node* InsertAtBeginning(struct node *temp, struct node *ptr){
    ptr->next=temp;
    temp=ptr;
    return(temp);
}
struct node* InsertInTheMiddle(struct node *head, struct node *ptr, int n){
    int i=0;
    struct node *temp=head;
    while(i<n-1){
        temp=temp->next;
        i++;
    }
    ptr->next=temp;
    temp=ptr;
    return(temp);
}
struct node* InsertAtTheEnd(struct node *head, struct node *ptr){
    struct node * temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=ptr;
    return(temp);
}

struct node* DeleteANode(struct node * head) {
    if (head == NULL) {
        printf("Underflow condition achieved. Exiting...");
    } else {
        printf("From where would you like to delete a node?\n1. The beginning.\n2. The end.\n3. The middle.\n");
        int ch;
        scanf("%d", &ch);
        switch (ch) {
            case 1: {
                head=DeleteInTheBeginning(head);
                break;
            }
            case 2: {
                head=DeleteInTheEnd(head);
                break;
            }
            case 3: {
                printf("At what position would you like it to be removed from?\n");
                int n;
                scanf("%d", &n);
                head=DeleteInTheMiddle(head, n);
            }
        }
    }
    return(head);
}
struct node* DeleteInTheBeginning(struct node* head){
    struct node* temp = head;
    int info =head->info;
    head = head->next;
    free(temp);
    printf("%d",info);
    return(head);
}
struct node* DeleteInTheMiddle(struct node *head, int n){
    int i=0;
    struct node * temp = head;
    while(i<n-1){
        temp=temp->next;
        i++;
    }
    int info = temp->next->info;
    temp->next = temp->next->next;
    printf("%d",info);
    return(temp);
}
struct node* DeleteInTheEnd(struct node * head){
    struct node * temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    int info = temp->info;
    free(temp->next);
    temp=NULL;
    return(temp);
}