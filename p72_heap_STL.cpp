#include <queue>
#include <cstdio>
#include <iostream>

using namespace std;

int main(){

	// in descending order
	//priority_queue<int> pque;

	// in ascending order
	priority_queue<int, vector<int>, greater<int> > pque;

	int size;

	cout << "Input size: ";
	cin >> size;
	cout << "Input numbers: ";

	// input numbers
	for(int i=0; i<size; i++){
		int temp;
		cin >> temp;
		pque.push(temp);
	}

	// print all in accending order
	while( !pque.empty() ){
		cout << pque.top() << ',';
		pque.pop();
	}
	cout << "\n";
	return 0;
}