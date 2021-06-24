#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
    long long int n;
    long long int k;
    long long int sum=0;
    cin>>n;
    cin>>k;
    long long int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    long long int rem[n];
    long long int need[n];
    long long int result[n+1];
    for(long long int i=0;i<n;i++)
    {
        rem[i]=arr[i]%k;
        need[i]=k-rem[i];
    }
    for(long long int i=0;i<n;i++)
    {
        sum=sum+rem[i];
    }
    for(long long int i=0;i<n+1;i++)
    {
        result[i]=1000000000;
    }
    result[0]=sum;
    long long int tr=sum;
    long long int j=1;
    long long int tn=0;
    for(long long int i=n-1;i>=0;i--)
    {
        sum=sum-rem[i];
        tn=tn+need[i];
        if(sum>=tn)
        {
            result[j]=sum-tn;
            j++;
        }
        else
        {
            result[j]=tr;
            break;
        }
    }
    long long int * ans;
    ans=std::min_element(result+0,result+(n+1));
    
    cout<<*ans<<endl;
    t--;
}
    return 0;
}

