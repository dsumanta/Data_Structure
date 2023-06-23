#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int data;
    struct Queue* next;
}*front=NULL,*rear=NULL;
void enqueue(int d){
   struct Queue* temp=(struct Queue*)malloc(sizeof(struct Queue));
   if(temp==NULL){
        printf("queue is full\n");
   }
   else{
      temp->data=d;
      temp->next=NULL;
      if(front==NULL){
        front=rear=temp;
      }
      else{
        rear->next=temp;
        rear=temp;
      }
   }
}

int dequeue(){
    if(front==NULL){
        printf("The queue is empty\n");
        return -1;
    }
     struct Queue* temp=front;
     front=temp->next;
     int d=temp->data;
     free(temp);
     return d;
}
void print(){
    struct Queue * temp=front;
    while(temp!=NULL){
       printf("%d ",temp->data);
       temp=temp->next;
    }
}
int size(){
    struct Queue* temp=front;
    int count=0;
    while(temp!=NULL){
       temp=temp->next;
       count++;
    }
    return count;
}
int main(){
    printf("Enter -1 to stop adding elemenet\n");
    int d=0;
    while(d!=-1){
        scanf("%d",&d);
        if(d!=-1){
            enqueue(d);
       }
    }
    int i=0;
     printf("The size is %d\n",size());
    printf("The %dth enqueue value is %d\n",i++,dequeue());
     printf("The %dth enqueue value is %d\n",i++,dequeue());
      printf("The %dth enqueue value is %d\n",i++,dequeue());
      printf("The size is %d\n",size());
    print();
    return 0;
}