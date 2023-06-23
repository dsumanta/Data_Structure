#include<iostream>
using namespace std;
class Node{
    public:
   Node* lchild;
   Node* rchild;
   int data;
   Node(int data){
    this->lchild=NULL;
    this->rchild=NULL;
    this->data=data;
   }
};
Node* insert(Node* p,int data){
    Node *t;
    if(p==NULL){
      t=new Node(data);
      return t;
    }
    if(p->data<data){
        p->rchild=insert(p->rchild,data);
    }
    else if(p->data>=data){
        p->lchild=insert(p->lchild,data);
    }
}
void inorder(Node* p){
    if(p){
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
}
void deleteNode(Node* p){
    if(p){
        inorder(p->lchild);
        
        inorder(p->rchild);
        delete p;
    }
}
int main(){
    Node* root=NULL;
    int x=0;
    cout<<"Enter -1 to stop adding";
    while(x!=-1){
        cin>>x;
        if(x!=-1){
            root=insert(root,x);
        }
    }
    //deleteNode(root);
    inorder(root);
    return 0;
}