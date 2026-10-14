// linked_list.h - Singly linked list visualizer
// Each node stores a value and a pointer to the next node. The last node points to NULL.
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "utils.h"

struct Node {
    int data;
    Node* next;
    explicit Node(int v) : data(v), next(nullptr) {}
};

class LinkedList {
    Node* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    // Destructor: frees every node so the program does not leak memory.
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Copying a list would make two lists delete the same nodes, so we forbid it.
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    void insertAtHead(int value) {
        Node* node = new Node(value);
        node->next = head;  // new node points to the old first node
        head = node;        // head now points to the new node
        ++size;
        cout << "Inserted " << value << " at the head.\n";
    }

    void insertAtTail(int value) {
        Node* node = new Node(value);
        if (head == nullptr) {
            head = node;
        } else {
            Node* current = head;
            while (current->next != nullptr) current = current->next;  // walk to the last node
            current->next = node;
        }
        ++size;
        cout << "Inserted " << value << " at the tail.\n";
    }

    void deleteValue(int value) {
        if (head == nullptr) {
            cout << "The list is empty. Nothing to delete.\n";
            return;
        }
        if (head->data == value) {  // special case: deleting the first node
            Node* temp = head;
            head = head->next;
            delete temp;
            --size;
            cout << "Deleted " << value << " (it was the head).\n";
            return;
        }
        Node* current = head;
        while (current->next != nullptr && current->next->data != value) current = current->next;
        if (current->next == nullptr) {
            cout << "Value " << value << " was not found in the list.\n";
            return;
        }
        Node* temp = current->next;
        current->next = temp->next;  // skip over the node we are removing
        delete temp;
        --size;
        cout << "Deleted " << value << ".\n";
    }

    void search(int value) const {
        int position = 1;
        for (Node* current = head; current != nullptr; current = current->next, ++position) {
            if (current->data == value) {
                cout << "Found " << value << " at position " << position << ".\n";
                return;
            }
        }
        cout << "Value " << value << " was not found in the list.\n";
    }

    // Reverses the list by flipping every 'next' pointer.
    void reverse() {
        Node* previous = nullptr;
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;  // remember the rest of the list
            current->next = previous;        // flip the pointer
            previous = current;
            current = nextNode;
        }
        head = previous;
        cout << "The list has been reversed.\n";
    }

    void display() const {
        if (head == nullptr) {
            cout << "\n   HEAD -> NULL  (the list is empty)\n\n";
            return;
        }
        cout << "\n   HEAD -> ";
        for (Node* current = head; current != nullptr; current = current->next)
            cout << "[" << current->data << "] -> ";
        cout << "NULL\n   Size: " << size << "\n\n";
    }
};

inline void linkedListMenu(LinkedList& list) {
    int choice;
    do {
        cout << "\n--- LINKED LIST ---\n"
             << "1. Insert at head\n2. Insert at tail\n3. Delete a value\n"
             << "4. Search a value\n5. Reverse the list\n6. Display\n0. Back\n";
        choice = readInt("Choose: ");
        switch (choice) {
            case 1: list.insertAtHead(readInt("Enter value: ")); list.display(); break;
            case 2: list.insertAtTail(readInt("Enter value: ")); list.display(); break;
            case 3: list.deleteValue(readInt("Enter value to delete: ")); list.display(); break;
            case 4: list.search(readInt("Enter value to search: ")); break;
            case 5: list.reverse(); list.display(); break;
            case 6: list.display(); break;
            case 0: break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
}

#endif
