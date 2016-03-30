//Project 3 data structures
//justin hill

#include<iostream>
#define CAPACITY  100
using namespace std;





class BST{
public:
    
	    int index;
    
   // int* array;
	void Insert(int x);
	void Delete(int x);
	void Search(int x);
	int Find_max();
	int Find_min();
	void Print_BST();
	
	static int array[];


    
};
int BST::array[10000] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	int main()
{

	BST* bst = new BST();

	bst -> Insert(5);
	bst -> Insert(8);
	bst -> Insert(3);
	bst -> Insert(1);
	bst -> Insert(4);
	bst -> Insert(9);
	bst -> Insert(18);
	bst -> Insert(20);
	bst -> Insert(19);
	bst -> Insert(2);
	bst -> Print_BST();
	bst -> Find_max();
	bst -> Find_min();
	bst -> Search(3);
	bst -> Search(18);
	bst -> Search(19);

	bst -> Delete(19);
	bst -> Print_BST();

	bst -> Delete(2);
	bst -> Print_BST();

	bst -> Delete(3);
	bst -> Print_BST();

	bst -> Delete(5);
	bst -> Print_BST();
	char answer;
	cout << "Did you like my code? ( 'y' or 'n' ) " << endl;		//just some fun
	cin >>  answer;
	if(answer=='y' || answer== 'Y')
		cout << "Thank you so much." << endl;
	else if(answer=='n'||answer=='N')
		cout << "Sadface :(" << endl;

	int y;
	cout << "Enter any value to exit the code :)" << endl;
		cin >> y;

return 0;

}




void BST::Insert(int  x){		//this will insert x at the correct place that is = to -1
	int Index = 1;

	while(array[Index] != -1){
		

	
	 if(array[Index] < x){
		
		Index = 2*Index+1;
		
		
	}
	else if(array[Index] > x){
		
		Index = 2* Index;
		
		
	}

	else{
		cout << "Can not enter the same value twice." << endl;
	break;
	}

	}
	array[Index] = x;
}


		



void BST::Delete(int x){		//this code will check for a value = to x and then replace it with -1, meaning that it is deleted
		int Index = 1;

	while(array[Index] != -1){
		

	
	 if(array[Index] < x){
		
		Index = 2*Index+1;
		
		
	}
	else if(array[Index] > x){
		
		Index = 2* Index;
		
		
	}

	else{
		
	break;
	}

	}
	array[Index] = -1;

}
void BST::Search(int x){
	int index = 1;
	while(true){
		if(array[index] == -1){
			cout << "Value not found." << endl;			//we dont have it :(
			break;
		}
		if(array[index] == x){
			cout << " Found number '" << x << "' at index: " << index << endl;		//we found it!!!
			cout << endl;
			break;
		}
		else if(array[index] < x){
			index = (2*index +1);
		}
		else if(array[index] >x){
			index = (2*index);
		}

	}


	}


int BST::Find_max(){
	int index = 1;
	
	if(array[index] == -1)	//check for empty tree
		cout << "EMPTY TREE." << endl;
	while(array[index] != -1){	//while loop is a value 
		index = (index *2) +1;
	}
	index = index-1;
	index = index / 2;		//take a step back to previous value
	cout << array[index] << endl;
	cout << endl;
	return array[index];


}

int BST::Find_min(){
	int index = 1;
	
	if(array[index] == -1)	//make sure that the tree is not empty
		cout << "EMPTY TREE." << endl;
	
	while(array[index] != -1){	//while the loop holds a value
		index = (index *2);
	}
	index = index/2;	//take one step back to the previous value. 
	cout << array[index] << endl;
	cout << endl;
	return array[index];

}

void BST::Print_BST(){
	int index = 1;
	int counter = 0;

	while(array[index] != NULL){			//This prints the code in tree for mation as in 1,(<<endl;),2,3,(<<endl;),4,5,6,7 and so forth.
		if(array[index]!= -1){
		cout << array[index] << " ";
		counter++;
			if(counter==1)
				cout << endl;
			else if(counter==3)
				cout << endl;
			else if(counter==7)
				cout << endl;
			else if(counter==15)
				cout << endl;
			else if(counter==31)
				cout << endl;


		}
		index++;
		
	}
	cout << endl;
	cout << endl;

 

 
  
}
		

	




