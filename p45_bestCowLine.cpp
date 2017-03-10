#include <iostream>

const int MAX_N = 2000;
char S[MAX_N+1];
int N;


int main(){
	std::cin >> N;

	for(int i=0; i<N; i++)	std::cin >> S[i];

	int a = 0, b = N-1;

	while(a <= b){

		bool left = false;
		for (int i=0; a+i<=b; i++){
			if( S[a+i] < S[b-i]){
				left = true;
				break;
			}
			else if( S[a+i] > S[b-i] ){
				left = false;
				break;
			}
		}

		if (left) putchar(S[a++]);
		else putchar(S[b--]);
	}

	putchar('\n');
}
