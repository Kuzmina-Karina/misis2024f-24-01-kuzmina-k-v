#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

int main(){
    int t;
    std::cin>>t;
    while(t--){
        int ans=0;
        std::vector<std::vector<char> > v(10, std::vector<char> (10));
        for (int i1=0; i1<10; i1++){
            for (int j1=0; j1<10; j1++){
                std::cin >> v[i1][j1];
                if (v[i1][j1]=='X'){
                    int i=0;
                    int j=0;
                    if (i1>=5){
                        i=4-i1%5;
                    }
                    else{
                        i=i1;
                    }
                    if (j1>=5){
                        j=4-j1%5;
                    }
                    else{
                        j=j1;
                    }
                    ans+=std::min(i, j)+1;
                }
            }
        }

        std::cout << ans << std:: endl;
    }
return 0;
}
