#include<bits/stdc++.h>
using namespace std;
#define ll long long
4
ll min(ll a,ll b)
{
	if(a>b)
		return b;
	else
		return a;
}
ll tree[200000],mn[200000];
 
ll n;
void build( ll arr[])  
{  
    for (ll i=0; i<n; i++)     
        {
            tree[n+i] = arr[i]; 
        	mn[n+i] = arr[i]; 
        }
    for (ll i = n - 1; i > 0; --i)      
        {
        	tree[i] = tree[i<<1] + tree[i<<1 | 1]; 
        	mn[i] = min(mn[i<<1],mn[i<<1 | 1]); 
        } 
 
} 
void update(ll p, ll value)  
{  
    tree[p+n] = value;
    mn[p+n] = value; 
    p = p+n; 
    for (long long i=p; i > 1; i >>= 1) 
       { tree[i>>1] = tree[i] + tree[i^1]; 
          mn[i>>1] = min(mn[i],mn[i^1]); 
       }
} 
ll query(ll l, ll r)  
{  
    ll res = 0,mn_=1e9+7; 
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) 
    { 
		
        if (l&1)  
           {
            res += tree[l++];
            l--;
            mn_=min(mn[l++],mn_);
            } 
        if (r&1)  
            {
            	res += tree[--r];
            	r++; 
            	mn_=min(mn[--r],mn_);
            }
    }   
    return res-mn_; 
} 
int  main()
{
   for(ll i=0;i<200000;i++)
mn[i]=1e9;  
	scanf("%lld",&n);
    ll a[n];
    for(ll i=0;i<n;i++)
    scanf("%lld",&a[i]);
    build(a);
    ll q;
    scanf("%lld",&q); 
    while(q--)
    {
    	char s[20];
    	scanf("%s",s);
    	if(s[0]=='C')
    	{
    		ll l,r;
    		scanf("%lld%lld",&l,&r);
    		printf("%lld\n",query(l,r+1));
    	}
    	else if(s[0]=='G')
    	{
    		ll l,r;
    		scanf("%lld%lld",&l,&r);
    		a[r]+=l;
    		update(r,a[r]);
    	}
    	else if(s[0]=='E')
    	{
    		ll l,r;
    		scanf("%lld%lld",&l,&r);
    		a[r]-=l;
    		update(r,a[r]);
    	}
    }
 
	return 0;
} 
