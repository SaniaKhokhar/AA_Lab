#include <bits/stdc++.h>
using namespace std;

#define NO_OF_CHARS 256

int getNextState(string pat, int M, int state, int x){
    
    if (state < M && x == pat[state])
        return state+1;
 
    int nextstate, i;

    for (nextstate = state; nextstate > 0; nextstate--){
        if (pat[nextstate-1] == x){
            for (i = 0; i < nextstate-1; i++)
                if (pat[i] != pat[state-nextstate+1+i])
                    break;
            if (i == nextstate-1)
                return nextstate;
        }
    } 
    return 0;
}

void computeTF(string pat, int M, int TF[][NO_OF_CHARS]){
    int state, x;
    for (state = 0; state <= M; ++state)
        for (x = 0; x < NO_OF_CHARS; ++x)
            TF[state][x] = getNextState(pat, M, state, x);
}
 
void FiniteAutomaton(string t, string p){
    int M = (p).size();
    int N = (t).size();
 
    int TF[M+1][NO_OF_CHARS];
 
    computeTF(p, M, TF);
 
    int i, state=0;
    for (i = 0; i < N; i++){
        state = TF[state][t[i]];
        if (state == M)
            cout << "Pattern found at index " <<  i-M+1 << endl;
    }
}
 
int main(){
    string t = "aabcdbbdadacc";
    string p = "adac";

    FiniteAutomaton(t, p);

    return 0;
}
//
// Output:
// Pattern found at index 8