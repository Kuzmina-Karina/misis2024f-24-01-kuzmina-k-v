#include <iostream>
#include <vector>
int main(){
    int n=0;
    std:: cin >> n;
    while (n--){
        std ::vector <std:: vector <char> > a(8, std:: vector <char>(8));
       // char c;
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                std::cin >> a[i][j];
            }
        }
        int x=0;
        int y=0;
        for(int i=1; i<7; i++){
            for(int j=1; j<7; j++){
                if (a[i-1][j+1]=='#' and a[i-1][j-1]=='#'){
                    x=j+1;
                    y=i+1;
                    break;
                }
            }
            if(x and y){
                break;
            }
        }
        std:: cout << y << " " << x << std:: endl;
    }
    return 0;
}
