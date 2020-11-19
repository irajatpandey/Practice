#include<bits/stdc++.h>
using namespace std;

void printNQueen(int **chess, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            chess[i][j] = 1;
            printNQueen(chess, r)

        }
    }
}
int main(){
    cout << "Enter the length of the chess board\n";
    int n; cin >> n;
    int **chess = new int*[n];
    for(int i = 0; i < n; i++){
        chess[i] = new int[n];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
                chess[i][j] = 0;
        }
     }
    printNQueen(chess, n);

    return 0;
}