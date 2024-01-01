class Solution {
public:
    // Function to check if pairs can be formed
    bool canPair(vector<int> nums, int k) {
        // If the number of elements is odd, cannot form pairs
        if(nums.size() % 2 != 0) return false;

        // Map to store remainder counts after division by k
        unordered_map<int, int> m;

        // Count the remainders after division by k
        for(int i = 0; i < nums.size(); i++) {
            m[nums[i] % k]++;
        }

        // Iterate through the array
        for(int i = 0; i < nums.size(); i++) {
            // If complement exists in the map
            if(m.find(k - (nums[i] % k)) != m.end()) {
                // If the count for the complement is 0, cannot form pairs
                if(m[k - (nums[i] % k)] == 0) return false;
                else m[k - (nums[i] % k)]--; // Decrement the count for the complement
            }
            // If the current number's remainder is 0
            else if(nums[i] % k == 0) {
                // If 0 is present in the map and its count is non-zero, decrement its count
                if(m.find(0) != m.end() && m[0] != 0) m[0]--;
            }
            // If no valid condition is met, cannot form pairs
            else return false;
        }
        // All pairs can be formed
        return true;
    }
};
