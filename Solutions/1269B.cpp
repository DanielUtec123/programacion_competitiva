#include <bits/stdc++.h>

using namespace std;

multiset<long long> a;
multiset<long long> b;

set<long long> posible;

int n;
long long m;

bool compare(multiset<long long> s1, multiset<long long> s2){

    int n = s1.size();

    auto it1 = s1.begin();
    auto it2 = s2.begin();

    bool ans = true;
    for (int i = 0; i< n; i++){
        if (*it1 != *it2){
            ans = false;
        }
        it1 ++;
        it2 ++;
    }

    return ans;
}



int main(){

    cin >> n >> m;

    for (int i = 0; i < n; i++){
        long long a_i;
        cin >> a_i ;
        a.insert(a_i);
    }

    long long b_0;

    for (int i = 0; i < n; i++){


        long long b_i;
        cin >> b_i ;
        if(i ==0) b_0 = b_i;

        b.insert(b_i);
    }

    for (long long  a_i: a){
        long long diff = (b_0 - a_i)%m;
        posible.insert( (diff + m )%m);
    }

    long long ans ;

    bool r = false;
    for (long long val: posible){
        multiset<long long> new_set;
        
        for (long long a_i: a){
            new_set.insert( (a_i + val)%m);    
        }

        if (compare(b,new_set)){
                r = true;
                ans = val;
                break;
        }
    }  



    cout << ans; 


    return 0;
}