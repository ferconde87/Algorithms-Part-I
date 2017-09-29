#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

//Complexity: (N: size of the elements)
//Insertion: O(log(N))
//Delete max: O(log(N))
//Return max: O(1)

template <class Key>
class MaxPQ{
	private:
		vector<Key> pq;
		int n;
	public:
		MaxPQ(int capacity){
			pq.resize(capacity+1);
			n = 0;
		}
		bool isEmpty(){
			return n == 0;
		}
		void insert(Key x){
			pq[++n] = x;
			swim(n);
		}
		Key delMax(){
			Key max = pq[1];
			swap(pq[1], pq[n--]);
			sink(1);
			//~ pq[n-1] = NULL;//when Key is not a basic type
			return max;
		}
		void sink(int k){
			while(2*k <= n){
				int j = 2*k;
				if(j < n && pq[j] < pq[j+1]) j++;
				if(!(pq[k] < pq[j])) break;
				swap(pq[k],pq[j]);
				k = j;
			}
		}
		void swim(int k){
			while(k > 1 && pq[k/2] < pq[k]){
				swap(pq[k/2],pq[k]);
				k = k/2;
			}
		}
		void peek(){
			return pq[1];
		}
};



int main(){
	MaxPQ<string> pq(9);
	pq.insert("P");
	pq.insert("Q");
	pq.insert("E");
	assert(pq.delMax() == "Q");
	pq.insert("X");
	pq.insert("A");
	pq.insert("M");
	assert(pq.delMax() == "X");
	pq.insert("P");
	pq.insert("L");
	pq.insert("E");
	assert(pq.delMax() == "P");
	return 0;
}

