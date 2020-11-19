#include <math.h>
#include<bits/stdc++.h>
using namespace std;

int c;
int n_root;

void express(int x, int p, int curr_num = 0)
{
    int power, i;
    
    for(i = curr_num + 1; i <= n_root; ++i)
    {   
        power = (int)pow(i, p);
        if(power < x) express(x - power, p, i);
        else break;
    }
    
    if(x == power) ++c;

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, i;
    
    t = 1;
    cin.ignore();
    for(i = 0; i < t; ++i)
    {
        int x, p;
        cin >> x >> p;
        
        c = 0;
        n_root = (int)pow(x, 1.0/p);
        
        express(x, p);
        
        cout << c << "\n";
    }

    return 0;
}