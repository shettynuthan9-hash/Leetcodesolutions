class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        int n = nums.size();
        
        if(n%2 != 0){
            return false;
        }
        int i,j;
        int arr[100001]= {0};
        for(int i=0;i<n;i++)
        {
            arr[nums[i]] +=1;
            if(arr[nums[i]]>2)
            {
                return false;
            }
        }
   
       return true;
    }
};