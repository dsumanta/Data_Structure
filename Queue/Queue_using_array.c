#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int front;
    int rear;
    int size;
    int *q;
};
void creat(struct Queue* Q,int siz){
     Q->size=siz;
     Q->q=(int*)malloc(Q->size*sizeof(int));
     Q->front=Q->rear=-1;
}
void enqueue(struct Queue *Q,int data){
       if( Q->rear+1==Q->size ){
        printf("Queue is Full\n");
       }
       else{
          Q->rear++;
          Q->q[Q->rear]=data;
           if(Q->front==-1){
            Q->front=0;
           }
       }
}
int dequeue(struct Queue *Q){
    int d=-1;
    if(Q->front==-1 || (*Q).front>(*Q).rear){
        printf("The Queue is empty\n");
        
    }
    else{
        d=(*Q).q[Q->front];
        Q->front++;
    }
    return d;
}
void print(struct Queue Q){
    for(int i=Q.front;i<=Q.rear;i++){
        printf("%d ",Q.q[i]);
    }
}
int main(){
    struct Queue queue;
    creat(&queue,7);
    int d=0;
     printf("Enter the value of to add on Queue\n Enter -1 to exit");
    while(d!=-1){  
        scanf("%d",&d);
        if(d!=-1){
            enqueue(&queue,d);
        }
    }
    printf("%d ",dequeue(&queue));
     printf("%d ",dequeue(&queue));
      printf("%d ",dequeue(&queue));
       printf("%d ",dequeue(&queue));
       print(queue);
       return 0;
}