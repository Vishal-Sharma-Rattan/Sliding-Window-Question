/* 
    https://leetcode.com/problems/find-all-anagrams-in-a-string/
*/

class Solution {
public:
    vector<int> findAnagrams(string txt, string pat) {
        vector<int>v;
       
        int i = 0, j = 0;
        
        int k = pat.length();
        
       map <char, int> m;
          for(auto i: pat)
             m[i]++;
        
        int count = m.size();
        while(j < txt.length())
        {
           
            if(m.find(txt[j]) != m.end())
            {
                m[txt[j]]--;
                 
                if(m[txt[j]] == 0)
                {
                    count--;
                }
            }
            
            
            if(j-i+1 <k)
            {
                j++;
            }
            else if(j-i+1 == k)
            {
                if(count == 0)
                {
                    v.push_back(i);
                }
                // sliding the window 
                if(m.find(txt[i]) != m.end())
                {
                    m[txt[i]]++;
                    if(m[txt[i]] == 1)
                    {
                        count++;
                    }
                }
                i++; j++;
                
            }
        }
      return v;
    }
    
};
