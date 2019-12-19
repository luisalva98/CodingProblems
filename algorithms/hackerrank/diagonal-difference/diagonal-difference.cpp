#include <iostream>
#include <vector>
using namespace std;

// func signature
int diagonalDifference(vector<vector<int>> arr);
void printSqMatrix(vector<vector<int>> arr);

// Driver program
int main() {
    int n;
    cin >> n;
    vector<vector<int>> input(n, vector<int>(n));
    
    // populate 
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            cin >> input[row][col];
        }
    }
    cout << diagonalDifference(input) << endl;
    return 0;
}

// func implementation
// O(n) solution
int diagonalDifference(vector<vector<int> > arr){ 
    int n = arr.size();
    int prim_diag = 0;
    int sec_diag = 0;
    
    for(int row = 0; row < n; row++) {
        prim_diag +=  arr[row][row];
        sec_diag += arr[row][n - row - 1];
    }
    return abs(prim_diag-sec_diag);
}

// O(n^2) solution
/*int diagonalDifference(vector<vector<int>> arr) {
    int n = arr.size();
    int prim_diag = 0;
    int sec_diag = 0;
    
    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n; col++) {
            if(row == col) {
                prim_diag +=  arr[row][col];
            }
            if(row == n - col - 1) {
                sec_diag += arr[row][col];
            }
        }
    }
    return abs(prim_diag-sec_diag);
}*/