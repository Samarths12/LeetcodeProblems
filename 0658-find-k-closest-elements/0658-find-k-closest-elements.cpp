class Solution {
public:

int lowerbound(vector<int>& arr , int x) {
    int start = 0;
    int end = arr.size()-1;
    int ans = end;

    while(start <= end) {
        int mid = start + (end-start)/2;
        if(arr[mid] >= x) {
            ans = mid;
            end = mid-1;
        }

        else if(x > arr[mid]) {
            start = mid + 1;
        }

        else {
            end = mid - 1;
        }
    }

    return ans;
}

vector<int> bsMethod(vector<int>& arr, int k, int x) {
    //lower bound
    int h = lowerbound(arr, x);
    int l = h-1;
    while(k--) {
        if( l<0) {
            h++;
        }
        else if(h >= arr.size()) {
            l--;
        }
       else if(x - arr[l] > arr[h] - x) {
            h++;
        }
        else{
            l--;
        }
    }

    vector<int> ans;
    for(int i = l+1; i < h; i++) {
        ans.push_back(arr[i]);
    }

    return ans;

}
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //Method 2 : find closest element to x(which is x itself)
        //Uske bad wo no jis bhi index pr ho us index ko high maanlo
        //High -1 ko low mark krdo
        //Uske bad low and high k corresponding 1 window form krenge aur usko expand krenge k tak based on some conditions

        return bsMethod(arr, k , x);
    }
};