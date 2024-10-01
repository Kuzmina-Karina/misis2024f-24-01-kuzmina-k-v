#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

int main(){
    int t;
    std:: cin >> t;
    while (t>0){
        int n=0, k=0, r=0, c=0;
        std::cin >> n >> k >> r >> c;
        r--;
        c--;
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if ((r+c)%k==(i+j)%k){
                    std::cout << 'X';
                }
                else{
                    std::cout << '.';
                }
            }
            std::cout << std::endl;
        }
        t--;
    }
return 0;
}
