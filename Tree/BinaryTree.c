#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node* lchild;
    struct Node* rchild;
    int data;
};
struct Queue{
    int front;
    int rear;
    int size;
    struct Node **q;
};
struct Queue *queue;
void creat(int siz){
    queue=(struct Queue*)malloc(sizeof(struct Queue));
   queue->size=siz;
   queue->q=(struct Node**)malloc(queue->size*sizeof(struct Node*));
   queue->front=queue->rear=0;
}
void enqueue(struct Node* d){
      if((queue->rear+1)%queue->size==queue->front){
        printf("The queue is full");
        
      }
      queue->rear=(queue->rear+1)%queue->size;
      queue->q[queue->rear]=d;
}
struct Node* dequeue(){
    struct Node* d=NULL;
    if(queue->front==queue->rear){
        printf("The queue is empty\n");
        return NULL;
    }
    queue->front=(queue->front+1)%queue->size;
    d=queue->q[queue->front];
    return d;
}
int isEmpty(){
   return queue->rear==queue->front;
}
struct Node* Root=NULL;

void treeCreat(){
    struct Node *p,*t;
    creat(100);
    int data;
    printf("Enter the value of root Node :");
    scanf("%d",&data);
    Root=(struct Node*)malloc(sizeof(struct Node));
    Root->data=data;
    Root->lchild=NULL;
    Root->rchild=NULL;
    enqueue(Root);
    while(!isEmpty()){
        p=dequeue();
        printf("Enter the leftChild value for %d Node :",p->data);
        int x;
        scanf("%d",&x);
        if(x!=-1){
            t=(struct Node* )malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=NULL;
            t->rchild=NULL;
            p->lchild=t;
            enqueue(t);
        }
        printf("Enter the rightChild value for %d Node :",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t=(struct Node*)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=NULL;
            t->rchild=NULL;
            p->rchild=t;
            enqueue(t);
        }
    }
}
// preorder Traversal//
void preorder(struct Node* p){
    if(p){
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
//postorder traversal//
void postorder(struct Node* p){
    if(p){
        
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);
    }
}
// Inorder Trvaersal//
void inOrder(struct Node* p){
    if(p){
      inOrder(p->lchild);
       printf("%d ",p->data);
      inOrder(p->rchild);
     
    }
}

int main(){
    treeCreat();
    //  printf("Preorder Traversal\n");
    //  preorder(Root);
     printf("Postorder Traversal\n");
    postorder(Root);
      //printf("Inorder Traversal\n");
      //inOrder(Root);
  // LevelOrder(Root);
    return 0;
}