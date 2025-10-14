#include <bits/stdc++.h>
using namespace std;

struct item
{
    int weight;
    int profit;
    float p_w;
};

bool comp(item i1, const item i2)
{
    return i1.p_w > i2.p_w;
}

float fractional_knapsack(item item_list[], int len, int capacity)
{
    //step 1: find the profit/weight ratio of each item
    for (int i = 0; i < len; i++) {
        item_list[i].p_w = (float)item_list[i].profit / item_list[i].weight;
    }
    //step 2: sort in the descending order of profit/weight
    sort(item_list, item_list + len, comp);
    //step 3
    int current_capacity = capacity;
    float total_profit = 0;
    for (int i = 0; i < len; i++) {
        if (item_list[i].weight <= current_capacity) {
            total_profit = total_profit + item_list[i].profit;
            current_capacity = current_capacity - item_list[i].weight;
        }
        else {
            total_profit = total_profit + (current_capacity * item_list[i].p_w);
            current_capacity = 0;
        }
    }
    return total_profit;
}

int main()
{
    item item_list[] = {
        {3, 10, 0.0},
        {3, 15, 0.0},
        {2, 10, 0.0},
        {5, 12, 0.0},
        {1, 8, 0.0}
    };
    int len = sizeof(item_list)/sizeof(item_list[0]);
    cout << len << endl;
    int capacity = 10;
    float maximum_profit = fractional_knapsack(item_list, len, capacity);
    cout << maximum_profit << endl;
    return 0;
}
