struct qu
    {
        int l,r,id;
        qu() {}
        bool operator<(const qu &R)
        {
            if(l/sq!=R.l/sq)
                return l<R.l;
            return r<R.r;
        }
    };
    sq=sqrt(m);
    for(int i=0; i<m; i++)
    {
        Q[i].id=i;
        cin>>Q[i].l>>Q[i].r;
    }
    sort(Q,Q+m);
    for(int i=0; i<m; i++)
    {
        while(R<Q[i].r)
            Add(++R,+1);
        while(R>Q[i].r)
            Add(R--,-1);
        while(L>Q[i].l)
            Add(--L,+1);
        while(L<Q[i].l)
            Add(L++,-1);
        ans[Q[i].id]=Ans;
    }
    for(int i=0; i<m; i++)
        cout<<ans[i]<<"\n";
