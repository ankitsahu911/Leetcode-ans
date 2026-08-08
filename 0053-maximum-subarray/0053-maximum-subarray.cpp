class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSoFar = nums[0];
        int currentMax = nums[0];
        
        for (size_t i = 1; i < nums.size(); ++i) {
            currentMax = max(nums[i], currentMax + nums[i]);
            maxSoFar = max(maxSoFar, currentMax);
        }
        
        return maxSoFar;
    }
};