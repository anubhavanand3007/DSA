class Solution {
public:
     int sumOfUnique(vector<int>& nums) {
	 // freq array counts the number of times an element occurs in an array.
        int freq[101] = {0};
        int sum = 0,n = nums.size();
        for(int i = 0; i < n;i++)  
            freq[nums[i]]++;
        for(int i =0;i < n;i++){
            if(freq[nums[i]] == 1)
                sum += nums[i];
        }
        return sum;
    }
};