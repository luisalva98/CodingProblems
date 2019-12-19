#include <iostream>
#include <vector>
using namespace std;

// func signature
int hourglassSum(vector<vector<int>> arr);

// Driver program
int main() {
   vector<vector<int>> arr(6);
   for(int row = 0; row < 6; row++) {
       for(int col = 0; col < 6; col++) {
           int temp;
           cin >> temp;
           arr[row].push_back(temp);
       }
   }
   cout << hourglassSum(arr) << endl;
   return 0;
}

// func implementation
int hourglassSum(vector<vector<int>> arr) {
    int maxHourglassSum = INT_MIN;
    for(int i = 0; i < 4; i++) {
        int j = 0;
        while(j < 4) {
            int a, b, c, d, e, f, g;
            a = arr[i][j];
            b = arr[i][j+1];
            c = arr[i][j+2];
            d = arr[i+1][j+1];
            e = arr[i+2][j];
            f = arr[i+2][j+1];
            g = arr[i+2][j+2];
            int sum = a + b + c + d + e + f + g;
            if(maxHourglassSum < sum) { maxHourglassSum = sum; }
            j++;
        }
    }
    return maxHourglassSum;
}
