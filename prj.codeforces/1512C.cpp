#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

int main(){
    int t;
    std::cin>>t;
    while(t--){
        int k0, k1;
        std::cin >> k0 >> k1;
        std::string s;
        std::cin >> s;
        int n=s.size();
        int sch1=0;
        int sch0=0;
        int sch=n%2;
        int t=0;
        int f=-1;
        for (int i=0; i<n/2; i++){
            char a=s[i];
            char b=s[n-i-1];
            if (a=='0' and b=='0'){
                sch0+=2;
            }
            if (a=='1' and b=='1'){
                sch1+=2;
            }
            if (a=='0' and b=='1' or a=='1' and b=='0'){
                f=0;
                break;
            }
            if (a=='1' and b=='?'){
                sch1+=2;
                s[n-i-1]='1';
            }
            if (a=='?' and b=='1'){
                sch1+=2;
                s[i]='1';
            }
            if (a=='0' and b=='?'){
                sch0+=2;
                s[n-i-1]='0';
            }
            if (a=='?' and b=='0'){
                sch0+=2;
                s[i]='0';
            }
            if (a=='?' and b=='?'){
                sch+=2;
            }
        }
        k0-=sch0;
        k1-=sch1;
       // std::cout << k0 << " " << k1 << " " << sch1 << " " << sch0 << " " << sch << " " << s  << " " << std::endl;
        if (n%2==1){
            if (s[n/2]=='1'){
                k1-=1;
                sch-=1;
            }
            else{
                if (s[n/2]=='0'){
                    k0-=1;
                    sch-=1;
                }
                else{
                    if (s[n/2]=='?' and k0%2==1 and k1%2==0){
                        s[n/2]='0';
                        k0-=1;
                        sch-=1;
                    }
                    else{
                        if (s[n/2]=='?' and k1%2==1 and k0%2==0){
                            s[n/2]='1';
                            k1-=1;
                            sch-=1;
                        }
                        else{
                            f=0;
                        }
                    }
                }
            }

        }
       // std::cout << k0 << " " << k1 << " " << sch1 << " " << sch0 << " " << sch << " " << s  << " " << std::endl;
        if (f!=0 and k0>=0 and k1>=0 and k0%2==0 and k1%2==0 and k0+k1==sch){
            for (int i=0; i<n/2 and k0>0; i++){
                if (s[i]=='?'){
                    s[i]='0';
                    s[n-i-1]='0';
                    k0-=2;
                }
            }
            for (int i=0; i<n/2 and k1>0; i++){
                if (s[i]=='?'){
                    s[i]='1';
                    s[n-i-1]='1';
                    k1-=2;
                }
            }

        }
        else{
            f=0;
        }
        if (f!=0){
            std::cout << s << std::endl;
        }
        else{
            std::cout << -1 << std::endl;
        }
    }
return 0;
}
