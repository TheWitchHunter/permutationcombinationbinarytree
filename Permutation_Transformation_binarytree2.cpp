#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node
{
   int data;
   node* left;
   node* right;

   node(int val){
       data=val;
       left=NULL;
       right=NULL;
   }
};

ll searchmax(ll arr[],ll start,ll end){
    return max_element(arr+start,arr+end+1)-(arr);
}

node* BinaryTree(ll arr[],ll start ,ll end ,map<ll,ll>&mp,ll level){
    if(start>end){
        return NULL;
    }
    ll pos=searchmax(arr,start,end);
    mp[pos]=level; // assignnig the value of index to its depth
    node* n=new node(arr[pos]);
    if(start==end){
        return n;
    }
    n->left=BinaryTree(arr,start,pos-1,mp,level+1);
    n->right=BinaryTree(arr,pos+1,end,mp,level+1);

    return n;

}


int main(){
    ll t,x,n;
    
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        ll arr[n];
        map<ll,ll>mp;
        for(int j=0;j<n;j++){
            cin>>arr[j];
            x=arr[j];
            mp[j]=0; // forming a map which store the value of index
            
        }
        
        node* root=BinaryTree(arr,0,n-1,mp,0);
        for(auto k:mp){
            cout<<k.second<<" ";
        }
        cout<<endl;
        
    }
    
    return 0;
}