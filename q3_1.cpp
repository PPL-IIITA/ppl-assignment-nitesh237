#include<iostream>
#include<stdlib.h>
#include "matching.h"
using namespace std;
int main()
{
	freopen("output_q3_1.txt","a", stdout);
	matching m;
	m.match();
	for(int i = 0; i < m.ct; i++) {
		printf("%d %s %s\n",i,m.c[i].b.name, m.c[i].g.name);
	}	
}