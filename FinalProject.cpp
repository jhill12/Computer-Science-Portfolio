//Justin Hill
//Final Project


#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "FinalClass.h"

using namespace std;



int main(){
	//Initialize time. #timelord
	 clock_t t;
	clock_t u;
	clock_t v;
	t = clock();
	
	
	Final* f = new Final();
	
	f->filetoarray();


	//do selection sort
	f->SelectionSort();

		t = clock() - t;
		
	cout << "It took " <<(float)t/1000 << " seconds to use selection sort." << endl;

	
	

	//do heap sort yooooooo
	
	u = clock();

	f->HeapSort();

	u = clock() -t;
	
	cout << "It took only " << (float)u/1000<< " seconds to use the heap sort ! :) " << endl;

	t = clock();

	//counting sort
	v = clock();
	f->CountingSort();

	v = clock() - t;

	cout << "It took "<< (float)v/1000 << " seconds to use the counting sort, yo!" << endl; //YOOOO
	v = clock();

return 0;
}













