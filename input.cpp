/**
 * CLASS INPUT
 * read the randomly generated data and stores them in appropriate data structure
 */
#include "input.h"
#include<iostream>
#include<stdlib.h>
using namespace std;
input::input(boy boys[], girl girls[], int *gt, int *bt)
{
	char tname[10];
	int tattract;
	int tintel;
	int tbudget;
	int tattr_req;
	int ttype;
	int tmaintainance;
	int tchoice;
	FILE *fp1, *fp2;
	fp1 = fopen("boys.txt", "r");
	fp2 = fopen("girls.txt", "r");
	int n;
	fscanf(fp1,"%d", &n);
	//boy b[20];
	//cout<<n<<endl;
	*bt = n;
	for(int i = 0; i < n; i++) {
		boy *temp;
		fscanf(fp1,"%s %d %d %d %d %d", tname, &tattract, &tintel, &tbudget, &tattr_req, &ttype);
		if(ttype == 1) {
			temp = new miser(tname, tattract, tintel, tbudget, tattr_req);
		} else if(ttype == 2) {
			temp = new generous(tname, tattract, tintel, tbudget, tattr_req);
		} else {
			temp = new geek(tname, tattract, tintel, tbudget, tattr_req);
		}
		boys[i] = *temp;
	}
	/*for(int i = 0; i < n; i++) {
		cout<<boys[i].name<<" "<<boys[i].attract<<" "<<boys[i].intel<<" "<<boys[i].budget<<" "<<boys[i].attr_req<<" "<<boys[i].type<<" "<<boys[i].commited<<endl;
	}
	cout<<endl;*/
	int m;
	fscanf(fp2,"%d", &m);
	*gt  = m;
	//girl g[10];
	for(int i = 0; i < m; i++) {
		girl *temp;
		fscanf(fp2,"%s %d %d %d %d %d", tname, &tattract, &tintel, &tmaintainance, &ttype, &tchoice);
		if(ttype == 1){
			temp = new choosy(tname, tattract, tintel, tmaintainance, tchoice);
		} else if(ttype == 2) {
			temp = new normal(tname, tattract, tintel, tmaintainance, tchoice);
		} else {
			temp = new desparate(tname, tattract, tintel, tmaintainance, tchoice);
		}
		girls[i] = *temp;
	}
	/*for(int i = 0; i < m; i++) {
		cout<<girls[i].name<<" "<<girls[i].attract<<" "<<girls[i].intel<<" "<<girls[i].maintainance<<" "<<girls[i].type<<" "<<girls[i].choice<<" "<<girls[i].commited<<endl;
	}*/
	//couple c[10];
}