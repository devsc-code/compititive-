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
        map<int,int> ob;
        for(long int i=0;i<2*n;i++)
        {
            ob[crr[i]]++;
        }
        for(long int i=0;i<2*n;i++)
        {
            if(ob[crr[i]]%2!=0)
            {
                f=1;
                break;
            }
        }
        if(f==1)
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
            vector <long int> v1(0);
            //vector <long int> v2(1);
            
            map <int,int> ob1,ob2,ob3,ob4;
            for(long int i=0;i<n;i++)
            {
                ob1[arr[i]]++;
            }
            for(long int i=0;i<n;i++)
            {
                ob2[brr[i]]++;
            }
            
            for(long int i=0;i<n;i++)
            {
                long int p=0;
                if(i!=0 && arr[i]==arr[i-1])
                {
                    continue;
                }
                
                if(ob1[arr[i]]==ob2[arr[i]])
                {
                    continue;
                }
                else
                {
                    if(ob1[arr[i]]>ob2[arr[i]])
                    {
                        p=(ob1[arr[i]]-ob2[arr[i]])/2;
                         while(p!=0)
                        {
                            v1.push_back(arr[i]);
                            p--;
                        }
                    }
                }
            }
             vector <long int> v2(0);
            for(long int i=n-1;i>=0;i--)
            {
                long int p=0;
                if(i!=n-1 && brr[i]==brr[i+1])
                {
                    continue;
                }
                
                if(ob2[brr[i]]==ob1[brr[i]])
                {
                    continue;
                }
                else
                {
                    if(ob2[brr[i]]>ob1[brr[i]])
                    {
                        p=(ob2[brr[i]]-ob1[brr[i]])/2;
                         while(p!=0)
                        {
                            v2.push_back(brr[i]);
                            p--;
                        }
                    }
                }
            }
            long int size=v1.size();
            long int min;
            min=*min_element(crr,crr+(2*n));
            long int c=0;
            for(long int i=0;i<size;i++)
            {
                if(v1[i]>v2[i])
                {
                    if(2*min<v2[i])
                    {
                        c=c+(2*min);
                    }
                    else
                    {
                        c=c+v2[i];   
                    }
                }
                else
                {
                    if(2*min<v1[i])
                    {
                        c=c+(2*min);
                    }
                    else
                    {
                        c=c+v1[i];   
                    }
                }
            }
            cout<<c<<endl;

        }
    }
    return 0;
}
