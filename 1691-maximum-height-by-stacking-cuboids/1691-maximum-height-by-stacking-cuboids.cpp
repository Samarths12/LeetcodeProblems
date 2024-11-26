class Solution {
public:
    //ye fucntion ye btayega ki kya current wale cuboid ko prev wale k upar rkh skte h ya nahi 
    bool check(vector<int>& curr, vector<int>& prev) {
        //curr->bada wala dabba
        //prev->chote wala dabba
        if(prev[0] <= curr[0] && prev[1] <= curr[1] && prev[2] <= curr[2]) {
            return true;
        }
        else {
            return false;
        }
    }

    int solveusingSpaceOpt(vector<vector<int> >& cuboids) {
        // vector<vector<int> > dp(nums.size()+1, vector<int>(nums.size()+1, 0));

        vector<int> currRow(cuboids.size()+1, 0);
        vector<int> nextRow(cuboids.size()+1, 0);

       //analyze base case krke poore array ko hi 0 krdia
       for(int curr_index = cuboids.size()-1; curr_index>=0; curr_index--) {
        for(int prev_index = curr_index-1; prev_index>=-1; prev_index--) {

            //include
        int include = 0;
        if(prev_index == -1 || check(cuboids[curr_index], cuboids[prev_index])) {
            int heightToAdd = cuboids[curr_index][2];
            include = heightToAdd + nextRow[curr_index+1];
        }

        //exclude
        int exclude = 0 + nextRow[prev_index+1];

        int ans = max(include, exclude);
        currRow[prev_index+1] = ans;
       

        }
        nextRow = currRow;
       }
       return nextRow[0];
    }


    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &cuboid : cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }
        sort(cuboids.begin(), cuboids.end());

        return solveusingSpaceOpt(cuboids);
    }
};