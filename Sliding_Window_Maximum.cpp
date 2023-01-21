// code link:
//  https://leetcode.com/problems/sliding-window-maximum/description/


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
/*
// Approach 2 : using queue
#include<iostream>
#include<bits/stdc++.h>
#include "binaryTreeNode.h"
using namespace std;


vector<int> maxSlidingWindow(vector<int>& arr, int k) {
    deque<int>q;
        int i=0,j=0;
        vector<int>res;
        while(j<arr.size()){
            while(!q.empty() && q.back()<arr[j]) q.pop_back();
            q.push_back(arr[j]);
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                res.push_back(q.front());
                if(q.front()==arr[i]) q.pop_front();
                i++;
                j++;
            }
        }
        return res;
    
}
int main()
{
    vector<int>v;
    int n; cin >> n;
    for(int i = 0; i< n; i++ ){
        int t; cin >> t;
        v.push_back(t);
    }
    int k ; cin >> k;
    vector<int>v1 = maxSlidingWindow(v,k);
    for(auto i : v1)
    {
        cout << i <<" ";//[3,3,5,5,6,7]
    }
}
*/
