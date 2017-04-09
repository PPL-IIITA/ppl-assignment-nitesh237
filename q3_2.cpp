#include<iostream>
#include "out2.h"
using namespace std;
int main()
{
	freopen("output_q3_2.txt","a", stdout);
	matching m;
	m.match();
	m.gifting();
	out2 obj;
	obj.print(m);
	for(int i = 0; i < m.ct; i++) {
		m.c[i].happiness();
		m.c[i].compatiblity();
	}
	m.sorting();
}