#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key, i, found = -1;

    cout << "Enter the element to search: ";
    cin >> key;

    // Performing Linear Search
    for (i = 0; i < size; i++) {
        if (arr[i] == key) {
            cout << "Element found at index " << i << endl;
            found = 1;  // Mark as found
            break;      // Exit loop after finding the element
        }
    }

    if (found==-1) {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}

