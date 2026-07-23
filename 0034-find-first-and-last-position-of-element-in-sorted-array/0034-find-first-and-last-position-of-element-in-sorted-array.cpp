class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == target) {

                int left = mid;
                int right = mid;

                // Move left
                while (left - 1 >= 0 && nums[left - 1] == target) {
                    left--;
                }

                // Move right
                while (right + 1 < n && nums[right + 1] == target) {
                    right++;
                }

                return {left, right};
            }
            else if (nums[mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        // Target not found
        return {-1, -1};
    }
};