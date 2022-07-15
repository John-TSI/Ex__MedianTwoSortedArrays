#include<limits.h> // INT_MIN, INT_MAX
#include<algorithm> // std::min(), std::max()
#include"../inc/solution.hpp"


double Solution::findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
{
    // guarantee that smaller vector is first argument for convenience
    if(nums1.size() > nums2.size()){ return findMedianSortedArrays(nums2,nums1); }

    int totSize = nums1.size() + nums2.size();
    int partIdx1 = nums1.size()/2, partIdx2 = (int) (totSize + 1)/2 - partIdx1;
    int nums1Left{0}, nums1Right{0}, nums2Left{0}, nums2Right{0}; 
    
    while(true)
    {
        nums1Left = (partIdx1 == 0) ? INT_MIN : nums1[partIdx1-1];
        nums1Right = (partIdx1 == nums1.size()) ? INT_MAX : nums1[partIdx1];
        nums2Left = (partIdx2 == 0) ? INT_MIN : nums2[partIdx2-1];
        nums2Right = (partIdx2 == nums2.size()) ? INT_MAX : nums2[partIdx2];

        if(nums1Left <= nums2Right && nums2Left <= nums1Right)
        {
            // partition successful, compute the median
            double median{0};
            median = (totSize%2)  // true if totSize odd, false if even
            ? std::max(nums1Left, nums2Left)
            : (double) ( std::max(nums1Left, nums2Left) + std::min(nums1Right, nums2Right) )/2;
            return median;
        }
        else
        {
            (nums1Left > nums2Right) 
                // max value in LHS of partition of nums1 too large, shift partition index of nums1 to the left
            ?    --partIdx1
                // min value in RHS partition of nums1 too small, shift partition index of nums1 to the right
            :    ++partIdx1;
            partIdx2 = (int) (totSize + 1)/2 - partIdx1;
        }
    }
}