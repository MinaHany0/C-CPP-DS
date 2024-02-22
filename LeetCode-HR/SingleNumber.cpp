class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
            int arr[100000] = {0};
            int result = 0;
            for(int i : nums)
            {
                arr[i+50000]++;
                if(arr[i+50000] == 1)   result += i;
                if(arr[i+50000] == 2)   result -= i;
            }
            return result;
    }
};

//another solution
class Solution {
public:
    int singleNumber(vector<int>& nums) {
            int result = 0;
            for(int i : nums) result ^= i;
            return result;
    }
};

//another solution
class Solution {
public:
    int singleNumber(vector<int>& nums) {
            
        int result = accumulate(nums.begin(),nums.end(), 0, bit_xor<int>());
        return result;
    }
};