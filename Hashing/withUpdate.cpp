int mul(int x,int y,int mod)
{
    return (ll) x*y %mod;
}
int sum(int x,int y,int mod)
{
    return (x+y) %mod;
}
int sub(int x,int y,int mod)
{
    return sum((x-y)%mod,mod,mod);
}
int po(int x,int y,int mod)
{
    if(!y) return 1;
    if(y&1) return mul(x,po(x,y-1,mod),mod);
    int z=po(x,y/2,mod);
    return mul(z,z,mod);
}
int inv(int x,int mod)
{
    return po(x,mod-2,mod);
}
class Hash
{
public:
    int n,Base,Mod,Inv;
    vector <int> Po,iPo,Pre;
    Hash(string s,int N,int base,int mod)
    {
        n=N;
        Mod=mod;
        Base=base;
        Po.resize(n+1,1);
        iPo.resize(n+1,1);
        Pre.resize(5*n,0);
        Inv=inv(base,Mod);
        for(int i=1; i<=n; i++)
        {
            Po[i]=(mul(Base,Po[i-1],Mod));
            iPo[i]=(mul(Inv,iPo[i-1],Mod));
        }
        for(int i=1;i<=n;i++)
            Upd(i,s[i-1],1,1,n);
    }
    void Upd(int i,char c,int p,int L,int R)
    {
        if(L==R)
        {
            Pre[p]=mul(Po[i],c,Mod);
            return;
        }
        if(i<=Mid)
            Upd(i,c,2*p,L,Mid);
        else
            Upd(i,c,2*p+1,Mid+1,R);
        Pre[p]=sum(Pre[2*p],Pre[2*p+1],Mod);
        return;
    }
    int Get(int l,int r,int p,int L,int R)
    {
        if(l>R || r<L)
            return 0;
        if(l<=L && r>=R)
            return Pre[p];
        return sum(Get(l,r,2*p,L,Mid),Get(l,r,2*p+1,Mid+1,R),Mod);
    }
    int G(int L,int R)
    {
        // indexing : 1-->n
        int g=Get(L,R,1,1,n);
        return mul(iPo[L],g,Mod);
	// if you want to concatenate like (some string(x)+This) mult by Po[size of (x) or x-1 or x+1]
    }
};
