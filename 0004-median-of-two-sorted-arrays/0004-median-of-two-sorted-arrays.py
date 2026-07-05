class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
            
        m, n = len(nums1), len(nums2)
        low, high = 0, m
        total_left = (m + n + 1) // 2

        while low <= high:
            partition_x = (low + high) // 2
            partition_y = total_left - partition_x

            max_left_x = float('-inf') if partition_x == 0 else nums1[partition_x - 1]
            min_right_x = float('inf') if partition_x == m else nums1[partition_x]

            max_left_y = float('-inf') if partition_y == 0 else nums2[partition_y - 1]
            min_right_y = float('inf') if partition_y == n else nums2[partition_y]
            if max_left_x <= min_right_y and max_left_y <= min_right_x:
                if (m + n) % 2 == 1:
                    return float(max(max_left_x, max_left_y))
                else:
                    return (max(max_left_x, max_left_y) + min(min_right_x, min_right_y)) / 2.0

            elif max_left_x > min_right_y:
                high = partition_x - 1  
            else:
                low = partition_x + 1 
            
        return 0.0