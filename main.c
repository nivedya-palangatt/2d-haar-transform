/* this is an implementation of 2d haar transform 
   input is taken as a 8*8 matrix value 
   calculation is done by averaging and differencing.
  author: Nivedya P 
*/ 
/////////////////////////////////////////////////

#include <stdio.h>
#include <math.h>
void rowreduce (int mat[][8] , int);
void transpose_matrix(int[][8],int,int);
int main()
{
  int mat[8][8] ,mat2[8][8];
  int i, j, n ,z,l;
  z=8;

  printf("\nEnter the elements of the matrix : \n\n") ;
  for(i = 0 ; i < z ; i++)
   {
     for(j = 0 ; j < z ; j++)
        scanf("%d", &mat[i][j]) ;
   }
   printf("\n\nThe elements in the matrix are: \n\n") ;
  for(i = 0 ; i < z ; i++)
     {
     for(j = 0 ; j < z ; j++)
       {
         printf("%d", mat[i][j]) ;
         printf("\t");
        }
       printf("\n");
         
     }
     
    for(int m = 0 ; m < z ; m++)
   {  rowreduce ( mat,m);
   }
   
    transpose_matrix(mat,8,8);
     
    for(int m = 0 ; m < z ; m++)
   {  rowreduce ( mat,m);
   }
   
    transpose_matrix(mat,8,8);
     
  printf("\n\nwavelet transposed matrix \n\n") ;
  for(i = 0 ; i < z ; i++)
     {
     for(j = 0 ; j < z ; j++)
       {
         printf("%d", mat[i][j]) ;
         printf("\t");
        }
       printf("\n");
         
     }
     
}

void rowreduce(int mat[][8],int m)
{ int x[8],i,j,l,y[8];
   for(i=0;i<8;i++)
   { x[i] = mat[m][i];
   }
   
   int k = log2(8);
   int n=8;
  
  for(l=0;l<k;l++)
  {
    i=0;
    for(j=0;j<n/2;j++)                      
    {y[j]=(x[i]+x[i+1])/2;                  /////averaging
      i=i+2;
    }
     i=0;
    for(j=n/2;j<n;j++) 
    {y[j]=(x[i]-x[i+1])/2;                  /////differencing
      i=i+2;
    }
    
    n=n/2;
   for(i=0;i<8;i++)
   {
    x[i]=y[i];
   }
    
 for(i=0;i<8;i++)
   {
       mat[m][i]=x[i];                       /////writing back to original
   }
 }
}

void transpose_matrix(int mat[][8], int r, int c)
{
	int  trans[10][10],i,j;
    	for(i=0; i<r; ++i)
    		for(j=0; j<c; ++j)                             ////finding transpose
    		{
       			trans[j][i]=mat[i][j];
    		}
    	
    	for(i=0; i<r; ++i)
    		for(j=0; j<c; ++j)                   ////////////writing back to orignal matrix
    		{
       			mat[i][j]=trans[i][j];
    		}
	
}
