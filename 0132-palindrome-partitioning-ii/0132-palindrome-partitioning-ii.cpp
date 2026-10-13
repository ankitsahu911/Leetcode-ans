#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n);
        iota(dp.begin(), dp.end(), 0);

        for (int mid = 0; mid < n; mid++) {
            // Odd length palindromes
            int l = mid, r = mid;
            while (l >= 0 && r < n && s[l] == s[r]) {
                int new_cuts = (l == 0) ? 0 : dp[l - 1] + 1;
                dp[r] = min(dp[r], new_cuts);
                l--;
                r++;
            }

            // Even length palindromes
            l = mid;
            r = mid + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                int new_cuts = (l == 0) ? 0 : dp[l - 1] + 1;
                dp[r] = min(dp[r], new_cuts);
                l--;
                r++;
            }
        }

        return dp[n - 1];
    }
};