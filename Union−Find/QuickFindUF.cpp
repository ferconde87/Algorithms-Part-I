#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

class QuickFindUF{
	vector<int> id;
	int const length;
	public:
	QuickFindUF(int N) : length(N){
		id.resize(N);
		for(int i = 0; i < N; i++){
			id[i] = i;
		}
	}
	bool connectedUF(int p, int q){
		return id[p] == id[q];
	}
	void unionUF(int p, int q){
		int pid = id[p];
		int qid = id[q];
		for(int i = 0; i < id.size(); i++){
			if(id[i]==pid) id[i] = qid;
		}
	}
};


int main(){

	QuickFindUF qf(10);
	qf.unionUF(1,2);
	qf.unionUF(3,4);
	qf.unionUF(5,6);
	qf.unionUF(7,8);
	qf.unionUF(7,9);
	assert(!qf.connectedUF(1,9));
	qf.unionUF(1,9);
	assert(qf.connectedUF(1,9));
	qf.unionUF(0,5);
	qf.unionUF(2,8);
	assert(qf.connectedUF(7,2));
	assert(qf.connectedUF(6,0));
	assert(qf.connectedUF(2,9));
	assert(qf.connectedUF(3,4));
	
}
