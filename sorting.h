// sorting.h - Step-by-step sorting animations
// Elements shown inside [ ] are the two being compared or swapped at that moment.
#ifndef SORTING_H
#define SORTING_H

#include "utils.h"
#include <thread>
#include <chrono>

static const int DELAY_MS = 500;  // pause between steps (in milliseconds)

inline void pauseStep() {
    this_thread::sleep_for(chrono::milliseconds(DELAY_MS));
}

// Prints the array. The elements at index a and index b are wrapped in [ ].
inline void printArray(const vector<int>& arr, int a = -1, int b = -1) {
    cout << "   ";
    for (int i = 0; i < (int)arr.size(); ++i) {
        if (i == a || i == b) cout << "[" << setw(3) << arr[i] << "]";
        else cout << " " << setw(3) << arr[i] << " ";
    }
    cout << "\n";
}

// Bubble sort: repeatedly compare neighbours and swap them if they are in the wrong order.
// After each pass the largest remaining element "bubbles up" to its final place.
inline void bubbleSort(vector<int> arr) {
    int n = (int)arr.size();
    int comparisons = 0, swaps = 0;
    cout << "\nBUBBLE SORT\nStart:\n";
    printArray(arr);

    for (int pass = 0; pass < n - 1; ++pass) {
        bool swapped = false;
        cout << "\nPass " << pass + 1 << ":\n";
        for (int j = 0; j < n - pass - 1; ++j) {
            ++comparisons;
            printArray(arr, j, j + 1);
            cout << "   Compare " << arr[j] << " and " << arr[j + 1];
            if (arr[j] > arr[j + 1]) {
                cout << " -> wrong order, swap\n";
                swap(arr[j], arr[j + 1]);
                ++swaps;
                swapped = true;
                printArray(arr, j, j + 1);
            } else {
                cout << " -> already in order\n";
            }
            pauseStep();
        }
        if (!swapped) {
            cout << "No swaps in this pass, so the array is already sorted.\n";
            break;
        }
    }
    cout << "\nSorted!\n";
    printArray(arr);
    cout << "Comparisons: " << comparisons << ", Swaps: " << swaps << "\n";
}

// Selection sort: find the smallest element in the unsorted part and put it in front.
inline void selectionSort(vector<int> arr) {
    int n = (int)arr.size();
    int comparisons = 0, swaps = 0;
    cout << "\nSELECTION SORT\nStart:\n";
    printArray(arr);

    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        cout << "\nRound " << i + 1 << ": find the smallest element from position " << i + 1 << " onwards.\n";
        for (int j = i + 1; j < n; ++j) {
            ++comparisons;
            printArray(arr, minIndex, j);
            cout << "   Is " << arr[j] << " smaller than current minimum " << arr[minIndex] << "?";
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
                cout << " Yes, new minimum.\n";
            } else {
                cout << " No.\n";
            }
            pauseStep();
        }
        if (minIndex != i) {
            cout << "   Swap " << arr[i] << " with " << arr[minIndex] << "\n";
            swap(arr[i], arr[minIndex]);
            ++swaps;
            printArray(arr, i, minIndex);
        } else {
            cout << "   " << arr[i] << " is already in the right place.\n";
        }
        pauseStep();
    }
    cout << "\nSorted!\n";
    printArray(arr);
    cout << "Comparisons: " << comparisons << ", Swaps: " << swaps << "\n";
}

// Insertion sort: take each element and slide it left into its correct place,
// like sorting playing cards in your hand.
inline void insertionSort(vector<int> arr) {
    int n = (int)arr.size();
    int comparisons = 0, swaps = 0;
    cout << "\nINSERTION SORT\nStart:\n";
    printArray(arr);

    for (int i = 1; i < n; ++i) {
        cout << "\nTake " << arr[i] << " and insert it into the sorted part on its left.\n";
        for (int j = i; j > 0; --j) {
            ++comparisons;
            printArray(arr, j - 1, j);
            cout << "   Compare " << arr[j - 1] << " and " << arr[j];
            if (arr[j - 1] > arr[j]) {
                cout << " -> swap\n";
                swap(arr[j - 1], arr[j]);
                ++swaps;
                printArray(arr, j - 1, j);
                pauseStep();
            } else {
                cout << " -> in place, stop\n";
                pauseStep();
                break;
            }
        }
    }
    cout << "\nSorted!\n";
    printArray(arr);
    cout << "Comparisons: " << comparisons << ", Swaps: " << swaps << "\n";
}

inline void sortingMenu() {
    vector<int> data = {64, 25, 12, 22, 11};  // default array to start with
    int choice;
    do {
        cout << "\n--- SORTING ---\nCurrent array:\n";
        printArray(data);
        cout << "1. Enter my own array\n2. Bubble sort\n3. Selection sort\n4. Insertion sort\n0. Back\n";
        choice = readInt("Choose: ");
        switch (choice) {
            case 1: {
                int n = readInt("How many numbers (2 to 10)? ");
                if (n < 2 || n > 10) {
                    cout << "Please choose a size between 2 and 10.\n";
                    break;
                }
                data.clear();
                for (int i = 0; i < n; ++i)
                    data.push_back(readInt("Enter number " + to_string(i + 1) + ": "));
                break;
            }
            case 2: bubbleSort(data); break;
            case 3: selectionSort(data); break;
            case 4: insertionSort(data); break;
            case 0: break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
}

#endif
