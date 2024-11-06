#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#define ll long long

int main(){
    ll n;
    ll m;
    std::cin >> n >> m;
    ll pos=1;
    ll ans=0;
    for (int i=0; i<m; i++){
        int x;
        std::cin >> x;
        if (pos<=x){
            ans+=x-pos;
            pos=x;
        }
        else{
            if (pos>x){
                ans+=n-(pos-x);
                pos=x;
            }
        }
    }
    std::cout << ans;
return 0;
}
