#include<iostream>
#include "out2.h"
using namespace std;
int main()
{
	freopen("output2.txt","a", stdout);
	matching m;	
	m.gifting();
	for(int i = 0; i < m.ct; i++) {
		m.c[i].happiness();
		m.c[i].compatiblity();
	}
	out2 obj;
	obj.print(m);
	m.sorting();
}