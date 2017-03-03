#include <iostream>

int const MAX_N = 20;

int n;
int nums[MAX_N];
int target;

// depth-first search (深さ優先探索)　再帰関数
// also use global vars : n, *nums, target
bool dfs(int i,int sum);

int main(){

	std::cin >> n;
	for(int i=0; i<n; i++){
		std::cin >> nums[i];
	}

	std::cin >> target;

	if (dfs(0,0)) std::cout << "Yes\n";
	else std::cout << "No\n";

	return 0;
}

bool dfs(int i, int sum){

	if( i==n ) return sum == target;

	if( dfs(i+1, sum+nums[i]) ) return true;

	if( dfs(i+1, sum) ) return true;

	return false;

}