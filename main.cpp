//In this program we are totating the image 90 degree 
//Given a 2D array and we have to rotate it by 90 degree
/* sample test case 
        4
        1 2 3 4
        5 6 7 8
        9 10 11 12 
        13 14 15 16
*/

#include<iostream>
#include<algorithm>
using namespace std;
void swap1(int *a, int *b){
    int temp = *a;
    *a =*b;
    *b=temp;
}


int main(){
    int arr[100][100];
    int n;
    cin>>n;

    //Taking the input of 2D array
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    //doing it without using stl library
    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            swap1(&arr[i][j],&arr[i][n-j-1]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    return 0;
}