// Data Structure Visualizer
// A command-line tool that shows how common data structures and sorting algorithms work.
//
// Build:  g++ -std=c++17 main.cpp -o visualizer
// Run:    visualizer        (Windows)    or    ./visualizer   (Linux / macOS)

#include "utils.h"
#include "stack.h"
#include "queue.h"
#include "linked_list.h"
#include "sorting.h"

int main() {
    Stack stack;
    Queue queue;
    LinkedList list;
    int choice;

    cout << "==============================\n"
         << "  DATA STRUCTURE VISUALIZER\n"
         << "==============================\n";

    do {
        cout << "\nMAIN MENU\n"
             << "1. Stack\n2. Queue\n3. Linked List\n4. Sorting algorithms\n0. Exit\n";
        choice = readInt("Choose: ");
        switch (choice) {
            case 1: stackMenu(stack); break;
            case 2: queueMenu(queue); break;
            case 3: linkedListMenu(list); break;
            case 4: sortingMenu(); break;
            case 0: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
