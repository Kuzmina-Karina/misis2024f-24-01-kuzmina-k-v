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
        int k=0;
        int ans=0;
        std::cin >> n >> k;
        std::string s;
        std::cin >> s;
        for(int i=0; i<s.size(); i++){
            if (s[i]=='B'){
                i+=k-1;
                ans+=1;
            }
        }
        std::cout << ans << std::endl;
    }
return 0;
}
