#include <iostream>
#include <vector>
#include <string>

#define ll long long
using namespace std;
int main(){

int n, a;
cin >> n;
for(int i=0; i<n; i++){
    int f=1;
    cin >> a;
    vector<int> v(a);
    for(int j=0; j<a; j++){
        cin >> v[j];
    }
    for(int j=2; j<a; j+=2){
        if(v[j-2]%2!=v[j]%2 || v[j-1]%2!=v[j+1]%2 && j<a-1){
            cout << "NO" << endl;
            f=0;
            break;
        }
    }
    if(f){
        cout << "YES" << endl;
    }
}

return 0;
}
