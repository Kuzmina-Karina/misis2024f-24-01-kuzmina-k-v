#include <iostream>
int main(){
    int n=0;
    std:: cin >> n;
    int k=0;
    int ans=0;
    std:: cin >> k;
    for (int i=0; i<n; i++){
        int x=0;
        std:: cin >> x;
        if (k%x==0 and ans<x){
            ans = x;
        }
    }
    std::cout << ans;
    return 0;
}
