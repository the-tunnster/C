#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *pre;
    int info;
    struct node *next;
};

struct node* CreateNewNode(int);

struct node* InsertANode(struct node *);
struct node* InsertAtTheBeginning(struct node *, struct node *);
struct node* InsertInTheMiddle(struct node *, struct node *, int);
struct node* InsertAtTheEnd(struct node *, struct node *);

struct node* DeleteANode(struct node *);
struct node* DeleteAtTheBeginning(struct node *);
struct node* DeleteInTheMiddle(struct node *, int);
struct node* DeleteAtTheEnd(struct node *);

int main(){
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
            head=DeleteANode(head);
        }
    }while(n==1||n==2);
    return 0;
}

struct node * CreateANewNode(int value){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->pre=NULL;
    ptr->info=value;
    ptr->next=NULL;
    return (ptr);
}

struct node* InsertANode(struct node *head){
    printf("Enter the value to put in the node.\n");
    int value;
    scanf("%d", &value);
    struct node *PTR = CreateANewNode(value);
    if (PTR == NULL) {
        printf("Overflow condition achieved. Exiting...");
    }
    else{
        printf("Where would you like to insert a node?\n1. The beginning.\n2. The end.\n3. The middle.\n");
        int ch;
        scanf("%d", &ch);
        switch (ch) {
            case 1: {
                head=InsertAtTheBeginning(head, PTR);
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
}
struct node* InsertAtTheBeginning(struct node *head, struct node *ptr){
    if(head==NULL){return(ptr);}
    ptr->next=head;
    head->pre=ptr;
    return(ptr);
}
struct node* InsertInTheMiddle(struct node *head, struct node *ptr, int n){
    if(head==NULL){
        printf("List is empty.\n");
        return(ptr);
    }
    int i=0;
    struct node *temp=head;
    while(i<n-1&&temp->next!=NULL){
        temp=temp->next;
        i++;
    }
    temp->pre->next=ptr;
    ptr->next=temp;
    ptr->pre=temp->pre;
    temp->pre=ptr;
    return(head);
}
struct node* InsertAtTheEnd(struct node *head, struct node *ptr){
    struct node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=ptr;
    ptr->pre=temp;
    return(temp);
}

struct node* DeleteANode(struct node *head){
    if (head == NULL) {
        printf("Underflow condition achieved. Exiting...");
    } else {
        printf("From where would you like to delete a node?\n1. The beginning.\n2. The end.\n3. The middle.\n");
        int ch;
        scanf("%d", &ch);
        switch (ch) {
            case 1: {
                head=DeleteAtTheBeginning(head);
                break;
            }
            case 2: {
                head=DeleteAtTheEnd(head);
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
struct node* DeleteAtTheBeginning(struct node *head){
    struct node *toFree;
    toFree=head;
    head=head->next;
    printf("%d\n",toFree->info);
    free(toFree);
    return(head);
}
struct node* DeleteInTheMiddle(struct node *head, int n){
    int i=0;
    struct node *ptr=head;
    struct node *toFree;
    while(i<n-1){
        ptr=ptr->next;
        i++;
    }
    toFree=ptr;
    ptr->pre->next=ptr->next;
    ptr->next->pre=ptr->pre;
    printf("%d\n",toFree->info);
    free(toFree);
    return(head);
}
struct node* DeleteAtTheEnd(struct node *head){
    if(head->next==NULL){
        struct node *toFree=head;
        head=NULL;
        printf("%d\n", toFree->info);
        free(toFree);
        return (head);
    }
    else {
        struct node *ptr = head;
        struct node *toFree;
        while (ptr->next->next != NULL) {
            ptr = ptr->next;
        }
        toFree = ptr;
        ptr->pre->next = NULL;
        printf("%d\n", toFree->info);
        free(toFree);
        return (head);
    }
}