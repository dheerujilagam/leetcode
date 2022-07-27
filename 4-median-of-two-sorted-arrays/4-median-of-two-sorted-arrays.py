class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        self.nums1=nums1
        self.nums2=nums2
        n=nums1+nums2
        n.sort()
        if len(n)%2==0:
                m=(n[len(n)//2]+n[len(n)//2-1])/2
        else:
            m=n[len(n)//2]
        return m   
            