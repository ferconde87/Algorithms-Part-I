#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

class QuickUnionUF{
	private:
	vector<int> id;
	int root(int i){
		while(id[i]!=i) i = id[i];
		return i;
	}
	
	public:
	QuickUnionUF(int N){
		id.resize(N);
		for(int i = 0; i < N; i++) id[i] = i;
	}
	
	bool connectedUF(int p, int q){
		return root(p) == root(q);
	}
	
	void unionUF(int p, int q){
		id[root(p)] = root(q);//change root of p to point to root of q
	}
};



int main(){

	QuickUnionUF qu(10);
	qu.unionUF(1,2);
	qu.unionUF(3,4);
	qu.unionUF(5,6);
	qu.unionUF(7,8);
	qu.unionUF(7,9);
	assert(!qu.connectedUF(1,9));
	qu.unionUF(1,9);
	assert(qu.connectedUF(1,9));
	qu.unionUF(0,5);
	qu.unionUF(2,8);
	assert(qu.connectedUF(7,2));
	assert(qu.connectedUF(6,0));
	assert(qu.connectedUF(2,9));
	assert(qu.connectedUF(3,4));
	
}
