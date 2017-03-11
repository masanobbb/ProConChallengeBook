#include <iostream>

const int N_MAX = 100;
int N, W;
int w[N_MAX], v[N_MAX];

// i番目以降の品物から重さの総和がj以下となるように選ぶ
int rec(int i, int j){

	int res;
	if( i==N ){
		// not exist
		res = 0;
	} else if( j<w[i] ){
		// too heavy to select
		res = rec(i+1, j);
	} else{
		// try both to select and not to do
		res = std::max(rec(i+1, j), rec(i+1, j-w[i]) + v[i]);
	} 

	return res;

}


int main(){


	std::cin >> N;
	for(int i=0; i<N; i++){
		std::cin >> w[i] >> v[i];
	}
	std::cin >> W;

	std::cout << rec(0,W) << '\n';

}