#include <iostream>
using namespace std;
#define MAX 10
class Stack{
	int arr[MAX];
	int top;
public:
	Stack();
	void push(int val);
	void push(int* values,int n);
	int Top();
	int pop();
	bool isEmpty();
	bool isFull();
	void disp();
};

Stack::Stack(){
	top=-1;
}
int Stack::Top(){
	return arr[top];
}
bool Stack::isFull(){
	if(top==MAX-1) return true;
	return false;
}
bool Stack::isEmpty(){
	if(top==-1) return true;
	return false;
}
void Stack::push(int val){
	if(!isFull())
		arr[++top]=val;
}
void Stack::push(int* values,int n){
	for(int i=0;i<n;i++){
		push(values[i]);
	}
}
int Stack::pop(){
	if(!isEmpty())
	{
		int temp=arr[top];
		top--;
		return temp;
	}
}

int main(){
	
	return 0;
}