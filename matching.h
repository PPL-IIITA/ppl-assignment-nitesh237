/**
 * CLASS MATCHING
 * contains details of al the boys, girls and couples
 */
#include "couple.h"
class matching{
	public:
		int ct; //!< No. of couples
		int bt;	//!< No. of boys
		int gt;	//!< No. of girls 
		couple c[10]; //!< Array of couples
		boy boys[20]; //!< Array of boys
		girl girls[10]; //!< Array of girls
		/** @brief Allocate boyfriends to all girls when matching object is created
 		*
		* Reads the data of girls from girls.txt and store them in g[10]
		* Reads the data of boys from boys.txt and store them in b[20]
		* Couples are formed in the same order as given in the input, and print the couples so formed
	 	*/
		void match();
		/** @brief Allocate boyfriends to all girls when matching object is created
 		*
		* Reads the data of girls from girls.txt and store them in g[10]
		* Reads the data of boys from boys.txt and store them in b[20]
		* Couples are formed in an alternate of girls and boys
		* first girls chooses a boy appropriate for her
		* next a boy chooses the most attractive girl
	 	*/ 
		void match2();
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
		/** @brief Sort all the couples according to happiness 
 		*
		* First all the couples are sorted according to happiness in decreasing order
		* next least k happiest are broken up and new boyfriends are assigned to girls
	 	*/
		void sorting2(); 
		/** @brief Performs breakup between couples
 		*
		* @param c array of couples
		* @param i index of couples where breakup needs to be performed
	 	*/
		void breakup(couple c[], int i);
};