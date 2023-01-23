// https://leetcode.com/problems/minimum-window-substring/submissions/883921563/

class Solution {
public:
    string minWindow(string s, string t) {
        if(s == t)
        {
            return s;
        }
        if(t.size() > s.size())
        {
            return "";
        }
       
        int i = 0, j = 0;
        int ans_start_index = 0;
        int ans = INT_MAX;
        unordered_map<char,int>m;
       for(int i = 0; i<t.size(); i++ )
        {
            m[t[i]]++;
        }
        int count = m.size();
        while(j < s.length())
        {
            if(m.find(s[j]) != m.end())
            {
                m[s[j]]--;
                if(m[s[j]] == 0)
                {
                    count--;
                }
            }
            if(count == 0)
            {
                if(ans >  j-i+1)
                {
                    ans = j-i+1;
                    ans_start_index  =i; 
                }
                while(count == 0)
                {
                    if(m.find(s[i]) != m.end())
                    {
                        m[s[i]]++;
                        if(m[s[i]] == 1)
                        {
                            count++;
                        
                            if(ans >  j-i+1)
                            {
                                ans = j-i+1;
                                ans_start_index  =i; 
                            }
                        }
                        i++;
                    }
                    else
                    {
                        i++;
                    }
                    
                }    
            }
            j++;
        }
        string str = "";
        if(ans != INT_MAX)
        {
            return str.append(s.substr(ans_start_index,ans));
        }
        else return str;
    }
};
