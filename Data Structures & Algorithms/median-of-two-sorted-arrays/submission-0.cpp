class Solution {
public:
    int rec(int l1,int l2,int k, vector<int>&nums1,vector<int>&nums2){
        int m=nums1.size();
        int n=nums2.size();
        if(l1>=m){
            return nums2[l2+k-1];
        }
        if(l2>=n){
            return nums1[l1+k-1];
        }
        if(k==1){
            return min(nums1[l1],nums2[l2]);
        }
        int m1=(l1+k/2 -1<m)?nums1[l1+k/2 -1 ]:INT_MAX;
        int m2=(l2+k/2 -1<n)?nums2[l2+k/2 -1 ]:INT_MAX;
        if(m1<m2){
            return rec(l1+k/2, l2, k-k/2,nums1,nums2);
        }else{
            return rec(l1, l2+k/2, k-k/2,nums1,nums2);
        }

    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int tot=m+n;
        if(tot%2!=0){
            return (double)rec(0,0,tot/2 +1,nums1,nums2);

        }
        double m1=rec(0,0,tot/2 +1,nums1,nums2);
        double m2=rec(0,0,(tot+1)/2,nums1,nums2);
        return (m1+m2)/2.0;
    }
};