/*
    Given a k sorted array , sort it;
*/

#include<iostream>
#include<queue>
using namespace std;

class solution{
    public:
        int* make_arr(int n);
        
        void sorted(int* arr , int n , int k);

        void disp_arr(int* arr , int n);
};

int main(){

    int n;
    cout<<"Enter no of elements: ";
    cin>>n;
    solution sl;

    cout<<"Enter array elements: ";
    int* arr = sl.make_arr(n);

    int k;
    cout<<"Enter value of k: ";
    cin>>k;

    sl.sorted(arr, n , k);
    cout<<"Sorted array is: ";
    sl.disp_arr(arr,n);

    return 0;
}

int* solution::make_arr(int n){
    int* arr = new int [n];
    
    for(int i = 0 ; i < n ; ++i){
        cin>>arr[i];
    }

    return arr;
}

void solution::sorted(int* arr , int n , int k){

    priority_queue < int , vector<int> , greater<int> > pq;

    int index = 0;

    for(int i = 0 ; i < k; ++i){
        pq.push(arr[i]);
    }

    for(int i = k ; i< n ;++i){
        pq.push(arr[i]);

        arr[index++] = pq.top();
        pq.pop();

    }

    while(!pq.empty()){

        arr[index++] = pq.top();
        pq.pop();

    }

    return ;
}

void solution::disp_arr(int* arr , int n ){
    for(int i = 0; i < n ;++i){
        cout<<arr[i]<<" ";
    }
    return ;
}