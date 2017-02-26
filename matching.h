/**
 * CLASS MATCHING
 * contains details of al the boys, girls and couples
 */
#include "couple.h"
class matching{
	public:
		int ct; //!< No. of couples
		couple c[10]; //!< Array of couples
		boy b[20]; //!< Array of boys
		girl g[10]; //!< Array of girls
		/** @brief Allocate boyfriends to all girls when matching object is created
 		*
		* Reads the data of girls from girls.txt and store them in g[10]
		* Reads the data of boys from boys.txt and store them in b[20]
		* Couples are formed in the same order as given in the input, and print the couples so formed
	 	*/
		matching(); 
		/** @brief Gift basket of all couples are filled according to given constraints
 		*
	 	*/
		void gifting();
		/** @brief Sort all the couples according to happiness and compatibility
 		*
		* First all the couples are sorted according to happiness in decreasing order
		* next all the couples are sorted according to compatibility in decreasing order
	 	*/
		void sorting(); 
};