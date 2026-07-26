class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findBound(nums, target, true), findBound(nums, target, false)};
    }

private:
    int findBound(vector<int>& nums, int target, bool isFirst) {
        int low = 0;
        int high = nums.size() - 1;
        int bound = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                bound = mid;
                if (isFirst) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return bound;
    }
};