#include <cstdio>
#include <set>
using namespace std;

int main(){

	// declear
	set<int> s;

	// adding elements
	s.insert(1);
	s.insert(3);
	s.insert(5);

	// search element
	set<int>::iterator ite;

	ite = s.find(1);
	if (ite == s.end()) puts("not found");
	else puts("found");

	ite = s.find(2);
	if (ite == s.end()) puts("not found");
	else puts("found");

	// delete element
	s.erase(3);

	// search element in another way
	if (s.count(3) != 0) puts("found");
	else puts("not found");

	// loop for all elements
	for (ite = s.begin(); ite != s.end(); ++ite) {
		printf("%d\n", *ite);
	}

	return 0;
}