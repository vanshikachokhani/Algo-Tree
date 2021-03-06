
/*
This Program splits the linked list into two parts.
Language: C++

Logic Used:
If it's number of nodes in the linked list is even(2n) then both the lists contains n nodes.
If the original list contains odd number of nodes(2n+1) then 1st list contains n+1 nodes and 2nd contains n nodes.
*/


#include <iostream>
#include <stdlib.h>

using namespace std;

//initializing structure
class Node{
public:
    int data;
    Node *next;
};

Node* head = nullptr;
Node* tail = nullptr;

//Function to create a linked list
void create(int n)
{
    while(n!=0)
    {
        int x;
        cin>>x;
        if (head == nullptr)
        {
            Node* temp=new Node;
            temp->data=x;
            temp->next = nullptr;
            head=temp;
            tail=head;
        }
        else
        {
            Node* temp=new Node;
            temp->data=x;
            temp->next = nullptr;
            tail->next=temp;
            tail=temp;
        }
        n--;
    }
}

Node* list1 = nullptr;
Node* list2 = nullptr;

//Split Function
void split()
{
    Node* temp=head;
    int count=0;
    while(temp != nullptr)
    {
        temp=temp->next;
        count++;
    }
    int n=0;
    temp=head;
    while(n!=(count-1)/2)
    {
        temp=temp->next;
        n++;
    }
    list1=head;
    list2=temp->next;
    temp->next = nullptr;
}

void display(struct Node* list)
{
    Node* temp=list;
    while(temp!=nullptr)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    cout<<"Enter no. of nodes in linked list: ";
    int y;
    cin>>y;
    create(y);
    cout<<"Linked List Created: ";
    display(head);
    split();
    cout<<"Split-ed Linked List: ";
    display(list1);
    display(list2);


}

/*
Input format in test cases:
1st line contains number of nodes in the linked list(n).
2nd line contains value of each node (total n) separated by spaces.

--------------------------------------------------
Test Case 1:
Input:
6
1 2 3 4 5 6

Output:
Linked List Created: 1->2->3->4->5->6->NULL
Split-ed Linked List: 1->2->3->NULL
4->5->6->NULL
---------------------------------------------------
Test Case 2:
Input:
7
1 2 3 4 5 6 7
Output:
Linked List Created: 1->2->3->4->5->6->7->NULL
Split-ed Linked List: 1->2->3->4->NULL
5->6->7->NULL
----------------------------------------------------

Time Complexity: split() function: O(n)
Space complexity: split() function: O(n)

*/
