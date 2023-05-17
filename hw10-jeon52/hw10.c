// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h>
#include "hw10.h"

// DO NOT MODIFY this function --->>>
void printListNode(ListNode * head)
{
  ListNode * p = head;
  printf("printListNode: ");
  while (p != NULL) // the linked list must end with NULL
    {
      printf("%7d ", p -> value);
      p = p -> next;
    }
  printf("\n");
}
// <<<--- until here

// You MUST modify the following functions

#ifdef TEST_CREATELIST
// create a linked list storing values 0, 1, 2, ... valn - 1
// The first node (head) stores 0, the next node stores 1,
// ..., the last node stores valn - 1
// return the head of the linked listn
// the linked list must end with NULL
ListNode * createList(int valn)
{
  //first node
  ListNode * firsthead = NULL;
  ListNode * head = NULL; //initialize an empty linked list
  ListNode * temp = NULL;

  int count = 0;
  head = malloc (sizeof(ListNode));
  head -> value = count;

  firsthead = head;
  temp = head;

  //rest of the node
  while (count <= valn)
  {
    if(count == valn - 1)
    {
      temp -> next = NULL; 
      break;
    }

    count++;
    temp -> next = malloc(sizeof(ListNode));
    temp -> next -> value = count; 
    temp = temp -> next;
  }
  return firsthead;
}
#endif

#ifdef TEST_ELIMINATE
// eliminate the nodes in the linked list
// starting from the head, move one node at a time and count to valk.
// eliminate that node, keep counting
//
// when reaching the end of the list, continue from the beginning of
// the list
//
// print the values of the nodes to be deleted
void eliminate(ListNode * head, int valk) 
{
  // this #ifdef ... #endif should be inside the condition *BEFORE* a
  // node' value is printed and it is deleted
  ListNode * todelete = NULL;
  ListNode * temp = NULL;

  //initial counting!
  int count = 1; 
  temp = head; //initializtion to first head. will be using temp to traverse (DONT CHANGE HEAD HERE)

  while (count <= valk)
  {
    //when counting hits valk 
    if (count == valk) 
    {
      todelete = temp; 
      //if next is not null

      #ifdef DEBUG
      if (head -> next != NULL)
      {
        printListNode (todelete); //print up to to delete 
        printf("%d\n", todelete -> value);
        head = deleteNode(head, todelete); //we reset the head value in the deletenode
        if (head == NULL) //value returned from deletenode 
        {
          return;
        }
      }
      else
      {
        printf("%d\n", todelete -> value);
        free(head);
        return;
      }
      #endif

      if (temp -> next != NULL)
      {
        temp = temp -> next; 
        count = 1;
      }
      else if (temp -> next == NULL)
      {
        count = 1; 
        temp = head; 
      }
    }
    else //when not hit valk
    {
      if (temp -> next == NULL) //when we hit the last list
      {
        count++;
        temp = head;
      }
      else //if not at the end of the list
      {
        count++;
        temp = temp -> next; //traversing to next node
      }
    }
  }
}
#endif

#ifdef TEST_DELETENODE
// head points to the first node in the linked list
// todelete points  to the node to be deleted
//
// delete the node and return the head of the linked list
// release the memory of the deleted node
//
// should check several conditions:
// 1. If head is NULL, the list is empty and this function returns NULL X
// 2. If todelete is NULL, nothing can be deleted, return head
// 3. If todelete is not in the list, keep the list unchanged and
//    return head
// It is possible that todelete is the first node in the list (i.e.,
// the head). If this occurs, return the second node of the list.
ListNode * deleteNode(ListNode * head, ListNode * todelete)
{
  ListNode * ptr = NULL; //for deleting
  ListNode * temp = NULL; //for traversing (checking if todelete is part of the list)
  ptr = head; 
  temp = head; 
  int count = 0;

  if (head == NULL)
  {
    return NULL;
  }
  if (todelete == NULL)
  {
    return head;
  }

  while (temp != NULL) //checking if temp value does exist in the list
  {
    if (temp -> value != todelete -> value) //if value does not match, traverse to the next value
    {
      temp = temp -> next;
    }
    else //if there is a value that matches, increase the value to 1
    {
      count++;
      break;
    }
  }

  if (count == 0) //todelete is not in the list, return head
  {
    return head;
  }
  else //todelete is in the list (USE PTR FROM HERE)
  {
    if (todelete == head) //if delete is first node
    {
      head = head -> next; //relink
      free(todelete); //free memory
      return head; //return updated head 
    }
    else //if delete is not the first node
    {
      while (ptr -> next -> value != todelete -> value) //Note that ptr starts from the head (todelete is always ahead)
      {
        ptr = ptr -> next; //traverse ptr by 1
      }

      if (todelete -> next == NULL) //make sure delete next links to the head!
      {
        ptr -> next = NULL; //(relinking): think of this as ptr node -> todelete node -> NULL
        free(todelete);
        return head; //returning the unchanged head
      }
      else
      {
      ptr -> next = todelete -> next; //(relinking) -> think of this as ptr node -> todelete node -> next node
      free(todelete);
      return head; //returning the unchanged head
      }
    }
  }
}
#endif
