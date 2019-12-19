#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

void maximumElement(vector<string> input);
int getInt(string query);

int main() {
    int n;
    cin >> n; // take in number of queries n
    vector<string> input; // vector to hold all queries
    cin.ignore();
    for(int i = 0; i < n; i++) {
        string temp;
        getline(cin, temp);
        input.push_back(temp);
        // storing queries as either:
        // Type 1:  "1 x"
        // Type 2:  "2"
        // Type 3:  "3"
    }
    maximumElement(input);
}

/* UTILITY func to extract int from type 1 query string*/
int getInt(string query) {
    size_t spaceIdx = query.find(' ');
    int x = stoi(query.substr(spaceIdx+1));
    return x;
}

void maximumElement(vector<string> input) {
    stack<int> elements; // stack to place type 1 query elements
    stack<int> maxStack; // stack to keep track of previous and current max vals

    for(int q = 0; q < input.size(); q++) {
        if(input[q].length() > 1) { // query q is of type 1
            int x = getInt(input[q]); // extract int value
            elements.push(x);
            if(maxStack.empty()) { // if maxStack empty simply push
                maxStack.push(x);
            } else { // only push if x is bigger than or same as previous max
                if(maxStack.top() <= x) { maxStack.push(x); }
            }
        } else { // query q is of either type 2 or type 3
          if(input[q] == "2") {
              if(elements.top() == maxStack.top()) { maxStack.pop(); }
              elements.pop();
          } else {
            cout << maxStack.top() << endl;
          }
        }
    }
}
