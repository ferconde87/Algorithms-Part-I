#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

//Complexity: (N: size of the elements)
//Sort: O(log(N))

template <class Key>
class MaxHeap{
	public:
		MaxHeap(){
		}

		void sink(vector<int> & v, int k, int n){
			while(2*k+1< n){
				int j = 2*k+1;
				if(j < n-1 && v[j] < v[j+1]) j++;
				if(!(v[k] < v[j])) break;
				swap(v[k],v[j]);
				k = j;
			}
		}

		void sort(vector<Key> & v){
			int n = v.size();
			for(int i = (n-1)/2; i >= 0; i--)
				sink(v, i, n);
			while(n > 0){
				swap(v[0], v[n-1]);
				sink(v, 0, --n);
			}
		}
};

void print(vector<int> & v){
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

int main(){
	vector<int> v = {2,3,5,2,14,5,3,68};
	MaxHeap<int> h;
	h.sort(v);
	print(v);
	v = {-1, -3, 0, -25, -4, 9, 1023, -3, 3, 503, 2, 23, -33, 23};
	h.sort(v);
	print(v);
}
