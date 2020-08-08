#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
  int n,k,temp=0,temp1=0,r,m=0,sum;
  cin>>n;
  cin>>k;
  int arr[n];
  int result[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  for(int i=0;i<n;i++)
  {
      result[i]=INT_MAX;
  }
  for(int i=n-1;i>=0;i--)
  {
    if(arr[i]%k==0)
    {
      continue;
    }
    else
    {   sum=0;
        temp1=temp1+(arr[i]%k);
        temp=temp+k-(arr[i]%k);
        for(int j=0;j<i;j++)
        {
            sum=sum+(arr[j]%k);
        }
        if(sum>=temp)
        {
            r=sum-temp;
        }
        else
        {
            r=temp1+sum;
        }
        result[m]=r;
        m++;
    }
  }
//  for(int i=0;i<n;i++)
  //{
    //  cout<<result[i]<<"    ";
  //}
  int * ans;
  ans=std::min_element(result+0,result+n);
  cout<<*ans<<endl;
  t--;
}
return 0;
}
