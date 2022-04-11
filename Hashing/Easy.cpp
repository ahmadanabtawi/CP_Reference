int mul(int x,int y,int mod){
    return (ll) x*y %mod;
}
int sum(int x,int y,int mod){
    return (x+y) %mod;
}
int sub(int x,int y,int mod){
    return sum((x-y)%mod,mod,mod);
}
int po(int x,int y,int mod){
    if(!y) return 1;
    if(y&1) return mul(x,po(x,y-1,mod),mod);
    int z=po(x,y/2,mod);
    return mul(z,z,mod);
}
int inv(int x,int mod){
    return po(x,mod-2,mod);
}
struct Hash
{
    int n,Base,Mod,Inv;
    vector <int> Po,iPo,Pre;
    Hash(string &s,int base,int mod)
    {
        Mod=mod;
        Base=base;
        Po.pb(1);
        iPo.pb(1);
        Pre.pb(0);
        Inv=inv(base,Mod);
        for(int i=1; i<=s.size(); i++)
            Add(s[i-1]);
    }
    void Add(char c)
    {
        Po.pb(mul(Base,Po.back(),Mod));
        iPo.pb(mul(Inv,iPo.back(),Mod));
        Pre.pb(sum(Pre.back(),mul(c,Po.back(),Mod),Mod));
    }
    int G(int L,int R)
    {
        // indexing : 0-->n-1
        R++;
        int g=sub(Pre[R],Pre[L],Mod);
	//divide
        return mul(iPo[L+1],g,Mod);
	// if you want to concatenate like (some string(x)+This) mult by Po[size of (x) or x-1 or x+1]
    }
};
