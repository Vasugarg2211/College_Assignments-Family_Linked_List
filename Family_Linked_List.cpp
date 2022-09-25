#include<bits/stdc++.h>
using namespace std;

/* Question:- Create a doubly linked list with your family members as elements; include the following details as node values:
Name
Age
Bonus: Try to find a way to link the family members' doubly-linked list based on their relationship. (Is it possible?) */

struct node // basic  structure of node of a doubly linked ist
{
    string name;
    int age;
    node* next;
    node* prev;
    
    node(string d,int a)
    {
        name = d;
        age = a;
        next = NULL;
        prev = NULL;
    }
};

void printFamily(node *head)  // function to print the details of all family members
{
    if(head==NULL)
    {
        return;
    }
    
    cout<<head->name<<' '<<head->age<<' '<<endl;
    printFamily(head->next);
}

node* insertMember(node* head, string name , int age) // insert member at the end of the linked list
{
    node* new_node = new node(name,age);
    
    if(head == NULL)
    {
        return new_node;
    }
    
    node* curr=head;
    
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    
    curr->next = new_node;
    new_node->prev = curr;
    return head;
}

node* deleteMember(node* head,string name) // deletes the member with a given name
{
    if(head->name == name)
    {
        head = head->next;
        return head;
    }
    
    node* curr = head;
    
    while(curr->next->name != name  && curr->next != NULL)
    {
        curr = curr->next;
    }
    
    node* temp = curr->next;
    
    curr->next = curr->next->next;
    curr->next->prev = curr;
    
    delete temp;
    return head;
}


int familySize(node *head) // returns the current ize of the family
{
    if(head==NULL)
    {
        return 0;
    }
    
    int size = 1;
    
    node* temp = head;
    
    while(temp->next != NULL)
    {
        temp = temp->next;
        size+=1;
    }
    
    return size;
}

int main()
{
    
    node* head = new node("Ashok",42);  
    node* member1 = new node("Parveen",41);
    node* member2 = new node("Vasu",18);
    node* member3 = new node("Gaurav",17);
    
    head->next = member1;
    member1->next = member2;
    member2->next = member3;
    
    member1->prev = head;
    member2->prev = member1;
    member3->prev = member2;
    
    head = insertMember(head,"Sample",20);
    cout<<"family after inserting one member :"<<endl;
    printFamily(head); // prints the name and age of all the family members
    
    cout<<endl;
    cout<<"family after deleting one member :"<<endl;
    head = deleteMember(head,"Vasu"); // deletes the member with the given head
    printFamily(head);
    
    cout<<endl;
    cout<<"Size of the family is : ";
    cout<<familySize(head)<<endl; // gives the current size of family
    
    return 0;
}