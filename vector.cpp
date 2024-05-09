#include<bits/stdc++.h>
using namespace std;

int main(){
int n;
cin>>n;
vector<int> v;

for(int i=0;i<n;i++){
int x;
cin>>x;
v.push_back(x);

}
sort(v.begin(),v.end());
cout<< "Here is the sorted vector"<<" ";
for(auto s: v) cout<<s <<" ";
cout<<endl;
for(int i=n-1;i>=0;i--){
    cout<<v[i]<<" ";
    v.pop_back();
}
cout<<endl;
cout<<"Size of vector now: "<<v.size()<<endl;

    return 0;
}

