#include <iostream>
#include <vector>
int main(){
    int n=0;
    std:: cin >> n;
    std:: vector<int> v(n);
    for (int i=0; i<n; i++){
        int x;
        std:: cin >>x;
        v[x-1]=i+1;
    }
    for(int i=0; i<n; i++){
        std::cout << v[i] << " ";
    }
    return 0;
}
