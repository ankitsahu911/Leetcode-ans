class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int n = s.length();
        if (n < 4 || n > 12) return res;

        auto isValid = [](const string& segment) {
            if (segment.empty() || segment.length() > 3) return false;
            if (segment.length() > 1 && segment[0] == '0') return false;
            int val = stoi(segment);
            return val >= 0 && val <= 255;
        };

        for (int i = 1; i <= 3 && i < n; ++i) {
            for (int j = 1; j <= 3 && i + j < n; ++j) {
                for (int k = 1; k <= 3 && i + j + k < n; ++k) {
                    string s1 = s.substr(0, i);
                    string s2 = s.substr(i, j);
                    string s3 = s.substr(i + j, k);
                    string s4 = s.substr(i + j + k);

                    if (isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4)) {
                        res.push_back(s1 + "." + s2 + "." + s3 + "." + s4);
                    }
                }
            }
        }

        return res;
    }
};