// Count Occurences of Anagrams
//https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

class Solution{
public:
    int search(string pat, string txt) {
        // code here
    
        int ans = 0;
        int i = 0, j = 0;
        
        int k = pat.length();
        // pushing value of pattern string
       map <char, int> m;
          for(auto i: pat)
             m[i]++;
        // taking count of number of elements in map m
        int count = m.size();
        while(j < txt.length())
        {
            // 1 calculation if char is present in the the map decrease its count in the map
            if(m.find(txt[j]) != m.end())
            {
                m[txt[j]]--;
                // 2 if char 's value in map = 0 then decrease the count 
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
                    ans++;
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
        return ans;
    }
};
