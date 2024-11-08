#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <math.h>
int main(){
	int t;
	std::cin >> t;
	while(t--){
		int n, m;
		std::cin >> n >> m;
		std::vector<std::vector<char> > s(n, std::vector<char>(m));
        for(int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                std::cin >> s[i][j];
            }
        }
        int mii=INT_MAX;
        int mij=INT_MAX;
        for(int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (s[i][j]=='R'){
                    mii=std::min(mii, i);
                    mij=std::min(mij, j);
                }
            }
        }
		if(s[mii][mij]=='R')
            std::cout << "YES" << std::endl;
        else 
            std::cout << "NO"<< std::endl;
	}
	return 0;
}
