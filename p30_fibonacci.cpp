#include <cstdio>

int fib(int num);

int main(){

	int num;

	scanf("%d", &num);

	printf("%d\n",fib(num));

	return 0;
}

int fib(int num){
	if(num<=1) return num;
	else return fib(num-1) + fib(num-2);
}