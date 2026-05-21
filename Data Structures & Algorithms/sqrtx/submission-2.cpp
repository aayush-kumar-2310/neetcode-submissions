class Solution {
   public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;

        int l = 1, r = x;

        while (l <= r) {
            long long mid = l + (r - l) / 2;
            cout << mid << endl;
            if (mid * mid == x)
                return mid;
            else if (mid * mid > x)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return r;
    }
};