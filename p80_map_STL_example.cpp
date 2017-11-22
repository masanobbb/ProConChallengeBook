#include <cstdio>
#include <map>
using namespace std;

int main(){

	// declear
	// int -> key, const char* -> value
	map<int, const char*> m;

	// insert element
	m.insert(make_pair(1, "ONE"));
	m.insert(make_pair(10, "TEN"));
	m[100] = "HUNDRED";				// another way

	// search element
	map<int, const char*>::iterator ite;
	ite = m.find(1);
	puts(ite->second);				// ONE

	ite = m.find(2);
	if (ite == m.end()) puts("not found");
	else puts(ite->second);

	puts(m[10]);	// another way to search
	puts(m[0]);		// (null) 
					// warning (0, (null)) is added into m in this way

	// delete element
	m.erase(10);

	// loop for all elements
	for (ite = m.begin(); ite != m.end(); ++ite){
		printf("%d: %s\n", ite->first, ite->second);
	}

	return 0;
}
