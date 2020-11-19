#include<bits/stdc++.h>

using namespace std;




bool used[4] = {false};

class LotteryTicket{


public:
    LotteryTicket(){
        
    };
    string buy(int price, int b1, int b2, int b3, int b4){
        vector<int> e = {b1,b2,b3,b4};

        if (price < 1 or price > 4000){
            return "IMPOSSIBLE";
        }

        if (buy_p(price, e, 0)){
            return "POSSIBLE";
        }else
        {
            return "IMPOSSIBLE";
        }
        

    }

    bool buy_p(int price, vector<int> &e, int d){
        if(price == 0){
            return true;
        }

        for (int i = 0; i< e.size(); i++){
            
            if(used[i]) continue;
            

            used[i] = true;
            if (e[i] == price ){
                return true;
            }
            if (buy_p(price - e[i], e, d+1)){
                return true;
            }
            used[i] = false;

         }
         return false;

    }


};


int main(){

    LotteryTicket l= LotteryTicket();
    
    int price, b1,b2,b3,b4;

    cin >> price >> b1 >> b2 >> b3 >> b4;

    cout << l.buy(price,b1,b2,b3,b4);
    

    return 0 ;
}