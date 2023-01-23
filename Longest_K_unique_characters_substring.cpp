// https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

int longestKSubstr(string s, int k) {
    int i =0, j = 0;
    int maximum = -1;
    unordered_map<char,int>m;
    while(j < s.size())
        {
            m[s[j]]++;
            if(m.size() < k){
                j++;
            }
            else if(m.size() == k)
            {
                maximum = max(maximum, j-i+1);
                j++;
                
            }
            else if(m.size() >k)
            {
                while(m.size() > k)
                {
                    m[s[i]]--;
                    if(m[s[i]] == 0)
                    {
                        m.erase(s[i]);
                    }
                    i++;
                }
                if(m.size() == k)
                {
                    maximum = max(maximum, j-i+1);
                  
                    
                }
                j++;
                
               
            }
            
            
        }
        return maximum;
    }
// or 
/* 
int longestKSubstr(string s, int k) {
    int i =0, j = 0;
    int maximum = -1;
    unordered_map<char,int>m;
    while(j < s.size())
        {
            m[s[j]]++;
            if(m.size() < k){
             
            }
            else if(m.size() == k)
            {
                maximum = max(maximum, j-i+1);

                
            }
            else if(m.size() >k)
            {
                while(m.size() > k)
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
        return maximum;
    }
*/
