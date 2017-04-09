/**
* Randomly generate a list of boys for questiom 7
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	srand(time(NULL));
	freopen("q7_boys.txt", "w", stdout);
  string bname[] = {"MATT", "JOHN", "TYRIAN", "TRAVIS", "MIKE", "HARVEY", "LOUIS", "TONNY", "SAM", "HARRY", "ROHN", "DANIEL", "FOGGY", "JAMES", "BEN", "EDWARD", "BRUCE", "HODOR", "WILL", "PETER"};
  	int k = rand()%21 + 1;

 	cout<<k<<endl;
 	for(int i = 0; i < k; i++) {
   		cout<<bname[i]<<endl;
 	}
}