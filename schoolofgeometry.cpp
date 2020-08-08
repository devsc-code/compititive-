#include<iostream>
using namespace std;
int smaller(int a,int b)
{
  if(a>=b)
  {
    return b;
  }
  else
  {
    return a;
  }
}
int main()
{
  int t;
  cin>>t;
  while(t!=0){
  int n;
  cin>>n;

  int a[n],b[n];

  for(int i=0;i<n;i++)
  {
    cin>>a[i];

  }
  for(int j=0;j<n;j++)
  {

    cin>>b[j];
  }
  int matrix[n][n];
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      matrix[i][j]=smaller(a[i],b[j]);
    }
  }
  int sum=0;
  int max[3][n];
  int row[n];
  int col[n],m,m1;
for(int x=0;x<n;x++)
{
  for(int i=0;i<n;i++)
  {
    m=INT_MIN;
    for(int j=0;j<n;j++)
    {
      if(m<matrix[i][j])
      {
        m=matrix[i][j];
        row[i]=i;
        col[i]=j;
      }
    }
      max[0][i]=m;
      max[1][i]=row[i];
      max[2][i]=col[i];
  }
  m1=INT_MIN;
  int r=0,c=0;
  for(int i=0;i<n;i++)
  {
    if(max[0][i]>m1)
    {
      m1=max[0][i];
      r=max[1][i];
      c=max[2][i];
    }
  }
  sum=sum+m1;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(i==r || j==c)
      matrix[i][j]=-1;
    }
  }
}
  cout<<endl<<sum;
  t--;
}
  return 0;
}
