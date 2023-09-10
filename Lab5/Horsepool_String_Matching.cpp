#include <bits/stdc++.h>
using namespace std;

int main() {
    
	string t= "JIM_SAW_ME_IN_BARBER_SHOP";
	string p = "BARBER";

	int n = t.size();
	int m = p.size();
    
	int shift[26];
    
	//1. Pre Processing
	for(int i = 0; i < 26; i++){
    	shift[i] = m;
	}
	for(int i=0; i < m-2; i++){
    	shift[p[i] - 'A'] = m-1-i;
	}
    
	//printing shift table
	// for(int i = 0; i < 26; i++){
	// 	cout << shift[i] << endl;
	// }

	//2.Search
	int s = 0;
	while(s + m <= n){
    	if(t[s + m - 1] == p[m - 1]){
        	int i = m-2;
        	while(i >= 0 && (p[i] == t[s + i])){
            	i--;
        	}
        	if(i == -1){
            	cout << "Pattern found at index " <<  s << endl;
        	}
    	}
    	s += shift[t[s + m - 1] - 'A'];
	}
    
	return 0;
}

//output:
//Pattern found at index 14