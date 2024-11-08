#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){

int n, a;
cin >> n;
for(int i=0; i<n; i++){
    int x;
    cin >> x;
    cout << "Division ";
    if(x>=1900){
        cout << 1;
    }
    else{
        if(x>=1600 && x<=1899){
            cout << 2;
        }
        else{
            if(x>=1400 && x<=1599){
                cout << 3;
            }
            else{
                cout << 4;
            }
        }
    }
    cout << endl;
}
return 0;
}
