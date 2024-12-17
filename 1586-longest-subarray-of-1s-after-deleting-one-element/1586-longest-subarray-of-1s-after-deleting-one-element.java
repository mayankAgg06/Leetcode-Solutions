class Solution {
    public int longestSubarray(int[] nums) {
        int midZero = -1;
        int i = 0;
        int j = 0;
        int ans = 0;
        int n = nums.length; // Use nums.length for arrays

        while (j < n) {
            if (nums[j] == 0) { // Access elements directly for arrays
                ans = Math.max(ans, j - i - 1);
                i = midZero + 1;
                midZero = j;
            }
            j++;
        }
        ans = Math.max(ans, j - i - 1);

        return ans;
    }
}