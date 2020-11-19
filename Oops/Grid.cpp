#include <string.h>

#include <iostream>
using namespace std;

void take_input(int &n, int &m){
    cin >> n >> m;
}
int main() {
    int n, m;
    take_input(n, m);

    int a[n][m], 
    b[n][m],    // Left to right sum
    topToBottom[n + 1][m]; // Top to bottom sum
    memset(topToBottom, 0, sizeof(topToBottom));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            b[i][j] = topToBottom[i + 1][j] = a[i][j];
            topToBottom[i + 1][j] += topToBottom[i][j];     // Add sum of previous row
        }
        for (int j = m - 2; j >= 0; j--) {
            b[i][j] += b[i][j + 1];     // Add sum of previous column
        }
    }

    int output = -1;
    // We will try every possible way and see which one is maximum
    for (int i = m - 1; i >= 0; i--) {  // Start from the right
        for (int j = 0; j < n - 1; j++) {   // Top row
            for (int k = j + 1; k < n; k++) {   // Bottom row
                int temp = b[j][i] + b[k][i];
                if (k - j > 1) {
                    temp += topToBottom[k][i] - topToBottom[j+1][i];    // Vertical distance
                }                      
                output = max(temp, output);
            }
        }
    }
    cout << output << endl;
}