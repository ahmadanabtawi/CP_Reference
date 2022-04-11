/// Convex Hull Trick (CHT) <O(n)>
/// lines and query should be sorted in increasing order
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Line{    /// y = a*x + b
    ll a , b;
    Line(ll a, ll b):a(a),b(b){}
    ll value(ll x) {return a*x + b;}    // return y
    pair < ll , ll > cross(Line he) {return make_pair(he.b - b , a - he.a);}
    // return x of point of intersection between two lines as a pair
};

int main()
{
    int n;
    cin >> n;

    vector < Line > v;
    int start = 0;
    for(int i = 0 ; i < n ; i++)
    {
        int type;   cin >> type;
        if(type == 1) // add new line
        {
            int a , b;
            cin >> a >> b;

            Line line(a,b);
            while(start <= (int) v.size() - 2)
            {
                pair < ll , ll > one = line.cross(v.end()[-1]);
                pair < ll , ll > tow = v.end()[-1].cross(v.end()[-2]);
                if(one.first * tow.second >= tow.first * one.second)
                    v.pop_back();
                else break;
            }
            v.push_back(line);
        }
        else // query
        {
            int x;
            cin >> x;
            while(start <= (int) v.size() - 2)
            {
                if(v[start].value(x) >= v[start+1].value(x))
                    start++;
                else break;
            }

            cout << v[start].value(x) << '\n';
        }
    }
    return 0;
}
