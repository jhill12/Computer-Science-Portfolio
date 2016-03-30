

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "FinalClass.h"
using namespace std;

Final::Final(){
iLength = 0;
iArray = new int[600000];
ecx = 0;
}


void Final::filetoarray(){
	//check for file
	int ecx= 0;
	int index = 0;


fstream in_file("Final_project_dataset.txt", ios::in);
if (!in_file)
	{
		cout << "Cannot open file.\n";
		exit(-1);
	}

while(true){
		//read line
		in_file >> index;

		iArray[ecx] = index;

		//test for eof
		if (!in_file.eof())
			break;

		ecx++;
	}
	int INDEX = 0;
	int iLength = 0;
	for(int d = 0; iArray[d] <= NULL; d++){
		INDEX++;
		iLength++;
		
	}



}
void Final::SelectionSort(){
	
 

	
    for (int i = 0; i < iLength - 1; ++i) {
       
		
		int Smallest = i;


					 for (int j = i + 1; j < iLength; ++j) {
						  if (iArray[Smallest] > iArray[j]) {
						iArray[Smallest] = j;
				  }
        }
        //this puts the num remaining in where ever i happens to be. 
        int temp = iArray[Smallest];
        iArray[Smallest]  = iArray[i];
        iArray[i] = temp;
    }


}

void Final::HeapSort(){

	

	buildMaxHeap(); //building the max 
	int i;
	int temp;
	for (i = ecx; i >= 2; i--)
	{
		temp = iArray[i];
		iArray[i] = iArray[1];
		iArray[1] = temp;
		maxHeapify();
	}
}

void Final::buildMaxHeap()
{
	for (int j = ecx / 2; j >= 1; j--)
	{
		maxHeapify();//call the hepify
	}
}

void Final::maxHeapify()
{
	//int those variables
	int l;
	int r;
	int largest;
	int location;


	l = 2 * ecx;
	r = (2 * ecx + 1);
	if ((l <= ecx) && iArray[l] > iArray[ecx]){ //lets get the largest values eh?
		largest = l;
	}

	else{
		largest = ecx;
	}

	if ((r <= ecx) && (iArray[r] > iArray[largest])){
		largest = r;
	}

	if (largest != ecx){
		location = iArray[ecx];
		iArray[ecx] = iArray[largest];
		iArray[largest] = location;
		maxHeapify();
	}
}





void Final::CountingSort(){
	//LAST ONEEEE ALMOST DONEEE
    int n=sizeof(int)/sizeof(int);

    int max=iArray[0];//this makes the max


    for (int i=1;i<n;i++){
       
		if (iArray[i]>max) { 
            max=iArray[i];
        }
    }
	//lets get the output in there
    int *output=new int[n];


    for (int i=0;i<n;i++) {
        output[i]=0;
    }

	//declare a temp 
    int *temp=new int[max+1];

    for (int i=0;i<max+1;i++) {
        temp[i]=0;
    }
	//more sorting through
    for (int i=0;i<n;i++){
        temp[iArray[i]]=temp[iArray[i]]+1;
    }

    for (int i=1;i<max+1;i++) {
        temp[i]=temp[i]+temp[i-1];
    }

    for (int  i=n-1;i>=0;i--) {
        output[temp[iArray[i]]-1]=iArray[i];
        temp[iArray[i]]=temp[iArray[i]]-1;
    }

//All the sorting in the world.


}