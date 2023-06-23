#include<iostream>
#include<queue>
using namespace std;
struct Node{
    struct Node* lchild;
    struct Node* rchild;
    int data;
};

void treecreat(queue<struct Node*>& q, struct Node* &root){
    root = new Node();
    root->lchild = NULL;
    root->rchild = NULL;
    int d;
    cout << "Enter the root value: ";
    cin >> d;
    root->data = d;
    q.push(root);
    while(!q.empty()){
        Node* p;
        p = q.front();
        q.pop();
        int x;
        cout << "Enter the left value of " << p->data << ": ";
        cin >> x;
        if(x != -1){
            Node *t;
            t = new Node();
            t->data = x;
            t->lchild = NULL;
            t->rchild = NULL;
            p->lchild = t;
            q.push(t);
        }
        int y;
        cout << "Enter the right value of " << p->data << ": ";
        cin >> y;
        if(y != -1){
            Node* t;
            t = new Node();
            t->data = y;
            t->lchild = NULL;
            t->rchild = NULL;
            p->rchild = t;
            q.push(t);
        }
    }
}

void preorder(struct Node* Root){
    if(Root){
        cout << Root->data << " ";
        preorder(Root->lchild);
        preorder(Root->rchild);
    }
}
void leveleOrder(struct Node* Root){
    queue<Node*> q;
     if(Root!=NULL){
       
        q.push(Root);
     }
     while(!q.empty()){
        Node* p=q.front();
        q.pop();
        if(p!=NULL){
            cout<<p->data<<" ";
            if(p->lchild!=NULL){
                q.push(p->lchild);
            }
            if(p->rchild!=NULL){
                q.push(p->rchild);
            }
        }    
     }
}
int heightCount(struct Node* p){
    int x,y;
    if(p){
        x=heightCount(p->lchild);
        y=heightCount(p->rchild);
        return x+y+1;
    }
    return 0;
}
int countCompleteNode(struct Node* p){
    int x,y;
    if(p){
        x=countCompleteNode(p->lchild);
        y=countCompleteNode(p->rchild);
        if(p->lchild && p->rchild){
            return x+y+1;
        }
        else{
            return x+y;
        }
    }
    return 0;
}
int leafCount(struct Node* p){
    int x,y;
    if(p){
       x=leafCount(p->lchild);
       y=leafCount(p->rchild);
       if(!p->lchild && !p->rchild){
        return x+y+1;
       }
       else{
        return x+y;
       }
    }
    else{
        return 0;
    }
}
int onechildCount(struct Node* p){
    int x,y;
    if(p){
         x=onechildCount(p->lchild);
         y=onechildCount(p->rchild);
         if((p->lchild && !p->rchild) || (!p->lchild && p->rchild)){
            return x+y+1;
         }
         else{
            return x+y;
         }
    }
    else{
        return 0;
    }
}
int main(){
    queue<Node*> q ;
    Node* root = NULL;
    treecreat(q, root);
    //cout << "Preorder Traversal: ";
    //preorder(root);
    cout << "levelOrder Traversal: ";
    leveleOrder(root);
    cout<<endl;
    cout<<"Total Number of node is ";
    cout<<heightCount(root)<<endl;
    cout<<endl;
    cout<<"Total number of complete node ";
    cout<<countCompleteNode(root);
    cout<<endl;
    cout<<"number of leaf "<<leafCount(root);
    cout << endl;
    cout<<"Number of nodes which has only one child "<<onechildCount(root);
    return 0;
}
