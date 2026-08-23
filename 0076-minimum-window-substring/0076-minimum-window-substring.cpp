class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        vector<int> targetCount(128, 0);
        for (char c : t) {
            targetCount[c]++;
        }

        int remaining = t.length();
        int left = 0;
        int minLen = INT_MAX;
        int startIndex = 0;

        for (int right = 0; right < s.length(); ++right) {
            if (targetCount[s[right]] > 0) {
                remaining--;
            }
            targetCount[s[right]]--;

            while (remaining == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIndex = left;
                }

                targetCount[s[left]]++;
                if (targetCount[s[left]] > 0) {
                    remaining++;
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};