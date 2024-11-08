#include <bits/stdc++.h>
using namespace std;
int main(){

int n, m;
cin >> n >> m;
int l2=0;
while(m!=n){
    if(m%2==0 && m>n){
        m/=2;
        l2++;
    }
    else{
        m+=1;
        l2++;
    }
}
cout << l2;
return 0;
}
