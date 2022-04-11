const int mod=1e9+7;
const int N = 200200;
int fa[N]; // Calculate fa
int mul(int x,int y){
    return (ll) x*y %mod;
}
int sum(int x,int y){
    if((x+=y)>=mod)
        x-=mod;
    return x;
}
int sub(int x,int y){
    if((x-=y)<0)
        x+=mod;
    return x;
}
int po(int x,int y){
    if(!y)  return 1;
    if(y&1) return mul(x,po(x,y-1));
    int z=po(x,y/2);
    return mul(z,z);
}
int inv(int x){
    return po(x,mod-2);
}
int C(int x,int y){
    if(y>x) return 0;
    return mul(mul(fa[x],inv(fa[y])),inv(fa[x-y]));
}
