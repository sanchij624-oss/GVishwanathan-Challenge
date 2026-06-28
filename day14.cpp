//Leetcode 6
//zigzag conversion

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size())
            return s;

        vector<string> rows(numRows);
        int currRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currRow] += c;

            if (currRow == 0 || currRow == numRows - 1)
                goingDown = !goingDown;

            currRow += goingDown ? 1 : -1;
        }

        string ans;
        for (string &row : rows)
            ans += row;

        return ans;
    }
};

//leetcode 32
//Longest Valid Parentheses
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);  // Base index

        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();

                if (st.empty()) {
                    st.push(i);
                } else {
                    ans = max(ans, i - st.top());
                }
            }
        }

        return ans;
    }
};