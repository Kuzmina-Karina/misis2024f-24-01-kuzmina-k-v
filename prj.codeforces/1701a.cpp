#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <math.h>
int main(){
    int n;
    std::cin >> n;
    for(int i=0; i<n; i++){
        int x, y, z, h;
        std::cin >> x >> y >> z >> h;
        int s=x+y+z+h;
        if (s==0){
            std::cout << 0 << std::endl;
        }
        else{
            if (s==4){
                std::cout << 2 << std::endl;
            }
            else{
                std::cout << 1 << std::endl;
            }
        }
    }
	return 0;
}
