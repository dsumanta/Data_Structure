#include<iostream>
using namespace std;

struct Node {
    struct Node* lchild;
    int data;
    struct Node* rchild;
};

void insert(Node* &r, int data) {
    if (r == NULL) {
        Node* p = new Node();
        p->lchild = NULL;
        p->rchild = NULL;
        p->data = data;
        r = p;
        return;
    }
    if (data < r->data) {
        insert(r->lchild, data);
    }
    else if (data > r->data) {
        insert(r->rchild, data);
    }
}

int Height(Node* p) {
    if (p == NULL) {
        return 0;
    }
    int x = Height(p->lchild);
    int y = Height(p->rchild);
    return (x > y) ? (x + 1) : (y + 1);
}
// InPre() function is redundant function
Node* InPre(Node* p) {
    if (p && p->rchild != NULL) {
        p = p->rchild;
    }
    return p;
}

Node* InSucc(Node* p) {
    if (p && p->lchild != NULL) {
        p = p->lchild;
    }
    return p;
}

void Nodedelete(Node* &p, int key) {
    if (p == NULL) {
        return;
    }
    if (p->data > key) {
        Nodedelete(p->lchild, key);
    }
    else if (p->data < key) {
        Nodedelete(p->rchild, key);
    }
    else {
        if (p->lchild == NULL) {
            Node* temp = p;
            p = p->rchild;
            delete temp;
        }
        else if (p->rchild == NULL) {
            Node* temp = p;
            p = p->lchild;
            delete temp;
        }
        else {
            Node* q = InSucc(p->rchild);
            p->data = q->data;
            Nodedelete(p->rchild, q->data);
        }
    }
}

void inorder(Node* p) {
    if (p) {
        inorder(p->lchild);
        cout << p->data << " ";
        inorder(p->rchild);
    }
}

int main() {
    struct Node* root = NULL;
    cout << "Enter the node values, -1 to stop adding: ";
    int x;
    while (cin >> x) {
        if (x == -1) {
            break;
        }
        insert(root, x);
    }
    cout << "Enter the node value to delete: ";
    int y;
    cin >> y;
    Nodedelete(root, y);
    inorder(root);
    return 0;
}
 