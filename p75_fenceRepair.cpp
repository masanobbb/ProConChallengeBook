#include <iostream>
#include <queue>

using namespace std;

#define MAXN 50000

int main(){

	// priority queue in descending order
	priority_queue<int, vector<int>, greater<int> > pque;
	int N, temp;

	cin >> N;
	for (int i=0; i<N; i++){
		cin >> temp;
		pque.push(temp);
	}

	int ans=0,sum=0;
	// get two smallest value from pque
	// add the sum of them into ans
	// push ans into pque
	while ( pque.size() > 1 ){
		sum = pque.top();
		cout << pque.top() << ' ';
		pque.pop();
		sum += pque.top();
		cout << pque.top() << ' ';
		pque.pop();
		cout << ans << endl;
		pque.push(sum);
		ans += sum;
	}

	cout << ans << endl;

}