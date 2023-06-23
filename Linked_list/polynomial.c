#include <stdio.h>
#include <stdlib.h>

struct polynomial {
    int pow;
    int val;
    struct polynomial* next;
};

struct polynomial* addNode(struct polynomial* head, struct polynomial** tail, int p, int d) {
    if (head == NULL) {
        struct polynomial* temp = (struct polynomial*)malloc(sizeof(struct polynomial));
        temp->val = d;
        temp->pow = p;
        temp->next = NULL;
        *tail = temp;
        return temp;
    } else {
        struct polynomial* temp = (struct polynomial*)malloc(sizeof(struct polynomial));
        temp->val = d;
        temp->pow = p;
        temp->next = NULL;
        (*tail)->next = temp;
        *tail = temp;
        return head;
    }
}

void createNode(struct polynomial** head) {
    struct polynomial* tail = NULL;
    int p = 0;
    int d;
    while (p!=-1) {
        scanf("%d", &p);
        if (p !=-1) {
            scanf("%d", &d);
            *head = addNode(*head, &tail, p, d);
        }
    }
}

void printPolynomial(struct polynomial* head) {
    struct polynomial* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->val, temp->pow);
        temp = temp->next;
        if(temp){
            printf(" + ");
        }
    }
    printf("\n");
}
struct polynomial* addTwoPolynomial(struct polynomial* num1, struct polynomial* num2, struct polynomial* head) {
    struct polynomial* sum = NULL;
    struct polynomial* tail = NULL;
    
    while (num1 != NULL && num2 != NULL) {
        struct polynomial* temp = (struct polynomial*)malloc(sizeof(struct polynomial));
        
        if (num1->pow > num2->pow) {
            temp->val = num1->val;
            temp->pow = num1->pow;
            num1 = num1->next;
        } else if (num1->pow < num2->pow) {
            temp->val = num2->val;
            temp->pow = num2->pow;
            num2 = num2->next;
        } else {
            temp->val = num1->val + num2->val;
            temp->pow = num1->pow;
            num1 = num1->next;
            num2 = num2->next;
        }
        
        temp->next = NULL;
        
        if (sum == NULL) {
            sum = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    
    
    while (num1 != NULL) {
        struct polynomial* temp = (struct polynomial*)malloc(sizeof(struct polynomial));
        temp->val = num1->val;
        temp->pow = num1->pow;
        temp->next = NULL;
        
        tail->next = temp;
        tail = temp;
        
        num1 = num1->next;
    }
    
    
    while (num2 != NULL) {
        struct polynomial* temp = (struct polynomial*)malloc(sizeof(struct polynomial));
        temp->val = num2->val;
        temp->pow = num2->pow;
        temp->next = NULL;
        
        tail->next = temp;
        tail = temp;
        
        num2 = num2->next;
    }
    
    return sum;
}


int main() {
    struct polynomial* num1 = NULL;
    struct polynomial* num2 = NULL;
    
    printf("Enter polynomial 1 (enter -1 as power to exit):\n");
    createNode(&num1);

    printf("Enter polynomial 2 (enter -1 as power to exit):\n");
    createNode(&num2);

    printf("Polynomial 1: ");
    printPolynomial(num1);

    printf("Polynomial 2: ");
    printPolynomial(num2);
    
    struct polynomial* sum = NULL;
    sum=addTwoPolynomial(num1,num2,sum);

     printf("SUM: ");
     printPolynomial(sum);

    return 0;
}
