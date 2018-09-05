#include <iostream>
#include <vector>
#include "C11Concepts.h"
using namespace std;

/*Uniform initialization Search Order:
 * 1. Initializer_list constructor
 * 2. Regular constructor that takes the appropriate parameters
 * 3. Aggregate initializer
 */

//1. Initializer's list - Simple
vector<int> v = { 1, 2, 3, 4 };

//2. Class initializer constructor
C11Concepts v1{ 1, 2, 3, 4, 5 };

//3. Aggregate initialization
AggregateInit testObj = { 10, "Tommy" };

//dog d1{ 3 ,"Tommy"};


/* AUTO TYPE
 * Easy to use. Best works for defining the iterator during traversing a container
 */
auto test = { 1, 3 };

/*------FOREACH-------
 *Works best for replacing redundant for loop parameters
 * Works only with containers having begin() and end() functions
 */

/*--------nullptr-------
 *Keyword defined for NULL
 */
void fun(int i){}
void fun(char* p){}


/*---ENUM CLASS------
 *Strong typed check class
 */
enum class ford {figo, ecosport, endeavour, mustang};
enum class chevrolet{spark, cruze, beat};

auto car1 = ford::figo;
auto car2 = chevrolet::beat;
//if (car1 == car2)
//	cout << "How could it be!!";
//else
//	cout << "It's not possible\n";

/*-----DELEGATING CONSTRUCTORS----------
 * Helps in reusing the already written constructors
 * Should always be called first in initializer list
 * 
 */
int main()
{
	fun(NULL);
	fun(nullptr);
	for (auto i : v)
		cout << i;
	return 0;
}