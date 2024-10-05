// COMSC-210 | Lab 17: Modularize the Linked List Code | Yukun Zhang
// IDE used: Visual Studio Code

#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

// Function prototypes
void output(Node * hd);
void create_linked_list(Node*& head, int size = SIZE);
void delete_a_node(Node*& head);
void insert_a_node(Node*& head);
void delete_linked_list(Node*& head);

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

// create a linked list of size SIZE with random numbers 0-99
void create_linked_list(Node*& head, int size){
    for (int i = 0; i < size; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        
        // adds node at head
        if (!head) { // if this is the first node, it's the new head
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else { // its a second or subsequent node; place at the head
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }
}

void delete_a_node(Node*& head){
    if (!head) {
        cout << "List is empty. Cannot delete node." << endl;
        return;
    }

    Node * current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    if (entry < 1) {
        cout << "Invalid entry." << endl;
        return;
    }

    current = head;
    Node *prev = head;

    // Case for deleting the first node
    if (entry == 1) {
        head = head->next;
        delete current;
        return;
    }

    // Traverse to the node to be deleted
    for (int i = 1; i < entry - 1 && current != nullptr; i++) {
        current = current->next;
        prev = prev->next;
    }

    if (!current || !current->next) {
        cout << "Invalid node number. Node does not exist." << endl;
        return;
    }

    Node *toDelete = current->next;
    current->next = toDelete->next;
    delete toDelete;
}

void insert_a_node(Node*& head){
    Node* current = head;
    if (!head) {
        cout << "List is empty, inserting at head." << endl;
        Node* newnode = new Node;
        newnode->value = 10000;
        newnode->next = nullptr;
        head = newnode;
        return;
    }

    cout << "After which node to insert 10000? " << endl;
    int count = 1, entry;
    output(head);
    cout << "Choice --> ";
    cin >> entry;

    if (entry < 1) {
        cout << "Invalid entry." << endl;
        return;
    }

    current = head;
    Node *prev = nullptr;

    for (int i = 1; i < entry && current != nullptr; i++) {
        prev = current;
        current = current->next;
    }

    if (!current) {
        cout << "Invalid node number. Node does not exist." << endl;
        return;
    }

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

void delete_linked_list(Node*& head){
    Node* current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
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
