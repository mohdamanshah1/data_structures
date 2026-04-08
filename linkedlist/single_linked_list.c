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
bool delete_at_end(Node **head);
bool delete_at(Node **head, int position);
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
        delete_at_end(&list1);
        print_list(list1);
    }

    return 0;
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

bool validate_before_insertion(Node **head, int position)
{
    if (head == NULL)
    {
        return false;
    }

    if (position < 1)
    {
        return false;
    }

    return true;
}

bool validate_before_deletion(Node **head, int position)
{
    if (head == NULL)
    {
        return false;
    }

    if (*head == NULL)
    {
        return false;
    }

    if (position < 1)
    {
        return false;
    }

    return true;
}

bool insert_at_beginning(Node **head, int value)
{
    bool is_valid = validate_before_insertion(head, 1);

    if (is_valid == false)
        return false;

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
    bool is_valid = validate_before_insertion(head, INT_MAX);

    if (is_valid == false)
        return false;

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

bool insert_at(Node **head, int value, int position)
{
    bool is_valid = validate_before_insertion(head, position);

    if (is_valid == false)
        return false;

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
    bool is_valid = validate_before_deletion(head, 1);

    if (is_valid == false)
        return false;

    Node *node_to_delete = *head;
    (*head) = (*head)->next;

    free(node_to_delete);

    return true;
}

bool delete_at_end(Node **head)
{
    bool is_valid = validate_before_deletion(head, INT_MAX);

    if (is_valid == false)
        return false;

    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return true;
    }

    Node *ptr = *head;
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
    return true;
}

bool delete_at(Node **head, int position)
{
    bool is_valid = validate_before_deletion(head, position);

    if (is_valid == false)
        return false;

    if (position == 1)
    {
        Node *temp = *head;
        (*head) = (*head)->next;
        temp->next = NULL;
        free(temp);
        return true;
    }

    int index;
    Node *prev_node = *head;

    for (index = 1; index < position - 1; index++)
    {
        prev_node = prev_node->next;
        if (prev_node == NULL)
        {
            break;
        }
    }

    if (prev_node == NULL)
        return false;

    if (prev_node->next == NULL)
        return false;

    Node *node_to_delete = prev_node->next;
    prev_node->next = node_to_delete->next;
    node_to_delete->next = NULL;
    free(node_to_delete);
    return true;
}
