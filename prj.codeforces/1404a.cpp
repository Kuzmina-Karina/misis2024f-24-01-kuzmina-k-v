
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <math.h>
int main(){
    int t;
    int n, k;
    std::string s;
    std::cin >> t;
    while (t--) {
        std::cin >> n >> k >> s;
        int z = 0, o = 0;
        bool f = true;
        for (int i = 0; i < k; i++) {
            int tmp = -1;
            for (int j = i; j < n; j += k) {
                if (s[j] != '?') {
                    if (tmp != -1 && s[j] - '0' != tmp) {
                        f = false;
                        break;
                    }
                    tmp = s[j] - '0';
                }
            }
            if (tmp != -1) {
                if (tmp==0){
                    z++;
                }
                else{
                    o++;
                }
            }
        }
        if (std::max(z, o) > k / 2) {
            f = false;
        }
        if (f){
            std::cout << "YES" << std::endl;
        }
        else{
            std::cout << "NO" << std::endl;
        }
    }
	return 0;
}
