class Solution {
public:
    string removeDuplicates(string s) {

        //sare string k letter ko stack m push krte jao
        //jaha push krne wala letter aur stack k top ka letter same aaye to stack s pop krdo aur us letter ko push na kro
        //aisa krne k bad aakhri m jo stack m bache usko reverse krke print kro kyoki stack reverse krke output deta hai


        stack<char> st;

        for(auto ch:s){
            if(st.empty()){
                st.push(ch);
            }

            else if(!st.empty() && st.top() == ch){

                //pair banakr stack s pop krdo
                st.pop();
            }
            else{
                //mtlb stack k top p aur string k next char same ni h
                st.push(ch);
            }
                
            
        }

        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin() , ans.end());

        return ans;

        
    }
};