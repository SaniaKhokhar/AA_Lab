#include <bits/stdc++.h>
using namespace std;

void RabinKarp(string T, string P, int d, int q) {
    int n = T.length();
    int m = P.length();
    
    int h = 1;
    for(int i = 0; i < (m-1); i++) {
        h = (h*d) % q;
    }

    int p = 0, t = 0;

    for(int i = 0; i < (m); i++) {
        p = (d * p + P[i]) % q;
        t = (d * t + T[i]) % q;
    }

    int s,j;
    for(s = 0; s <= (n-m); s++) {
        if(p == t) {
            for(j = 0; j < m; j++) {
                if(T[s+j] != P[j]) {
                    break;
                }
            }
            if(j == m) {
                cout << "Pattern matched " << s << endl;
            }
        }
        if(s < (n-m)) {
            t = ((d * (t - T[s] * h)) + T[s+m]) % q;
            if(t < 0) {
                t = t + q;
            }
        }
    }
}

int main() {
    char T[] = "2359023141526739921";
    char P[] = "31415";

    int d = 10;
    int q = 13;

    RabinKarp(T, P, d, q);

    return 0;
}