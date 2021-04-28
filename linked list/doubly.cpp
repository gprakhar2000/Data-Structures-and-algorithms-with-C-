#include<iostream>
using namespace std;
                                    //structure of node
struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
}*first=NULL;
void create(int A[],int n){       //creating a doubly linked list
    struct Node *t, *last;
    int i;
    first=new Node;
    first->data=A[0];
    first->prev=NULL;
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        t->prev=last;
        last->next=t;
        last=t;
    }
    
}
void display(struct Node* p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int length(struct Node* p){
    int len=0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}
void insert(int pos,int n){
    
    if(pos==0){
        struct Node* t=new Node;
        t->data=n;
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first=t;
    }
    else{
        struct Node*p=first;
        struct Node* t=new Node;
        t->data=n;
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        t->next=p->next;
        t->prev=p;
        if(p->next){
            p->next->prev=t;
        }
        p->next=t;
    }
}
void deletel(int pos){
    if(pos==1){
        struct Node* p=first;
        first=first->next;
        if(first){
            first->prev=NULL;
        }
        delete p;
    }
    else{
        struct Node* p=first;
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next!=NULL){
            p->next->prev=p->prev;
        }
        delete p;
    }
}
int main(){
    int A[]={10,20,30,40,50};
    create(A,5);
    display(first);
    // insert(0,5);
    // display(first);
    // insert(4,35);
    // display(first);
    deletel(1);
    display(first);
    deletel(4);
    display(first);
    return 0;
}