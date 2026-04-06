#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

struct list_node
{
    int value;
    struct list_node *next;
};
typedef struct list_node Node;

Node *return_new_node()
{
    return (Node *)malloc(sizeof(Node));
}

bool insert_at_beginning(Node **head, int value);
bool insert_at_end(Node **head, int value);
bool insert_at(Node **head, int value, int position);
bool delete_at_beginning(Node **head);
void print_list(Node *head);

int main()
{
    Node *list1 = NULL;
    for (int i = 0; i < 10; i++)
    {
        insert_at_end(&list1, i + 1);
        print_list(list1);
    }

    // char option[10] = "y";

    // while (strcmp(option, "y") == 0)
    // {
    //     int value = 0;
    //     int position = 0;
    //     printf("\nNew Value to insert:");
    //     scanf("%d", &value);
    //     printf("Enter position:");
    //     scanf("%d", &position);

    //     bool result = insert_at(&list1, value, position);
    //     if (result == true)
    //     {
    //         printf("Value inserted: ");
    //         print_list(list1);
    //     }
    //     else
    //     {
    //         printf("Could not insert value.");
    //     }

    //     printf("\n\nwould you like to continue (y/n)");
    //     scanf("%s", &option);
    // }

    for (int i = 0; i < 9; i++)
    {
        delete_at_beginning(&list1);
        print_list(list1);
    }

    return 0;
}

bool insert_at_beginning(Node **head, int value)
{
    if (head == NULL)
    {
        return false;
    }

    if ((*head) == NULL)
    {
        (*head) = return_new_node();
        (*head)->value = value;
        (*head)->next = NULL;
        return true;
    }

    Node *new_node = return_new_node();
    new_node->value = value;
    new_node->next = *head;
    *head = new_node;

    return true;
}

bool insert_at_end(Node **head, int value)
{
    if (head == NULL)
    {
        return false;
    }

    if (*head == NULL)
    {
        (*head) = return_new_node();
        (*head)->value = value;
        (*head)->next = NULL;
        return true;
    }

    Node *ptr = *head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    Node *new_node = return_new_node();
    new_node->value = value;
    new_node->next = NULL;
    ptr->next = new_node;

    return true;
}

void print_list(Node *head)
{
    if (head == NULL)
    {
        return;
    }

    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d, ", ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}

bool insert_at(Node **head, int value, int position)
{
    if (head == NULL)
    {
        return false;
    }

    if (position == 0)
    {
        return false;
    }

    if (*head == NULL)
    {
        (*head) = return_new_node();
        (*head)->value = value;
        (*head)->next = NULL;

        return true;
    }

    if (position == 1)
    {
        Node *new_node = return_new_node();
        new_node->value = value;
        new_node->next = *head;
        (*head) = new_node;
        return true;
    }

    // traverser to end or till just before required position
    Node *ptr = *head;
    int index = 2;
    position--;

    while (ptr->next != NULL && index <= position)
    {
        ptr = ptr->next;
        index++;
    }

    Node *new_node = return_new_node();
    new_node->value = value;
    new_node->next = ptr->next;
    ptr->next = new_node;

    return true;
}

bool delete_at_beginning(Node **head)
{
    if (head == NULL)
    {
        return false;
    }

    if (*head == NULL)
    {
        return false;
    }

    Node *node_to_delete = *head;
    (*head) = (*head)->next;

    free(node_to_delete);

    return true;
}

bool delete_at_end(Node **head)
{
    if (head == NULL)
    {
        return false;
    }
    if (*head == NULL)
    {
        return false;
    }

    if ((*head)->next = NULL)
    {
        free(*head);
        *head = NULL;
        return true;
    }

    Node *ptr = *head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
}
