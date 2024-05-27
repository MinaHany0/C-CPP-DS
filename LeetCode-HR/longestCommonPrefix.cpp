#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        /* var for holding length of common characters */
        int endCommonIndex = strs[0].length();

        /* iterate over all strings in vector */
        for( auto &i : strs)
        {
            endCommonIndex = (endCommonIndex > i.length()) ? i.length() : endCommonIndex ;
            /* iterate  */
            for(int j = 0; j < endCommonIndex; j++)
            {
                if( i[j] != strs[0][j])
                {
                    endCommonIndex = j;
                    break;
                }
            }
        }

        string result = "";
        result += strs[0].substr(0 , endCommonIndex);
        return result;
    }
};
int main()
{
    vector<string> vec{"abbbaaaaba" , "abbb","abbc","abvc"};
    Solution s;
    string s1 = s.longestCommonPrefix(vec);
    std::cout << s1;

    return 0;

}