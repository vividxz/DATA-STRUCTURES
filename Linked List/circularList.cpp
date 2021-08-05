#include <iostream>
using namespace std;

struct Node {
  int data;
  struct Node *next;
};

struct Node *Head = NULL;

struct Node * createNode(void)
{
  struct Node *temp;
  temp = (struct Node *)malloc(sizeof(struct Node));
  return temp;
}

void insertNode(void)
{
  struct Node *temp , *traverse;
  temp = createNode();
  cout<<"Enter a number\n";
  cin>> temp -> data;
  if(Head == NULL){
    Head = temp;
    temp -> next = Head;
  }

  else{
    traverse = Head;
    while(traverse->next != Head)
      traverse = traverse -> next;
    traverse -> next = temp;
    temp -> next = Head;
  }
}

void displayNode(void){
  struct Node * traverse;
  traverse = Head;
  cout<<traverse->data<<" ";
  traverse = traverse -> next;
  while(traverse != Head)
  {
    cout<<traverse->data<<" ";
    traverse = traverse -> next;
  }
}

int main()
{
  int listSize;
  cout<<"Enter list size\n";
  cin>>listSize;
  while(listSize--)
    insertNode();
  cout<<"Elements of List are :- \n";
  displayNode();
}
