#include <iostream>
using namespace std;


class node
{

public:
  int data;

  node *next;


node (int data)
  {
    this->data = data;
    this->next = NULL;
  }
};



void
InsertatHead (node * &head, int d)
{

// New node
  node *temp = new node (d);

  temp->next = head;

  head = temp;

}

void
InsertatTail (node * &tail, int d)
{

//new node
  node *temp = new node (d);

  tail->next = temp;

  tail = temp;

}

void
InsertatPosition (node * &head, node * &tail, int position, int d)
{

  if (position == 1)		// Insertion at head
    {

      InsertatHead (head, d);

      return;

    }

  node *temp = head;

  int cnt = 1;

  while (cnt < position - 1)

    {

      temp = temp->next;

      cnt++;

    }

  if (temp->next == NULL)	// Last position Insertion at tail
    {

      InsertatTail (tail, d);

      return;

    }


  node *toinsert = new node (d);

  toinsert->next = temp->next;

  temp->next = toinsert;

}



void
printHead (node * &head)
{

  node *temp = head;

  while (temp != NULL)

    {

      cout << temp->data << " ";

      temp = temp->next;

    }

  cout << endl;

}


int
main ()
{

  node *node1 = new node (10);

  node *head = node1;

  node *tail = node1;

/* printHead(head);
InsertatHead(head , 12);
printHead(head);
InsertatHead(head , 15);
printHead(head);*/
//printHead(node1);
  InsertatTail (tail, 12);

//printHead(node1);
  InsertatTail (tail, 15);

  printHead (node1);


  InsertatPosition (node1, tail, 4, 30);

  printHead (head);

  cout << head->data << endl;

  cout << tail->data << endl;

  InsertatPosition (head, tail, 1, 50);

  printHead (head);

  cout << head->data << endl;

  cout << tail->data << endl;


  return 0;

}
