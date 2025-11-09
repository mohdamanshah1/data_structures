typedef struct node{
	int value;
	struct node* next;
}Node;

typedef struct singly_linked_list {
	Node *head;
}SinglyLinkedList;

typedef struct 

SinglyLinkedList * create_new_list();
void insert_at_beginning(SinglyLinkedList* list, int data);
void insert_at_end(SinglyLinkedList * list, int data);
void delete_at_beginning(SinglyLinkedList *list);
void delete_at_end(SinglyLinkedList *list);
void traverse(SinglyLinkedList *list);
void dispose(SinglyLinkedList *list);