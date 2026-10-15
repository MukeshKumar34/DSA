class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";

        string ans;
        while (sum > 0) {
            int d = min(9, sum);
            ans += char('0' + d);
            sum -= d;
        }
        ans += string(num - ans.size(), '0');
        return ans;
    }
};