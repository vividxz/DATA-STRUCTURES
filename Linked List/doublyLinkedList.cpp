#include <iostream>
using namespace std;

struct Node{
  int data;
  struct Node *prev , *next;
};

struct Node *Head = NULL;

struct Node * createNode(){
  struct Node *temp;
  temp = (struct Node *)malloc(sizeof(struct Node));
  return temp;
}

void insertNode(){
  struct Node *temp , *traverse;
  temp = createNode();
  cout<<"Enter a number\n";
  cin>>temp -> data ;
  if(Head == NULL)
  {
    Head = temp;
    temp -> prev = NULL;
    temp -> next = NULL;
  }
  else
  {
    traverse = Head;
    while(traverse -> next != NULL)
    {
      traverse = traverse -> next;
    }
    traverse -> next = temp;
    temp -> prev = traverse;
    temp -> next = NULL;
  }
}

void displayNode(){
  struct Node *traverse = Head;
  while(traverse -> next != NULL)
  {
    cout<<traverse -> data<<" ";
    traverse = traverse -> next;
  }

  cout<<traverse -> data<<" ";

  while(traverse != NULL)
  {
    cout<<traverse -> data<<" ";
    traverse = traverse -> prev;
  }
}

int main()
{
  int n;
  cin>>n;
  while(n--)
    insertNode();
  displayNode();
}
