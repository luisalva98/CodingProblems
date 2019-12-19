#include <iostream>
#include <vector>
using namespace std;

// func signature
long aVeryBigSum(vector<long> ar);

// Driver program
int main() {
    int n;
    cin >> n;
    vector<long> input;
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        input.push_back(val);
    }
    cout << aVeryBigSum(input) <<  endl;
    return 0;
}

// func implementation
long aVeryBigSum(vector<long> ar) {
    long sum = 0;
    for(int i = 0; i  < ar.size(); i++) {
        sum +=  ar[i];
    }
    return sum;
}           