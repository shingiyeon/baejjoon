#include <iostream>
using namespace std;

class Node {
	private:
		int data;
		Node* left;
		Node* right;
	
	public:
		Node(Node* ptr = NULL)
		{
			left= ptr;
			right = ptr;
		}
		int getData()
		{
			return data;
		}
		Node* getLeft()
		{
			return left;
		}
		Node* getRight()
		{
			return right;
		}
		void setData(int x)
		{
			data = x;
		}
		void setLeft(Node* x){
			left = x;
		}
		void setRight(Node* x){
			right = x;
		}
}

class heap{
	private:
		Node* rootPtr;
	public:
		class Node;
		heap()
		{
			rootPtr=NULL;
		}




