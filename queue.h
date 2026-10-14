// queue.h - Queue visualizer
// A queue is FIFO (First In, First Out): add at the REAR, remove from the FRONT.
#ifndef QUEUE_H
#define QUEUE_H

#include "utils.h"

class Queue {
    vector<int> data;
    int capacity;

public:
    explicit Queue(int cap = 6) : capacity(cap) {}

    void enqueue(int value) {
        if ((int)data.size() == capacity) {
            cout << "Queue Overflow! The queue is full.\n";
            return;
        }
        data.push_back(value);
        cout << "Enqueued " << value << " at the rear.\n";
    }

    void dequeue() {
        if (data.empty()) {
            cout << "Queue Underflow! The queue is empty.\n";
            return;
        }
        cout << "Dequeued " << data.front() << " from the front.\n";
        data.erase(data.begin());  // every other element shifts one place to the left
    }

    void peek() const {
        if (data.empty()) cout << "The queue is empty.\n";
        else cout << "Front element is " << data.front() << ".\n";
    }

    // Draws the queue horizontally: FRONT on the left, REAR on the right.
    void display() const {
        cout << "\n   FRONT -> ";
        if (data.empty()) {
            cout << "(empty)";
        } else {
            for (int v : data) cout << "[" << setw(3) << v << " ]";
        }
        cout << " <- REAR\n\n";
    }
};

inline void queueMenu(Queue& q) {
    int choice;
    do {
        cout << "\n--- QUEUE (FIFO) ---\n"
             << "1. Enqueue\n2. Dequeue\n3. Peek front\n4. Display\n0. Back\n";
        choice = readInt("Choose: ");
        switch (choice) {
            case 1: q.enqueue(readInt("Enter value to enqueue: ")); q.display(); break;
            case 2: q.dequeue(); q.display(); break;
            case 3: q.peek(); break;
            case 4: q.display(); break;
            case 0: break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
}

#endif
