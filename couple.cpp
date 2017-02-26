/**
 * CLASS COUPLE
 * containing detail about couple
 */
#include<iostream>
#include<math.h>
#include "couple.h"
 void couple::commit(boy b1, girl g1)
 {
 	b = b1;
 	g = g1;
 	//printf("COMMITED\n");
 } 
 void couple::happiness()
 {
 	//
 	if(g.type == 1) {
 		int temp = giftcost - g.maintainance;
 		if(temp != 0) {
 			happ = log(temp);
 		} else {
 			happ = 0;
 		}
 	} else if(g.type == 2) {
 		happ = giftcost + giftvalue;
 	} else {
 		int temp = giftcost - g.maintainance;
 		happ = temp*log(2);
 	}
 	if(b.type == 1) {
 		happ += (b.budget - giftcost);
 	} else if(b.type == 3) {
 		happ += g.intel;
 	} else {
 		happ += happ;
 	}
 }
 void couple::compatiblity()
 {
 	//
 	cmp = abs(b.budget - g.maintainance) + abs(b.attract - g.attract) + abs(b.intel - g.intel);
 }