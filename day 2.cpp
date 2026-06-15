// leetcode 8
//string to integer

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length();

        while (i < n && s[i] == ' ') {
            i++;
        }

        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        long long result = 0;

        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            if (sign * result > INT_MAX)
                return INT_MAX;
            if (sign * result < INT_MIN)
                return INT_MIN;

            i++;
        }

        return static_cast<int>(sign * result);
    }
};

//leetcode 1021
//Remove outermost parantheses

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int count = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')') count--;
            
            if (count != 0) ans.push_back(s[i]);

            if (s[i] == '(') count++;
        }

        return ans;
    }
};