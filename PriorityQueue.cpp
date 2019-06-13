#include <iostream>
#include <climits>
using namespace std;

class Node{
	int data;
	int priority;
	friend class PriorityQueue;
};

class PriorityQueue
{	
	Node* arr;
	int size;
	Node* rear;
	Node* front;
public:
	PriorityQueue(int s);
	void add(int val,int priority);
	int remove();
	int peek();
	bool isEmpty();
	bool isFull();
	void disp();
	~PriorityQueue();
	
};

PriorityQueue::PriorityQueue(int s){
	size=s;
	arr=new Node[s];
	rear=arr;
	front=arr;
}

bool PriorityQueue::isEmpty(){
	if(rear==front) return true;
	return false;
}
bool PriorityQueue::isFull(){
	int len=rear-front;
	if(len==size) return true;
	return false;
}
void PriorityQueue::add(int val,int pri){
	
	if(isEmpty()) {
		(*rear).data=val;
		(*rear).priority=pri;
		rear++;
	}

	else{

		for(Node* i=front; i<rear;i++){
			if(i==rear-1 && (*i).priority>pri){
				(*rear).data=val;
				(*rear).priority=pri;
				rear++;
				break;
			}
			if((*i).priority>pri) continue;
			if((*i).priority<=pri){
				if(!isFull()){
					for(Node* j=rear-1;j>=i;j--){
						*(j+1)=*j;
					}
					i->data=val;
					i->priority=pri;
					rear++;

					break;
				}else{
					exit(1);
				}
			}
		}
	}
}

int PriorityQueue::remove(){
	if(!isEmpty())
		return (front++)->data;
	return INT_MIN;
}

int PriorityQueue::peek(){
	if(!isEmpty())
		return front->data;
}

void PriorityQueue::disp(){
	for(Node* i=front;i<rear;i++){
		cout<<i->data<<" ";
	}

	cout<<endl;
}

PriorityQueue::~PriorityQueue(){
	delete[] arr;
}
int main(){

	return 0;
}