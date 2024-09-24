#include <vector>
#include <iostream>
#include <algorithm>
int main(){
int n;
std::cin >> n;
for (int i=0; i<n; i++){
    int x, y, z;
    std::cin >> x >> y >> z;
    int f1=(abs((x-y)))/2;
    if (f1*2<abs(x-y)){
        f1+=1;
    }
    if (f1/z*z<f1){
        f1=f1/z+1;
    }
    else{
        f1=f1/z;
    }
    std::cout << f1 <<std::endl;
}
return 0;
}
