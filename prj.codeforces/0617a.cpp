#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main(){
    int n;
    cin >> n;
    if (n-n/5*5>0){
        cout << n/5+1;
    }
    else{
        cout << n/5;
    }
return 0;
}
