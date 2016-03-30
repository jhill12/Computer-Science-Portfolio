#include<iostream>
using namespace std;



class node
{
 public:
    int data;
    node* next;
};

class PointerList
{
	public:
	PointerList()
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

	void insert(int preptr_value, int element)
	{
		node *newptr = new node;
		newptr->data = element;
		
		node* preptr = top;
		//preptr = top;

			while(preptr_value!=element)
				{

				if(top == NULL && preptr_value == 0)	{		//insert the very first element
					
				top = newptr;

				newptr->next = NULL;
				
				break;
					
						}


			else if(preptr_value== NULL) {
				cout <<"Error. Data not allocated at location specified.";
				//	preptr = preptr->next;
				break;
			}

			else if(preptr_value == element) {

				break;
			}
	
						
			else {
				preptr->next= newptr->next;
				newptr->next = preptr;
			} 

				
		}
	
	}
		
	

	void remove(int preptr_value)
	{
		while(preptr_value!=NULL)	{
		if(preptr_value==0)			//delete the first element
		{
			node * ptr = top;
			top = ptr->next;
			delete(ptr);
		}
		else
		{
			node *preptr = top;
			
			
			
				preptr=preptr->next;
			
			node * ptr = preptr->next;
			preptr->next = ptr->next;
			delete(ptr);
		}
		}
	}


	void print()
	{
		node *temp;
		temp = top;
		while(temp!=NULL)
		{
			cout<<temp->data<<",";
			temp=temp->next;
		}
	}
	
private:
		node *top;
		int stackData;      
};

int main() {   
    PointerList *sl = new PointerList();  

    sl->insert(0,10);   //current linked list: 10 (default status, when empty)   
    sl->insert(10,20);	//current linked list: 10->20
    sl->insert(20,30);	//current linked list: 10->20->30
    sl->insert(20,40);	//current linked list: 10->20->40->30
    sl->insert(30,50);	//current linked list: 10->20->40->30->50
    sl->insert(50,60);	//current linked list: 10->20->40->30->50->60
    sl->insert(5,70);	//error, no 5 existed in the linked list
	sl->print();
	sl->remove(30); 	//current linked list: 10->20->40->30->60
    sl->remove(10);	//current linked list: 10->40->30->60
    sl->remove(50);	//error, no 50 existed in the linked list
    sl->print();



    return 0;
}

