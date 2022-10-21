# Implementation of "Hello World" and Linked List of 100 elements

## Hello World

	command/prompt/text$ cat helloworld.c
	
	/* hello.c */
	#include <stdio.h>
	#include <stdlib.h>
	int main()
	{
	  printf("Hello world.\n");
	  exit(0);
	}
	command/prompt/text$ a.out
	Hello world.
	
- This code prints "hello world" using printf().
- The print statement is called within the int main(0) function, which is exited by returning an int value of 0

## List

	command/prompt/text$ cat list.c
	// C program for generic linked list
	#include<stdio.h>
	#include<stdlib.h>
	 
	/* A linked list node */
	struct Node
	{
	    // Any data type can be stored in this node
	    void  *data;
	 
	    struct Node *next;
	};
	 
	/* Function to add a node at the beginning of Linked List.
	   This function expects a pointer to the data to be added
	   and size of the data type */
	void push(struct Node** head_ref, void *new_data, size_t data_size)
	{
	    // Allocate memory for node
	    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	 
	    new_node->data  = malloc(data_size);
	    new_node->next = (*head_ref);
	 
	    // Copy contents of new_data to newly allocated memory.
	    // Assumption: char takes 1 byte.
	    int i;
	    for (i=0; i<data_size; i++)
	        *(char *)(new_node->data + i) = *(char *)(new_data + i);
	 
	    // Change head pointer as new node is added at the beginning
	    (*head_ref)    = new_node;
	}
	 
	/* Function to print nodes in a given linked list. fpitr is used
	   to access the function to be used for printing current node data.
	   Note that different data types need different specifier in printf() */
	void printList(struct Node *node, void (*fptr)(void *))
	{
	    while (node != NULL)
	    {
	        (*fptr)(node->data);
	        node = node->next;
	    }
	}
	 
	// Function to print an integer
	void printInt(void *n)
	{
	   printf(" %d", *(int *)n);
	}
	 
	// Function to print a float
	void printFloat(void *f)
	{
	   printf(" %f", *(float *)f);
	}
	 
	/* Driver program to test above function */
	int main()
	{
	    struct Node *start = NULL;
	 
	    // Create and print an int linked list
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
	command/prompt/text$ a.out   
	Created integer linked list is 
	 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 

- This code works by defining a node struct.
- Each node only needs to define an int (the data value) and a pointer to the next node.
- This code also contains a fair bit of utility functions to print properly formatted ints, floats, etc..
-  The main() works by defining an array of ints all at once, then translating it into a list using the push() function which automatically adds the new node to the end of the list. The list is then printed using printList()