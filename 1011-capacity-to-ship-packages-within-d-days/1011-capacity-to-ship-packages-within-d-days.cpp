class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
      int n = weights.size();
      int sum = 0;
      int mx = 0;
      int ans = 0;
      for(int i=0;i<n;i++){
        sum += weights[i];
        mx = max(weights[i],mx);
      } 
      int low = mx;
      int high = sum;
       while(low<=high){
        int mid = (low+high)/2;
        int lod = 0,day = 1;
        for(int j=0;j<n;j++){
            if(lod+weights[j] > mid){
                day += 1;
                lod = weights[j];
            }
            else{
                lod += weights[j];
            }
        }
        if(day <= days){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
       } 
       return ans;
    }
};