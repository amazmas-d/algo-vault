#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &A, int low, int high) {
    int pivot = A[low];
    int i = low;
    int j = high+1;

     while (i < j){
        do {
            i++;
        } while (i <= high && A[i] <= pivot);
        do {
            j--;
        } while (A[j] > pivot);

        if (i < j)
            swap(A[i], A[j]);

    }
    swap(A[low], A[j]);
    return j;
}
void quickSort(vector<int> &A, int low, int high) {
    if (low < high) {
        int mid = partition(A, low, high);
        quickSort(A, low, mid - 1);
        quickSort(A, mid + 1, high);
    }
}
int main()
{
    int n;
    cout<<"Total numbers in the array is: ";
    cin>>n;
    vector<int> A(n);
    cout<<"\nThe values of the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    quickSort(A,0,n-1);
    cout<<"\nSorted Array: ";
    for(int x:A)
    {
        cout<<x<<" ";
    }
}
