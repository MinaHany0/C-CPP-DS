int dp[46] = {0,1,2,3};
class Solution {
public:
    int climbStairs(int n) {

        //SOLUTION 1
        // if(n < 4) return n;

        // if(!dp[n])
        // {
        //     if(!dp[n-1])
        //         dp[n-1] = climbStairs(n-1);

        //     if(!dp[n-2])
        //         dp[n-2] = climbStairs(n-2);

        //     dp[n] = dp[n-1] + dp[n-2];
            
        // }
        // return dp[n]; 


        //SOLUTION 2 as it actually was just a fibonacci series
        int one = 1;
        int two = 2;
        int temp;

        if(n <= 3) return n;
        else
        {
            int var = 2;
            while(var !=n)
            {
                temp = one + two;
                one = two;
                two = temp;
                var++;
            }
            return two;
        }
    }
};

