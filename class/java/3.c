for(i=0 ;i<n ;i++){
  for(j=0 ;j<i-1 ;i++){
    for(k=j ;k<i-1 ;k++){
      p[i][j]+=l[i][k]*p[k][j];
    }
    p[i][j]/=-l[i][i];
  }
 }
