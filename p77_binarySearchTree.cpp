
#include <iostream>
#include <cstdio>

struct node{
	int val;
	node *lch, *rch;
};

// add x
node *insert(node *p, int x){
	if(p == NULL){
		node *q = new node;
		q->val = x;
		q->lch = q->rch = NULL;
		return q;
	}
	else {
		if(x < p->val) p->lch = insert(p->lch,x);
		else p->rch = insert(p->rch, x);
		return p;
	}
}

// looking for x
bool find(node *p, int x){
	if (p == NULL) return false;
	else if (x == p->val) return true;
	else if (x < p->val) return find(p->lch, x);
	else return find(p->rch, x);
}

// delete x
node *remove(node *p, int x){
	if (p == NULL) return NULL;
	else if (x < p->val) p->lch = remove(p->lch, x);
	else if (x > p->val) p->rch = remove(p->rch, x);
	else if (p->lch == NULL) {
		node *q = p->rch;
		delete p;
		return q;
	}
	else if (p->lch->rch == NULL) {
		node *q = p->lch;
		q->rch = p->rch;
		delete p;
		return q;
	}
	else {
		node *q;
		for (q = p->lch; q->rch->rch != NULL; q = q->rch);
		node *r = q->rch;
		q->rch = r->lch;
		r->lch = p->lch;
		r->rch = p->rch;
		delete p;
		return r;
	}
	return p;
}

int main(){

	node *tree = new node;
	tree = NULL;

	char input;
	int x;

	while(1){
		std::cout << "i:insert, f:find, r:remove" << std::endl;
		std::cin >> input;

		if (input == 'i'){
			std::cout << "Input num : ";
			std::cin >> x;
			tree = insert(tree, x);
		}
		else if (input == 'f'){
			std::cout << "Find num : ";
			std::cin >> x;
			if (find(tree,x))
				std::cout << "Found!" << std::endl;
			else
				std::cout << "Not found" << std::endl;
		}
		else if (input == 'r'){
			std::cout << "Remove num : ";
			std::cin >> x;
			tree = remove(tree, x);
		}
		else break;
	}
	
	std::cout << std::endl;
	return 0;
}


