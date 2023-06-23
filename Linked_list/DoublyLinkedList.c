#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head=NULL;
struct Node* tail=NULL;
void addNode(int data){
    if(head==NULL){
        struct Node* list=(struct Node*)malloc(sizeof(struct Node));
        list->data=data;
        list->next=NULL;
        list->prev=NULL;
        head=list;
        tail=list;
    }
    else{
        struct Node* list=(struct Node*)malloc(sizeof(struct Node));
        list->data=data;
        tail->next=list;
        list->prev=tail;
        list->next=NULL;
        tail=list;
    }
}
void addAtFront(int data){
    if(head==NULL){
        struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=data;
        temp->next=NULL;
        temp->prev=NULL;
        head=temp;
        tail=temp;
    }
    else{
        struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=data;
        temp->next=head;
        temp->prev=NULL;
        head=temp;
    }
}
void addAtAnyPosition(int data,int position){
    if(position==1){
        addAtFront(data);
        return ;
    }
    else{
        struct Node* list=(struct Node*)malloc(sizeof(struct Node));
        list->data=data;
        struct Node* temp=head;
        int count=0;
        while(count<position-2){
        temp=temp->next;
        count++;
        }
        if(temp->next==NULL){
            addNode(data);
            return;
        }
        list->next=temp->next;
        temp->next->prev=list;
        temp->next=list;
        list->prev=temp;
    }
}
void deleteAtFront(){
    if(head==NULL || (head->next==NULL && head->prev==NULL)){
        head=NULL;
        tail=head;
        return;
    }
    else{
        struct Node* temp=head;
        head=head->next;
        head->prev==NULL;
        free(temp);
    }
}
void deleteAtEnd(){
    if(head==NULL || (head->next==NULL && head->prev==NULL)){
        head==NULL;
        tail==head;
        return;
    }
    else{
        struct Node* temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        free(temp);
    }
}
void deleteAtAnyPosition(int postion){
    if(postion==1){
        deleteAtFront();
        return;
    }
    else{
        int count=0;
        struct Node*temp=head;
        while(count<postion-2){
           temp=temp->next;
           count++;
        }
        struct Node* toConncet=temp->next->next;
        struct Node* toDelete=temp->next;
        temp->next=toConncet;
        toConncet->prev=temp;
        free(toDelete);
    }

}
void print(){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
    printf("Enter the elemenet of linked list \n");
    printf("Enter -1 to stop adding");
    int n=0;
    while(n!=-1){
        scanf("%d",&n);
        if(n!=-1){
            addNode(n);
        }
    }
    printf("The elemenet are :\n");
    print();
    printf("Enter elemenets you want to add at front\n");
    int x;
    scanf("%d",&x);
    addAtFront(x);
    printf("Enter elemenets you want to add at rear\n");
    scanf("%d",&x);
    addNode(x);
    print();
    printf("Enter position you want to add at and the data you want to add");
    int pos;
    scanf("%d%d",&pos,&x);
    addAtAnyPosition(x,pos);
    print();
    printf("Do you want to delete a node from front\n 1 for yes Or 0 for No \n");
    int flag;
    scanf("%d",&flag);
    if(flag){
         deleteAtFront();
    }
    print();
    printf("Do you want to delete a node from rear\n 1 for yes Or 0 for No \n");
    scanf("%d",&flag);
    if(flag){
         deleteAtEnd();
    }
    print();
    printf("Enter the position of node you want to delete");
    scanf("%d",&flag);
    deleteAtAnyPosition(flag);
    print();
    return 0;
}