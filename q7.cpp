#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "linear_search.h"
#include "bin_search.h"
#include "hash_search.h"
using namespace std;
int main()
{
	srand(time(NULL));
	freopen("output_q7.txt","a", stdout);
	int n;
	FILE *fp = fopen("q7_boys.txt","r");
	fscanf(fp,"%d", &n);
	char **names;
	searching *s = new searching();
	s->match();
	names = (char **) malloc(n * sizeof(char *));
	for(int i = 0 ; i < n; i++) {
		names[i] = (char *)malloc(6*sizeof(char));
	}
	for(int i = 0 ; i < n; i++) {
		fscanf(fp,"%s",names[i]);
		cout<<names[i]<<endl;
	}
	linear_search *ls = (linear_search *)s;
	bin_search *bs = (bin_search *)s;
	hash_search *hs = (hash_search *)s;
	int ch;
	/*cout<<"1. Linear Search"<<endl;
	cout<<"2. Binary Search"<<endl;
	cout<<"3. Hash Search"<<endl;	*/
	ch = rand()%4 + 1;
	switch(ch) {
		case 1:	cout<<"linear search"<<endl;
				ls->search(names, n);
				break;
		case 2:	cout<<"binary search"<<endl;
				bs->search(names, n);
				break;
		default:cout<<"hash search"<<endl;
				hs->search(names, n);
				break;
	}
}