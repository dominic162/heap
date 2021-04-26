/*
    Given prices of element and a money k , find max no of elements you can buy from money equal to k; 
*/

#include<iostream>
using namespace std;

class solution{
    public:
        int no_of_items(int* arr , int n , int k);

        void build_heap(int* arr, int n);

        void heapify(int* arr, int n, int root);
};

int main(){

    int n;
    cout<<"Enter no of elements: ";
    cin>>n;
    
    int* arr = new int[n];
    cout<<"Enter elements: ";
    
    for(int i =0 ; i < n; ++i){
        cin>>arr[i];
    }

    int k;
    cout<<"Enter total money: ";
    cin>>k;

    solution sl;
    cout<<"Maximum element you can purchase with "<<k<<" money are "<<sl.no_of_items(arr, n ,k);

    return 0;
}

int solution::no_of_items(int* arr , int n ,int k){

    int* temp = new int[n];
    for(int i =0 ;i < n ; ++i){
        temp[i] = arr[i];
    }
    build_heap(temp,n);

    int count = 0;
    while(n > 0){

        if(temp[0] <= k){
            ++count;
            k-=temp[0];
            n-=1;
            temp[0] = temp[n];
            heapify(temp,n,0);
        }
        else{
            break;
        }
    }

    delete []temp;

    return count;

}

void solution::build_heap(int* arr , int n){

    for(int i = (n-1)/2 ; i>=0 ; i--){
        heapify(arr,n,i);
    }

}

void solution::heapify(int* arr , int n , int root){

    while(root != n-1){

        int larg = root,li,ri;

        li = 2*root + 1;
        ri = 2*root +2;

        if( li < n && arr[li] < arr[larg]){
            larg = li;
        }

        if(ri < n && arr[ri] < arr[larg]){
            larg = ri;
        }
        if(larg != root){
            arr[larg]=arr[larg]^arr[root];
            arr[root]=arr[larg]^arr[root];
            arr[larg]=arr[larg]^arr[root];
            root = larg;
        }
        else{
            return ;
        }
        

    }

}