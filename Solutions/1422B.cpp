#include <bits/stdc++.h>

using namespace std;


long long M[100][100];
int n,m;

long long min_steps(long long a, long long b, long long c, long long d){

    multiset<long long> s;
    s.insert(a);
    s.insert(b);
    s.insert(c);
    s.insert(d);

    int i = 1;
    long long min_sum = 0;
    for (long long e: s){
        
        if (i <= 2){
            min_sum -= e;
        }else
        {
            min_sum += e;
        }
        
        i++;
    }
    return min_sum;

}


long long solve(){

    long long suma = 0;
    for (int i = 0; i < n/2; i++){
        for (int j = 0; j < m/2; j++){
            suma += min_steps(M[i][j], M[n - 1-i][j], M[i][m - 1- j], M[n-1-i][m-1-j]);
        }
    }

    if (n%2 == 1){
        for (int j = 0; j < m/2; j++){
            suma += abs(M[n/2][j] - M[n/2][m-1-j]);
        }
    }
    if (m%2 == 1){
        for (int i = 0; i < n/2; i++){
            suma += abs(M[i][m/2] - M[n-1-i][m/2]);
        }

    }

    return suma;

}

int main(){
    int t;
    cin >> t;

    while (t--)
    {
     
        cin >> n >> m;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                long long e;
                cin >> e;
                M[i][j] = e;
            }
        }

        cout << solve() << "\n";

    }
    


    return 0;
}