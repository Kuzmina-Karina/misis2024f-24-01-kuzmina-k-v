 #include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        ll k;
        cin >> k;
        string s;
        cin >> s;
        sort (s.begin(), s.end());
        ll ans=2;
        for(int j=1; j<s.size(); j++){
            if(s[j]==s[j-1]){
                ans++;
            }
            else{
                ans+=2;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
 
