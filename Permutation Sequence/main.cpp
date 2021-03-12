#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;
int fact(int n)
{
    int p = 1;
    while (n > 1)
    {
        p *= n--;
    }
    return p;
}
int getFromSet(const set<int> &s, int index)
{
    auto begin = s.begin();
    auto end = s.end();
    int i = 0;
    while (begin != end)
    {
        if (i == index)
        {
            return *begin;
        }
        begin++;
        i++;
    }
    return -1;
}
string getPermutation(int n, int k)
{
    string permSol = "";
    set<int> s;
    for (int i = 1; i <= n; i++)
    {
        s.insert(i);
    }
    int permLength = n;
    int permK = k - 1;
    while (s.size() > 1)
    {
        int numPerm = fact(--permLength);
        int q = permK / numPerm;
        int r = permK % numPerm;
        int val = getFromSet(s, q);
        s.erase(val);
        permK = r;
        permSol += to_string(val);
    }
    permSol += to_string(*s.begin());
    return permSol;
}
int main()
{
    int n, k;
    cin >> n >> k;
    cout << getPermutation(n, k) << endl;
    return 0;
}