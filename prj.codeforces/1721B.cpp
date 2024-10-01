#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

int main(){
    int t;
    std:: cin >> t;
    while (t>0){
        int n=0, m=0, x=0, y=0, r=0;
        std::cin >> n >> m >> x >> y >> r;
        int a=std::max(x-r, 1);
        int b=std::min(x+r, n);
        int c=std::max(y-r, 1);
        int d=std::min(y+r, m);

        if ((a==1 and b==n) or (c==1 and d==m) or (b==n and d==m) or (a==1 and c==1)){
            std::cout << -1 << std::endl;
        }
        else{
            std::cout << m+n-2 << std::endl;
        }
        t--;
    }
return 0;
}
