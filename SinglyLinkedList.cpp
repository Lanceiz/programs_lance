#include<bits/stdc++.h>
using namespace std;

//CLASS NODE
class node
{
  public:
  int data;
  node* next;
  node(int x)
  {
    data=x;
    next=NULL;
  }
};

//PRINT PROGRAM
void printLL(node* curr)
{
  cout<<endl;
  while(curr!=NULL)
  {
    cout<<curr->data<<"->";
    curr=curr->next;
  }
}

//INSERT AT HEAD
void inserthead(node* &head, int x)
{
  node* temp=new node(x);
  temp->next=head;
  head=temp;
}

//INSERT AT LAST
void insertlast(node* &head,int x)
{
  node* temp= new node(x);
  if(head==NULL)
  {
    head=temp;
  }
  node* curr=head;
  while(curr->next!=NULL)
  {
    curr=curr->next;
  }
  curr->next=temp;
}

//INSERT AT MIDDLE
void insertmid(node* head, int x, int pos)
{
  node* temp=new node(x);
  node* curr= head;
  int i=0;
  while(i<pos-2)
  {
    curr=curr->next;i++;
  } 
  temp->next=curr->next;
  curr->next=temp;
}

//DELETE HEAD
void deletehead(node* &head)
{
  node* temp=head;
  head=head->next;
  delete temp;
}


//DELETE LAST
void deletelast(node* &head)
{
  if(head==NULL)
  {
    head=NULL;
  }
  if(head->next==NULL)
  {
    delete head;
    head=NULL;

  }
  node* curr=head;
  while(curr->next->next!=NULL)
  {
    curr=curr->next;
  }
  delete curr->next;
  curr->next=NULL;
}

//SEARCH A NODE
void search(node* head, int ele)
{
  node* curr=head;
  while(curr!=NULL)
  {
     if(curr->data==ele)
     {
      cout<<"Found!!";
      exit(0);
     }
     curr=curr->next;
  }
  if(curr==NULL)
  {
    cout<<"Not found!!";
  }
}

//SORTED INSERT
void sortinsert(node* head,int x)
{
  node* temp=new node(x);
  if(x<head->data)
  {
    inserthead(head,x);
  }
  if(head==NULL)
  {
    head=temp;
  }
  node* curr=head;
  while((curr->next!=NULL)&&(curr->next->data<x))
  {
    curr=curr->next;
  }
  temp->next=curr->next;
  curr->next=temp;
}

//MIDDLE OF LINKED LIST
void middle(node* head)
{
  //naive
  node* curr=head;
  int cnt=0;
  for(;curr!=NULL;curr=curr->next)
  {cnt++;}
  curr=head;
  for(int i=0;i<cnt/2;i++)
  {curr=curr->next;}
  cout<<"\nMiddle element: "<<curr->data;

  /*EFFICIENT SOLUTION
  node* slow=head, *fast=head;
  while(fast!=NULL&&fast->next!=NULL)
  {
    slow=slow->next;
    fast=fast->next->next;
  }
  cout<<"\nMiddle element: "<<slow->data;
  */
}

//Nth node from the end
void nth(node* head,int n)
{
  //NAIVE
  int pos,len=0;
  node* curr=head;
  for(;curr!=NULL;curr=curr->next)
  {
    len++;
  }
  pos=len-n;
  curr=head;
  for(int i=0;i<pos;i++)
  {
    curr=curr->next;
  }
  cout<<"\nNth element from the end: "<<curr->data;

  //effecient
  /*
  node* first=head,*second=head;
  for(int i=0;i<n;i++)
  {
    curr=curr->next;
  }
  first=curr->next;
  while(first!=NULL)
  {
    first=first->next;
    second=second->next;
  }
  cout<<"Nth element is: "<<second->data;
  */
}

//REVERSE A LINKED LIST
void rev(node* &head)
{
  node* prev=NULL;
  node* curr=head;
  while(curr!=NULL)
  {
    node* temp=curr->next;
    curr->next=prev;
    prev=curr;
    curr=temp;
  }
  head=prev;
}

//REMOVE DUPLICATES
void duplicate(node* head)
{
  node* curr=head;
  while(curr!=NULL&&curr->next!=NULL)
  {
    if(curr->data==curr->next->data)
    {
      node *temp=curr->next;
      curr->next=curr->next->next;
      delete temp;
    }
    else
    {
      curr=curr->next;
    }
  }
}

//LOOP DETECTION
bool detectloop(ListNode *head) 
{
  node* slow=head,*fast=head;
  while(fast!=NULL&&fast->next!=NULL)
  {
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast)
    {
      return true;
    }
  }
  return false;
        
}

//DELETE NODE WHEN HEAD IS NOT GIVEN  (ONLY NODE IS GIVEN)
void deleteNode(node *ptr)
{s
  node* temp=ptr->next;
  ptr->data=temp->data;
  ptr->next=temp->next;
  delete temp;
}

//SEGREGATE EVEN&ODD NODES
void segregate(node* &head)
{
  node* es=NULL, ee=NULL,os=NULL,oe=NULL;
  for(node* curr=head;curr!=NULL;curr=curr->next)
  {
    int x=curr->data;
    if(x%2==0)
    {
      if(es==NULL)
      {
        es=curr;
        ee=es;
      }
      else
      {
        ee->next=curr;
        ee=ee->next;
      }
    }
    else
    {
      if(os==NULL)
      {
        os=curr;
        oe=os;
      }
      else
      {
        oe->next=curr;
        oe=oe->next;
      }
    }
  }
  ee->next=os;
  oe->next=NULL;
}

//MAIN
int main()
{
  int pos=3, x=25,ele;
  node *head= new node(10);
  head->next= new node(20);
  head->next->next= new node(30);
  inserthead(head,5);
  insertlast(head,40);
  deletehead(head);
  deletelast(head);
  insertmid(head,x,pos);
  printLL(head);
  /*cout<<"\nEnter the element to be searched: ";
  cin>>ele;
  search(head,ele);*/
  sortinsert(head,35);
  printLL(head);
  middle(head);
  nth(head,4);
  rev(head);
  cout<<"\nReverse list: ";
  printLL(head);
  return 0;
}


//SOME OTHER IMP FUNCTIONS

//FINDIND INTERSECTION OF 2 LISTS
/*int length(node* head)
{
  int l=0;
  node* temp=head;
  while(temp!=NULL)
  {
    temp=temp->next;
    l++;
  }
  return l;
}
int getintersection(node* h1,node *h2)
{
  node* ptr1=NULL,ptr2=NULL;
  l1=length(h1);
  l2=length(h2);
  if(l1>l2)
  {
    d=l1-l2;
    ptr1=head1;
    ptr2=head2;
  }
  else
  {
    d=l2-l1;
    ptr1=head2;
    ptr2=head1;
  }
  while(d)
  {
    ptr1=ptr1->next;
    if(ptr1==NULL)
    {
      return -1;
    }
    d--;
  }
  while(ptr1!=NULL&&ptr2!=NULL)
  {
    if(ptr1==ptr2)
    {
      return ptr1->data;
    }
    ptr1=ptr1->next;
    ptr2=ptr2->next;
  }
  return -1;
}
*/


//COPY  2 lists
/*void copy(Node* head)
{
 if(head==NULL)
  {
    return NULL;
  }
    Node *temp;
  for(Node *curr=head;curr!=NULL;)
  {
    temp=curr->next;
    curr->next=new Node(curr->val);
    curr->next->next=temp;
    curr=temp;
  }
  for(Node *curr=head;curr!=NULL;curr=curr->next->next)
  {
    curr->next->random=(curr->random!=NULL)?(curr->random->next):NULL;
  }
    
  Node* original = head, *copy = head->next; 
  
  temp = copy; 
  
  while (original && copy) 
  { 
    original->next = 
    original->next? original->next->next : original->next; 
    copy->next = copy->next?copy->next->next:copy->next; 
    original = original->next; 
    copy = copy->next; 
  } 
  return temp;   
}
*/

