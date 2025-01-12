/*
 * Complete the 'sortedInsert' function below.
 *
 * The function is expected to return an INTEGER_DOUBLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_DOUBLY_LINKED_LIST llist
 *  2. INTEGER data
 */

/*
 * For your reference:

 DoublyLinkedListNode{
      int data;
      DoublyLinkedListNode* next;
      DoublyLinkedListNode* prev;
  };
 */
 

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
  
   
   DoublyLinkedListNode *current = NULL;
  DoublyLinkedListNode *new_node = (DoublyLinkedListNode*)malloc(sizeof(DoublyLinkedListNode));
    new_node->data=data;
    new_node->next=NULL;
    new_node->prev=NULL;
    
  if (llist == NULL )
  {
    llist= new_node; 
  }
  else if(llist->data >= new_node->data)
  {
    new_node->next = llist;
    llist->prev=new_node;
   llist= new_node; 
  }
  else
  {
    
    current = llist;
    while (current->next!=NULL && current->next->data < new_node->data)
    {
      current = current->next;
    }
      
      if(current->next!=NULL)
      {
          new_node->next = current->next;
          current->next->prev=new_node;
      }     
      current->next = new_node;
      new_node->prev=current;
      
  }       
    return llist;
}

