ques--> Given N,X,Y,Z array containing n elements,    all are<=50
a[i] and a[i+1] can be merged to (a[i]*X + a[i+1]*Y + Z)%50  and cost is a[i]*a[i+1]
//idea can L,R  range be merged to some value XX;
  done[50][50]
  int rec(int l,int r,int xx){
    if(l==r){
      if(a[l]==xx) return 0; //no cost merging

      return 1e9;  //a[l] != xx, so impossible to form
    }
if(done[l][r]){
  return dp[l][r][xx];
}

//iterating over every single mid

for(int i=l;i<r;i++){
  for(int x=0;x<50;x++){ //left can merged to x
    for(int y=0;y<50;y++){ //right can be merged to y;
      dp[l][r][(x*X + y*Y+Z)%50] = min(dp[l][r][(x*X + y*Y+Z)%50] ,rec(l,i,x) + rec(i+1,r,y) + x*y);
    }
  }
}

done[l][r] =1;

return dp[l][r][xx];
}

rec(0,n-1,0);

int ans =1e9;
for(int i=0;i<50;i++){
  ans = min(ans,dp[0][n-1][i]);
}
