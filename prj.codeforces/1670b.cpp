#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#define ll long long

int main(){
    int t;
    std::cin >> t;
    while(t--){
        int n=0;
        std::cin >> n;
        std::string s;
        std::cin >> s;
        int m;
        std::cin >> m;
        std::vector<char> v(m);
        std::vector<int> a(n);
        for(int i=0; i<m; i++){
            std::cin >> v[i];
            for (int j=0; j<n; j++){
                if(s[j]==v[i]){
                    a[j]=1;
                }
            }
        }
        int f=0;
        int ans=0;
        int sch=0;
        for (int i=0; i<n; i++){
            if(a[i]==1){
                if(f){
                    sch+=1;
                }
                ans=std::max(sch, ans);
                sch=0;
                f=1;
            }
            else{
                sch+=1;
            }
        }
        std::cout<<ans << std::endl;
    }
return 0;
}
