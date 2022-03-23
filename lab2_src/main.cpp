/* Student Information
  Shterenberg, Simon
  Project 2
*/

#include "calculator.h"

int main()
{
	using namespace std;

// I. 
	printf("Enter: ");
	string expr;
	cin >> expr;
	printf("\n");
	
	Calculator calc;
	
	calc.evaluate(expr);
	printf("Result: %f\n", calc.eval);
	
	
// . End of program
	return 0;
}
