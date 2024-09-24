#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

int main(){
    int t;
    std:: cin >> t;
    for (int i=0; i<t; i++){
        int n, x;
        std::cin >> n >> x;
        std::vector<int>v(n);
        std::vector<int>a(1000);
        for (int i=0; i<n; i++){
            std::cin >> v[i];
            a[v[i]]=1;
        }
        int j=0;
        while(x>=0){
            j++;
            if (a[j]==0){
                x--;
            }
        }
        std::cout << j-1 << std::endl;
    }
return 0;
}
