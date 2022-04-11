// n(log n)^2

map <int,int> my[N];
void add(int u,int color,int cnt)
{
    my[u][color]+=cnt;
    // Edit
}
void Merge(int u,int v)
{
    if(my[u].size() < my[v].size() )
    {
        swap(my[u],my[v]);
 	// Edit
    }
    for(auto mp : my[v]) //v
        add(u,mp.first,mp.second); //u
}
void Dfs(int u,int par)
{
    for(int v : adj[u])
    {
        if(v==par)  continue;
        Dfs(v,u);
        Merge(u,v);
    }
    // Answer Queries Here for u
}
