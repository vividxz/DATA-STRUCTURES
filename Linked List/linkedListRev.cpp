#include <iostream>
using namespace std;

struct Node{
  int data;
  struct Node* next;
};

struct Node* Head = NULL;

struct Node* createNode(void){
  struct Node * temp;
  temp = (struct Node*)malloc(sizeof(struct Node));
  return temp;
}

void insertNode(void){
  struct Node *temp , *traverse;
  temp = createNode();
  cout<<"Enter a number\n";
  cin>>temp -> data;
  if(Head == NULL){
    Head = temp;
    temp -> next = NULL;
  }
  else{
    traverse = Head;
    while(traverse -> next != NULL)
      traverse = traverse -> next;
    traverse -> next = temp;
    temp -> next = NULL;
  }
}

void reverseList(void){
  struct Node *traverse , *prev = NULL , *forward;
  traverse = Head;
  while(traverse != NULL)
  {
    forward = traverse -> next;
    traverse -> next = prev;
    prev = traverse;
    traverse = forward;
  }
  Head = prev;
}

void displayList(){
  struct Node * traverse = Head;
  while(traverse != NULL){
    cout<<traverse -> data<<" ";
    traverse = traverse -> next;
  }
}

int main()
{
  int n;
  cout<<"Enter list size";
  cin>>n;
  while(n--)
    insertNode();
  reverseList();
  displayList();
}
