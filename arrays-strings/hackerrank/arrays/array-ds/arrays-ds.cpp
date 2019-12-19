#include <iostream>
#include <vector>
using namespace std;

// Func signatures
vector<int> reverseArray(vector<int> a);
void printVector(vector<int>a);

// Driver program
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i <  n; i++) {
        cin >> a[i];
    }
    
    printVector(reverseArray(a));
    return 0;
}

// func implementation
vector<int> reverseArray(vector<int> a) {
    int size = a.size();
    for(int i = 0; i < size / 2; i++) {
        int temp = a[i];
        a[i] = a[size - 1 - i];
        a[size - 1 - i] = temp;
    }
    return a;
}

// UTILITY func to print a vector
void printVector(vector<int> a) {
    for(int i = 0; i < a.size(); i++) { 
        if(i == a.size()-1)
            cout << a[i];
        else 
            cout << a[i] << " ";
    }
    cout << endl;
}
