#include<bits/stdc++.h>
using namespace std;
#define sz 10

int main(){

		 float a[sz][sz], x[sz], rasio;
		 int i, j, k, n;

		 cout<<"Enter order of matrix: ";
		 cin>>n;

		 cout<<"Enter coefficients of Matrix:\n";
		 for(i=1;i<=n;i++)for(j=1;j<=n;j++) cin>>a[i][j];

		 /* Augmenting Identity Matrix of Order n */
		 for(i=1;i<=n;i++){
			  for(j=1;j<=n;j++){
				   if(i==j) a[i][j+n] = 1;
				   else a[i][j+n] = 0;
			  }
		 }

		 /* Applying Gauss Jordan Elimination */
		 for(i=1;i<=n;i++){
			  if(a[i][i] == 0.0){
				   cout<<"Mathematical Error!";
				   exit(0);
			  }
			  for(j=1;j<=n;j++){
				   if(i!=j){
					    rasio = a[j][i]/a[i][i];
					    for(k=1;k<=2*n;k++){
					     	a[j][k] = a[j][k] - rasio*a[i][k];
					    }
				   }
			  }
		 }

		 /* Row Operation to Make Principal Diagonal to 1 */
		 for(i=1;i<=n;i++) for(j=n+1;j<=2*n;j++) a[i][j] = a[i][j]/a[i][i];

		 /* Displaying Inverse Matrix */
		 cout<<"\nInverse Matrix is:\n";
		 for(i=1;i<=n;i++){
			  for(j=n+1;j<=2*n;j++){
                printf("%0.3f\t",a[i][j]);
			  }
			  cout<<"\n";
		 }
}












