#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <math.h>
int main(){
    int t;
    std::cin >>t;
    while (t--){
        std::string s;
        std::cin >> s;
        bool ans=1;
        for(int i=0; i<s.size(); i++){
            if ((i == 0 or s[i] != s[i - 1]) and (i == s.size() - 1 or s[i] != s[i + 1])){
                ans=0;
            }
        }       
        if(ans==0){
            std::cout << "NO"<<std::endl;
        }
        else{
            std:: cout << "YES" << std::endl;
        }
    }
}
