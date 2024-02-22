class Solution {
public:
    void moveZeroes(vector<int>& nums) {


        int *start = &nums[0];
        int *end   = &nums[0] +1;
        while(end <= &nums[0] + nums.size() -1 )
        {
            if(*start == 0)
            {
                while(*end == 0 && end < &nums[0] + nums.size() -1) {end++;}
                if( end == &nums[0] + nums.size() -1 && *end == 0) {break;}
                else
                {
                    *start = *end;
                    *end = 0;
                    start++;
                    end++;
                }
            }
            else
            {
                start++;
                if(start == end) end++;
            }
        }
    }
};

//another solution

class Solution {
public:
    void moveZeroes(vector<int>& nums) {


        int snowball= 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0) snowball++;
            else
            {
                int temp = nums[i];         //take care you cannot optimize this step
                nums[i] = 0;                //because if you have one element in your array and then you 
                nums[i-snowball] = temp;    //change value of element and then set zero the element gets erased
            }                               //but setting element later saves the element in case of one element array
        }
    }
};