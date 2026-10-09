class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int size = nums.size();
        if(size==0||size==1){
            return;
        }
        int nZero=0,zero=0;

        while(nZero<size){
            if(nums[nZero]!=0){
             int temp=nums[nZero];
             nums[nZero]=nums[zero];
             nums[zero]=temp;

             nZero++;
             zero++;
            }
            else{
                nZero++;
            }
            
            
        }
    }
};