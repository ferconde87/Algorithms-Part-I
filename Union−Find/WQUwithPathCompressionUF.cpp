#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

class wqupcwithPathCompression{
	private:
	vector<int> id;
	vector<int> sz;
	int root(int i){
		while(id[i]!=i){
			id[i] = id[id[i]];//one pass variant: make every one in the path point to its grandparent (halving path lenght)
			i = id[i];
		}
		return i;
	}
	
	public:
	wqupcwithPathCompression(int N){
		id.resize(N);
		sz.resize(N);
		fill(sz.begin(), sz.end(), 1);
		for(int i = 0; i < N; i++) id[i] = i;
	}
	
	bool connectedUF(int p, int q){
		return root(p) == root(q);
	}
	
	void unionUF(int p, int q){
		int i = root(p);
		int j = root(q);
		if(i == j) return;
		if(sz[i] < sz[j]){id[i] = j; sz[j] += sz[i];}
		else 			 {id[j] = i; sz[i] += sz[j];} 
	}
};



int main(){

	wqupcwithPathCompression wqupc(10);
	wqupc.unionUF(1,2);
	wqupc.unionUF(3,4);
	wqupc.unionUF(5,6);
	wqupc.unionUF(7,8);
	wqupc.unionUF(7,9);
	assert(!wqupc.connectedUF(1,9));
	wqupc.unionUF(1,9);
	assert(wqupc.connectedUF(1,9));
	wqupc.unionUF(0,5);
	wqupc.unionUF(2,8);
	assert(wqupc.connectedUF(7,2));
	assert(wqupc.connectedUF(6,0));
	assert(wqupc.connectedUF(2,9));
	assert(wqupc.connectedUF(3,4));
	
}

