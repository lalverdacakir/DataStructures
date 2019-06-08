#include <iostream>
#include <climits>
using namespace std;
#define MAX 40 
class Queue{
	int arr[MAX];
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

Queue::Queue(){
	rear=arr;
	front=arr;
}
bool Queue::isFull(){
	int len=rear-front+1;
	if(len==MAX) return true;
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
Queue::~Queue(){
	rear=arr;
	front=arr;
}

void Queue::disp(){
	for(int* i=front;i<rear;i++){
		cout<<*i<<" ";
	}

	cout<<endl;
}
int main(){
	return 0;
}