#include <iostream>
#include <string>
using namespace std;

// func signature
string superReducedString(string s);

// Driver program
int main() {

    string str;
    getline(cin, str);
    cout << superReducedString(str) << endl;
    return 0;
}

// func implementation
string superReducedString(string s) { 
    int i = 0;
    while(i < s.length()) {
        if(s[i] == s[i + 1]) {
            s.erase(i, 2);
            i = 0;
        } else {
            i++;
        }
    }
    return s == "" ? "Empty String" : s;
}
