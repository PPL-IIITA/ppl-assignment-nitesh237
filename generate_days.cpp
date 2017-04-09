/**
 * CLASS generate_days
 * randomly generates days where the gift exchnage takes place
 */
#include "generate_days.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
generate_days::generate_days(int days[], int *t)
{
	srand(time(NULL));
	for(int i = 0; i < 31; i++) {
		days[i] = rand()%2;
		if(days[i] == 1) {
			//cout<<"1"<<endl;
			(*t)++;
		}
	}
	//cout<<*t<<endl;
	*t *= 100;
}