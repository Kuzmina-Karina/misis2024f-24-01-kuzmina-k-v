#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        char a, b, c;
        cin >> a >> b >> c;
        if((a=='y' || a=='Y') && (b=='e' || b=='E') && (c=='s' || c=='S')){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
 
