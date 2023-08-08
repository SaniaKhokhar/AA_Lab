#include <bits/stdc++.h>
using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b){
    if(a < b){
        return gcd(b,a);
    }
    else if(a % b == 0){
        return b;
    }
    else{
        return gcd(b, a % b);
    }
}

unsigned long long power(unsigned long long a, unsigned long long x, unsigned long long n){
    unsigned long long res = 1;
    while(x > 0){
        if(x % 2 == 1){
            res = (res * a) % n;
        }
        x /= 2;
        a = (a * a) % n;
       // cout << res << endl;
    }
    return res;
}

bool prime(unsigned long long n){
    if(n <= 1 || n == 4){
        return false;
    }
    if(n <= 3){
        return true;
    }
    int k = 100;
    while(k > 0){
        unsigned long long a = 2 + (rand() % (n - 4));

        if(gcd(n,a) != 1){
            return false;
        }
        if(power(a,n-1,n) != 1){
            return false;
        }
        k--;
    }
    return true;
}
int main() {
    srand(time(0));
    int ans = prime(1000000007); // 858993589  == > prime
    cout << ans;
    return 0;
}
