#include <iostream>
#include <vector>
#include <string>
int main(){
    int n=0;
    std:: cin >> n;
    std:: string s;
    std::cin >>s;
    int x=0;
    int y=0;
    int ans=0;
    for (int i=0; i<n; i++){
        if (x!=0 and y!=0 and x==y){
            if (s[i-1]==s[i]){
                ans+=1;
            }
        }
        if (s[i]=='U'){
            x+=1;
        }
        else{
            if (s[i]=='R'){
                y+=1;
            }
        }
    }
    if (x!=0 and y!=0 and x==y){
            if (s[n-3]==s[n-1]){
                ans+=1;
            }
    }
    std::cout << ans;
}
