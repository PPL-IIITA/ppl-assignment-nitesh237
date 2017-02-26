#include<iostream>
#include<stdlib.h>
#include "matching.h"
using namespace std;
int main()
{
	freopen("output.txt","a", stdout);
	matching m;
	for(int i = 0; i < m.ct; i++) {
		printf("%d %s %s\n",i,m.c[i].b.name, m.c[i].g.name);
	}	
}