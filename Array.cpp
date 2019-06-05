#include <iostream>

using namespace std;
int MAX=1;
class Array{
	double* x;
	int size;
	int cap;

public:
	Array(){
		x=new double[MAX];
		cap=MAX;
		size=0;
	}
	void add(double data);
	void del(unsigned int index);
	void insert(double data,unsigned int index);
	void getIndex(double data);
	bool isFull();
	bool isEmpty();
	int capacity();
	void disp();

};

bool Array::isFull(){
	if(size==MAX) return true;
	return false;

}

bool Array::isEmpty(){
	if(size==0) return true;
	return false;
}

void Array::add(double data){
	if(isFull()) return;
	x[size]=data;
	size++;
}

void Array::del(unsigned int index){
	if(index>=size) return;
	int i=index;
	for(i=index;i<cap;i++){
		x[i]=x[i+1];
	}
	x[i+1];
	size--;
}

void Array::insert(double data, unsigned int index){
	if((size+1)==MAX-1) {
		double* newArray=new double[2*MAX];
		MAX=2*MAX;
		for(int i=0;i<=MAX;i++){
			if(i<index) newArray[i]=x[i];
			else if(i>index) newArray[i]=x[i-1];
			else newArray[i]=data;

		}
		size++;
		x=newArray;
		delete[] newArray;
		return;

	}
	int i;
	for(i=size;i>index;i--){
		x[i]=x[i-1];
	}
	x[index]=data;
	size++;
}
void Array::disp(){
	cout<<"Size: "<<size<<endl;
	for(int i=0;i<size;i++){
		cout<<x[i]<<" ";

	}
	cout<<"\n";
}

int main(){
	Array example;
	example.add(5);
	example.add(75);
	example.add(42);
	example.disp();
	example.insert(23,0);
	example.disp();
	example.del(1);
	example.disp();
	return 0;

}