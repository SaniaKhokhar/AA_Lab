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
         }       
         if(dmin > d){
            dmin = d;
            indi = i;
            indj = j;
         } 
    }
    cout << "Minimum distance is  between point P" << indi  << " and P"  << indj << endl;
    cout <<  "Minimum distance is " << dmin ;
}

int main(){
    Point P[3];
    P[0].x =2;
    P[0].y =2;
    P[1].x =4;
    P[1].y =4;
    P[2].x =6;
    P[2].y =6;
    minDistance(P);

    return 0;
}

//Output:
//Minimum distance is  between point P1 and P3
// Minimum distance is 2.82843