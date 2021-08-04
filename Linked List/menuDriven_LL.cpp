#include <iostream>
using namespace std;

int main();

char ch;

struct Node{
  int data;
  struct Node *next;
};

struct Node *Head = NULL;

struct Node * createNode(void)
{
  struct Node * temp;
  temp = (struct Node *)malloc(sizeof(struct Node));
  return temp;
}

void insertNode(void)
{
  struct Node * temp , *traverse;
  temp = createNode();
  cout<<"Enter a number"<<endl;
  cin>>temp->data;
  if(Head == NULL){
    Head = temp;
    temp -> next = NULL;
  }
  else
  {
    traverse = Head;
    while(traverse->next != NULL)
      traverse = traverse -> next ;
    traverse -> next = temp;
    temp -> next = NULL;
  }
}

void deleteNode(void)
{
  if(Head == NULL){
    cout<<"List is empty\n";
    int k = main();
  }
  int position;
  cout<<"Enter position of element to delete\n";
  cin>>position;
  struct Node *traverse , *temp;
  if(position == 1){
    temp = Head;
    Head = Head -> next;
    free(temp);
  }
  else{
    traverse = Head;
    while(position-- -2)
      traverse = traverse -> next;
    temp = traverse -> next;
    traverse -> next = temp -> next;
    free(temp);
  }
}

void displayNode(void)
{
  struct Node * traverse = Head;
  while(traverse != NULL)
  {
    cout<<traverse -> data<<endl;
    traverse = traverse -> next ;
  }
}

int main()
{
  int choice;
  do{
    cout<<"Enter 1 to Add element\nEnter 2 to Delete element\nEnter 3 to display elements\n";
    cin>>choice;

    switch (choice){
      case 1:
        insertNode();
        break;
      case 2:
        deleteNode();
        break;
      case 3:
        displayNode();
        break;
      default:
        cout<<"Enter appropriate choice\n";
    }
    cout<<"Continue ? y/n";
    cin>>ch;
  }while(ch == 'y');
  return 0;
}
