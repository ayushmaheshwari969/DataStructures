#include<iostream>
using namespace std;

class node{
  public:
        int data;
        node* next;
        node(int d)
        {
            this->data = d;
            this->next = NULL;
        }
};

//Insert at First position of list 
void InsertatHead(node * &head , int d)
{
    node* temp = new node(d);
    temp ->next = head;
    head = temp;
}

//Insert at Last position of list
void InsertatTail(node*&tail , int d)
{
    node* temp = new node(d);
    tail->next = temp;
    tail = temp;
}

//Insert at any position
void InsertatPosition(node* &head , node* &tail , int position , int d)
{
    if(position == 1)
    {
        InsertatHead(head , d);
        return;
    }
    
    int cnt = 1;
    node* temp = head;
    while(cnt < position - 1)
    {
        temp = temp -> next;
        cnt++;
    }
    
    if(temp -> next == NULL)
    {
        InsertatTail(tail , d);
        return;
    }
    
    node* toinsert = new node(d);
    toinsert -> next = temp-> next;
    temp -> next = toinsert;
    
}
//Print the list
void printlist(node* &head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<',';
        temp = temp->next;
    }
}
int main()
{
    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;
    
    InsertatHead(head , 14);
    InsertatTail(tail , 15);
    InsertatTail(tail , 16);
    InsertatHead(head , 12);
    InsertatPosition(head , tail , 4 , 9);
    printlist(head);
}
