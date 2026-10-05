class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) {
            return 0;
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        if (dict.find(beginWord) != dict.end()) {
            dict.erase(beginWord);
        }

        while (!q.empty()) {
            auto [currentWord, steps] = q.front();
            q.pop();

            if (currentWord == endWord) {
                return steps;
            }

            for (int i = 0; i < currentWord.length(); ++i) {
                char originalChar = currentWord[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == originalChar) continue;

                    currentWord[i] = c;
                    if (dict.find(currentWord) != dict.end()) {
                        q.push({currentWord, steps + 1});
                        dict.erase(currentWord);
                    }
                }
                currentWord[i] = originalChar;
            }
        }

        return 0;
    }
};