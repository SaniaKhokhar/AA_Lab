#include <bits/stdc++.h>
using namespace std;

int main() {
   string t = "aaaaaaaaaaaaaaaaaaaaaaaaaaa"; // test
   string p = "a"; // pattern
   
   int n = t.length();
   int m = p.length();
   
   int comp=0;
   
   for(int s=0; s <= n-m; s++){
   	int j;
   	for(j = 0; j < m; j++){
       	comp++;
       	if(t[s+j] != p[j]){
           	break;
       	}
   	}
   	if(j == m){
       	cout << "Pattern found at index: " << s << endl;
   	}
   }
   cout << "Comparisons : " << comp << endl;
	return 0;
}

//Testcase 1: 
//input:
//string t = "this_is_apple_apple_is_red"; 
//string p = "apple"; 

//output: 
//Pattern found at index: 8
//Pattern found at index: 14
//Comparisons : 30


//Testcase 2:
// input:
// string t = "THIS IS A TEST TEXT"; // test
// string p = "TEST"; // pattern

// output:
// Pattern found at index 10
// comparisons 23


//Testcase 3:
//input:
//string t = "aaaaaaaaaaaaaaaaaaaaaaaaaaa"; 
//string p = "a";   

//output:
// Pattern found at index: 0
// Pattern found at index: 1
// Pattern found at index: 2
// Pattern found at index: 3
// Pattern found at index: 4
// Pattern found at index: 5
// Pattern found at index: 6
// Pattern found at index: 7
// Pattern found at index: 8
// Pattern found at index: 9
// Pattern found at index: 10
// Pattern found at index: 11
// Pattern found at index: 12
// Pattern found at index: 13
// Pattern found at index: 14
// Pattern found at index: 15
// Pattern found at index: 16
// Pattern found at index: 17
// Pattern found at index: 18
// Pattern found at index: 19
// Pattern found at index: 20
// Pattern found at index: 21
// Pattern found at index: 22
// Pattern found at index: 23
// Pattern found at index: 24
// Pattern found at index: 25
// Pattern found at index: 26
// Comparisons : 27