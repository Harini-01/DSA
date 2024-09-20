class Solution {
public:

    void mergesort(vector<int>& nums, int low, int high)
    {
        int mid=low+(high-low)/2;
        if(low<high)
        {
            mergesort(nums,low,mid);
            mergesort(nums,mid+1,high);
            merge(nums,low,mid,high);
        }
        return;
    }

    void merge(vector<int>& nums,int low,int mid,int high)
    {
        vector<int> temp;
        int left=low;
        int right=mid+1;

        while(left<=mid&&right<=high)
        {
            if(nums[left]<=nums[right])
            {
                temp.push_back(nums[left]);
                left++;
            }
            else
            {
                temp.push_back(nums[right]);
                right++;
            }
        }

        while(left<=mid)
        {
            temp.push_back(nums[left]);
            left++;
        }

        while(right<=high)
        {
            temp.push_back(nums[right]);
            right++;
        }

        for(int i=low;i<=high;i++)
        {
            nums[i]=temp[i-low];
        }
    }

    void sortColors(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        mergesort(nums,low,high);
        return;
    }

};