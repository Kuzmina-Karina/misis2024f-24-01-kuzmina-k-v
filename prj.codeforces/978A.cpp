#include <vector>
#include <iostream>
#include <algorithm>
int main(){
int n;
std::cin >> n;
std::vector<int>a(n);
for (int i=0; i<n; i++){
    std::cin >> a[n-i-1];
}
std::vector<int>v;
for (int i=0; i<n; i++){
    int f=1;
    for (int j=0; j<v.size(); j++){
        if (a[i]==v[j]){
            f=0;
            break;
        }
    }
    if (f){
        v.push_back(a[i]);
    }
}
reverse(v.begin(), v.end());
std::cout << v.size() << std::endl;
for(int i=0; i<v.size(); i++){
    std::cout << v[i] << " ";
}
return 0;
}
