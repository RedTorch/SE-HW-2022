// C program for generic linked list
#include<stdio.h>
#include<stdlib.h>


// the node struct
struct Node
{
    void  *data;
    struct Node *next;
};
 


// pushes a new node to the linked list
void push(struct Node** head_ref, void *new_data, size_t data_size)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
 
    new_node->data  = malloc(data_size);
    new_node->next = (*head_ref);

    int i;
    for (i=0; i<data_size; i++)
        *(char *)(new_node->data + i) = *(char *)(new_data + i);

    (*head_ref)    = new_node;
}



void printList(struct Node *node, void (*fptr)(void *))
{
    while (node != NULL)
    {
        (*fptr)(node->data);
        node = node->next;
    }
}



void printInt(void *n)
{
   printf(" %d", *(int *)n);
}



void printFloat(void *f)
{
   printf(" %f", *(float *)f);
}



// This function first creates an array of ints.
// Then, it translates each of these ints into the linked list.
int main()
{
    struct Node *start = NULL;

    unsigned int_size = sizeof(int);
    int arr[100] = {};
    for(int i=0;i<100;i++) {
      arr[i] = i+1;
    }
    for (int i=sizeof(arr)/sizeof(arr[0]); i>=0; i--)
       push(&start, &arr[i], int_size);
    printf("Created integer linked list is \n");
    printList(start, printInt);
 
    return 0;
}
