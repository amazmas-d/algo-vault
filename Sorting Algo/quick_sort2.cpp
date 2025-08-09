#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& A, int l, int h) {
    int pivot = A[l];
    int i = l, j = h;

    cout << "\nPartitioning with pivot " << pivot << ": ";
    for (int x : A) cout << x << " ";
    cout << endl;

    while (i < j) {
        while ( A[i] <= pivot) i++;
        while (A[j] > pivot) j--;

        if (i < j) {
            swap(A[i], A[j]);
            cout << "Swapped " << A[i] << " and " << A[j] << ": ";
            for (int x : A) cout << x << " ";
            cout << endl;
        }
    }

    swap(A[l], A[j]);
    cout << "Placed pivot " << pivot << " at index " << j << ": ";
    for (int x : A) cout << x << " ";
    cout << endl;

    return j;
}

void quickSort(vector<int>& A, int l, int h) {
    if (l < h) {
        int loc = partition(A, l, h);
        quickSort(A, l, loc - 1);
        quickSort(A, loc + 1, h);
    }
}

int main() {
    vector<int> A = {9, 4, 3, 11, 15, 20, 2, 24, 30, 1, 35};
    int n = A.size();

    cout << "Initial array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    quickSort(A, 0, n - 1);

    cout << "\nAfter sorting, final array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
