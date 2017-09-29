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
	public:
		MaxPQ(){
		}
		bool isEmpty(){
			return pq.size()==0;
		}
		void insert(Key x){
			pq.push_back(x);
			swim();
		}
		Key delMax(){
			Key max = pq[0];
			swap(pq[0], pq[pq.size()-1]);
			pq.pop_back();
			sink();
			//~ pq[n-1] = NULL;//when Key is not a basic type
			return max;
		}
		void sink(){
			int k = 0;
			int n = pq.size();
			while(2*k+1< n){
				int j = 2*k+1;
				if(j < n-1 && pq[j] < pq[j+1]) j++;
				if(!(pq[k] < pq[j])) break;
				swap(pq[k],pq[j]);
				k = j;
			}
		}
		void swim(){
			int k = pq.size()-1;
			while(k > 0 && pq[(k-1)/2] < pq[k]){
				swap(pq[(k-1)/2],pq[k]);
				k = (k-1)/2;
			}
		}
		Key peek(){
			return pq[0];
		}
};



int main(){
	MaxPQ<string> pq;
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
