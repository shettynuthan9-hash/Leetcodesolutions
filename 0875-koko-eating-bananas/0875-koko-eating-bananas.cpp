class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       int n = piles.size();
       int low = 1;
       int high = *max_element(piles.begin(),piles.end());
       int ans = high;
       while(low<=high){
        int mid = (low+high)/2;
        double sum = 0;
        for(int i=0;i<n;i++){
          sum += ceil((double)piles[i]/mid);
        }
        if(sum<=h){
            ans = mid;
            high = mid-1;
           
        }
        else if(sum>h){
            low = mid+1;
        }
       }
       return ans;
    }
};