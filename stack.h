// stack.h - Stack visualizer
// A stack is LIFO (Last In, First Out): only the TOP element can be added or removed.
#ifndef STACK_H
#define STACK_H

#include "utils.h"

class Stack {
    vector<int> data;
    int capacity;

public:
    explicit Stack(int cap = 6) : capacity(cap) {}

    void push(int value) {
        if ((int)data.size() == capacity) {
            cout << "Stack Overflow! The stack is full.\n";
            return;
        }
        data.push_back(value);
        cout << "Pushed " << value << " onto the stack.\n";
    }

    void pop() {
        if (data.empty()) {
            cout << "Stack Underflow! The stack is empty.\n";
            return;
        }
        cout << "Popped " << data.back() << " from the top.\n";
        data.pop_back();
    }

    void peek() const {
        if (data.empty()) cout << "The stack is empty.\n";
        else cout << "Top element is " << data.back() << ".\n";
    }

    // Draws the stack vertically with the top element at the top of the picture.
    void display() const {
        cout << "\n";
        for (int i = capacity - 1; i >= 0; --i) {
            if (i < (int)data.size()) {
                cout << "   | " << setw(4) << data[i] << " |";
                if (i == (int)data.size() - 1) cout << "  <- TOP";
                cout << "\n";
            } else {
                cout << "   |      |\n";
            }
        }
        cout << "   +------+\n\n";
    }
};

inline void stackMenu(Stack& s) {
    int choice;
    do {
        cout << "\n--- STACK (LIFO) ---\n"
             << "1. Push\n2. Pop\n3. Peek\n4. Display\n0. Back\n";
        choice = readInt("Choose: ");
        switch (choice) {
            case 1: s.push(readInt("Enter value to push: ")); s.display(); break;
            case 2: s.pop(); s.display(); break;
            case 3: s.peek(); break;
            case 4: s.display(); break;
            case 0: break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
}

#endif
