#include <iostream>
#include <vector>
using namespace std;

// func signatures
void printVector(vector<int> arr);
vector<int> leftRotate(int d, vector<int> arr);

// Driver program
int main() {
    int n, d;
    cin >> n >> d;
    vector<int> a;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    printVector(leftRotate(d, a));
    return 0;
}

// UTILITY func to print a vector
void printVector(vector<int> arr) {
    for(int i = 0; i < arr.size(); i++) {
        if(i != arr.size()-1) {
            cout << arr[i] << " ";
        } else {
            cout << arr[i];
        }
    }
    cout << endl;
}

// func signature implementation
vector<int> leftRotate(int d, vector<int> arr) {
    int last = arr.size()-1; // store last valid index #
    while(d > 0) { // perform 1 rotation d times
        int first = arr[0]; // temp to store [0] index
        // loop that performs 1 rotation
        for(int current = 1; current < arr.size(); current++) {
            arr[current - 1] = arr[current];
        }
        arr[last] = first;
        d--;
    }
    return arr;
}
