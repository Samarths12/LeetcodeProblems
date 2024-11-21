class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
//         vector<int> ans;
//         int product = 1;
//        for(int i = 0 ; i < nums.size() ; i++) {
//            product *= nums[i];
//        }
//         for(int i = 0 ; i < nums.size() ; i++) {
//            if(nums[i] != 0) ans.push_back(product/nums[i]);
            
//             else{
//                 ans.push_back(0);
//             }
//         }
        
//         return ans;
        
        
        
// Vector to store all left multiplication
    vector<int> left(nums.size());

    // Vector to store all right multiplication
    vector<int> right(nums.size());

    left[0] = 1;
    for (int i = 1; i < nums.size(); i++) {
        left[i] = left[i - 1] * nums[i - 1];
    }

    right[nums.size() - 1] = 1;
    for (int i = nums.size() - 2; i >= 0; i--) {
        right[i] = right[i + 1] * nums[i + 1];
    }

    vector<int> ans(nums.size());
    for (int i = 0; i < nums.size(); i++) {
        ans[i] = left[i] * right[i];
    }

    return ans;
        
    }
};