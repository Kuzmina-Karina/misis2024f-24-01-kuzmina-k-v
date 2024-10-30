#include <iostream>
int main(){
    int n=0;
    std:: cin >> n;
    while (n--){
        int m;
        std::cin >> m;
        for (int i=0; i<m; i++){
            int x;
            std:: cin >> x;
        }
        if (m%2) std:: cout << '4' << std:: endl << 1 << " " << m-1 << std:: endl << 1 << " " << m-1
         << std:: endl << m-1 << " " << m << std:: endl << m-1 << " " << m << std:: endl; 
        else std:: cout << '2' << std:: endl << 1 << " " << m << std:: endl << 1 << " " << m << std:: endl; 
    }
    return 0;
}
