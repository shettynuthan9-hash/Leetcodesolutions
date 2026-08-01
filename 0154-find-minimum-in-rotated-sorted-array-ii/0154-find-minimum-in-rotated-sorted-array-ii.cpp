class Solution {
public:
    int findMin(vector<int>& nums) {
      int n = nums.size();
      int low = 0;
      int high = n-1;
      int ans = nums[0];
      while(low<=high){
        if(nums[low]<=nums[high]){
            ans = min(ans,nums[low]);
        }
        int mid = (low+high)/2;
        if(nums[low]==nums[mid] && nums[mid]==nums[high]){
            low = low+1;
            high = high-1;
            continue;
        }

        if(nums[low]<=nums[mid]){
            ans = min(ans,nums[low]);
            low = mid+1;
        }
        else {
            ans = min(ans,nums[mid]);
            high = mid-1;
        }
      }
      return ans;  
    }
};