#include <vector>
#include <iostream>
#include <algorithm>

int f (int k){
    int a=k;
    int t=0;
    std::vector<int>v;
    while (a>0){
        v.push_back(a%2);
        a/=2;
    }
    for (int i=0; i<v.size(); i++){
        t*=10;
        t+=v[v.size()-i-1];
    }
    return t;
}
int main(){
    int n=0;
    std:: cin >> n;
    int k=1;
    while(f(k)<=n){
        k++;
    }
    std::cout<<k-1;
return 0;
}
