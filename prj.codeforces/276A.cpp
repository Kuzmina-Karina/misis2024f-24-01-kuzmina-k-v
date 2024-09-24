#include <bits/stdc++.h>


int main(){
    int n;
    std::cin >>n;
    for (int i=0; i<n; i++){
        int a;
        int ch=0;
        int s=1;
        std::cin>>a;
        std::vector<int>v;
        while(a>0){
            if (a%10!=0){
                v.push_back((a%10)*s);
                ch+=1;
            }
            a/=10;
            s*=10;
        }
        std::cout << ch << std::endl;
        for (int i=0; i<v.size(); i++){
            std::cout << v[i] <<" ";
        }
        std:: cout << std::endl;
 }

return 0;
}
