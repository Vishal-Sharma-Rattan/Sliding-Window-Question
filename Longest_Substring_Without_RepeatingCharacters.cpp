// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
// code:

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        int ans = 0;
        if (s.size() == 0) return 0;
        unordered_map<char,int>m;
        while(j < s.size())
        {
            m[s[j]]++;
            if(m.size() == j-i+1)
            {
                ans = max(ans,j-i+1);
                
            }
            else if(m.size() < j-i+1) /* map size will remain same 
            in case if duplicate enter in the map and 
            length of the substring is increased */
            {
                while(m.size() < j-i+1)
                {
                    m[s[i]]--;
                    if(m[s[i]] == 0)
                    {
                        m.erase(s[i]);
                    }
                    i++;
                    
                }
                
            }
            j++;
        }
        return ans;
    }
};
