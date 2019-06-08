#include <iostream>
#include <climits>
using namespace std;

class Queue{
	int* arr;
	int size;
	int *rear,*front;
public:
	Queue();
	void add(int val);
	void add(int* arr,int n);
	int remove();
	int peek();
	bool isEmpty();
	bool isFull();
	void disp();
	~Queue();

};

Queue::Queue(int s){
	size=s;
	arr= new int[s];
	rear=arr;
	front=arr;
}
bool Queue::isFull(){
	int len=rear-front+1;
	if(len==size) return true;
	return false;

}
void Queue::add(int val){
	if(!isFull())
		*(rear++) = val;
}
void Queue::add(int* arr,int n){
	for (int i = 0; i < n; ++i)
	{
		add(arr[i]);
	}
}
bool Queue::isEmpty(){
	if(rear==front) return true;
	return false;
}
int Queue::remove(){
	if(!isEmpty())
		return *(front++);
	return INT_MIN;
}
int Queue::peek(){
	if(!isEmpty())
		return *front;
}
void Queue::disp(){
	for(int* i=front;i<rear;i++){
		cout<<*i<<" ";
	}

	cout<<endl;
}
Queue::~Queue(){
	rear=arr;
	front=arr;
}


int main(){
	return 0;
}