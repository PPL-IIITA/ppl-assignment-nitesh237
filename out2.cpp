/**
 * CLASS OUT2
 * prints all the gifts exchanged between couples along with k happiest and compatible couples
 */
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
			cout<<"Price- "<<m.c[i].basket[j].price<<" "<<"Value- "<<m.c[i].basket[j].value<<endl;
			
		}
		cout<<endl;
	}		
}