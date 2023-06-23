#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
       next=NULL;
       this->data=data;
    }
};
void add(Node* &head,Node* &tail,int x){
    if(head==NULL){
         Node* list=new Node(x);
         head=list;
         tail=list;
    }
    else{
         Node* temp=new Node(x);
         tail->next=temp;
         tail=temp;
    }
}
void deleteAtBegining(Node* &head){
    if(head==NULL || head->next==NULL){
        head=NULL;
    }
    else{
        Node* temp=head;
        head=head->next;
        delete temp;
    }
}
void deleteAtEnd(Node* &head,Node* &tail){
    if (head == NULL) {
        return;
    }
    if (head->next == NULL) {
        head=NULL;
    } else {
       Node* temp=head;
       Node* toDelete=NULL;
       while(temp->next){
           toDelete=temp;
           temp=temp->next;
       }
       toDelete->next=NULL;
       tail=toDelete;
       delete temp;
    }
}

void deleteAtAnyPosition(Node* head,int position){
    
}
void print(Node* &head){
     Node* temp=head;
     while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
     }
}

int main(){
    Node* head;
    Node* tail;
    head=NULL;
    cout<<"Enter -1 to stop adding";
    int x=0;
    while(x!=-1){
        cin>>x;
        if(x!=-1){
            add(head,tail,x);
        }
    }
    deleteAtBegining(head);
    cout<<"The head elemenet is"<<head->data<<endl;
    deleteAtEnd(head,tail);
    cout<<"The tail elemenet is"<<tail->data<<endl;
    print(head);
    return 0;
}