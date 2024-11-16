class Solution {
public:
    int jump(vector<int>& nums) {
        
        int maxSoFar = 0;
        int currMax = 0;
        int jump = 0;
        
        for(int i = 0 ; i < nums.size()-1; i++) {
            maxSoFar = max(maxSoFar, i+nums[i]);
            
            if(i == currMax) {
                //Same hojaye to jump karo aage and update current maximum
                jump++;
                currMax = maxSoFar;
            }
        }
        return jump;
        
    }
};