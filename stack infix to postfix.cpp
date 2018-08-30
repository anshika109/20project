#include<iostream>
#include<string.h>
#include<conio.h>
#define size 100
using namespace std;
class stack1{
	char stack[30],output[30],infix[30];
	int top;
	public:
	stack1()
	{
		top=-1;
	}
	int prec(char symb){
	    	if(symb=='(' || symb==')')
	    	return 0;
	    	else if(symb=='+' || symb=='-')
	    	return 1;
	    	else if(symb=='*' || symb=='/')
	    	return 2;
	    	else if(symb=='^')
	    	return 3;
		}
	void push(char ele){
		if(top==size-1){
			cout<<"overflow";
		}
			else{
				top++;
				stack[top]=ele;
			}
		}
	    int pop(){
	    	if(top==-1){
	    		cout<<"underfloew";
			}
			else{
	       int temp=stack[top];
		   top--;
		   return temp; 
	}
		}
		void infixtopostfix(char infix[]){
	    	int length,j=0,i;
	    	length=strlen(infix);
	    	for(i=0;i<length;i++){
	    	if(infix[i]!='(' && infix[i]!=')' && infix[i]!='+' && infix[i]!='-' && infix[i]!='*' && infix[i]!='/' && infix[i]!='^')
	    		output[j++]=infix[i];
	    	else{
	    		if(infix[i]!='(' && infix[i]!=')'){
	    			if(top==-1){
					push(infix[i]);
					}
					else 
					{
					if(prec(infix[i])<=prec(stack[top])){
						while(prec(infix[i])<=prec(stack[top])){
							output[j++]=pop();
						}
					}
						push(infix[i]);
					}
					}
				else{
						if(infix[i]=='(')
						push(infix[i]);
						if(infix[i]==')'){
							char temp1;
							temp1=pop();
							while(temp1!='('){
								output[j++]=temp1;
								temp1=pop();} } }
			   }	
		    }
		    while(top!=-1){
		    	output[j++]=pop();
			}
		    cout<<output;
		}
};
int main(){
	stack1 obj;
	char infix[size];
	cin>>infix;
	obj.infixtopostfix(infix);
	return 0;
}
