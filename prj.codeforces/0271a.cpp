#include <iostream>
#include <vector>
#include <string>


bool f(int n){
    int a, b, c, d;
    a=n/1000;
    b=(n/100)%10;
    c=(n/10)%10;
    d=n%10;
    //std::cout << a << " " << b << " " << c << " " << d << std::endl;
    if (a==b || a==c || a==d || b==c || b==d || c==d){
        return 0;
    }
}

int main(){
    int n;
    std::cin >> n;
    n++;
    while (!(f(n))){
        n++;
    }
    std::cout << n;
return 0;
}
