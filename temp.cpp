#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "matching.h"
#include "generate_days.h"
using namespace std;
int main()
{
	int days[31];
	int t;
	generate_days obj(days, &t);
	matching m;
	m.match();
	for(int i = 0; i < 31; i++) {
		if(days[i]) {
			m.gifting();
			for(int i = 0; i < m.ct; i++) {
				m.c[i].happiness();
				if(m.c[i].happ < t) {
					m.breakup(m.c, i);
				}
				m.c[i].giftcost = 0;
				m.c[i].giftvalue = 0;
			}
		}
	}
}