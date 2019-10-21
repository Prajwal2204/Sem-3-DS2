#include <stdio.h>
#include <stdlib.h>

// Node of the linked list
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Handle of the list. Its head points to the first node in the list.
typedef struct List {
    Node *head;
    int number_of_nodes;
} List;

// initializes a linked list
List* initialize_list();

// Creates a node and stores the data in it.
Node* create_node(int value);

// Inserts data at the beginning of the List
void insert_front(List* dll, int value);

// Deletes the node at position pos. No operation if pos is out of range.
void position_delete(List* dll, int pos);

// Return index of key in the list(0-based). Return -1 if not found
int search_list(List* dll, int key);

// Prints the entire list. Prints "EMPTY" if the list is empty.
void display(List* dll);

// Deallocates resources held by the list
void destroy_list(List* dll);

int main() {
    List* dll = initialize_list();
    int ele, choice, pos;
    
    do {
        scanf("%d", &choice);

        switch(choice) {
            // Insert at beginning
            case 1:
                scanf("%d", &ele);
                insert_front(dll, ele);
                break;

            // Delete at position
            case 2:
                scanf("%d", &pos);
                position_delete(dll, pos);
                break;

            // Search for element
            case 3:
                scanf("%d", &ele);
                pos = search_list(dll, ele);
                printf("%d\n", pos);
                break;

            // Print entire list
            case 4:
                display(dll);
                break;        
        }
    }
    while (choice != 0);

    destroy_list(dll);
    return 0;
}

List* initialize_list()
{
    List *list;
    list=(List *)malloc(sizeof(List));
    list->head=NULL;
    list->number_of_nodes=0;
    return list;
}

Node* create_node(int value)
{
    Node *new_node;
    new_node=(Node *)malloc(sizeof(Node));
    new_node->data=value;
    new_node->prev=NULL;
    new_node->next=NULL;
    return new_node;
}

void insert_front(List* dll, int value)
{
    Node *new_node;
    new_node=create_node(value);
    if(dll->head=NULL)
    {
        dll->head=new_node;
        dll->number_of_nodes+=1;
    }
    else
    {   
        Node *ptr=dll->head;
        dll->head=new_node;
        new_node->next=ptr;
        ptr->prev=new_node;
        dll->number_of_nodes+=1;
    }
}

void position_delete(List* dll, int pos)
{
    if(dll->head==NULL || pos<0 || pos>=dll->number_of_nodes)
    {
        return;
    }
    else if(pos==0)
    {
        if(dll->number_of_nodes==1)
        {
            Node *ptr=dll->head;
            dll->head=NULL;
            free(ptr);
        }
        else
        {
            Node *ptr=dll->head;
            Node *ptr2=ptr->next;
            ptr2->prev=NULL;
            dll->head=ptr2;
            free(ptr);
        }
        dll->number_of_nodes-=1;
    }
    else
    {
        Node *ptr=dll->head, *ptr2;
        int c=0;
        while(c<pos)
        {
            ptr2=ptr;
            ptr=ptr->next;
            c++;
        }
        Node *ptr3=ptr->next;
        ptr2->next=ptr3;
        if(ptr3!=NULL)
        {
            ptr3->prev=ptr2;
        }
        free(ptr);
        dll->number_of_nodes-=1;
    }
}

int search_list(List* dll, int key)
{
    if(dll->number_of_nodes==0)
        return -1;
    else
    {
        Node *temp=dll->head;
        int i=0;
        while(temp!=NULL)
        {
            if(key==(temp->data))
            {
                return i;
            }
            i++;
            temp=temp->next;
        }
        return -1;
    }
}

void display(List* dll)
{
    Node *temp;
    temp=dll->head;
    if(temp==NULL)
    {
        printf("EMPTY\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void destroy_list(List* dll)
{
    Node *temp=dll->head;
    while(temp!=NULL)
    {
        Node *p=temp;
        temp=temp->next;
        free(p);
    }
    dll->head=NULL;
    free(dll);
}
