/*
    Given a array and a value k , find k-largest elements;
*/

#include<iostream>
using namespace std;

class solution{
    public:
        int* klarg(int arr[] , int n ,int k);

        void heapify(int* arr , int n , int root);

        void print_arr(int* arr, int n);
};

int main(){

    int n;
    cout<<"Enter no of elements: ";
    cin>>n;
    int arr[n];

    cout<<"Enter elements: ";
    for(int i = 0 ; i < n ;++i){
        cin>>arr[i];
    }

    int k; 
    cout<<"Enter value of k: ";
    cin>>k;

    solution sl;
    int* ans = sl.klarg(arr,n,k);

    cout<<"k-largest elements are: ";
    sl.print_arr(ans,k);

    return 0;
}

int* solution::klarg(int arr[], int n ,int k){

    int* ans = new int [k];
    for(int i = 0 ; i < k ;++i){
        ans[i] = arr[i];
    }    

    for(int i = (k-1)/2 ; i >= 0 ; i--){
        heapify(ans, k ,i);
    }

    for(int i = k ; i < n ; ++i){
        
        if(arr[i] > ans[0]){
            ans[0] = arr[i];
            heapify(ans, k , 0);
        }

    }

    return ans;

}

void solution::heapify(int* arr , int n ,int root){

    while(root != n-1){

        int li = 2*root + 1;
        int ri = 2*root + 2;
        int small = root;

        if( li < n && arr[small] > arr[li] ){
            small = li;
        }

        if(ri < n && arr[small] > arr[ri]){
            small = ri;
        }
        if(small != root){
            arr[small] = arr[small]^arr[root];
            arr[root] = arr[small]^arr[root];
            arr[small] = arr[small]^arr[root];
            root = small;
        }
        else{
            break;
        }

    }
    return ;
}

void solution::print_arr(int* arr, int n){

    for(int i = 0; i < n; ++i){
        cout<<arr[i]<<" ";
    }

    return ;
}