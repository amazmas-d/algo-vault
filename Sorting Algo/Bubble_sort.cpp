#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Array size: ";
    cin>>n;
    int swapCount = 0;
    vector<int> a(n);
    cout<<"\nEnter the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
            int temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
            swapCount++;
        }
    }
    }
    cout<<"\nAfter sorting the array: ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\nTotal number of swap: "<<swapCount;
}
