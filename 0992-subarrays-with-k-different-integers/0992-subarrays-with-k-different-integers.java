class Solution {
    public int solve(int[] nums, int k) {
        int i = 0, j = 0, res = 0;
        HashMap<Integer, Integer> freq = new HashMap<>();
        while (j < nums.length) {
            freq.put(nums[j], freq.getOrDefault(nums[j], 0) + 1);
            while (freq.size() > k) {
                freq.put(nums[i], freq.get(nums[i]) - 1);
                if (freq.get(nums[i]) == 0) {
                    freq.remove(nums[i]);
                }
                i++;
            }
            res += j - i + 1;
            j++;
        }
        return res;
    }
    public int subarraysWithKDistinct(int[] nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
}