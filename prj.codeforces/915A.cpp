#include <iostream>
int main(){
    int n=0;
    std:: cin >> n;
    int k=0;
    int ans=1010003;
    std:: cin >> k;
    for (int i=0; i<n; i++){
        int x=0;
        std:: cin >> x;
        if (k%x==0 and k/x<ans){
            ans = k/x;
        }
    }
    std::cout << ans;
    return 0;
}
