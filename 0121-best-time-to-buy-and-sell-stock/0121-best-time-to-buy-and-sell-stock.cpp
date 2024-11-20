class Solution {
public:


void maxprofitfinder(vector<int>& prices , int i , int& minprice , int& maxprofit){


    //base case
    if(i==prices.size()){
        return;
    }

    //1 case solve karo

    if(prices[i]<minprice){
        minprice = prices[i];
    }

    int todaysprofit = prices[i]-minprice;
    if(todaysprofit>maxprofit){
        maxprofit = prices[i]-minprice;
    }

    //Recursivee call

    maxprofitfinder(prices , i+1 , minprice , maxprofit);
}
    int maxProfit(vector<int>& prices) { 



        int maxprofit = INT_MIN;
        int minprice = INT_MAX;
        int i = 0;

        maxprofitfinder(prices , i , minprice , maxprofit );

        return maxprofit;


        

        
    }
};