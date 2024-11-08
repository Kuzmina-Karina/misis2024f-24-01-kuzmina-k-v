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
        int n=0;
        std:: cin >> n;
        int f=1;
        int k1=0;
        int k2=0;
        for(int i=0; i<n; i++){
            int x;
            std::cin >> x;
            if (x==0 and f){
                k1=i;
                k2=i;
                f=0;
            }
            else{
                if (x==0){
                    k2=i;
                }
            }
        }       
        if (k1==0){
            std::cout << 0 << std::endl;
        }
        else
            std::cout << k2-k1+2 << std::endl; 
    }
}
