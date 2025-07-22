#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[]={10,20,30,40,50,60,70,80,90};
    int n=sizeof (a)/sizeof (a[0]);
    cout<<"Main array: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    int l=0,r=n-1,mid;
    int target;
    cout<<"\nValue you want to search: ";
    cin>>target;
    bool found=false;
    while(l<=r)
    {
        mid=l+(r-l)/2;
        if(a[mid]==target)
        {
            found=true;
            break;
        }
        else if(a[mid]>target)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    if(found==false)
    {
        cout<<"Value isn't present";
    }
    else
    {
        cout<<"Value is present at "<<mid<<" index";
    }

}
