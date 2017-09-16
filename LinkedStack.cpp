#include <iostream>
#include <cassert>
#include <stdexcept>
#include <iterator>

using namespace std;

template <class Item>
class LinkedStack{
	private:
		class Node{
			public:
				Item item;
				Node * next;
		};
		int n;			//size of the stack
		Node * first;		//top of the stack
	public:
		LinkedStack(){
			first = NULL;
			n = 0;
			assert(check());
		}
		
		bool isEmpty(){
			return first == NULL;
		}
		
		
		int size(){
			return n;
		}
		
		void push(Item item){
			Node * oldfirst = first;
			first = new Node();
			first->item = item;
			first->next = oldfirst;
			n++;
			assert(check());
		}
		
		Item pop(){
			if(isEmpty()){
				throw out_of_range("Stack underflow");
			}
			Item item = first->item;
			first = first->next;
			n--;
			assert(check());
			return item;
		}
		
		Item peek(){
			if(isEmpty()) throw out_of_range("Stack underflow");
			return first->item;
		}
		
		string toString(){
			string s;
			for(Item item : this)
				s + item;
			return s;
		}
			
		class Iterator : public iterator<forward_iterator_tag, Item>{
			Node * current = first;
			public:
				bool hasNext(){ return current != NULL; }
				void remove() { 
					throw exception("UnsupportedOperationException");
				}
				Item next(){
					if(!hasNext()) throw exception("NoSuchElementException");
					Item item = current->item;
					current = current->next;
					return item;
				}
		};
		
		Iterator iterator(){
			Iterator iterator;
			return iterator;
		}
		
    // check internal invariants
    bool check() {
        // check a few properties of instance variable 'first'
        if (n < 0) {
            return false;
        }
        if (n == 0) {
            if (first != NULL) return false;
        }
        else if (n == 1) {
            if (first == NULL)      return false;
            if (first->next != NULL) return false;
        }
        else {
            if (first == NULL)      return false;
            if (first->next == NULL) return false;
        }

        // check internal consistency of instance variable n
        int numberOfNodes = 0;
        for (Node * x = first; x != NULL && numberOfNodes <= n; x = x->next) {
            numberOfNodes++;
        }
        if (numberOfNodes != n) return false;

        return true;
    }
};


int main(){
	LinkedStack<string> * stack = new LinkedStack<string>();
	string item;
	while(cin >> item){
		if(item != "-"){
			stack->push(item);
		}else if(!stack->isEmpty()){
			cout << stack->pop() << " ";
		}
	}
	cout << "(" << stack->size() << " left on stack)";
}
