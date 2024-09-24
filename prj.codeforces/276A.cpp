#include <bits/stdc++.h>


int main(){
    int n, k;
    int m=-INT_MAX;
    std::cin >> n >> k;
    for (int i=0; i<n; i++){
        int f, t;
        std::cin >> f >> t;
        if (k<t){
            m=std::max(m, f-(t-k));
        }
        else{
            m=std::max(m, f);
        }
    }
    std::cout << m;
return 0;
}
