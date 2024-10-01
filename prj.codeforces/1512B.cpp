#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

int main(){
    int t;
    std:: cin >> t;
    while (t>0){
        int n;
        std::cin >> n;
        std::vector<std::vector<char> >v(n, std::vector<char> (n));
        int f=1;
        int a=0;
        int b=0;
        int a1=0;
        int b1=0;
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                std::cin >> v[i][j];
                if(v[i][j]=='*' and f){
                    f=0;
                    a=i;
                    b=j;
                }
                else{
                    if(v[i][j]=='*' and !f){
                        a1=i;
                        b1=j;
                    }
                }
            }
        }
        if (a==a1){
            if (a!=0){
                a=0;
            }
            else{
                a+=1;
            }
        }
        if (b==b1){
            if (b!=0){
                b=0;
            }
            else{
                b+=1;
            }
        }
        v[a1][b]='*';
        v[a][b1]='*';
        v[a][b]='*';
        v[a1][b1]='*';
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                std::cout << v[i][j];
            }
            std::cout << std::endl;
        }
        t--;
    }
return 0;
}
