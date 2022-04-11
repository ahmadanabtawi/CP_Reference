typedef vector <double> Row ;
typedef vector <Row> Matrix ;
Matrix Const(int n,int m,ll val){
    return Matrix(n,Row(m,val));
}
Matrix Zero(int n,int m){
    return Matrix( n , Row(m,0) );
}
Matrix Identity(int n)
{
    Matrix Res = Zero(n,n);
    for(int i=0;i<n;i++)  Res[i][i] = 1;
    return Res;
}
Matrix Mul(const Matrix& A,const Matrix& B)
{
    assert(A[0].size()==B.size());
    Matrix Res = Const(A.size(),B[0].size(),0);
    for(int i=0; i<A.size(); i++)
        for(int j=0; j<B[0].size(); j++)
            for(int k=0; k<A[0].size(); k++)
                Res[i][j]+=(A[i][k]*B[k][j]);
    return Res;
}
Matrix Power(const Matrix& A,ll p)
{
    if(!p)      return Identity( A.size() );
    if(p==1)    return A;
    if(p&1)     return Mul(A,Power(A,p-1));
    return Power(Mul(A,A),p>>1);
}
void print(Matrix A)
{
    cout << "A:" << endl;
    for(int i=0; i<A.size(); i++)
    {
        for(int j=0; j<A[i].size(); j++)
        {
            cout << A[i][j] << " " ;
        }
        cout << endl;
    }
    cout << endl;
}
