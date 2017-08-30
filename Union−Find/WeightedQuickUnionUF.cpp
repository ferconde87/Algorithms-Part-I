#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

class WieghtedQuickUnionUF{
	private:
	vector<int> id;
	vector<int> sz;
	int root(int i){
		while(id[i]!=i) i = id[i];
		return i;
	}
	
	public:
	WieghtedQuickUnionUF(int N){
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

	WieghtedQuickUnionUF wqu(10);
	wqu.unionUF(1,2);
	wqu.unionUF(3,4);
	wqu.unionUF(5,6);
	wqu.unionUF(7,8);
	wqu.unionUF(7,9);
	assert(!wqu.connectedUF(1,9));
	wqu.unionUF(1,9);
	assert(wqu.connectedUF(1,9));
	wqu.unionUF(0,5);
	wqu.unionUF(2,8);
	assert(wqu.connectedUF(7,2));
	assert(wqu.connectedUF(6,0));
	assert(wqu.connectedUF(2,9));
	assert(wqu.connectedUF(3,4));
	
}

