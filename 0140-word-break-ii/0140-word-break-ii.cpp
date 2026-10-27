class Solution {
    unordered_map<string, vector<string>> memo;

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return dfs(s, dict);
    }

private:
    vector<string> dfs(const string& s, const unordered_set<string>& dict) {
        if (memo.count(s)) return memo[s];
        if (s.empty()) return {""};

        vector<string> res;
        for (int len = 1; len <= s.length(); ++len) {
            string prefix = s.substr(0, len);
            if (dict.count(prefix)) {
                vector<string> subList = dfs(s.substr(len), dict);
                for (const string& sub : subList) {
                    res.push_back(prefix + (sub.empty() ? "" : " ") + sub);
                }
            }
        }

        return memo[s] = res;
    }
};