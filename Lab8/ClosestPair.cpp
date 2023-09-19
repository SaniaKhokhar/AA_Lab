#include <bits/stdc++.h>
using namespace std;

class Point{
public:
    int x;
    int y;
    Point(int x = 0, int y = 0){
        this->x = x;
        this->y = y;
    }
};

void minDistance(Point P[]){
    double d=0;
    double dmin = INT_MAX;
    int indi,indj, i, j;
    for( i = 0; i < 3; i++){
         for( j = i+1; j < 3; j++){
            d = sqrt(pow(P[i].x - P[j].x, 2) + pow(P[i].y - P[j].y,2)); 
            if(dmin > d){
                dmin = d;
                indi = i;
                indj = j;
            } 
         }       
         
    }
    cout << "Minimum distance is  between point P" << indi  << " and P"  << indj << endl;
    cout <<  "Minimum distance is " << dmin << endl;
}

int main(){int n;
    cout << "Enter number of points" << endl;
    cin >> n ;

    cout << "Enter points " << endl;
    Point P[n];
    for(int i = 0; i < n; i++){
        cin >> P[i].x >> P[i].y;
    }

    minDistance(P);

    return 0;
}

//Input:
//Enter number of points
// 3
// Enter points
// 2 4
// 1 2
// 5 9

//Output:
// Minimum distance is  between point P0 and P1
// Minimum distance is 2.23607