#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
int main(){
int n;
std::cin >> n;
std::string s;
std::cin >> s;
int f=0;
int ans=0;
for(int i=0; i<n; i++){
  //  std::cout << f << " ";
    if (s[i]=='x'){
        f+=1;
    }
    else{
        f=0;
    }
    if (f>=3){
        ans+=1;
        f-=1;
    }
}
std::cout << ans;
return 0;
}
