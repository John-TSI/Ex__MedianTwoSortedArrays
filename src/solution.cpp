#include<algorithm>
#include"../inc/solution.hpp"


double Solution::findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
{
    // guarantee that smaller vector is first argument for convenience
    if(nums1.size() > nums2.size()){ return findMedianSortedArrays(nums2,nums1); }

    int totSize = nums1.size() + nums2.size();
    int partIdx1 = nums1.size()/2, partIdx2 = (int) (totSize + 1)/2 - partIdx1; // CHECK AGAIN
    
    while(true)
    {
        if(nums1[partIdx1-1] <= nums2[partIdx2] && nums2[partIdx2-1] <= nums1[partIdx1])
        {
            // partition successful, compute the median
            return (double) (totSize%2)  // true if totSize odd, false if even
            ? std::max(nums1[partIdx1-1], nums2[partIdx2-1])
            : (std::max(nums1[partIdx1-1], nums2[partIdx2-1]) + std::min(nums1[partIdx1], nums2[partIdx2]) )/2;
        }
        else
        {
            partIdx1 = (nums1[partIdx1-1] > nums2[partIdx2]) 
                // max value in LHS of partition of nums1 too large, shift partition index of nums1 to the left
            ?    (partIdx1-1)/2 // TEST, INT_MIN / INT_MAX
                // min value in RHS partition of nums1 too small, shift partition index of nums1 to the right
            :    (nums1.size() - (partIdx1+1))/2; // TEST
            partIdx2 = (int) (totSize + 1)/2 - partIdx1;
        }
    }
}