#include<bits/stdc++.h>
using namespace std;
void display(int **chess, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << chess[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << endl;

}
void knightTour(int **chess, int n, int r, int c, int move){
    
    if(r < 0 || c < 0 || r >= n || c >= n || chess[r][c] != 0){
            return;
        } 
        else if(move == n * n){
            chess[r][c] = move;
            display(chess, n);
            chess[r][c] = 0;    
            return;
        }

    chess[r][c] = move;
    
    knightTour(chess, n, r - 2, c + 1, move + 1);
    knightTour(chess, n, r - 1, c + 2, move + 1);
    knightTour(chess, n, r + 1, c + 2, move + 1);
    knightTour(chess, n, r + 2, c + 1, move + 1);
    knightTour(chess, n, r + 2, c - 1, move + 1);
    knightTour(chess, n, r + 1, c - 2, move + 1);
    knightTour(chess, n, r - 1, c - 2, move + 1);
    knightTour(chess, n, r - 2, c - 1, move + 1);
    chess[r][c] = 0;

}
int main(){
    cout << "Enter the size of the chess Board\n";
    int n; cin >> n;
    int  **chess = new int*[n];
    for(int i = 0; i < n; i++){
        chess[i] = new int[n];
    }
    cout << "Enter the position of Knight\n";
    int r, c; cin >> r >> c;
     for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
                chess[i][j] = 0;
        }
     }
    display(chess, n);
    int move = 1; 
    knightTour(chess, n, r, c, move);
    



    return 0;
}