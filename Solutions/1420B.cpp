
#include <bits/stdc++.h>

using namespace std;

const int N = 32;


int P[N] = {0};
void clear(){

    for (int i = 0; i<N;i++){
        P[i] = 0;
    }
}

void add_max_pow(int a){

    int i = 1;
    int pos = 0;

    while (2*i <= a){
        i = i*2;
        pos ++;
    }

    P[pos] = P[pos] + 1;

}

long long comb(long long n){
    return n*(n-1)/2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        for(int i = 0; i < n; i++){
            int a_i;
            cin >> a_i;
            add_max_pow(a_i);
        }
        long long sum = 0;
        for (int i = 0; i< N;i++){
            sum += comb(P[i]);
        }

        cout << sum <<  "\n";

        clear();


    }
    


    return 0;
}