#include <bits/stdc++.h>
using namespace std;

bool knapsack(int n,int p[], int w[], int C, int V) {
    int M[n+1][C+1]; 
    for(int i = 0; i <= n; i++) { 
        M[i][0] = 0;
    }
    for(int j = 0; j <= C; j++) { 
        M[0][j] = 0;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= C; j++) {
            if(w[i] <= j) {
                if(p[i] + M[i-1][j-w[i]] > M[i-1][j]){
                    M[i][j] = p[i] + M[i-1][j-w[i]];
                }
                else {
                    M[i][j] = M[i-1][j];
                }
            }
            else {
                M[i][j] = M[i-1][j];
            }
        }
    }
    // cout << M[n][C] << endl;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= C; j++){
            cout << M[i][j] << " " ;
        }
        cout << endl;
    }
    if(M[n][C] >= V){
        return true;
    }
    return false;
    
}
bool SubsetSum(int n,int s[],int sum){
    int p[n+1];
    int w[n+1];
    int C = sum;
    int V = sum;

    for(int i = 0; i <= n; i++){
        p[i] = s[i];
        w[i] = s[i];
    }
    if(knapsack(n,p,w,C,V) == true){
        return true;
    }
    return false;
}
int main() {
    int n = 6; // no. of object
    int sumset[] = {0,4,3,6,8,5,9};
    // {0,3,5,7,9,11}; 
    int sum = 23;
    bool ans = SubsetSum(n,sumset,sum);
    cout << "Answer: " << ans << endl;
    return 0;
}

//Input:{0,4,3,6,8,5,9}  sum = 23
//Output:
//Answer: 1 //true

//Input:{0,3,5,7,9,11} sum = 13
//Output:
//Answer: 0 //false