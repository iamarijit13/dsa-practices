class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1.size() < nums2.size() ? nums1 : nums2;
        vector<int>& B = nums1.size() < nums2.size() ? nums2 : nums1;
        int total = A.size() + B.size();
        int half = total / 2;
        int l = 0, r = A.size();

        while (l <= r) {
            int i = (l + r) / 2;
            int j = half - i;

            int leftA = (i == 0) ? INT_MIN : A[i - 1];
            int rightA = (i == A.size()) ? INT_MAX : A[i];
            int leftB = (j == 0) ? INT_MIN : B[j - 1];
            int rightB = (j == B.size()) ? INT_MAX : B[j];

            if (leftA <= rightB && leftB <= rightA) {
                if (total % 2 == 0) {
                    return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
                } else {
                    return min(rightA, rightB);
                }
            } else if (leftA > rightB) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }

        return -1;
    }
};
