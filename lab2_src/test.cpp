// CPP program to convert infix to prefix
#include <bits/stdc++.h>
using namespace std;

double evaluatePrefix(string exprsn)
{
    stack<double> Stack;
 
    for (int j = exprsn.size() - 1; j >= 0; j--) {
       
        // if jth character is the delimiter ( which is
        // space in this case) then skip it
        if (exprsn[j] == ' ')
            continue;
 
        // Push operand to Stack
        // To convert exprsn[j] to digit subtract
        // '0' from exprsn[j].
        if (isdigit(exprsn[j])) {
           
            // there may be more than
            // one digits in a number
            double whole = 0.0, frac = 0.0;
            int i = j;
            while (j < exprsn.size() && isdigit(exprsn[j]))
            {
                j--;
            }
            
            if (exprsn[j]=='.')
            {
            	//frac = double(exprsn[j+1] - '0')/10;
            	for (int k = j+1; k <= i; k++)
            	{
            		frac += double(exprsn[k] - '0') / pow(10, (k-j));
            	}
            	
            	j--;
            	i = j;
            	while (j < exprsn.size() && isdigit(exprsn[j]))
            	{
              	j--;
            	}
            }
            
            j++;
            // from [j, i] exprsn contains a number
            for (int k = j; k <= i; k++)
            	whole = whole * 10 + double(exprsn[k] - '0');
 
            Stack.push(whole+frac);
        }
        else {
 
            // Operator encountered
            // Pop two elements from Stack
            double o1 = Stack.top();
            Stack.pop();
            double o2 = Stack.top();
            Stack.pop();
 
            // Use switch case to operate on o1
            // and o2 and perform o1 O o2.
            switch (exprsn[j]) {
            case '+':
                Stack.push(o1 + o2);
                break;
            case '-':
                Stack.push(o1 - o2);
                break;
            case '*':
                Stack.push(o1 * o2);
                break;
            case '/':
                Stack.push(o1 / o2);
                break;
            case '^':
            	Stack.push( pow(o1, o2) );
            	break;
            }
        }
    }
 
    return Stack.top();
}

bool isOperator(char c)
{
	return (!isalpha(c) && !isdigit(c));
}

int getPriority(char C)
{
	if (C == '-' || C == '+')
		return 1;
	else if (C == '*' || C == '/')
		return 2;
	else if (C == '^')
		return 3;
	return 0;
}

string infixToPostfix(string infix)
	{
		infix = '(' + infix + ')';
		int size = infix.size();
		stack<char> stack;
		string postfix;
		
		// I. Push the characters into the stack in postfix order
		for (int i = 0; i < size; i++)
		{
			// i. If an operand, append it to output
			if (isalpha(infix[i]) || isdigit(infix[i]) || infix[i]=='.')
			{
				postfix += infix[i];
			}
			
			// ii. If ‘(‘, push it to stack
			else if (infix[i] == '(')
			{
				stack.push('(');
			}
			
			// iii. If ‘)’, pop from stack and append to output until ‘(‘ is encountered
			else if (infix[i] == ')')
			{
				while (stack.top() != '(')
				{
					postfix += " ";
					postfix += stack.top();
					stack.pop();
				}
				stack.pop();  // pop '(' from stack
			}
			
			// iv. Operator found
			else if ( ispunct(stack.top()) )
			{
			  postfix += " ";
			    
				if(infix[i] == '^')
				{
					while ( getPriority(infix[i]) <= getPriority(stack.top()) )
					{
						postfix += stack.top();
						stack.pop();
					}
				} else {
					while ( getPriority(infix[i]) < getPriority(stack.top()) )
					{
						postfix += stack.top();
						postfix += " ";
						stack.pop();
					}
				}
				
				stack.push(infix[i]);  // push current operator on stack
			}
		}
		
		// II. Append remaining characters
		while(!stack.empty())
		{
			postfix += stack.top();
			stack.pop();
		}
		
		// III. Return the postfix expression
		printf("%s\n", postfix.c_str());
		return postfix;
	}

string infixToPrefix(string infix)
{
	/* Reverse String
	* Replace ( with ) and vice versa
	* Get Postfix
	* Reverse Postfix * */
	int l = infix.size();

	// Reverse infix
	reverse(infix.begin(), infix.end());

	// Replace ( with ) and vice versa
	for (int i = 0; i < l; i++) {

		if (infix[i] == '(') {
			infix[i] = ')';
			i++;
		}
		else if (infix[i] == ')') {
			infix[i] = '(';
			i++;
		}
	}

	string prefix = infixToPostfix(infix);

	// Reverse postfix
	reverse(prefix.begin(), prefix.end());

	return prefix;
}

// Driver code
int main()
{
	string s = ("5+(5*5)+4^(7/2)/2.4+7.77");
	string prefix = infixToPrefix(s);
	cout << prefix << std::endl;
	printf("%f\n", evaluatePrefix(prefix));
	return 0;
}

