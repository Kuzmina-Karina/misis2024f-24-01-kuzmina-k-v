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
        std::vector<int>a(n);
        std::vector<int>b(n); 
        int pr=0;
        int ans=0;
        for (int i=0; i<n; i++){
            std::cin >> a[i] >> b[i];
        }
        int y1=0;
        for (int i=0; i<n; i++){
            int tm;
            std::cin >> tm;
            int x, y;
            
            if (i!=0){
                y1=b[i-1];
            }
            x=a[i];
            y=b[i];
            ans = pr+x-y1+tm;
            if (y>ans+(y-x+1)/2){
                pr=y;
            }
            else
                pr=ans+(y-x+1)/2;
        }
        std::cout << ans << std::endl; 
    }
}
