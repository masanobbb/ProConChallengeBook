#include <iostream>
#include <queue>
using namespace std;

#define MAXL 1000000

int main(){
	priority_queue<int> pque;

	int N, L, P;
	int A[MAXL], B[MAXL];

	cout << "Input N, L, P: ";
	cin >> N >> L >> P;

	cout << "Input A: ";
	for( int i=0; i<N; i++)
		cin >> A[i];
	
	cout << "Input B: ";
	for( int i=0; i<N; i++)
		cin >> B[i];

	int ans=0, pos=0, tank = P;

	for( int i=0; i<N; i++){

		int d = A[i] - pos;
		
		while (tank - d < 0){

			if (pque.empty()){
				puts("-1");
				return 0;
			}

			tank += pque.top();
			pque.pop();
			ans++;
		}

		tank -= d;
		pos = A[i];
		pque.push(B[i]);

	}

	cout << endl << "Answer: ";
	cout << ans << endl;

}