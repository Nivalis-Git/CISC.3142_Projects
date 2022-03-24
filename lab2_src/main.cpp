/* Student Information
  Shterenberg, Simon
  Project 2
*/

#include "calculator.h"

int main()
{
// I. Introduction and rules
	std::string header { "--------Calculator Program--------" },
							footer(header.size(), '-');
	printf("\n%s\n", header.c_str());
	
	char width[4] {' '};
	std::fill_n(width, 4, ' ');
	std::string rl1 { "1. The input alphabet is {0-9, ., (, ), +, -, *, /, ^}" }, 
							rl2 { "2. Whitespace is undreadable--do not include whitespace" };
	
	printf("Rules:\n%s%s\n%s%s\n\n", width, rl1.c_str(), width, rl2.c_str());
	
	
// II. Entering expression
	printf("Enter Expression: ");
	std::string expr;
	std::cin >> expr;
	printf("\n");
	
	
// III. Calculating expression
	Calculator calc;
	calc.evaluate(expr);
	printf("Result: %f", calc.eval);
	printf("\n%s\n\n", footer.c_str());
	
	
	return 0;
}
