#include <iostream>
#include <vector>
using namespace std;
// func signature
int simpleArraySum(vector<int> ar);

// Driver program
int main() {
    
    int n;
    cin >> n;
    vector<int> ar;
    
    int i = 0;
    while(i < n) {
        int temp;
        cin >> temp;
        ar.push_back(temp);
        i++;
    }
    cout << simpleArraySum(ar) << endl;
    return 0;
}

// func implementation
int simpleArraySum(vector<int> ar) {
    int sum = 0;
    for(int i = 0; i < ar.size(); i++) {
        sum += ar[i];
    }
    return sum;
}
