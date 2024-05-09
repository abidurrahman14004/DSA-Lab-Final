#include<bits/stdc++.h>
#include<queue> 
using namespace std;

int main() {
    queue<int> q;
    int n;  // number of elements you want to insert in queue
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }
   cout<<q.size()<<endl;

    cout << "The queue elements Are :" << endl; // corrected spelling of "The"
    for (int i = 0; i < n; i++) {
        cout << q.front() << endl;
        q.pop();
    }
    cout<<q.size();
    return 0;
}
