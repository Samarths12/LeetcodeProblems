class Solution {

    void removeOccurrence(string& s , string& part){

        int found = s.find(part);//stl function to find string "part"in string "s"
        if(found!= string::npos){
            //part string has been found in s
            //Remove the part string from s
            //to do that cut the string into left and right part

            string leftpart = s.substr(0 , found);//stl function which cuts string s starting from index 0 of length "found"
        

        string rightpart = s.substr(found+part.size() , s.size());

        //add the left and right part so that the specific part is deleted from the string

        s = leftpart+rightpart;

        //1 case hogya now recursion
        removeOccurrence(s , part);
        }

        else{
            //base case
            //All occurrences of part have been removed from string s
            return;
        }

    }
public:
    string removeOccurrences(string s, string part) {

        removeOccurrence(s , part);
        return s;
        
    }
};