#include "linear_search.h"
#include <iostream>
#include <string.h>
using namespace std;
void linear_search::search(char **names, int n)
{
	//cout<<"1"<<endl;
	for(int i = 0; i < n; i++) {
		int flag = 0;
		for(int j = 0; j < ct; j++) {
			if(!strcmp(names[i],c[j].b.name)) {
				flag = 1;
				cout<<c[j].g.name<<endl;
				break;
			}
		}
		if(flag == 0) {
			cout<<"No Girlfriend"<<endl;
		}
	}
}