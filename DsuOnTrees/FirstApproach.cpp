// n log n

const int N = 1e5 + 7;
vector <int> adj[N];
int n,tim,col[N],in[N],out[N],who[N],big[N],sz[N],cnt[N];

void Pre(int u,int p)
{
    sz[u]=1;
    in[u]=++tim;
    who[tim]=u;
    for(int v : adj[u])
        if(v!=p)
        {
            Pre(v,u);
            sz[u]+=sz[v];
            if(big[u]==-1 || sz[big[u]]<sz[v])
                big[u]=v;
        }
    out[u]=tim;
    return;
}

void Dfs(int u,int p,bool keep)
{
    for(int v : adj[u])
        if(v!=p && v!=big[u])
            Dfs(v,u,0); // with clear
    if(big[u]+1)
        Dfs(big[u],u,1); // without clear
    for(int v : adj[u])
        if(v!=p && v!=big[u])
            for(int T=in[v]; T<=out[v]; T++)
            {
		int w=who[T];
                cnt[col[w]]++;
                // 1 Edit
            }
    cnt[col[u]]++;
    // 2 Edit

    // answer Query of subtree u ; cnt [ i ] = count of color i in subtree u
    if(!keep)
    {
        for(int T=in[u]; T<=out[u]; T++)
            cnt[col[who[T]]]--;
        // 3 Edit
    }
    return;
}
// Enter The Colors and The Edges
// Memset big with -1
// Pre (1,-1)
// Then Dfs (1,-1,0)
