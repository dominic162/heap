/*https://cybergeeksquad.co/2021/06/five-star-seller-maximum-average-pass-ratio-amazon-oa.html*/
#include<iostream>
#include<queue>
using namespace std;

#define ff first
#define ss second

class obj{
	public:
		float delta;
		int pos;
		obj(float d , int p){
			delta = d;
			pos = p;
		}
};

bool operator < (const obj &a , const obj &b){
	if(a.delta < b.delta){
		return true;
	}
	return false;
}

int main(){

	int n;
	cin>>n;

	pair<float,float> pr[n];

	for(int i = 0 ; i < n ; ++i){
		cin>>pr[i].ff>>pr[i].ss;
	}

	int ex;
	cin>>ex;

	priority_queue<obj> pq;

	for(int i = 0 ; i < n ; ++i){
		float d = (pr[i].ff + 1)/(pr[i].ss + 1);
		d -= pr[i].ff/pr[i].ss;
		pq.push(obj(d,i));
	}

	while(ex){

		obj crr = pq.top();
		pq.pop();
		pr[crr.pos].ff += 1;
		pr[crr.pos].ss += 1;

		float d = (pr[crr.pos].ff + 1)/(pr[crr.pos].ss + 1);
		d -= pr[crr.ff]/pr[crr.ss];

		crr.delta = d;
		pq.push(crr);
		ex--;

	}

	float total = 0;

	for(int i = 0 ; i < n ; ++i){
		total += (pr[i].ff*100)/pr[i].ss;
	}

	total /= n;

	cout<<total;
	return  0;
}