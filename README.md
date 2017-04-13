CODE
====

quest to code


int Solution::minCut(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.length()<2) return 0;
    vector<vector<int> > v(A.length(),vector<int>(A.length(),INT_MAX));
    for(int i=0;i<A.length();++i){
        v[i][i]=0;
    }
    for(int i=0;i<=A.length()-2;++i){
        if(A[i]==A[i+1]) v[i][i+1]=0;
        else v[i][i+1]=1;
    }
    
    for(int l=3;l<=A.length();++l){
        for(int i=0;i<=A.length()-l;++i){
            if((v[i+1][i+l-2]==0)&&(A[i]==A[i+l-1])) v[i][i+l-1]=0;
            for(int j=i;j<l+i-1;++j){
                v[i][i+l-1]=min(v[i][i+l-1],v[i][j]+v[j+1][i+l-1]+1);
            }
        }
    }
    
    return v[0][A.length()-1];
}


int Solution::numDistinct(string S, string T) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(T.length()>S.length()) return 0;
    if(T==S) return 1;
    vector<vector<int> > v(S.length()+1,vector<int>(T.length()+1,0));
    //if(S[0]==T[0])v[0][0]=1;
    //v[0][0]=1;
    for(int i=0;i<S.length();++i){
        v[i][0]=1;
    }
    for(int j=1;j<=T.length();++j){
        for(int i=j;i<=S.length();++i){
            if(S[i-1]==T[j-1]){
                v[i][j]=v[i-1][j-1];
            }
            v[i][j]=v[i][j]+v[i-1][j];
        }
    }
    
    return v[S.length()][T.length()];
}

