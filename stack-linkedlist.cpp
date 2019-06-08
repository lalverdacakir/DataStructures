#include <iostream>
#include <climits>
using namespace std;

class Node{

	private:
		int data;
		Node* next;
		friend class Stack;
	public:
		Node(int val);
};

class Stack{

	private:
		Node* top;
	public:
		Stack();
		void push(int val);
		void push(int* arr, int n);
		int pop();
		int topElement();
		bool isEmpty();
		void disp();
};


Node::Node(int val){

	data=val;
	next=nullptr;
}


Stack::Stack(){

	top=nullptr;
}

void Stack::disp(){

	if(isEmpty()) return;
	
	Node* temp=top;
	
	while(temp){
	
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	
	cout<<endl;
}
bool Stack::isEmpty(){
	
	if(!top)
		return true;
	return false;
}

void Stack::push(int val){
	
	Node* temp = new Node(val);
	temp->next=top;
	top=temp;
}
void Stack::push(int* arr, int n){
	
	for(int i=0;i<n;i++)
		push(arr[i]);
	
}
int Stack::pop(){
	if(!isEmpty()){

		Node* temp;
		temp=top;
		top=top->next;
		int res=temp->data;
		delete temp;
		return res;
	}
	
	return INT_MIN;
}

int Stack::topElement(){
	
	if(!isEmpty()) return top->data;
	
	return INT_MIN; 
}
int main()
{
	return 0;
}