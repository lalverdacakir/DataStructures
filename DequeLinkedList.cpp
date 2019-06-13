#include <iostream>
#include <climits>

using namespace std;
class Node{
	int data;
	Node* next;
	Node* prev;
	friend class Deque;
	};
class Deque{
	Node* head;
	Node* tail;
	int size;

public:
	Deque();
	void pushfront(int val);
	void pushrear(int val);
	int removefront();
	int removerear();
	int peekfront();
	int peekrear();
	bool isEmpty();
	void disp();
	~Deque();
};

Deque::Deque(){
	head=nullptr;
	tail=nullptr;
	size=0;
}
bool Deque::isEmpty(){
	if((head==nullptr) && (tail==nullptr)) return true;
	return false;
}
void Deque::pushfront(int val){
	Node* newNode=new Node;
	newNode->data=val;
	newNode->next=newNode->prev=nullptr;

	if(isEmpty()) tail=head=newNode;
	else{
		newNode->next=head;
		head->prev=newNode;
		head=newNode;
	}
	size++;
}

void Deque::pushrear(int val){
	Node* newNode=new Node;
	newNode->data=val;
	newNode->next=newNode->prev=nullptr;

	if(isEmpty()) head=tail=newNode;
	else{
		newNode->prev=tail;
		tail->next=newNode;
		tail=newNode;
	}
	size++;
}

int Deque::removefront(){
	if(isEmpty()) return INT_MIN;
	Node* temp=head;
	int data=head->data;
	head=head->next;
	if(!head)
		tail=nullptr;
	else head->prev=nullptr;
	delete(temp);
	size--;
	return data;
}

int Deque::removerear(){
	if(isEmpty()) return INT_MIN;
	Node* temp=tail;
	int data=tail->data;

	tail=tail->prev;
	if(!tail)
		head=nullptr;
	else tail->next=nullptr;
	
	delete(temp);
	size--;
	return data;
}

int Deque::peekfront(){
	if(isEmpty()) return INT_MIN;
	return head->data;
}

int Deque::peekrear(){
	if(isEmpty()) return INT_MIN;
	return tail->data;
}
void Deque::disp(){
	Node* temp=head;
	cout<<"Size: "<<size<<endl;
	while(temp){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;

}

Deque::~Deque(){
	tail=nullptr;
	Node* temp;
	while(head){
		temp=head;
		head=head->next;
		delete(temp);
	}
	size=0;
}

int main(){
	return 0;
}