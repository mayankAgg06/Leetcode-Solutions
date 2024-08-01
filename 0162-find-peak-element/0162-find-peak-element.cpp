class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int e = nums.size()-1;
        int s = 0;
        
        while(s<e)
        {
            int m = s + (e-s)/2;

            if(nums[m]>nums[m+1]) e=m;

            else
            s=m+1;
        }

        return e;
    }
};
//         Intuition
// bhai O(log N) to samjh jane ka !!

// Approach
// same hi hai baaki sabhi solution se
// Certainly! In questions involving binary search or similar algorithms, there might be a common doubt regarding whether to return the variable s (left pointer) or e (right pointer) when the loop ends without finding the exact target element.

// In such cases, it's important to understand that both s and e will converge to the same position when the loop ends. The loop will terminate when s becomes greater than e, meaning the search space has been exhausted. At this point, s will be the first index where the condition inside the loop became false, and e will be the last index where the condition inside the loop became true.

// Since the target element is not present in the array, the final value of s or e will be the index where the target element should have been if it were present in the array. Hence, both s and e will point to the element that is just greater than the target (in case of a non-existent target).

// Therefore, in such scenarios, returning either s or e will yield the correct result, as they will be equal. There is no practical difference in returning one over the other since they will have the same value at the end of the loop.

// So, programmers can choose to return either s or e based on their preference or coding style. Both options are correct and will provide the same result.