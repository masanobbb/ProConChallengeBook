#include <iostream>

const int N_MAX = 1000;
int X[N_MAX];
int N, R;

int main(){

	std::cin >> N >> R;

	for(int i=0; i<N; i++){
		std::cin >> X[i];
	}

	std::sort(X,X+N);	// from textbook. I missed it.

	int i = 0;
	int s = X[i];
	int ans = 0;
	while(i<N){
		
		if(X[i]-s >= R){
			ans++;
			s = X[i];
		}
		i++;
	}
	std::cout << "myAns:" << ans <<'\n';


	// textbook code
	i = 0;
	ans = 0;
	while(i<N){

		int s = X[i++];

		while( i<N && X[i] <= s+R) i++;

		int p = X[i-1];

		while ( i<N && X[i] <= p+R) i++;

		ans++;
	}
	std::cout << "textbook Ans:" << ans <<'\n';
}