class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        int i = 0, j = 0;
        vector<int > v;
        list<int>l;
        while(j < a.size())
        {
            while(l.back() < a[j] && l.size()> 0)
            {
                l.pop_back();
            }
            l.push_back(a[j]);
            if(j -i +1 < k)
            {
                j++;
            }
            else if(j-i+1 == k)
            {
                // ans calculation
                v.push_back(l.front());
                // slide window
                if(a[i] == l.front())
                {
                    l.pop_front();
                }
               i++;j++;
            }
        }
        return v;
    }
};
