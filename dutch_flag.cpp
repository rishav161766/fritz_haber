    #include<iostream>
    #include<vector>
    #include<algorithm>
    using namespace std;
    void sortColors(vector<int>& nums) {
        /*int noz=0,noo=0,notw=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) noz++;
            else if(nums[i]==1) noo++;
            else if(nums[i]==2) notw++;
        }
        for(int i=0;i<nums.size();i++){
            if(i<noz) nums[i]=0;
            else if(i<(noz+noo)) nums[i]=1;
            else nums[i]=2;
        }*/
        int n=nums.size();
        int low=0,mid=0,high=n-1;
        while(mid<=high){
            if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;
            }
           else if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;mid++;
            }
            else mid++;
        }
    }
