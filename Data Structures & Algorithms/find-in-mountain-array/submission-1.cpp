class Solution {
public:
    
    int binarySearch(MountainArray &arr, int l, int r, int target, bool asc) {
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            int val = arr.get(mid);

            if(val == target)
                return mid;

            if(asc) {
                if(val < target)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            else {
                if(val > target)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }

        return -1;
    }

    int findInMountainArray(int target, MountainArray &arr) {

        int n = arr.length();

        int l = 0, r = n - 1;

        while(l < r) {
            int mid = l + (r - l) / 2;

            if(arr.get(mid) < arr.get(mid + 1))
                l = mid + 1;
            else
                r = mid;
        }

        int peak = l;

        int left = binarySearch(arr, 0, peak, target, true);

        if(left != -1)
            return left;

        return binarySearch(arr, peak + 1, n - 1, target, false);
    }
};