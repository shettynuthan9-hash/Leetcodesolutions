class Solution {
public:
    int cnt = 0;
    void merge(vector<int>&nums,int low,int mid,int high){
        int i = low,j = mid+1;
        vector<int>temp;
        while(i<=mid && j<=high){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i<=mid){temp.push_back(nums[i]);i++;}
        while(j<=high){temp.push_back(nums[j]);j++;}

        for(int k=low;k<=high;k++){
            nums[k] = temp[k-low];
        }

    }

    int getpairs(vector<int>&nums,int low,int mid,int high){
        int right = mid+1;
        for(int i=low;i<=mid;i++){
            while(right<=high && nums[i] > 2LL*nums[right])right++;
            cnt += (right - (mid+1));
        }
        return cnt;
    }

    void mergesort(vector<int>&nums,int low,int high){
        if(low>=high)return;
        int mid = (low+high)/2;
        mergesort(nums,low,mid);
        mergesort(nums,mid+1,high);
        getpairs(nums,low,mid,high);
        merge(nums,low,mid,high);
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        mergesort(nums,0,n-1);
        return cnt;
    }
};