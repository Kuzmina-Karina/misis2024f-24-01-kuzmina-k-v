#include <iostream>
#include <vector>
#include <string>

#define ll long long
using namespace std;
int main(){

int n;
cin >> n;
while(n--){
    int g, a;
    int m1=0;
    int m2=0;
    cin >> g;
    for(int i=0; i<g; i++){
        cin >> a;
        if(a>m1 && a>m2){
            m2=m1;
            m1=a;
        }
        else
            if(a>m2 && a<=m1){
                m2=a;
            }
    }
    if(abs(m1-m2)>1){
        cout <<"NO" <<endl;
    }
    else
        cout << "YES" << endl;

}

return 0;
}
