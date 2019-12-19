#include <iostream>
#include <string>
using namespace std;

// func signature
int camelcase(string s);

// Driver program
int main() {
    string str;
    getline(cin, str);
    cout << camelcase(str) << endl;
    return 0;
}

// func implementation
int camelcase(string s) { 
    int counter = 0;
    int i = 0;
    while(i < s.length()) {
        if(s[i] >= 65 && s[i]<= 90) {
            counter++;
        }
        i++;
    }
    return counter + 1;
}

