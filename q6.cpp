#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "out2.h"
#include "generate_days.h"
using namespace std;
int main()
{
	freopen("output_q6.txt","a", stdout);
	int days[31];
	int t;
	generate_days obj(days, &t);
	matching m;
	m.match();
	for(int i = 0; i < 31; i++) {
		if(days[i]) {
			cout<<"Day "<<i<<endl;
			m.gifting();
			for(int i = 0; i < m.ct; i++) {
				m.c[i].happiness();
				if(m.c[i].happ < t) {
					m.breakup(m.c, i);
				}
				m.c[i].giftcost = 0;
				m.c[i].giftvalue = 0;
			}
			cout<<endl;
		}
	}
}