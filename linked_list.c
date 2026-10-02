#include <stdio.h>
#include <stdlib.h>

// creating structure
typedef struct node
{
    int info;
    struct node *next;
} node;

// create node
node *create_node()
{
    int value;
    node *curr = (node *)malloc(sizeof(node));
    if (curr == NULL)
    {
        printf("memory not allocated!!!");
        return 0;
    }
    printf("enter value: ");
    scanf("%d", &value);
    curr->info = value;
    return curr;
}

// case::1 [insert at left or beginning]
node *left_insertion(node *head)
{
    node *curr;
    curr = create_node();
    curr->next = head;
    head = curr;
    return head;
}

// case::2 [insertion at right or ending]
node *right_insertion(node *head)
{
    node *curr;
    curr = create_node();
    if (head == NULL)
        return curr;
    node *temp;
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = curr;
    curr->next = NULL;
    return head;
}

// case::3 [insertion at between or at a position]
node *insertion_at_position(node *head)
{
    int pos;
    printf("enter a position you want to insert: ");
    scanf("%d", &pos);
    node *curr = create_node();
    if (head == NULL)
    {
        printf("there is no node so creating one\n");
        return curr;
    }
    node *temp;
    temp = head;
    int i = 1;
    if (pos == 1)
    {

        curr->next = head;
        head = curr;
    }
    else
    {
        for (i = 1; i < pos - 1 && temp->next != NULL; i++)
        {
            temp = temp->next;
        }
        curr->next = temp->next;
        temp->next = curr;
    }
    return head;
}

// case::4 [insertion after node]
node *insert_after_node(node *head)
{
    int n_value;
    printf("enter the node value after which u want to insert : ");
    scanf("%d", &n_value);

    node *temp = head;
    while (temp != NULL && temp->info != n_value)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("node not found\n");
        return head;
    }

    node *curr = create_node();
    if (head == NULL)
    {
        printf("List was empty, new node created.\n");
        return curr;
    }
    curr->next = temp->next;
    temp->next = curr;
    return head;
}

// deleting from left side
node *delete_from_left(node *head)
{
    if (head == NULL)
        printf("linked list does not exist\n");
    if(head->next==NULL)
    {
        free(head);
        return NULL;
    }
    else
    {
        node *temp;
        temp = head;
        head = head->next;
        temp->next = NULL;
        free(temp);
    }

    return head;
}

//deleting fom right
node* delete_from_right(node* head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    node* temp1=head;
    node* temp2=head;
    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
    }
    while(temp2->next!=temp1)
    {
        temp2=temp2->next;
    } 
    temp2->next=NULL; 
    free(temp1);
    return head; 
}

//deleting a node in between
node* delete_at_position(node* head)
{
    if(head == NULL)
    {
        printf("list is empty\n");
        return head;
    }
    int pos;
    printf("enter postion of node u want to delete : ");
    scanf("%d",&pos);
    
    int i=1;
    node* temp=head;
    if(pos==1)
    {
        head=head->next;
        free(temp);
        return head;
    }

    while(i<pos-1 && temp->next!=NULL)
    {
        temp=temp->next;
        i++;
    }
    temp->next=temp->next->next;
    temp->next->next=NULL;
    free(temp->next->next);
    return head;
}

// printing linked list
void display(node *head)
{
    node *temp = head;
    printf("-------LINKED LIST-------\n");
    while (temp != NULL)
    {
        printf("%d\n", temp->info);
        temp = temp->next;
    }
}

int main()
{
    node *head = NULL;
    head = left_insertion(head);
    head = left_insertion(head);
    head = left_insertion(head);
    head = left_insertion(head);
    /*
    head = right_insertion(head);
    head = insertion_at_position(head);
    head = insert_after_node(head);
    */
    display(head);
    head = delete_at_position(head);
    display(head);
    return 0;
}