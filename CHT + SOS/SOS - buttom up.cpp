#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;  cin >> n;   /// the length of the array is (2 ^ n)

    vector <int> A(1 << n);

    for(int i = 0; i < (1 << n); i++)  scanf("%d", &A[i]);

    vector <int> SOS(1 << n);

    for(int Mask = 0; Mask < (1 << n); Mask++)  SOS[Mask] = A[Mask];

    for(int i = 0; i < n; i++)
        for(int Mask = 0; Mask < (1 << n); Mask++)
            if(Mask & (1 << i))
                SOS[Mask] += SOS[Mask ^ (1 << i)];

    /// Now SOS[Mask] is equal to the sum over subsets of 'Mask'

    int q;  cin >> q;

    while(q--)
    {
        int Mask;

        cin >> Mask;

        cout << SOS[Mask] << endl;
    }
}
