#include <iostream>

#define MAX_N 10000
int heap[MAX_N], sz = 0;

void push(int x){

	int i = sz++;

	while (i > 0){
		// the number of a parent's node
		int p = (i-1) / 2;

		if(heap[p] <= x) break;

		heap[i] = heap[p];
		i = p;
	}

	heap[i] = x;
}

int pop(){
	// min
	int ret = heap[0];

	// root variable
	int x = heap[--sz];

	// drug x from root
	int i = 0;
	while (i*2+1<sz){
		// compare children
		int a = i * 2 + 1, b = i * 2 + 2;
		if (b < sz && heap[b] < heap[a]) a = b;

		if (heap[a] >= x) break;

		heap[i] = heap[a];
		i = a;
	}

	heap[i] = x;

	return ret;
}

int main(){

	int size;

	std::cout << "Input size: ";
	std::cin >> size;
	std::cout << "Input numbers: ";

	// input numbers
	for(int i=0; i<size; i++){
		int temp;
		std::cin >> temp;
		push(temp);
	}

	// print all in accending order
	for(int i=0; i<size; i++){
		std::cout << pop() << ',';
	}
	std::cout << std::endl;
	return 0;
}