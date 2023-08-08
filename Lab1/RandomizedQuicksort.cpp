#include <bits/stdc++.h>
using namespace std;

int comp = 0;

int part(int a[], int p, int r){
    int x = a[r];
    int i = p-1;
    int j;
    for(j = p; j < r; j++){
        if(a[j] <= x){
            i += 1;
            swap(a[i],a[j]);
        }
        comp++;
    }
    swap(a[i+1], a[r]);
    return (i+1);
}
int rpart(int a[], int p, int r){
    int rnd = (p + rand() % (r-p+1));
    swap(a[rnd],a[r]);
     
    return part(a,p,r);
}
void RQS(int a[], int p, int r){
    if(p < r){
        int q = rpart(a,p,r);
        RQS(a,p,q-1);
        RQS(a,q+1,r);
    }
}

int main() {
    
    srand(time(0));

    int n = 1000;
    int a[n];
    for(int i = 0; i < n; i++){
        a[i] =  i+1;    // for ascending order array
        //a[i] = n-i; // for descending order array
    }
    cout << "Original array" << endl;
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    
    RQS(a,0,n-1);
    
    cout << "After sort" << endl;
    cout << "Comparisons ::  " << comp << endl;
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }

    return 0;
}