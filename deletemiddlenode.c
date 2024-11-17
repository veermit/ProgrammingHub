#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *next;
};

void deletemiddlenode(struct node **head)
{
    
    // if list is empty
    if(*head == NULL)
    {
        // error head is empty
        return;
    }
 
    struct node *prev = NULL;
    struct node *slow = *head;
    struct node *fast = *head;
    
    // if only 1 node is present
    if(fast->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    
    // iterate through loop and get the middle of the node
    while(fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    if(prev != NULL)
    {
        prev->next = slow->next;        
    }

    free(slow);
    slow = NULL;
}
void pushatbegining(struct node **head, int data)
{
    struct node * newnode = (struct node *) malloc (sizeof(struct node));
    if( !newnode )
    {
        // error 
        return;
    }
    
    newnode->data = data;
    newnode->next = (*head);
    (*head) = newnode;
}
void pushatend(struct node **head, int data)
{
    struct node *newnode = (struct node *) malloc (sizeof(struct node));
    if( !newnode )
    {
        // error
        return;
    }
    newnode->data = data;
    newnode->next = NULL;
    
    // this is first node 
    if(*head == NULL)
    {
        (*head) = newnode;
        return;
    }
    
    struct node *temp = *head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    
    temp->next = newnode;
}

void printlist(struct node *node)
{
    while(node != NULL)
    {
        printf( "%d ->", node->data);
        node = node->next;
    }
    printf("\n");
}

int main()
{
    struct node * head = NULL;
    pushatend(&head, 10);
    pushatbegining(&head, 20);
    pushatbegining(&head, 30);
    pushatend(&head, 40);
    deletemiddlenode(&head);
    printlist(head);
    deletemiddlenode(&head);
    printlist(head);
    return 0;
}
