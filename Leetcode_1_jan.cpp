// https://leetcode.com/problems/assign-cookies/ 

class Solution {
public:
    // Function to find the maximum number of content children that can be satisfied
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sorting the arrays of children's greed factor and available cookies' sizes
        sort(s.begin(), s.end()); // Sorting the cookie sizes in ascending order
        sort(g.begin(), g.end()); // Sorting the children's greed factors in ascending order

        int j = s.size() - 1; // Initialize the index for the last (largest) cookie size
        int count = 0; // Initialize the count of satisfied children

        // Iterate through the sorted arrays from the largest to smallest
        for(int i = g.size() - 1; i >= 0 && j >= 0; i--) {
            // If the greed factor of the current child can be satisfied by the available cookie size
            if(g[i] <= s[j]) {
                count++; // Increment the count of satisfied children
                j--; // Move to the next smaller cookie size
            }
        }
        return count; // Return the total count of satisfied children
    }
};
