#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){

    ll n;
    ll k;
    cin >> n;
    while(n){
        cin >> k;
        ll a[k];
        ll s=1;
        for(int i=0; i<k; i++){
            cin >> a[i];
        }
        for(int i=k-1; i>=0; i--){
            if(a[i-1]==1 && a[i]==1){
                s+=5;
            }
            else{
                if(i==0 && a[i]==1){
                    s++;
                }
                else{
                    if(a[i-1]==0 && a[i]==1){
                        s++;
                    }
                    else{
                        if(a[i-1]==0 && a[i]==0){
                            s=-1;
                            break;
                        }
                    }
                }
            }
        }
        cout << s << endl;
        n--;
    }

return 0;
}
