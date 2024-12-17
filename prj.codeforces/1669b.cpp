#include <iostream>
#include <vector>
#include <string>

#define ll long long
using namespace std;
int main(){

int n, a;
cin >> n;
for(int i=0; i<n; i++){
    int f=-1;
    cin >> a;
    vector<int> v(a);
    for(int j=0; j<a; j++){
        int x;
        cin >> x;
        v[x-1]++;
    }
    for(int j=0; j<a; j++){
        if(v[j]>=3){
            f=j+1;
            break;
        }
    }
    cout << f << endl;
}

return 0;
}
