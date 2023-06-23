#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int front;
    int rear;
    int size;
    int *q;
};
struct Queue *queue;
void creat(int siz){
    queue=(struct Queue*)malloc(sizeof(struct Queue));
   queue->size=siz;
   queue->q=(int*)malloc(queue->size*sizeof(int));
   queue->front=queue->rear=0;
}
void enqueue(int data){
      if((queue->rear+1)%queue->size==queue->front){
        printf("The queue is full");
        return;
      }
      queue->rear=(queue->rear+1)%queue->size;
      queue->q[queue->rear]=data;
}
int dequeue(){
    int d=-1;
    if(queue->front==queue->rear){
        printf("The queue is empty\n");
        return -1;
    }
    queue->front=(queue->front+1)%queue->size;
    d=queue->q[queue->front];
    return d;
}
void print(){
    for(int i=queue->front+1;i!=queue->rear+1;i=(i+1)%queue->size){
        printf("%d ", queue->q[i]);
    }
}
int main(){
     
    creat(10);
    printf("Enter the elemenets (-1 to stop)\n");
    int data=0;
    while(data!=-1){
        scanf("%d",&data);
        if(data!=-1){
            enqueue(data);
        }
       
    }
    printf("%d \n", dequeue());
    printf("%d \n", dequeue());
    printf("%d \n", dequeue());
    print();
    return 0;
}