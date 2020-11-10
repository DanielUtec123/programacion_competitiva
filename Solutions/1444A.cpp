

#include <bits/stdc++.h>

using namespace std;


long long gcd(long long a , long long b){

    if(b == 0) return a;
    return gcd(b,a%b);

}

set<long long> prime_factors(long long n){
    set<long long> f;
    for(int x = 2; x*x <=n; x++){
        while (n%x == 0)
        {
            f.insert(x);
            n /= x;
        }
    }
    if (n > 1) f.insert(n);
    return f;

}

long long factor_out(long long p, long long f){

    while (p%f ==0)
    {
        p /=f;
    }
    return p;
    
}

int get_exp(long long p, long long f){
    
    int exp = 0;
    while (p%f ==0)
    {
        p /=f;
        exp ++;
    }
    return exp;

}

long long solve(long long p, long long q){

    if(p < q) return p;

    long long d = gcd(p,q);

    //cout << "gcd " << d << endl;
    if (d == 1 or q/d > 1) return p;


    set<long long> f = prime_factors(d);

    long long maximo = 0;

    for (auto p_factor: f){
        int exp_p = get_exp(p,p_factor);
        int exp_q = get_exp(q,p_factor); 

        //cout << "fac " << p_factor << " p --> " << exp_p << " q --> " << exp_q << endl;       

        if(exp_p < exp_q) return p;

        long long posible = factor_out(p,p_factor);
        posible *= pow(p_factor,exp_q -1);
        if (posible > maximo) maximo = posible;

    }

    return maximo;
}   

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t ;
    cin >> t;

    while (t--)
    {
        long long p ,q;
        cin >> p >> q;
        cout << solve(p,q) << "\n";

    }
    

    return 0;
}