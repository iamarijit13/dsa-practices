/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

// class Solution {
// public:
//     int findInMountainArray(int target, MountainArray &mountainArr) {
//         int n = mountainArr.length();
//         int l = 1, r = n - 1;
//         int peak = 0;

//         while (l <= r) {
//             int m = (l + r) / 2;

//             int left = mountainArr.get(m - 1), mid = mountainArr.get(m), right = mountainArr.get(m + 1);
//             if (left < mid && mid > right) {
//                 l = m + 1;
//             } else if (left > mid && mid > right) {
//                 r = m - 1;
//             } else {
//                 peak = m;
//                 break;
//             }
//         }

//         int leftSearch = binarySearch(0, peak, target, mountainArr);
//         if (leftSearch != -1) {
//             return leftSearch;
//         }

//         int rightSearch = binarySearch(peak + 1, n - 1, target, mountainArr);
//         if (rightSearch != -1) {
//             return leftSearch;
//         }

//         return -1;
//     }

//     int binarySearch(int l, int r, int target, MountainArray &a) {
//         while (l <= r) {
//             int m = (l + r) / 2;
//             int mid = a.get(m);
//             if (mid == target) {
//                 return m;
//             } else if (mid < target) {
//                 l = m + 1;
//             } else {
//                 r = m - 1;
//             }
//         }

//         return -1;
//     }
// };

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        // Find peak
        int l = 0, r = n - 1;

        while (l < r) {
            int m = l + (r - l) / 2;

            if (mountainArr.get(m) < mountainArr.get(m + 1)) {
                // Increasing slope
                l = m + 1;
            } else {
                // Decreasing slope
                r = m;
            }
        }

        int peak = l;

        // Search increasing part
        int leftSearch = binarySearch(
            0, peak, target, mountainArr, true
        );

        if (leftSearch != -1) {
            return leftSearch;
        }

        // Search decreasing part
        return binarySearch(
            peak + 1, n - 1, target, mountainArr, false
        );
    }

    int binarySearch(
        int l,
        int r,
        int target,
        MountainArray &a,
        bool ascending
    ) {
        while (l <= r) {
            int m = l + (r - l) / 2;
            int mid = a.get(m);

            if (mid == target) {
                return m;
            }

            if (ascending) {
                if (mid < target) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            } else {
                if (mid < target) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }

        return -1;
    }
};