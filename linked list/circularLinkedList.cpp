#include<iostream>
using namespace std;
struct Node
{
    /* data */int data;
    struct Node* next; // self referential pointer
}*head;    //initializing first head global pointer for linked list.

void Create(int arr[],int n){
    head=new Node;
    head->data=arr[0]; //first node created.
    head->next=head;
    Node* x,*last;
    last=head;
    for(int i=1;i<n;i++){
        x=new Node;
        x->data=arr[i];            //creating rest of linked list
        x->next=last->next;
        last->next=x;
        last=x;
    }
}


void Display(struct Node* p){
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
    cout<<endl;
}


void RecDisplay(struct Node* x){
    static int flag=0;  // creating a single variable for a function so that it is not created again and again.
    if(x!=head || flag==0){
        flag=1;
        cout<<x->data<<endl;
        RecDisplay(x->next);
    }
    flag=0; // again setting the variable to zero so that it could be used again.
}


//inserting node at a particular position according to 0 based indexing.
void Insert(struct Node* x,int pos,int n){
    if(pos==0){
        struct Node* t=new Node;
        t->data=n;
        while(x->next!=head){
            x=x->next;
        }
        x->next=t;
        t->next=head;
        head=t;
    }
    else{
        struct Node* t=new Node;
        t->data=n;
        for(int i=0;i<pos-1;i++){
            x=x->next;
        }
        t->next=x->next;
        x->next=t;
    }
}


void Delete(int pos){
    if(pos==1){
        struct Node* t=head;
        while(t->next!=head){
            t=t->next;
        }
        t->next=head->next;
        delete head;
        head=t->next;
    }
    else{
        struct Node* t=head;
        for(int i=0;i<pos-2;i++){
            t=t->next;
        }
        struct Node* q=t->next;
        t->next=q->next;
        delete q;
    }
}


int main(){
    int arr[]={2,3,4,5,6};
    Create(arr,5);
    // Display(head);
    // RecDisplay(head);
    // Insert(head,0,1);
    // Insert(head,6,7);
    Display(head);
    Delete(3);
    Display(head);
    Delete(1);
    Display(head);
}