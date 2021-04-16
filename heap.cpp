#include<iostream>
using namespace std;

//min heap
class heap{
    private:
        int *arr;
        int size;
        int capacity;
    public:
        // insertion in min heap 
        void insert(int d){
            if(size==capacity){
                cout<<"\nheap is full\n";
                return ;
            }
            
            arr[size]=d;
            size++;

            for(int i=size-1;i!=0;){

                int p;
                p=(i-1)/2;

                if(arr[p]>arr[i]){
                    arr[i]=arr[i]^arr[p];                                        
                    arr[p]=arr[i]^arr[p];
                    arr[i]=arr[i]^arr[p];
                    i=p;
                }
                else{
                    break;
                }

            }

            return ;
        }

        //array display of heap
        void display(){

            if(size==0){
                cout<<"\nNo Elements in heap\n";
                return ;
            }
            cout<<"\nElements of heap in array representation\n";
            for(int i=0;i<size;i++){
                cout<<arr[i]<<" ";
            }

            cout<<"\n";
            return ;

        }

        //only give min element not delete it
        int top(){
            return size>0?arr[0]:-1;
        }

        //heapify the heap
        void heapify(int i){
            for(; i<size ;){
                int sm=i,li,ri; 
                li=2*i+1;
                ri=2*i+2;

                if(li<size && arr[li]<arr[i])
                    sm=li;
                
                if(ri<size && arr[ri]<arr[sm])
                    sm=ri;

                if(sm!=i){
                    arr[sm]=arr[sm]^arr[i];
                    arr[i]=arr[sm]^arr[i];
                    arr[sm]=arr[sm]^arr[i];        
                    i=sm;            
                }
                else{
                    return ;
                }


            }
        }


        //deletes the top most element and returns it
        int pop(){
            if(size==0){
                return -1;
            }

            int temp=arr[0];

            --size;
            arr[0]=arr[size];

            this->heapify(0);
            
            return temp;
        }

        heap(int n){
            arr=new int[n];
            size=0;
            capacity=n;
        }

};

int main(){
    int n;
    cout<<"Enter number of elements in heap: ";
    cin>>n;
    heap hp(n);
    cout<<"Enter elements to be inserted: ";
    for(int i=0;i<n;i++){
        int d;
        cin>>d;
        hp.insert(d);
    }

    hp.display();

    cout<<hp.top()<<endl;

    cout<<hp.pop();
    hp.display();

    return 0;
}