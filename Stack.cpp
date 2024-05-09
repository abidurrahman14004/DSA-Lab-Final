#include<bits/stdc++.h>
#include<stack> 
using namespace std;

int main() {
    stack<int> s;
    int n;  // number of elements you want to insert in stack
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.push(x);
    }

    cout << "The Stack elements Are :" << endl; // corrected spelling of "The"
    for (int i = 0; i < n; i++) {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}
