#include <iostream>
#include <vector>
using namespace std;

// func signatures
void printVector(vector<int> a);
vector<int> dynamicArray(int n, vector<vector<int>> queries);

// Driver program
int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> queries(q);
    for(int row = 0; row < q; row++) {
       for(int col = 0; col < 3; col++) {
           int temp;
           cin >> temp;
           queries[row].push_back(temp);
       }
    }
    printVector(dynamicArray(n, queries));
    return 0;
}

// UTILITY func to print a vector
void printVector(vector<int> a) {
    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << endl;
    }
}

// func implementation
vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    int lastAnswer = 0;
    vector<vector<int>> seqList(n);
    vector<int> valuesToPrint;
    for(int i = 0; i < queries.size(); i++) {
        //  1   x   y
        // [0] [1] [2]
        //  2   x   y
        // [0] [1] [2]
        int x = queries[i][1];
        int y = queries[i][2];
        if(queries[i][0] == 1) {
            seqList[(x^lastAnswer)%n].push_back(y);
        } else {
            lastAnswer = seqList[(x^lastAnswer)%n][y%seqList[(x^lastAnswer)%n].size()];
            valuesToPrint.push_back(lastAnswer);
        }
    }
    return valuesToPrint;
}

/*
 !!The Problem statement is poorly articulated, so hope these references help!!
 
 -> reference comment by user @gbmartelli per discussion forum on hackerrank:
    "I will try to clarify the question for people which are having a hard time to
    understand it, like I was:
    seqList is basically an Array of Arrays,
    each Array in seqList will be dynamic,
    while seqList itself will be static with the input 'N' determining the number of
    Arrays that will compose it.
    The 'Q' input will determine the number of Queries.
    Each Query will demand an input of 3 integers: 't', 'x' and 'y'.
    The 't' is for "type".
    The type 1 Query will append the 'y' variable to some array in seqList, the
    formula will specify which one.
    The type 2 Query will take some value, that was alredy assigned to some Array of
    the seqList, and copy that to lastAnswer.
    The first formula specifies the array of seqList and the second formula
    specifies which value of that Array must be taken.
    I hope the schematic below make it clearer."
 -> reference video for better explanation of problem statement:
    **WARNING**
    -> video does provide solution!
    **WARNING**
    https://youtu.be/N0lSGQrya6s
 */
