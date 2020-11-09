
#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        int count = 0;
        int e = 0;
        for (int i = 1; i<= n; i++){
            
            if (s[n-i] == 'B'){
                e ++;
            }else{
                if(e>0){
                    e--;
                }else
                {
                    count ++;
                }          

            }
        }

        count = count + e%2;

        cout << count<< "\n";        


    }
    


}