// Linked List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct node {
    int data;
    struct node* next;
};
//Displaying linked list recusrsively
void display(struct node* p) {
    if (p != 0) {
        cout << p->data<<" ";
        display(p->next);
    }
}
void recdisplay

int main()
{
    struct node* newnode, * start, * copy;
    start = new node;
    //creating a linked list------
    if (start == NULL) {
        cout << "No memory";
    }
    start->data = 10;
    start->next = NULL;
    copy = start;
    int x;
    for (int i = 2; i <= 5; i++) {
        cin >> x;
        newnode = new node;
        if (newnode == NULL) {
            cout << " No Memory";
        }
        newnode->data = x;
        newnode->next = NULL;
        copy->next = newnode;
        copy = copy->next;
    }
    //Displaying linked list-------
    /*struct node* p = start;*/
    /*while (p != 0) {
        cout << p->data << endl;;
        p = p->next;
    }*/
    display(start);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
