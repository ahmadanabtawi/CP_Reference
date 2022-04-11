//N : Number of nodes
//M : Log2 n

void Dfs(int u,int p,int d)
{
    dp[u][0]=p;
    depth[u]=d;
    for(int v : adj[u])
        if(v!=p)
            Dfs(v,u,d+1);
}

void Build()
{
    for(int j=1; j<M; j++)
        for(int i=1; i<=n; i++)
            dp[i][j]=dp[dp[i][j-1]][j-1];
}

int kth(int u,int k)
{
    if(k>depth[u])
        return 0;
    for(int i=M-1; i>=0; i--)
        if(k&(1<<i))
            u=dp[u][i];
    return u;
}

int Lca(int u,int v)
{
    if(depth[u]<depth[v])
        swap(u,v);
    int k=depth[u]-depth[v];
    u=kth(u,k);
    if(u==v)
        return u;
    for(int i=M-1; i>=0; i--)
    {
        int x=dp[u][i];
        int y=dp[v][i];
        if(x && y && x!=y)
        {
            u=x;
            v=y;
        }
    }
    return dp[u][0];
}

int Dist(int u,int v)
{
    return depth[u]+depth[v]-2*depth[Lca(u,v)];
}
