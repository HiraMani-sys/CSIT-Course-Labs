#include<iostream>
#include<string>
using namespace std;
#define MAx 100
class conversion{
	char arr[MAX];
	int top;
	public;
	conversion(){top==-1;}
	bool isempty(){return top==-1;}
	bool isfull(){return top==MAX-1;}
	void push(char x){
		if(isfull()){
		cout<< "Stack is full."<<endl;			
		}else{
			return a[++top]=x;
		}
		}
	char pop(){
		if(isempty()){
		cout<< "Stack is empty."<<endl;			
		return '\0';
		}else{
		return arr[top--];
		}
	}
	char peek(){
		if(isempty()){
			cout<< "Stack is empty."<<endl;
			return '\0';
		}
		return arr[top];
	}
};

int precedence(char ch){
	if(ch=='^'){
	return 3;
	}
		if(ch=='*'||ch=='/'){
	return 2;
	}
		if(ch=='+'||ch=='-'){
	return 1;
	}
	return 0;
}

bool isoperator(char ch){
	return (ch=='+'||ch=='');
	
}

