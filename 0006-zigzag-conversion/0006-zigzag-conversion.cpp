class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s; // Special case when there's only one row

    vector<string> ans(numRows); // Vector to store rows
    bool flag = false; // Direction flag: false for down, true for up
    int i = 0; // Index to track the current row

    for (auto ch : s) {
        ans[i] += ch; // Add the current character to the current row

        // Toggle flag when reaching the first or last row
        if (i == 0 || i == numRows - 1) {
            flag = !flag;
        }

        // Update index based on flag
        i += flag ? 1 : -1;
    }

    // Combine all rows to form the zigzag pattern
    string zigzag = "";
    for (auto str : ans) {
        zigzag += str;
    }

    return zigzag;
    }
};