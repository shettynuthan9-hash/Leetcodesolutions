class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
      int n = weights.size();
      int ans  = 0;
      int low = *max_element(weights.begin(),weights.end());
      int high = accumulate(weights.begin(),weights.end(),0);

      while(low<=high){
        int mid = (low+high)/2;
        int lod = 0;int day = 1;
        for(int i=0;i<n;i++){
            if(lod+weights[i] > mid){
                lod = weights[i];
                day += 1;
            }
            else{
                lod += weights[i];
            }
        }
        if(day<=days){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid + 1;
        }
      }
      return ans;
    }
};