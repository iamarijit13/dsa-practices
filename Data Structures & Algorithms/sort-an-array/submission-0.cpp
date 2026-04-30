class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;

        int mid = (l + r) / 2;

        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }

    void merge(vector<int>& nums, int l, int m, int r) {
        vector<int> temp;
        int i = l, j = m + 1;

        while (i <= m && j <= r) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }

        while (i <= m) temp.push_back(nums[i++]);
        while (j <= r) temp.push_back(nums[j++]);

        // Copy back to original array
        for (int k = 0; k < temp.size(); k++) {
            nums[l + k] = temp[k];
        }
    }
};