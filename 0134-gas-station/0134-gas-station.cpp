class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        //method 1 : front rear wala concept use krna hai

        //jis bhi index k liye start krre hai waha p front rear rkho
        // agar movement possible hai(gas-cost > =0) to rear++ else front = rear+1 and rear = front


        //Method 2 : 
        

        int deficit = 0;  //kitni gas kam pad gyi
        int balance = 0;  //kitni gas bacha hua hai 
        int start = 0;    //circuit kaha s start krre hai

        //Ab traverse krna hai

        for(int i = 0 ; i<gas.size() ; i++) {
            //balance = purani gas jo bachi hai + abhi kitni gas hai-cost
            balance += gas[i] - cost[i]; //positive bhi ho skta negatuve bhi

            if(balance < 0) {
                deficit += balance;
                //ab jaha pr fail hua uske agle index s shuru kro
                start = i+1;
                balance = 0; //shuruat m to gas hogi hi ni
            }

        }

        if(deficit + balance >= 0) {
            return start;
        }

        else{
            return -1;
        }
    }
};