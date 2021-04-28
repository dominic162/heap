/*
    Given n sorted arrays , merge them;
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class triplet{
    public:
        int val,ind,elm_ind;
        triplet(int v, int in , int ein):val(v),ind(in),elm_ind(ein){
        }
};

class comp{
    public:

        bool operator()(const triplet &a , const triplet &b){
            return a.val > b.val; 
        }
};

vector<int> merge(vector<vector<int>> &vr , int n){

    vector<int> res;

    priority_queue< triplet ,vector< triplet > , comp >pq;
    
    for(int i = 0 ; i < n ; ++i){
        triplet t(vr[i][0] , i , 0);
        pq.push(t);
    }

    while(!pq.empty()){

        triplet t = pq.top();
        pq.pop();
        res.push_back(t.val);

        if(t.elm_ind != vr[t.ind].size()-1){
            triplet t1( vr[t.ind][t.elm_ind+1] , t.ind, t.elm_ind+1 );
            pq.push(t1);
        }
        

    }
    return res;
}

int main(){

    int n;
    cout<<"Enter no of array: ";
    cin>>n;
    vector<vector<int>> vr;

    for(int i = 0 ; i < n ; ++i){
        int temp;
        cout<<"Enter size of "<<i+1<<"array: ";
        cin>>temp;
        vector<int> v1(temp,0);
        cout<<"Enter elements: ";
        for(int i = 0 ; i < temp ; ++i){
            cin>>v1[i];
        }
        vr.push_back(v1);
    }

    vector<int> res = merge(vr,n);

    cout<<"Merged array is: ";
    for(int i = 0 ; i  < res.size() ; ++i){
        cout<<res[i]<<" ";
    }



    return 0;
}