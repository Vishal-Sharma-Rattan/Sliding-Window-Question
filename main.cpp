/*
First negative integer in every window of size k

link :https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
*/

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int k) {
    long long i = 0;
    long long j = 0;
    vector<long long> v;
    queue<long long>q;
    while(j < N)
    {
        if(A[j] < 0)
        {
            q.push(A[j]);
        }
        if(j-i+1 < k)
        {
            j++;
        }
        else if(j-i+1 == k)
        {
            if(q.size() == 0)
            {
                v.push_back(0);
            }
            else
            {
                v.push_back(q.front());
            }
            /*
            if(A[i] == q.front())
            {
                q.pop();
            }*/
            if(A[i] < 0)
            {
                q.pop();
            }
            i++;
            j++;
        }
    }
    return v;
                                                 
 }