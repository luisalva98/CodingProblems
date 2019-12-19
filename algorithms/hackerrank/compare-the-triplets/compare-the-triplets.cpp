#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// func signatures
vector<int> compareTriplets(vector<int> a, vector<int> b);
void printVector(vector<int> ar);

int main() {
    
    // filestream variable file
    fstream file;
    // filename of the file
    string filename = "input07.txt";;
    // opening file
    file.open(filename.c_str());
    
    // variable to hold incoming integers
    int tmp_int;
    vector<int> input;
    
    // extracting ints from the file
    while(file >> tmp_int) {
        input.push_back(tmp_int);
    }
    
    // splitting up input
    int mid = input.size()/2;
    vector<int> a(mid);
    vector<int> b(mid);
    int i = 0;
    int j = mid;
    while(i < j) {
        a[i] = input[i];
        b[i] = input[mid];
        i++;
        mid++;
    }
    printVector(compareTriplets(a, b));
    return 0;
}

/*UTILITY func to print  vector*/
void printVector(vector<int> ar) {
    for(int i = 0; i < ar.size(); i++) {
        if(i == ar.size()-1) {
            cout << ar[i];
        } else {
            cout << ar[i] << " ";
        }
    }
    cout << endl;
}

// func implementation
vector<int> compareTriplets(vector<int> a, vector<int> b) {
    vector<int> result(2,0);
    for(int i = 0; i < b.size(); i++) {
        if(a[i] > b[i]) {
            result[0]++;
        }
        if(a[i] < b[i]) {
            result[1]++;
        }
    }
    return result;
}
