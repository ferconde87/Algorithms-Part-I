#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

//Complexity: (N: size of the elements)
//Insertion: O(1)
//Delete max: O(N)
//Return max: O(N)
template <class Key>
class UnorderedMaxPQ{
	private:
		vector<Key> pq;
		int n;
	public:
		UnorderedMaxPQ(int capacity){
			pq.resize(capacity);
			n = 0;
		}
		bool isEmpty(){
			return n == 0;
		}
		void insert(Key x){
			pq[n++] = x;
		}
		Key delMax(){
			int maxIndex = 0;
			for(int i = 1; i < n; i++)
				if(pq[maxIndex] < pq[i]) maxIndex = i;
			Key max = pq[maxIndex];
			swap(pq[maxIndex], pq[n-1]);
			n--;
			return max;
		}
		void peek(){
			return pq[1];
		}		
};



int main(){
	UnorderedMaxPQ<string> pq(9);
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
