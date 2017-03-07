#include <iostream>
#include <algorithm>

const int MAX_N = 1000000;

bool used[MAX_N];
int perm[MAX_N];

int N;
// get n! pattern

void permutation1(int pos, int n){
	if (pos == n){

		// processing perm
		for(int j=0; j<n; j++) std::cout << perm[j];
		std::cout << '\n';
		return ;
	}

	// loop to pick up pos of perm from 0...n-1
	for (int i=0; i<n; i++){
		if(!used[i]){
			perm[pos] = i; 
			used[i] = true;
			permutation1(pos + 1, n);
			used[i] = false;
		} 
	} 
	return ;
}

int perm2[MAX_N];

void permutation2(int n){
	for(int i=0; i<n; i++){
		perm2[i] = i;
	}
	do {
		// process perm2
		for(int j=0; j<n; j++) std::cout << perm2[j];
		std::cout << '\n';
	} while (std::next_permutation(perm2, perm2+n));

	return ;
}

int main(){

	std::cout << "Input N :";
	std::cin >> N;
	for(int i=0; i<N; i++) used[i]=false;
	std::cout << "------------------Recursive Function----------------" << '\n';
	permutation1(0,N);
	std::cout << "------------------------Library---------------------" << '\n';
	permutation2(N);

}