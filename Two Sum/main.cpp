#include <vector>
#include <iterator>
#include <iostream>
#include <unordered_map>
#include <tuple>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> numExist;
    int index=0;
    for (auto it=nums.begin();it!=nums.end();++it)
    {
        auto pos=numExist.find(target-*it);
        if (pos!=numExist.end())
        {
            return {pos->second,index};
        }
        numExist[*it]=index;
        index++;
    }
    return {-1};
}

int main(int argc, char const *argv[])
{
    vector<int> tmp={2,7,11,15};
    auto vec=twoSum(tmp,9);
    for (auto x:vec)
    {
        cout<<x<<" ";
    }
    return 0;
}
