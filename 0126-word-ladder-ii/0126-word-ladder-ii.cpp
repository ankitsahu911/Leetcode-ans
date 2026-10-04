class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return {};

        unordered_map<string, int> dist;
        queue<string> q;

        q.push(beginWord);
        dist[beginWord] = 0;

        int wordLen = beginWord.size();
        bool found = false;

        while (!q.empty() && !found) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                string curr = q.front();
                q.pop();

                int d = dist[curr];
                string temp = curr;

                for (int j = 0; j < wordLen; ++j) {
                    char orig = temp[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == orig) continue;
                        temp[j] = c;

                        if (dict.count(temp)) {
                            if (!dist.count(temp)) {
                                dist[temp] = d + 1;
                                if (temp == endWord) found = true;
                                q.push(temp);
                            }
                        }
                    }
                    temp[j] = orig;
                }
            }
        }

        vector<vector<string>> ans;
        if (!found) return ans;

        vector<string> path = {endWord};
        dfs(endWord, beginWord, dist, dict, wordLen, path, ans);
        return ans;
    }

private:
    void dfs(const string& curr, const string& beginWord,
             unordered_map<string, int>& dist, unordered_set<string>& dict,
             int wordLen, vector<string>& path, vector<vector<string>>& ans) {
        if (curr == beginWord) {
            vector<string> validPath = path;
            reverse(validPath.begin(), validPath.end());
            ans.push_back(validPath);
            return;
        }

        int targetDist = dist[curr] - 1;
        string temp = curr;

        for (int i = 0; i < wordLen; ++i) {
            char orig = temp[i];
            for (char c = 'a'; c <= 'z'; ++c) {
                if (c == orig) continue;
                temp[i] = c;

                auto it = dist.find(temp);
                if (it != dist.end() && it->second == targetDist) {
                    path.push_back(temp);
                    dfs(temp, beginWord, dist, dict, wordLen, path, ans);
                    path.pop_back();
                }
            }
            temp[i] = orig;
        }
    }
};