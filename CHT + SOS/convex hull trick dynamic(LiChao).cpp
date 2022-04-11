#include <bits/stdc++.h> /// Li Chao Dynamic segment tree - Convex Hull Trick
using namespace std;
typedef long long Type;
const Type MAXR = 1e9+5;
const Type MAXL = -MAXR;
const Type Inf = 1e18+5;
struct Line{
    Type a , b;  /// y = a*x + b
    Line(){}
    Line(Type a, Type b):a(a),b(b){}
    Type value(Type x){return a*x + b;}
};
struct node{
    Line line;
    node *left;
    node *right;
    node():line(),left(NULL),right(NULL){}
    node(Line &line):line(line),left(NULL),right(NULL){}
};

void update(Line line , node* &p , Type l = MAXL , Type r = MAXR)
{
    if(p == NULL){p = new node(line);return;} /// empty node
    Type mid = (l+r)>>1;

    bool L = p->line.value(l) > line.value(l);
    bool R = p->line.value(r) > line.value(r);
    bool M = p->line.value(mid) > line.value(mid);

    if(L == R) /// no intersection , get the better one!
    {
        if(L)   p->line = line;
        return;
    }

    if(M == R) /// intersection in the left part.
    {
        if(R)swap(p->line,line);
        update(line,p->left,l,mid);
    }
    else /// intersection in the right part.
    {
        if(L)swap(p->line,line);
        update(line,p->right,mid+1,r);
    }
}

Type query(Type x , node *p , Type l = MAXL , Type r = MAXR)
{
    if(p == NULL)return Inf;
    Type mid = (l+r)>>1;

    Type me = p->line.value(x);
    if(x <= mid) return min(me,query(x,p->left,l,mid));
    else return min(me,query(x,p->right,mid+1,r));
}

int main()
{
    Line A(2,1);
    Line B(-1,2);
    Line C(1,0);
    node *root = NULL;

    update(A,root);
    update(B,root);    update(C,root);
    int x;
    while(cin >> x)
    {
        cout << query(root,x) << '\n';
    }
    return 0;
}
