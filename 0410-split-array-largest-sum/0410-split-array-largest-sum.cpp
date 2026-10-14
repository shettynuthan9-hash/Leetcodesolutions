class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int cnt = 0;
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid = (low+high)/2;
            int sum = 0;
            int cnt = 1;
            for(int i=0;i<n;i++){
               if(nums[i]+sum <= mid){
                sum += nums[i];
               }
               else{
                cnt++;
                sum = nums[i];
               }    
            }

            if(cnt<=k){
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return low;
    }
};