#include <bits/stdc++.h>
using namespace std;

int main() {
    int n1, n2;
    cout << "Number of processes: ";
    cin >> n1;

    vector<int> process(n1);
    cout << "Enter process sizes: ";
    for (int i = 0; i < n1; i++)
        cin >> process[i];

    cout << "Number of blocks: ";
    cin >> n2;

    vector<int> block(n2);
    cout << "Enter block sizes: ";
    for (int i = 0; i < n2; i++)
        cin >> block[i];

    vector<int> allocation(n1, -1);
    vector<int> internalFrag(n2, 0);

    // ----- First Fit -----
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (block[j] >= process[i]) {
                allocation[i] = j;
                internalFrag[j] = block[j] - process[i];
                block[j] = -1;
                break;
            }
        }
    }
    for (int i = 0; i < n1; i++) {
        if (allocation[i] == -1) {
            cout << "Process " << i + 1 << " not allocated\n";
        }
    }

    return 0;
}
