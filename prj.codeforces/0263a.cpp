#include <bits/stdc++.h>

int main(){
 int n=5;
 int x, y;
 std::vector < std::vector<int> > a(5, std::vector<int> (5));
 for (int i=0; i<5; i++){
    for (int j=0; j<5; j++){
        std::cin >> a[i][j];
        if (a[i][j]==1){
            x=i+1;
            y=j+1;
        }
    }
 }
 std::cout << abs(x-3)+abs(y-3);

return 0;
}
