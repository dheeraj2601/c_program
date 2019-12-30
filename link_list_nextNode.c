#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
  int data;
  struct Node *next;
};
 
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
 
void insertAfter(struct Node* prev_node, int new_data)
{
    if (prev_node == NULL)
    {
      printf("the given previous node cannot be NULL");
      return;
    }
 
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}
 
void append(struct Node** head_ref, int new_data) // head_ref=0x7fffffffe4c8 . new_data=6
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); // &new_node = (struct Node **) 0x7fffffffe4a8 .
    struct Node *last = *head_ref;  /* used in step 5*/    // *new_node = {data = 0, next = 0x0} . new_node = (struct Node *) 0x602010
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)  // *head_ref = (struct Node *) 0x0. 
    {
       *head_ref = new_node;
       return;
    }
 
    while (last->next != NULL)
        last = last->next;
 
    last->next = new_node;
    return;
}
 
void printList(struct Node *node)
{
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
  printf("\n\n");
}

int display(void **nextNode, struct Node **node)
{
 struct Node *nn; 

 if (!*nextNode)
   {
     *nextNode = *node;
   }
 else
   {
     nn = (struct Node *)(*nextNode);     
     printf(" %d ", nn->data);
     if ((*node)->next)
       {
         *node = (*node)->next;
         *nextNode = *node;
       }
     else
       {
         *nextNode = NULL;
       }
   }
}

int display2(void **nextNode, struct Node **node)
{
 static struct Node *nn; 

 if (!*nextNode)
   {
     *nextNode = *node;
   }
 else
   {
     nn = (struct Node *)(*nextNode);     
     printf(" %d ", nn->data);
     if (nn->next)
       {
         nn = nn->next;
         *nextNode = nn;
       }
     else
       {
         *nextNode = NULL;
       }
   }
}

// for (ain = rn->adj_in; ain; ain = ain->next)
void printList1(struct Node *node)
{
 void *nextNode = NULL;

 do
   {
     display(&nextNode, &node);
   }
 while(nextNode != NULL);

 printf("\n\n");
}

void printList2(struct Node *node)
{
  struct Node *ain = NULL;
  for (ain = node; ain; ain = ain->next)
  {
     printf(" %d ", ain->data);
  }
  printf("\n\n");
}

void printList3(struct Node *node)
{
 void *nextNode = NULL;

 do
   {
     display2(&nextNode, &node);
   }
 while(nextNode != NULL);

 printf("\n\n");
}



int main()
{
  struct Node* head = NULL; // head = (struct Node *) 0x0 . &head = (struct Node **) 0x7fffffffe4c8
 
  append(&head, 6); // after &head = (struct Node **) 0x7fffffffe4c8. *head = {data = 6, next = 0x0}. head = (struct Node *) 0x602010 
  push(&head, 7);
  push(&head, 1);
  append(&head, 4);
  insertAfter(head->next, 8);
  printf("\n Created Linked list is: ");
  printList(head);   // Created Linked list is:  1  7  8  6  4 
  printList1(head);   // Created Linked list is:  1  7  8  6  4 
  printList2(head);   // Created Linked list is:  1  7  8  6  4 
  printList3(head);   // Created Linked list is:  1  7  8  6  4 
 
  return 0;
}
