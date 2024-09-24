#include <vector>
#include <iostream>
#include <algorithm>

int main(){
    int n=0;
    std:: cin >> n;
    for (int i=0; i<n; i++){
        int b;
        std::cin>>b;
        std::vector<int>v(b);
        for (int j=0; j<b; j++){
            std::cin >> v[j];
        }
        std::sort(v.begin(), v.end());
            int k=1;
            int m=0;
            for (int h=0; h<b; h++){
                if (v[h]<=k){
                    m++;
                    k=1;
                }
                else{
                    k++;
                }
            }
        std::cout << m << std::endl;
    }
return 0;
}
