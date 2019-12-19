#include <iostream>
#include <string>
using namespace std;

int minimumNumber(int n, string password);

int main() {
    int n;
    cin >> n;
    cin.ignore();
    string str;
    getline(cin, str);
    cout << minimumNumber(n,str) << endl;
    return 0;
}

int minimumNumber(int n, string password) {
    int metReq = 0;
    bool digit = false;
    bool lower = false;
    bool upper = false;
    bool special = false;
    
    for(int i = 0; i < n; i++){
       if(islower(password[i]))
           lower = true;
       else if(isupper(password[i]))
           upper = true;
       else if(isdigit(password[i]))
           digit = true;
       else
           special = true;    
    }

    // record the number of requirements the password did not meet
    if(!upper)
        metReq++;
    if(!lower)
        metReq++;
    if(!digit)
        metReq++;
    if(!special)
        metReq++;
    
    // if the size + the metReq is less than 6 
    if(n + metReq < 6)
        metReq = metReq + (6 - (n + metReq));
    // otherwise, simply return the initial metReq.
    return metReq;    
}
