#include <iostream>
using namespace std;

int max(int a, int b) {
   return (a > b)? a : b;
}

int rodCutting(int price[], int n) {
   int profit[n+1];
   profit[0] = 0;
   int maxProfit;

   for (int i = 1; i<=n; i++) {
      maxProfit = INT_MIN;
      for (int j = 0; j < i; j++)
         maxProfit = max(maxProfit, price[j] + profit[i-j-1]);
      profit[i] = maxProfit;
   }
   return maxProfit;
}

int main() {
   int priceList[] = {2,5,7,8,10,13,17,20,24,30};
   int rodLength = 10;
   cout << "Maximum Price: "<< rodCutting(priceList, rodLength);
}
