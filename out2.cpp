#include<iostream>
#include <stdlib.h>
#include <ctime>
#include "out2.h"
using namespace std;
void out2::print(matching m)
{
		for(int i = 0; i < m.ct; i++) {
		cout<<i<<" "<<m.c[i].b.name<<" "<<m.c[i].g.name<<endl;
		cout<<"MAINTAINANCE- "<<m.c[i].g.maintainance<<endl;
		cout<<"BUDGET- "<<m.c[i].b.budget<<endl;
		cout<<"GIFT EXCHANGED-"<<endl;
		for(int j = 0; j < m.c[i].bk; j++) {
			time_t now = time(0);
			char* time = ctime (&now);
			cout <<time<<endl;
			int t = m.c[i].basket[j].type;
			cout<<"Type- "<<t<<" ";
			if(t == 1) {
				cout<<"Price- "<<m.c[i].basket[j].e.price<<" "<<"Value- "<<m.c[i].basket[j].e.value<<endl;
			} else if(t == 2) {
				cout<<"Price- "<<m.c[i].basket[j].l.price<<" "<<"Value- "<<m.c[i].basket[j].l.value<<endl;
			} else {
				cout<<"Price- "<<m.c[i].basket[j].u.price<<" "<<"Value- "<<m.c[i].basket[j].u.value<<endl;
			}
		}
		cout<<endl;
	}		
}