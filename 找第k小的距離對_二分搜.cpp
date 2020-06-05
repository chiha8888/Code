//719. Find K-th Smallest Pair Distance

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        int lb=0;
        int ub=1000000+1;
        while(ub-lb>1){     //[  )	//...00000000111111111111....
            int mid=(ub+lb)/2;
            if(!C(mid,nums,k))
                lb=mid;
            else
                ub=mid;
        }
        return lb;
    }
    
    bool C(int mid,vector<int>& nums,int k){	//差距比mid小的個數是否 > k-1 
        int count=0;
        int p=0;
        for(int i=0;i<nums.size();i++){
            while(nums[i]-nums[p]>=mid)
                p++;
            count+=i-p;
        }
        return count>k-1;
    }
};
