#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){


int n;
cin >> n;
int a, b, c, d;

for(int i=0; i<n; i++){
    int ans=0;
    cin >> a >> b >> c >> d;
    if(b>a){
        ans++;
    }
    if(c>a){
        ans++;
    }
    if(d>a){
        ans++;
    }
    cout << ans << endl;
}

return 0;
}
