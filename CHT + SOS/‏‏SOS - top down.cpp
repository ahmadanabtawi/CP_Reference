#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int A[1 << N];
int Dp[1 << N][N];

int Rec(int Mask,int i = 0)
{
    if(i == N)  return A[Mask];

    if(Dp[Mask][i] != -1)   return Dp[Mask][i];

    int Res = Rec( Mask, i + 1);

    if(Mask & (1 << i)) Res += Rec( Mask ^ (1 << i), i + 1);

    return Dp[Mask][i] = Res;
}

int main()
{
    int n;  cin >> n;   /// the length of the array is (2 ^ n)

    for(int i = 0; i < (1 << n); i++)  scanf("%d", &A[i]);

    memset( Dp, -1, sizeof(Dp));

    /// Now Rec(Mask) is equal to the sum over subsets of 'Mask'

    int q;  cin >> q;

    while(q--)
    {
        int Mask;

        cin >> Mask;

        cout << Rec(Mask) << endl;
    }
}
