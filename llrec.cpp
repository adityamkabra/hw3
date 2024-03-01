#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void helper(Node *&head, Node *&smaller, Node *&larger, int pivot,Node *smallertail, Node*largertail )
{
  if(head==nullptr)//base case to check if we have reached the end of the orignal linked list
  {
    if(smallertail!=nullptr)
    {
      smallertail->next=nullptr;//setting next pointer of the last node of smaller lists tail to null
    }
    if(largertail!=nullptr)
    {
      largertail->next=nullptr;//setting next pointer of the last node of larger lists tail to null
    }
    return;
  }
  if(head->val>pivot)//checking if value at the current node is greater than pivot
  {
    if(larger!=nullptr)//checking if larger does not point to a null pointer 
    {
      largertail->next=head;//adding current node at the end of the larger list
      largertail=head;//setting largertail to the current node
    }
    else
    {
      //if larger points to nullptr then we set larger and largertail to current node
      larger = head;
      largertail = head;
    }
  }
  else
  {
    if(smaller!=nullptr)//checking if smaller does not point to a null pointer 
    {
      smallertail->next=head;//adding current node at the end of the smaller list
      smallertail = head;//setting smallertail to the current node
    }
    else
    {
      //if smaller points to nullptr then we set smaller and smallertail to current node
      smaller = head;
      smallertail = head;
    }
  }
  helper(head->next,smaller, larger, pivot, smallertail, largertail);
  
}
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
  smaller=nullptr;
  larger=nullptr;
  Node* smallertail=nullptr;
  Node* largertail=nullptr;
  //calling helper
  helper(head, smaller, larger,pivot,smallertail, largertail);
  head = nullptr;//setting head to nullptr
}

