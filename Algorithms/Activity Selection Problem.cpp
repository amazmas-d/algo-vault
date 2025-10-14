#include <bits/stdc++.h>
using namespace std;

struct activity
{
    int start;
    int finish;
};

bool comp(activity a1, activity a2)
{
    return a1.finish < a2.finish;
}

int maximumActivity(activity arr[], int len)
{
    sort(arr, arr+len, comp);
    int total_activity = 1;
    int selected_activity_index = 0;
    for (int j = 1; j < len; j++) {
        if (arr[j].start >= arr[selected_activity_index].finish) {
            total_activity++;
            selected_activity_index = j;
        }
    }
    return total_activity;
}

int main()
{
    activity arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    int len = sizeof(arr)/ sizeof(arr[0]);
    int total_activity = maximumActivity(arr, len);
    cout << total_activity << endl;
    return 0;
}
