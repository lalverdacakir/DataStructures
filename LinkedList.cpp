#include <iostream>
using namespace std;
class Node{
public:
	int data;
	Node* next;
};

class LinkedList{
	Node* head;
	public:
		LinkedList(int val);
		void insert_front(int val);
		void insert_end(int val);
		void inset_after(int val,int after_val);
		void insert_before(int val,int before_val);
		void remove(int val);
		void display();
		void sort();
		void pop();
		
		Node* search(int val);
		bool isEmpty();
		~LinkedList();
};

LinkedList::LinkedList(int val){
	head=new Node;
	head->data=val;
	head->next=NULL;
}
void swapNode(Node* a, Node* b){
	
	int temp=a->data;
	a->data=b->data;
	b->data=temp;
}

void LinkedList::insert_front(int val){
	Node* newNode=new Node;
	newNode->data=val;
	 
	newNode->next=head;
	head=newNode;
}
void LinkedList::insert_end(int val){
	Node* temp=head;
	while(temp->next){
		temp=temp->next;
	}

	Node* newNode=new Node;
	newNode->data=val;
	newNode->next=nullptr;
	temp->next=newNode;

}

void LinkedList::insert_after(int val,int after_val){
	Node* temp=head;
	Node* newNode=new Node;
	newNode->data=after_val;
	while(temp){
		
		if(temp->data==val){
			newNode->next=temp->next;
			temp->next=newNode;
			break;
		}
		temp=temp->next;
		
	}
}

void LinkedList::insert_before(int val,int before_val){
	
	Node* temp=head;
	Node* newNode=new Node;
	newNode->data=before_val;
	if(head->data==val){
		insert_front(before_val);
		return;
	} 
	while(temp->next){
		
		if(temp->next->data==val){
			
			newNode->next=temp->next;
			temp->next=newNode;
			break;
		}
		temp=temp->next;
		
	}
}
void LinkedList::pop(){
	Node* temp=head;
	head=head->next;
	delete temp;

}

void LinkedList::remove(int val){
	Node* temp=head;
	if(head->data==val) {
		pop();
	}
	while(temp->next){
		
		if(temp->next->data==val){
			Node* gec=temp->next->next;
			delete temp->next;
			temp->next=gec;
			break;
		}
		temp=temp->next;
		

	}
}

void LinkedList::display(){
	Node* temp=head;
	while(temp){
		
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

void LinkedList::sort(){
	int flag;
	Node* temp;
	if(!head) return;

	do{
		flag=0;
		temp=head;

		while(temp->next){
			
			if(temp->data > temp->next->data){
				
				
				swapNode(temp,temp->next);
				flag=1;
				
			}
			temp=temp->next;
		}
		
	}while(flag);
}

Node* LinkedList::search(int val){
	Node* temp=head;
	while(temp->next){
		if(temp->next->data==val){
			return temp->next;
		}
		temp=temp->next;
	}

	return nullptr;
}

bool LinkedList::isEmpty(){
	if(head) return true;
	return false;
}
LinkedList::~LinkedList(){
	Node* curr=head;
	Node * next;
	while(curr){
		next=curr->next;
		delete(curr);
		curr=next;
	}
	head=nullptr;
	
	
}
int main(){
	
	return 0;
}
