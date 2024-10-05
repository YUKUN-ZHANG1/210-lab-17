// COMSC-210 | Lab 17: Modularize the Linked List Code | Yukun Zhang
// IDE used: Visual Studio Code

#include <iostream>
using namespace std;

const int SIZE = 7;  // Defines the default size of the linked list

// Struct for linked list nodes
struct Node {
    float value;
    Node *next;
};

// Function prototypes
void output(Node * hd);  // Prints all nodes in the linked list
void create_linked_list(Node*& head, int size = SIZE);  // Creates a linked list of size `size`
void delete_a_node(Node*& head);  // Deletes a node selected by the user
void insert_a_node(Node*& head);  // Inserts a new node into the list
void delete_linked_list(Node*& head);  // Deletes the entire linked list

// Function to print all nodes in the linked list
void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";  // If the list is empty, print a message
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        // Print each node's value
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;  // Move to the next node
    }
    cout << endl;
}

// Function to create a linked list with random numbers between 0-99
void create_linked_list(Node*& head, int size){
    for (int i = 0; i < size; i++) {
        int tmp_val = rand() % 100;  // Generate a random number between 0 and 99
        Node *newVal = new Node;  // Create a new node
        
        // Add the new node at the head of the list
        if (!head) {  // If the list is empty, the new node becomes the head
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else {  // Otherwise, place the new node before the current head
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }
}

// Function to delete a node selected by the user
void delete_a_node(Node*& head){
    if (!head) {
        cout << "List is empty. Cannot delete node." << endl;  // If the list is empty, no deletion is possible
        return;
    }

    Node * current = head;
    cout << "Which node to delete? " << endl;
    output(head);  // Show the current list
    int entry;
    cout << "Choice --> ";
    cin >> entry;  // Get the user's choice for which node to delete

    if (entry < 1) {  // Validate the input
        cout << "Invalid entry." << endl;
        return;
    }

    current = head;
    Node *prev = head;

    // Case for deleting the first node
    if (entry == 1) {
        head = head->next;  // Update the head to the next node
        delete current;     // Free the memory of the original head
        return;
    }

    // Traverse to the node before the one to be deleted
    for (int i = 1; i < entry - 1 && current != nullptr; i++) {
        current = current->next;
        prev = prev->next;
    }

    // If the node to delete doesn't exist
    if (!current || !current->next) {
        cout << "Invalid node number. Node does not exist." << endl;
        return;
    }

    Node *toDelete = current->next;  // Node to be deleted
    current->next = toDelete->next;  // Bypass the node being deleted
    delete toDelete;  // Free the memory of the node being deleted
}

// Function to insert a new node with the value 10000
void insert_a_node(Node*& head){
    Node* current = head;
    if (!head) {
        // If the list is empty, insert the new node at the head
        cout << "List is empty, inserting at head." << endl;
        Node* newnode = new Node;
        newnode->value = 10000;
        newnode->next = nullptr;
        head = newnode;
        return;
    }

    cout << "After which node to insert 10000? " << endl;
    int count = 1, entry;
    output(head);  // Show the current list
    cout << "Choice --> ";
    cin >> entry;  // Get the user's choice for where to insert the new node

    if (entry < 1) {  // Validate the input
        cout << "Invalid entry." << endl;
        return;
    }

    current = head;
    Node *prev = nullptr;

    // Traverse to the node after which the new node will be inserted
    for (int i = 1; i < entry && current != nullptr; i++) {
        prev = current;
        current = current->next;
    }

    // If the node to insert after doesn't exist
    if (!current) {
        cout << "Invalid node number. Node does not exist." << endl;
        return;
    }

    // Create the new node
    Node *newnode = new Node;
    newnode->value = 10000;

    if (entry == 1) {
        // Insert at head
        newnode->next = head;
        head = newnode;
    } else {
        // Insert between prev and current
        newnode->next = current->next;
        current->next = newnode;
    }
}

// Function to delete the entire linked list
void delete_linked_list(Node*& head){
    Node* current = head;
    while (current) {
        head = current->next;  // Move the head to the next node
        delete current;  // Delete the current node
        current = head;  // Move to the next node
    }
    head = nullptr;  // Set head to nullptr after the list is deleted
}

int main() {
    Node *head = nullptr;
    create_linked_list(head);
    output(head);
    delete_a_node(head);
    output(head);
    insert_a_node(head);
    output(head);
    delete_linked_list(head);
    output(head);
    return 0;
}
