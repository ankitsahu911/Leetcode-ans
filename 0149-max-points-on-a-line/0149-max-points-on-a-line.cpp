class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        
        int max_pts = 0;
        
        for (int i = 0; i < n; ++i) {
            unordered_map<string, int> slope_count;
            int current_max = 0;
            
            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                
                int g = gcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;
                
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                } else if (dx == 0) {
                    dy = abs(dy);
                }
                
                string key = to_string(dx) + "_" + to_string(dy);
                slope_count[key]++;
                current_max = max(current_max, slope_count[key]);
            }
            
            max_pts = max(max_pts, current_max + 1);
        }
        
        return max_pts;
    }
};