/*Given a singly linked list of integers, sort it using 'Merge Sort.'
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Sample Input 1 :
1
10 9 8 7 6 5 4 3 -1
Sample Output 1 :
 3 4 5 6 7 8 9 10 
 Sample Output 2 :
2
-1
10 -5 9 90 5 67 1 89 -1
Sample Output 2 :
-5 1 5 9 10 67 89 90 
*/



Node *merge(Node *h1, Node *h2)
{
    //Write your code here
    if(h1==NULL){
        return h2;
    }
    if(h2==NULL){
        return h1;
    }
    Node* fh=NULL;
    Node* ft=NULL;
    if(h1->data<=h2->data){
    	fh=h1;
        ft=h1;
        h1=h1->next;
    }
    else{
        fh=h2;
        ft=h2;
        h2=h2->next;
    }
    while(h1!=NULL && h2!=NULL){
        if(h2->data<=h1->data){
			ft->next=h2;
            ft=h2;
            h2=h2->next;
        }
        else{
            ft->next=h1;
            ft=h1;
            h1=h1->next;
        }
    }
    if(h2==NULL){
        ft->next=h1;
    }
    else{
        ft->next=h2;
    }
    return fh;
}
Node *mergeSort(Node *head)
{
	//Write your code here
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* p=head;
    int count=0;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    p=head;
    int mid=count/2;
    int i=0;
    while(p!=NULL && i<mid-1){
        p=p->next;
        i++;
    }
    Node* temp=p->next;
    p->next=NULL;
    Node* h1=mergeSort(head);
    Node* h2=mergeSort(temp);
    return merge(h1,h2);
    
}