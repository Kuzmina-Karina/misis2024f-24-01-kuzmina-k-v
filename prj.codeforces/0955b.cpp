#include <bits/stdc++.h>
using namespace std;
int main(){

    string s;
    cin >> s;
    int t=0, f=0;
    vector <int> a(33);
    for(int i=0; i<s.size(); i++){
        if(a[s[i]-97]==0){
            t++;
        }
        a[s[i]-97]++;
    }
    int k=0;
    for(int i=0; i<33; i++){
        k+=a[i];
    }
    if(t>4 || s.size()<4 || t==1){
        cout << "No";
    }
    else{
        if(t>=3){
            cout << "Yes";
        }
        else{
            for(int i=0; i<33; i++){
                if(a[i]==1){
                    f=1;
                }
            }
            if(f==1){
                cout << "No";
            }
            else{
                cout << "Yes";
            }
        }
    }
return 0;
}
