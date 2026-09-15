class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int l = 0, r = 1, re = 1;
        string pre = "";

        while (r < arr.size()) {
            if (arr[r - 1] > arr[r] && pre != ">") {
                re = max(re, r - l + 1);
                pre = ">";
                r++;
            } else if (arr[r - 1] < arr[r] && pre != "<") {
                re = max(re, r - l + 1);
                pre = "<";
                r++;
            } else {
                r = arr[r] == arr[r - 1] ? r + 1 : r;
                l = r - 1;
                pre = "";
            }
        }
        return re;
    }
};