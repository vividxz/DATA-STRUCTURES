#include <bits/stdc++.h>
using namespace std;

struct node
{
  int data;
  struct node* next;
};
struct node* START = NULL;

struct node* reverseNode(struct node* current)
{
  struct node *prev = NULL, *next=NULL;
  while(current!= NULL)
  {
    next = current -> next;
    current -> next = prev;
    prev = current;
    current = next;
  }
  return prev;
}
struct node* slowFast()
{
  struct node *slow = START, *fast = START;
  while (fast!=NULL) {
    fast = fast -> next;
    if (fast!=NULL){
      fast = fast -> next;
      slow = slow -> next;
    }
  }
    return slow;
}

bool isPallindrome()
 {
   struct node *END = reverseNode(slowFast()), *i, *j;
   i = START;
   j  = END;
   while(j->next->next != NULL)
   {
     if(i->data != j->data)
       return false;
     i = i -> next;
     j = j -> next;
   }
   return true;
 }

void insertNode()
{
  struct node *newNode;
  newNode = (struct node *)malloc(sizeof(struct node));
  cout<<"Enter a number\n";
  cin>>newNode -> data;
  newNode -> next = NULL;
  if(START == NULL)
    START = newNode;
  else
  {
    struct node *current = START;
    while(current->next != NULL)
      current = current->next;
    current -> next = newNode;
  }
}
int main()
{
  int n;
  cin>>n;
  while(n--)
     insertNode();
  if(isPallindrome())
    cout<<"Pallindrome\n";
  else
    cout<<"Not pallindrome\n";
}
