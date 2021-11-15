#include <bits/stdc++.h>
using namespace std;
int main();
struct node
{
  int data;
  struct node* next;
};

struct node* START = NULL;

struct node* CreateNode()
{
  struct node* temp;

  temp = (struct node*)malloc(sizeof(struct node));
  return temp;
}
void InsertEnd()
{
  struct node* temp = CreateNode();
  cout<<"Enter a number\n";
  cin>>temp->data;
  temp -> next = NULL;
  if(START == NULL)
    START = temp;
  else
  {
    struct node* t = START;
    while(t->next != NULL)
      t = t->next;
    t -> next = temp;
  }
}
void InsertStart()
{
  struct node* temp = CreateNode();
  cout<<"Enter a number\n";
  cin>>temp->data;
  if(START == NULL)
  {
    START = temp;
    temp -> next = NULL;
  }
  else
  {
    temp -> next = START;
    START = temp;
  }
}
void InsertBet()
{
  int pos;
  cout<<"Enter position\n";
  cin>>pos;
  struct node* temp = CreateNode();
  cout<<"Enter a number\n";
  cin>>temp->data;
  struct node* t = START;
  pos -= 2;
  while(pos--)
    t = t -> next;
  temp -> next =  t -> next;
  t -> next = temp;
}
void InsertNode()
{
    cout<<"Enter 1 to insert in begining\n";
    cout<<"Enter 2 to insert at end\n";
    cout<<"Enter 3 to insert at a given position\n";
    int choice;
    cin>>choice;
    switch (choice)
    {
      case 1:
        InsertStart();
        break;
      case 2:
        InsertEnd();
        break;
      case 3:
        InsertBet();
        break;
      default:
        cout<<"Enter appropriate choice\n";
    }
}
void deleteLast()
{
  struct node* t = START;
  while((t->next)->next != NULL)
    t = t -> next;
  free(t -> next);
  t -> next = NULL;
}
void deleteFirst()
{
   struct node* temp = START;
   START = START -> next;
   free(temp);
}
void deleteBet()
{
  int key;
  cout<<"Enter element to delete\n";
  cin>>key;
  struct node* t = START, *temp;
  while(t != NULL)
  {
    if(t->next!= NULL && (t->next)->data == key)
      break;
    t = t->next;
  }
  if(t == NULL)
    cout<<"Element Not found\n";
  else
  {
    temp = t->next;
    t->next = temp->next;
    free(temp);
  }
}

void displayNodes()
{
  struct node* t = START;
  while(t != NULL)
  {
    cout<<t->data<<endl;
    t = t->next;
  }
}

void deleteNode()
{
  cout<<"Enter 1 to delete first node\n";
  cout<<"Enter 2 to delete last node\n";
  cout<<"Enter 3 to delete a key node\n";
  int choice;
  cin>>choice;
  switch (choice)
  {
    case 1:
      deleteFirst();
      break;
    case 2:
      deleteLast();
      break;
    case 3:
      deleteBet();
      break;
    default:
      cout<<"Enter appropriate choice\n";
  }
}
void reverseList()
{
  struct node *prev = NULL, *current = START, *next;
  while(current -> next != NULL)
  {
    next = current -> next;
    current -> next = prev;
    prev = current;
    current = next;
    next = next -> next;
  }
  current -> next = prev;
  START = current;
}
int main()
{
  int choice;
  char yn;
  do
  {
    system("cls");
    cout<<"Enter 1 to insert node\n";
    cout<<"Enter 2 to delete node\n";
    cout<<"Enter 3 to reverse list\n";
    cout<<"Enter 4 to display list\n";
    cin>>choice;
    switch (choice)
    {
      case 1:
        InsertNode();
        break;
      case 2:
        deleteNode();
        break;
      case 3:
        reverseList();
        break;
        case 4:
        displayNodes();
        break;
      default:
        cout<<"Enter appropriate choice\n";
    }
    cout<<"Continue ? Y/N\n";
    cin>>yn;
  }while(yn == 'Y' || yn == 'y');

}
