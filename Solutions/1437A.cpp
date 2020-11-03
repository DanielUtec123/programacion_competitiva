
#include<bits/stdc++.h>


using namespace std;

int T;


void solve(int l, int r){
    if (2*l > r){
        cout << "YES" << "\n";
    }else
    {
        cout << "NO" << "\n";
    }
    

}


int main(){
    cin >> T;

    for (int i = 0;i<T;i ++){
        int l, r;

        cin >> l >> r;

        solve(l,r);

    }




    return 0;
}