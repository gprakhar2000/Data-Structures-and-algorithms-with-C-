/*Given a singly linked list of integers, reverse the nodes of the linked list 'k' at a time and return its modified list.
 'k' is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of 'k,' then left-out nodes, in the end, should be reversed as well.
Example :
Given this linked list: 1 -> 2 -> 3 -> 4 -> 5

For k = 2, you should return: 2 -> 1 -> 4 -> 3 -> 5

For k = 3, you should return: 3 -> 2 -> 1 -> 5 -> 4
*/


//Solution
Node *kReverse(Node *head, int k)
{
	//Write your code here
    if(head==NULL){
        return NULL;
    }
    if(k==0){
        return head;
    }
    Node* curr=head;
    Node* prev=NULL;
    Node* after=NULL;
    int count=1;
    while(curr!=NULL && count<=k){
        after=curr->next;
        curr->next=prev;
        prev=curr;
        curr=after;
        
        count++;
    }
    if(after!=NULL){
        head->next=kReverse(after,k);
    }
    return prev;
    
}