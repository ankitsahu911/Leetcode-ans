class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, int start) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        unordered_set<int> seen;
        for (int i = start; i < nums.size(); ++i) {
            if (seen.count(nums[i])) continue;
            seen.insert(nums[i]);
            swap(nums[start], nums[i]);
            backtrack(nums, result, start + 1);
            swap(nums[start], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, result, 0);
        return result;
    }
};