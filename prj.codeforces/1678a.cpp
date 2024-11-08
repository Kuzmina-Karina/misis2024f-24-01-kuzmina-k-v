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
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		for(int i=0;i<n;i++)
			std::cin >>a[i];
		sort(a.begin(),a.end());
		int z=count(a.begin(),a.end(),0);
		if(z>0)
			std::cout << n-z << std::endl;
		else{
			bool ans=false;
			for(int i=1;i<n;i++)
				if(a[i]==a[i-1])
					ans=true;
			if(ans)
                std::cout << n << std::endl;
			else 
                std::cout << n+1 << std::endl;
		}
	}
	return 0;

}
