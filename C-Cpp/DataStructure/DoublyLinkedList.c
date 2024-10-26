#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} Node;

typedef struct list {
    Node *head;
    int size;
} List;

// Initialize the list
void init(List *list) {
    list->head = NULL;
    list->size = 0;
}

// Add node at the end of the list
void addNext(List *list, int x)
{
    Node *n = malloc(sizeof(Node));                                 // Node to be added
    n->data = x;
    n->next = NULL;

    if (list->head == NULL)
    { 
        n->prev = NULL;                                             // If the list is empty, the new node is the head
        list->head = n;
    } 
    else 
    {
        Node *temp = list->head;
        while (temp->next != NULL) 
        {
            temp = temp->next;                                      // Traverse to the last node
        }
        temp->next = n;
        n->prev = temp;
    }

    list->size++;
    printf("Node added successfully at the end.\n");
}

// Add node at the start of the list
void addPrev(List *list, int x)
{
    Node *n = malloc(sizeof(Node));
    n->data = x;
    n->prev = NULL;
    n->next = list->head;

    if (list->head != NULL)
    { 
        list->head->prev = n;                                       // If the list is not empty, update the previous head
    }

    list->head = n;
    list->size++;
    printf("Node added successfully at the start.\n");
}

// Delete node at a specific position
void deleteNodeAtPosition(List *list, int pos)
{
    if (pos < 1 || pos > list->size) {
        printf("Invalid position!\n");
        return;
    }

    Node *temp = list->head;

    if (pos == 1) {                                                 // Deleting the head node
        list->head = temp->next;                                    // Update head
        if (list->head != NULL) {
            list->head->prev = NULL;
        }
        free(temp);
    } else {
        for (int i = 1; i < pos; i++) {                             // Traverse to the node to be deleted
            temp = temp->next;
        }

        temp->prev->next = temp->next;                              // Adjust pointers
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        free(temp);
    }

    list->size--;
    printf("Node at position %d deleted successfully.\n", pos);
}

// Print the list contents
void printList(List *list)
{
    Node *temp = list->head;
    printf("List: ");
    
    while (temp != NULL) 
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    List myList;
    char ch;
    bool loops = true;
    
    init(&myList);

    printf("This is a Code for DOUBLY LINKED LIST\n");

    while(loops)
    {
        printf("\n1) ADD NODE AT END\n2) ADD NODE BEFORE START\n3) DELETE NODE AT POSITION\n4) PRINT LIST\n5) EXIT\n");
        printf("What Would You Like to do in LINKED LIST: ");
        scanf(" %c", &ch);  // Added space before %c to handle newline characters
        
        if(ch == '1')
        {
            int d;
            printf("Enter the Data: ");
            scanf("%d", &d);
            addNext(&myList, d);
        }
        else if(ch == '2')
        {
            int d;
            printf("Enter the Data: ");
            scanf("%d", &d);
            addPrev(&myList, d);
        }
        else if(ch == '3')
        {
            int pos;
            printf("Enter the Position to Delete: ");
            scanf("%d", &pos);
            deleteNodeAtPosition(&myList, pos);
        }
        else if(ch == '4')
        {
            printList(&myList);
        }
        else if(ch == '5')
        {
            printf("Exiting the code!\n");
            loops = false;
        }
        else
        {
            printf("WRONG INPUT! Try Again.\n");
        }
    }

    return 0;
}
