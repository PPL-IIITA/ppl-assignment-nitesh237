#include <iostream>
#include <map>
#include <string.h>
#include "bin_search.h"
using namespace std;
void bin_search::search(char **names, int n)
{
	//cout<<"2"<<endl;
	map <string, string> mp;
	map <string, string> :: iterator it;
	string bb, gg; 
	for(int i = 0; i < ct; i++) {
		bb = c[i].b.name;
		gg = c[i].g.name;
		mp[bb] = gg;
	}
	for(int i = 0; i < n; i++) {
		it = mp.find(names[i]);
		if(it != mp.end()){
			cout<<it->second<<endl;
		} else {
			cout<<"No Girlfriend"<<endl;
		}
	}
}