// Lomuto Partition Scheme Method for Quick Sort with Random Pivot

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int l, int r)
{
    // Choose a random pivot index between l and r
    int pivotIndex = l + rand() % (r - l + 1);
    swap(arr[pivotIndex], arr[r]); // move chosen pivot to the end

    int pivot = arr[r];   // pivot is now the last element
    int i = l - 1;        // place for swapping smaller elements

    for (int j = l; j < r; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]); // place pivot in correct position
    return i + 1;
}

void quickSort(vector<int>& arr, int l, int r)
{
    if (l < r)
    {
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi - 1);  // left partition
        quickSort(arr, pi + 1, r);  // right partition
    }
}

int main()
{
    srand(time(0)); // seed random number generator

    int n;
    cout << "Give me the number of array elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "\nGive me the values of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\nUnsorted array: ";
    for (int x : arr) cout << x << " ";

    quickSort(arr, 0, n - 1);

    cout << "\nSorted array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
