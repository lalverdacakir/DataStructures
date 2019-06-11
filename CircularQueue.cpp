#include <iostream>
#include <climits>
using namespace std;

class CircularQueue{
	int rear;
	int front;
	int* arr;
	int size;
public:
	CircularQueue(int length);
	void add(int val);
	void add(int* a,int n);
	int remove();
	void disp();
	int peek();
	bool isEmpty();
	~CircularQueue();
};

CircularQueue::CircularQueue(int length){
	size=length;
	rear=-1;
	front=-1;
	arr=new int[size];
}

void CircularQueue::add(int val){
	if(front==0 && rear==size-1) return;
	if(rear==(front-1)%(size-1)) return;

	if(front==-1){
		front=0;
		rear=0;
		arr[rear]=val;
		return;
	}
	if(rear==size-1 && front!=0){
		rear=0;
		arr[rear]=val;
		return;
	}

	rear++;
	arr[rear]=val;

}

void CircularQueue::add(int* a,int n){
	for(int i=0;i<n;i++){
		add(a[i]);
	}
}
bool CircularQueue::isEmpty(){
	if(front==-1) return true;
	return false;
}
int CircularQueue::remove(){
	if(isEmpty()) return INT_MIN;
	int data=arr[front];
	if(front==rear){
		front=-1;
		rear=-1;
	}
	else if(front==size-1) front=0;
	else front++;

	return data;
}
int CircularQueue::peek(){
	if(isEmpty()) return INT_MIN;

	return arr[rear];
}

void CircularQueue::disp(){
	if(front==-1) return;
	if(rear>=front){
		for (int i = front; i <= rear; ++i)
			cout<<arr[i]<<" ";
		cout<<endl;
	}else{
		for (int i = front; i < size; ++i)
			cout<<arr[i]<<" ";
		for (int i = 0; i <= rear; ++i)
			cout<<arr[i]<<" ";
		
	}
}

CircularQueue::~CircularQueue(){
	delete[] arr;
}

int main(){
	return 0;

}