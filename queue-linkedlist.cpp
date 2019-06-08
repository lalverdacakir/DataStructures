#include <iostream>
#include <climits>
using namespace std;

class Node{

	private:
		int data;
		Node* next;
		friend class Queue;
	public:
		Node(int val);
};

class Queue{
	Node *rear,*front;
public:
	Queue();
	void add(int val);
	int remove();
	int peek();
	bool isEmpty();
	void disp();
	~Queue();
};

Node::Node(int val){
	data=val;
	next=nullptr;
}

Queue::Queue(){
	rear=nullptr;
	front=nullptr;
}

void Queue::add(int val){
	Node* temp =new Node(val);
	if(!rear){
		rear=temp;
		rear->next=nullptr;
		front=rear;
	}else{
		rear->next=temp;
		rear=temp;
	}
}

int Queue::remove(){
	Node* temp=front;
	if(!front) return INT_MIN;
	int res=front->data;
	if(temp->next){
		temp=temp->next;
		
		delete(front);
		front=temp;
		return res;
	}

	delete(front);
	front=nullptr;
	rear=nullptr;
	return res;
}

bool Queue::isEmpty(){
	if(front && rear) return false;
	return true;
}

void Queue::disp(){
	Node* temp=front;
	if(isEmpty()) return;

	while(temp){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

int Queue::peek(){
	return front->data;
}

Queue::~Queue(){
	Node* curr=front;
	Node* next;
	while(curr){
		next=curr->next;
		delete(curr);
		curr=next;
	}

	front=nullptr;
	rear=nullptr;

}

int main()
{	
	return 0;
}