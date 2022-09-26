#include<bits/stdc++.h>
using namespace std;

/*
Q1. While traversing a single-circular linked list, which condition establishes that the traversing element/variable has reached the first element?
Q2. What are the practical applications of a circular linked list?
*/

struct node
{
    int data;
    node *next;
    
    node(int x)
    {
        data=x;
        next=NULL;
    }
};


void printList(node* head)
{
    if(head == NULL) return;
    
    cout<<head->data<<' ';
    
    for(node* pointer = head->next ; pointer != head ; pointer = pointer->next)  // (pointer != head) establishes that the traversing element/variable has reached the first element
    {
        cout<<pointer->data<<' ';
    }
}


int main() // 5 10 15 20 50 100
{
    node* head = new node(5);
    head->next = new node(10);
    head->next->next = new node(15);
    head->next->next->next = new node(20);
    head->next->next->next->next = new node(50);
    head->next->next->next->next->next = new node(100);
    head->next->next->next->next->next->next = head;
    
    printList(head);
    
    return 0;
}


/*
Question 1:   the condition pointer != head ensures that the pointer has reached the head again while travering the circular linked list.

Question 2:  uses of circular linked list:

1: used in audio/video streaming softwares to ensure the loop after its ended.
2: Data structures such as stacks and queues are implemented with the help of the circular linked lists.
3: used in implementing advance data structures like fibonacci heap
4: implementing round robin algorithm in various fields.

*/