//1 - implementare una lista concatenata di interi
#include <iostream>
using namespace std;

class Node{
	int value;
	Node * succ;
};

class SList{
	private:
		Node * head;
	public:
		SList(){head=nullptr;}
		void insert(int val){
			Node * newNode = new Node;
			newNode->succ = this->head;
			newNode->value = val;
			this->head = newNode;
		}
		void insert(Node * nod, int val){
			Node * newNode = new Node;
			newNode->value = val;
			newNode->succ = nod;
			nod->succ = newNode; 
		}
};

int main(){

}
