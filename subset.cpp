#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector< vector<int> > subsets(vector<int>& nums) {
        
        int S = nums.size();
        int N = 1 << S;
        vector< vector<int> > res;
        for (int i = 0; i < N; ++i) {
            vector<int> v;
            for (int j = 0; j < S; ++j)
            {
                if (i & (1 << j))
                {
                    cout << i << "," << j <<","<< nums[j]<<" ";
                    v.push_back(nums[j]);
                }
            }
                    cout << endl;
            res.push_back(v);
        }
        for(vector< vector<int> >::iterator i = res.begin(); i != res.end(); i++)
        {
            for(vector<int>::iterator j = i->begin(); j != i->end(); j++)
                cout << *j <<" ";
            cout << endl;
        }
        return res;


        
    }
};

int main()
{
    Solution s;
    vector<int> temp= {1,2,3};
    s.subsets(temp);
}


