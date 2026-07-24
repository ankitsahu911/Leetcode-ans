#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        int sLen = s.size();

        if (sLen < totalLen) return result;

        unordered_map<string, int> wordFreq;
        for (const string& word : words) {
            wordFreq[word]++;
        }
        for (int i = 0; i < wordLen; ++i) {
            int left = i;
            int right = i;
            unordered_map<string, int> currentFreq;
            int count = 0;

            while (right + wordLen <= sLen) {
                string sub = s.substr(right, wordLen);
                right += wordLen;

                if (wordFreq.count(sub)) {
                    currentFreq[sub]++;
                    count++;
                    while (currentFreq[sub] > wordFreq[sub]) {
                        string leftWord = s.substr(left, wordLen);
                        currentFreq[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    currentFreq.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};