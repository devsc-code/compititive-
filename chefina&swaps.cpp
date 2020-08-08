#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int t;
    cin>>t;
    while(t--)
    {
        long int n;
        cin>>n;
        long int arr[n],brr[n];
        for(long int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        for(long int i=0;i<n;i++)
        {
            cin>>brr[i];
        }
        sort(arr,arr+n);
        sort(brr,brr+n);
        bool flag=0;
        for(long int i=0;i<n;i++)
        {
            if(arr[i]!=brr[i])
            {
                flag=1;
                break;
            }
        }
        long int crr[2*n];
        for(long int i=0;i<2*n;i++)
        {
            if(i<n)
            {
                crr[i]=arr[i];
            }
            else
            {
                crr[i]=brr[i-n];
            }
        }
        bool f=0;
        for(long int i=0;i<2*n;i++)
        {
            long int count=0;
            for(long int j=0;j<2*n;j++)
            {
                if(crr[i]==crr[j])
                {
                    count++;
                }
            }
            if(count%2!=0)
            {
                f=1;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"0"<<endl;
        }
        else if(f==1)
        {
            cout<<"-1"<<endl;
        }
        else
        {
            bool a[n],b[n];
            for(long int i=0;i<n;i++)
            {
                a[i]=0;
            }
            for(long int i=0;i<n;i++)
            {
                b[i]=0;
            }
            vector <long int> v1(1);
            //vector <long int> v2(1);
            for(long int i=0;i<n;i++)
            {
                long int l=0,r=0,p=0;
                if(a[i]==0)
                {
                for(long int j=0;j<n;j++)
                {
                        if(arr[i]==arr[j])
                        {
                            a[j]=1;
                            l++;
                        }
                }

                for(long int j=0;j<n;j++)
                {

                        if(arr[i]==brr[j])
                        {
                            r++;
                        }
                }
                if(l==r)
                {
                    continue;
                }
                else
                {
                    if(l>r)
                    {
                        p=(l-r)/2;
                    }
                    while(p!=0)
                    {
                        v1.push_back(arr[i]);
                        p--;
                    }
                }
                }

            }
            /////
            vector <long int> v2(1);
            for(long int i=n-1;i>=0;i--)
            {
                long int l=0,r=0,p=0;
                if(b[i]==0)
                {
                for(long int j=0;j<n;j++)
                {
                        if(brr[i]==jrr[j])
                        {
                            b[j]=1;
                            l++;
                        }
                }

                for(long int j=0;j<n;j++)
                {

                        if(brr[i]==arr[j])
                        {
                            r++;
                        }
                }
                if(l==r)
                {
                    continue;
                }
                else
                {
                    if(l>r)
                    {
                        p=(l-r)/2;
                    }
                    while(p!=0)
                    {
                        v2.push_back(arr[i]);
                        p--;
                    }
                }
                }

            }
            long int size=v1.size();
            long int c=0;
            for(long int i=0;i<size;i++)
            {
                if(v1[i]>v2[i])
                {
                    c=c+v2[i];
                }
                else
                {
                    c=c+v1[i];
                }
            }
            cout<<c<<endl;

        }
    }
    return 0;
}
