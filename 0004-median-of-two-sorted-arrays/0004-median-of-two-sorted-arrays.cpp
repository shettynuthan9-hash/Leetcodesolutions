
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0;
        int j = 0;
        int cnt = 0;
        int ind1 = 0;
        int ind2 = 0;
        int n = n1 + n2;

        if (n == 0) return 0;

        while (n % 2 != 0) {
            int m = n / 2;

            if (i < n1 && (j >= n2 || nums1[i] <= nums2[j])) {
                cnt++;
                if (cnt == m + 1) {
                    return nums1[i];
                }
                i++;
            }
            else {
                cnt++;
                if (cnt == m + 1) {
                    return nums2[j];
                }
                j++;
            }
        }

        while (n % 2 == 0) {
            int m = n / 2;

            if (i < n1 && (j >= n2 || nums1[i] <= nums2[j])) {
                cnt++;

                if (cnt == m) {
                    ind1 = nums1[i];
                    i++;

                    if (i < n1 && (j >= n2 || nums1[i] <= nums2[j])) {
                        ind2 = nums1[i];
                    }
                    else {
                        ind2 = nums2[j];
                    }

                    return ((long long)ind1 + ind2) / 2.0;
                }

                i++;
            }
            else {
                cnt++;

                if (cnt == m) {
                    ind1 = nums2[j];
                    j++;

                    if (j < n2 && (i >= n1 || nums2[j] <= nums1[i])) {
                        ind2 = nums2[j];
                    }
                    else {
                        ind2 = nums1[i];
                    }

                    return ((long long)ind1 + ind2) / 2.0;
                }

                j++;
            }
        }

        return 0;
    }
};
