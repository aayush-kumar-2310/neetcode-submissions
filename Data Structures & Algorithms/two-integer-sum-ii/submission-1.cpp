class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int a = 0, b = numbers.size() - 1;

        while (a < b) {
            int curr = numbers[a] + numbers[b];
            if (curr == target && a != b) return vector<int>{++a, ++b};
            if (curr > target)
                b--;
            else
                a++;
        }

        return {-1, -1};
    }
};
