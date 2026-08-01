class Solution {
public:
    bool isMatch(string s, string p) {
        int sIdx = 0, pIdx = 0;
        int matchIdx = -1, starIdx = -1;
        int sLen = s.length(), pLen = p.length();

        while (sIdx < sLen) {
            if (pIdx < pLen && (p[pIdx] == '?' || s[sIdx] == p[pIdx])) {
                sIdx++;
                pIdx++;
            } else if (pIdx < pLen && p[pIdx] == '*') {
                starIdx = pIdx;
                matchIdx = sIdx;
                pIdx++;
            } else if (starIdx != -1) {
                pIdx = starIdx + 1;
                matchIdx++;
                sIdx = matchIdx;
            } else {
                return false;
            }
        }

        while (pIdx < pLen && p[pIdx] == '*') {
            pIdx++;
        }

        return pIdx == pLen;
    }
};