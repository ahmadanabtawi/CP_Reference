int a[200200],n;
int root(int x){
    return pa[x]==x ? x : pa[x]=root(pa[x]);
}
ll Mst(vector <pii> v) // long long to first
{
    ll ans=0;
    sort(v.begin(),v.end());
    for(int i=1; i<=n; i++)
        pa[i]=i;
    for(pii xx : v)
    {
        int w=xx.F;
        int x=xx.S.F;
        int y=xx.S.S;
        x=root(x);
        y=root(y);
        if(x!=y)
        {
            pa[x]=y;
            ans+=w;
        }
    }
    return ans;
}
