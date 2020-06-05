#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int mat[3][3], i, j;
    double determinant = 0;
    
    //input
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
           cin>>mat[i][j];    
    //finding determinant
    for(i = 0; i < 3; i++)
        determinant = determinant + (mat[0][i] * (mat[1][(i+1)%3] * mat[2][(i+2)%3] - mat[1][(i+2)%3] * mat[2][(i+1)%3]));
    
    cout<<"\n\nInverse of matrix is: \n";
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++)
            cout<<((mat[(j+1)%3][(i+1)%3] * mat[(j+2)%3][(i+2)%3]) - (mat[(j+1)%3][(i+2)%3] * mat[(j+2)%3][(i+1)%3]))/ determinant<<"\t";   
        cout<<"\n";
    }
 
   return 0;
}
