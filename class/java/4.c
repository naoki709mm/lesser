for(i=n-1 ;i>=0 ;i--){
  p[i][i]=1/u[i][i];
  for(j=i+1 ;j<n ;j++){
    for(k=i+1 ;k<j k++){
      p[i][j]+=u[i][k]p[k][j];
    }
    p[i][j]/=-u[i][i];
  }
 } 
