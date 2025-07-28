#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n); int k = 0;
    for (int i = 0; i < n-1; i++)
    {
        cin >> v[i];
        k+=v[i];
    }
    int ans = n * (n + 1) / 2;
    cout<<ans-k<<endl;
}
