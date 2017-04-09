/**
 * CLASS MATCHING
 * contains details of al the boys, girls and couples
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "matching.h"
#include "essential.h"
#include "luxury.h"
#include "utility.h"
using namespace std;
void matching::match()
{
	ct = 0;
	input in(boys, girls, &gt, &bt);
	for(int i = 0; i < gt; i++) {
		int id = -1;
		boy max = boys[0];
		for(int j = 0; j < bt; j++) {
			if(boys[j].budget < girls[i].maintainance || girls[i].attract < boys[j].attr_req || boys[j].commited == true) {
				continue;
			}
			if(girls[i].choice == 1) {
				if(max.attract < boys[j].attract) {
					max = boys[j];
					id = j;
				}
			} else if(girls[i].choice == 2) {
				if(max.budget < boys[j].budget) {
					max = boys[j];
					id = j;
				}
			} else {
				if(max.intel < boys[j].intel) {
					max = boys[j];
					id = j;
				}
			}
		}
		if(id != -1 && boys[id].commited == false) {
			//printf("%s %s\n",max.name, g[i].name);
			c[ct++].commit(max, girls[i]);
			//cout<<"$"<<id<<" "<<i<<endl;
			boys[id].commited = true;
			girls[i].commited = true;
		}
	}
}
void matching::match2()
{
	int gcnt = 0;
	int bcnt = 0;
	int cnt = 0;
	ct = 0;
	input in(boys, girls, &gt, &bt);
	while(cnt != gt) {
		if(cnt % 2 == 0) {
			while(girls[gcnt].commited == true) {
				gcnt++;
			}
			int id = -1;
			boy max = boys[0];
			for(int j = 0; j < bt; j++) {
				if(boys[j].budget < girls[gcnt].maintainance || girls[gcnt].attract < boys[j].attr_req || boys[j].commited == true) {
					continue;
				}
				if(girls[gcnt].choice == 1) {
					if(max.attract < boys[j].attract) {
						max = boys[j];
						id = j;
					}
				} else if(girls[gcnt].choice == 2) {
					if(max.budget < boys[j].budget) {
						max = boys[j];
						id = j;
					}
				} else {
					if(max.intel < boys[j].intel) {
						max = boys[j];
						id = j;
					}
				}
			}
			if(id != -1 && boys[id].commited == false) {
				//printf("%s %s\n",max.name, g[i].name);
				c[ct++].commit(max, girls[gcnt]);
				//cout<<"$"<<id<<" "<<i<<endl;
				boys[id].commited = true;
				girls[gcnt].commited = true;
			}
			gcnt++;
		} else {
			while(boys[bcnt].commited == true) {
				bcnt++;
			}
			int id = -1;
			girl max = girls[0];
			for(int i = 0; i < gt; i++) {
				if(boys[bcnt].budget < girls[i].maintainance || girls[i].commited == true) {
					continue;
				}
				if(max.attract < girls[i].attract) {
					max = girls[i];
					id = i;
				}
			}
			if(id != -1) {
				c[ct++].commit(boys[bcnt], girls[id]);
				boys[bcnt].commited = true;
				girls[id].commited = true;
			}
			bcnt++;	
		}
		cnt++;
	}
	for(int i = 0; i < ct; i++) {
		cout<<i<<" "<<c[i].b.name<<" "<<c[i].g.name<<endl;
	}
}
void matching::gifting()
{
	int ttype;
	int tprice;
	int tvalue;
	int tluxury;
	int tdifficulty;
	int tutility;
	FILE *fp1;
	fp1 = fopen("gift_store.txt","r");
	int n;
	gift store[30];
	fscanf(fp1,"%d", &n);
	for(int i = 0; i < n; i++) {
		gift *temp;
		fscanf(fp1, "%d %d %d", &ttype, &tprice, &tvalue);
		if(ttype == 1) {
			temp = new essential(tprice, tvalue);
		} else if(store[i].type == 2) {
			fscanf(fp1,"%d %d",&tluxury, &tdifficulty);
			temp = new luxury(tprice, tvalue, tluxury, tdifficulty);
		} else {
			fscanf(fp1,"%d", &tutility);
			temp = new utility(tprice, tvalue, tutility);
		}
		store[i] = *temp;
	}
	for(int i = 0; i < ct; i++) {
		c[i].bk = 0;
		//int flag = 0;
		c[i].basket[c[i].bk++] = store[0];
		c[i].giftcost += store[0].price;
		c[i].giftvalue += store[0].value;
		if(c[i].b.type == 1 || c[i].b.type == 3) {
			for(int j = 1; j < n; j++) {
				if(c[i].giftcost < c[i].g.maintainance) {
					c[i].basket[c[i].bk++] = store[j];
					c[i].giftcost += store[j].price;
					c[i].giftvalue += store[j].value;
				} 
			}
			if(c[i].b.budget < c[i].giftcost) {
				c[i].b.budget = c[i].giftcost;
			}
		} else {
			for(int j = 1; j < n; j++) {
				if(c[i].giftcost < c[i].g.maintainance) {
					c[i].basket[c[i].bk++] = store[j];
					c[i].giftcost += store[j].price;
					c[i].giftvalue += store[j].value;
					continue;
				}
				if(c[i].giftcost > c[i].b.budget) {
					c[i].b.budget = c[i].giftcost;
					break;
				} else {
					if(c[i].giftcost + store[j].price <= c[i].b.budget) {
						c[i].basket[c[i].bk++] = store[j];
						c[i].giftcost += store[j].price;
						c[i].giftvalue += store[j].value;
					} else {
						break;
					} 
				}
			}
		} 
	}
}
void matching::sorting()
{
	srand(time(NULL));
	couple temp;
	for(int i = 0; i < ct-1; i++) {
		for(int j = 0; j < ct-i-1; j++) {
			if(c[j].happ < c[j+1].happ) {
				temp = c[j+1];
				c[j+1] = c[j];
				c[j] = temp;
			}
		}
	}
	int k = ((rand()%(ct+1)) + 1);
	cout<<"HAPPIEST "<<k<<" COUPLES-"<<endl<<endl;
	for(int i = 0; i < k; i++) {
		cout<<i<<" "<<c[i].b.name<<" "<<c[i].g.name<<endl;
		cout<<"HAPPINESS- "<<c[i].happ<<endl;
		cout<<"COMPATIBILITY- "<<c[i].cmp<<endl;
	
	}
	cout<<endl<<"COMPATIBLE "<<k<<" COUPLES-"<<endl<<endl;
	for(int i = 0; i < ct-1; i++) {
		for(int j = 0; j < ct-i-1; j++) {
			if(c[j].cmp < c[j+1].cmp) {
				temp = c[j+1];
				c[j+1] = c[j];
				c[j] = temp;
			}
		}
	}
	for(int i = 0; i < k; i++) {
		cout<<i<<" "<<c[i].b.name<<" "<<c[i].g.name<<endl;
		cout<<"HAPPINESS- "<<c[i].happ<<endl;
		cout<<"COMPATIBILITY- "<<c[i].cmp<<endl;
	
	}
}
void matching::sorting2()
{
	srand(time(NULL));
	couple temp;
	for(int i = 0; i < ct-1; i++) {
		for(int j = 0; j < ct-i-1; j++) {
			if(c[j].happ < c[j+1].happ) {
				temp = c[j+1];
				c[j+1] = c[j];
				c[j] = temp;
			}
		}
	}
	int k = ((rand()%(ct+1)) + 1);
	cout<<"LEAST HAPPIEST "<<k<<" COUPLES-"<<endl<<endl;
	int end = ct-k;
	for(int i = ct-1; i >= end; i--) {
		cout<<i<<" "<<c[i].b.name<<" "<<c[i].g.name<<endl;
		cout<<"HAPPINESS- "<<c[i].happ<<endl;
		cout<<"COMPATIBILITY- "<<c[i].cmp<<endl;
		//ct--;
		//int gid = -1;
		breakup(c, i);
	}
	cout<<endl<<endl;

	for(int i = ct-1; i >= 0; i--) {
		cout<<i<<" "<<c[i].b.name<<" "<<c[i].g.name<<endl;
	}

}
void matching::breakup(couple c[], int i)
{
	int bid = -1;
		int id = -1;
		boy max = boys[0];
		girl gl = c[i].g;
		for(int j = 0; j < bt; j++) {
			if(!strcmp(c[i].b.name, boys[j].name)) {
				bid = j;
			}
			if(boys[j].budget < gl.maintainance || gl.attract < boys[j].attr_req || boys[j].commited == true) {
				continue;
			}
			if(gl.choice == 1) {
				if(max.attract < boys[j].attract) {
					max = boys[j];
					id = j;
				}
			} else if(gl.choice == 2) {
				if(max.budget < boys[j].budget) {
					max = boys[j];
					id = j;
				}
			} else {
				if(max.intel < boys[j].intel) {
					max = boys[j];
					id = j;
				}
			}
		}
		if(id != -1 && boys[id].commited == false) {
			//printf("%s %s\n",max.name, g[i].name);
			cout<<c[i].b.name<<" Breaking Up with "<<c[i].g.name<<endl;
			//cout<<boys[bid].name<<endl;
			boys[bid].commited = false;
			c[i].commit(max, c[i].g);
			//cout<<"$"<<id<<" "<<i<<endl;
			cout<<c[i].b.name<<" Commiting to "<<c[i].g.name<<endl;
			//cout<<boys[id].name<<endl;
			boys[id].commited = true;
			//g[i].commited = true;
		} else if(id == -1) {
			cout<<c[i].b.name<<" Breaking Up with "<<c[i].g.name<<endl;
			for(int j = i; j < ct-1; j++) {
				c[j] = c[j+1];
			}
			--ct;
			//cout<<ct<<endl;
			for(int j =0; j < gt; j++) {
				if(!strcmp(c[i].g.name ,girls[j].name))
					girls[j].commited = false;
			}
			//cout<<boys[bid].name<<endl;
			boys[bid].commited = false;
		}
}