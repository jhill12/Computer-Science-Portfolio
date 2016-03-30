

#include<iostream>
#define CAPACITY 25
using namespace std;


class node
{
 public:
    int data;
    node* next;
};


class StackList{

	public:

		StackList()
	{
		
		 top = NULL;
		 
		 
	}

	bool empty()
	{
		if(top == NULL)
			return true;
		else
			return false;
	}


	
	void Push(int x) {


	  if (top < CAPACITY-1)   // array is not FULL 
{		stack[++top ] = x;
	  }
	  else
	  {
		cout << "Out of space";

	  }
	}


	int Top(){
	if( top > stack[0])
	{	
		return stack[top];
	}
	else 
		cout << "No elements in the stack.";
	}


	void Pop() {
		
		if(top == -1){
			cout << "There are no elements in the stack.";
			return;
		}
		
		else{
		
			top--;

			return;
		}
	}
	


		void Display()
	{
		int i;
		if(top == -1)
			printf("Stack is empty\n");
		printf("\n\n");
		for(i = top; i >= 1; i--){
			printf("%d\n",stack[i]);


		}
	}
	
private:
		int top;
		
		int stack[CAPACITY];  

};


int main()
{

	StackList* sl = new StackList();


sl ->Push(1);
sl ->Push(2);
sl ->Push(3);
sl ->Push(4);
sl ->Push(5);
sl ->Push(6);
sl ->Push(7);
sl ->Push(8);
sl ->Push(9);
sl ->Push(10);
sl ->Display();

sl ->Push(20);
sl ->Display();
sl ->Push(30);
sl ->Display();
sl ->Push(40);
sl ->Display();

sl ->Top();
sl ->Pop();
sl ->Display();
sl ->Top();
sl ->Pop();
sl ->Display();

sl ->Top();
sl ->Pop();
sl ->Display();

return 0;



}