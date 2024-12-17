#include <iostream>
#include <vector>
#include <string>

#define ll long long
using namespace std;
int main(){


int n;
cin >> n;
int a, b, c, d, s;
char k;
for(int i=0; i<n; i++){
    cin >> a >> k >> c >> s;
    int y=a*60+c;
    int ans=0;
    int t=0;
    while(1){
        y+=s;
        t+=s;
        int h=y/60%24;
        int m=y%60;
        if(h/10==m%10 && m/10 == h%10){
            ans++;
        }
        if(h==a && m==c){
            break;
        }

    }
    cout << ans << endl;
}
return 0;
}
