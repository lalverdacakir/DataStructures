#include <iostream>
#include <climits>
using namespace std;

class Node{
	int data,pri;
	Node *next;
	friend class PriorityQueue;
public:
	Node(int val,int pri){
		data=val;
		next=nullptr;
	
	}
};

class PriorityQueue{
	Node *front,*rear;
	int size;
public:
	PriorityQueue();
	void add(int val,int priority);
	int remove();
	bool isEmpty();
	int peek();
	void disp();
	~PriorityQueue();

};

PriorityQueue::PriorityQueue(){
	size=0;
	front=nullptr;
	rear=nullptr;
}

void PriorityQueue::add(int val,int priority){
	Node* newNode=new Node(val,priority);
	if(!front) {
		rear=newNode;
		front=newNode;
		size++;
		return;
	}

	newNode->next=rear;
	rear=newNode;
	size++;
}

int PriorityQueue::remove(){
	if(isEmpty()) return INT_MIN;
	if(front==rear){
		Node* temp=front;
		int val=temp->data;
		delete(temp);
		front=nullptr;
		rear=nullptr;
		return val;
	}
	Node* temp=rear;
	while(temp->next!=rear){
		temp=temp->next;
	}
	Node* silinecek=rear;
	int val=rear->data;
	rear=temp;
	rear->next=nullptr;
	delete(silinecek);
	size--;
	return val;
}


bool PriorityQueue::isEmpty(){
	if(front==nullptr && rear==nullptr)
		return true;
	return false;
}

int PriorityQueue::peek(){
	if(isEmpty()) return INT_MIN;
	return front->data;
}
void PriorityQueue::disp(){
	Node* temp=rear;
	while(temp){
		cout<<temp->data<<" ";
		temp=temp->next;
	}

	cout<<endl;
}

PriorityQueue::~PriorityQueue(){
	rear=nullptr;
	Node* temp;	
	while(front){
		temp=front;
		front=front->next;
		delete(temp);
	}
	size=0;
}

int main(){
	
	return 0;
}