#include <iostream>
#include <string>
#include <iomanip>
#include <stack>

using namespace std;

bool isOperand(char c);

bool isOperator(char c);

char result(int &num);

void table(string f);

void collapseOperands();


// declare globals
stack<char> operands;
stack<char> operators;
int resNum = 0;

int main()
{
  cout << "Give me an expression: ";
  string expr;
  getline(cin, expr);

  table(expr);
  return 0;
}

bool isOperand(char c)
{
  //determines whether or not the charater is an operand
  string validOperands = "abcdefghijklm";
  if (validOperands.find(c) == -1)
  {
    return false;
  }
  return true;
}

bool isOperator(char c)
{
  //determines whether or not the characte is an operator
  string validOperators = "+-/*";
  if (validOperators.find(c) == -1)
  {
    return false;
  }
  return true;
}

char result(int &num)
{
  //generates result value based on how many times the function is called
  string resultString = "zyxwvutsrqpon";
  char newLetter = resultString[num];
  num++;

  return newLetter;
}

bool currentHasPrecendence(char current, char top)
{
  //determines which functions have precendence
  if ((top == '+' || top == '-') && (current == '/' || current == '*'))
  {
    return true;
  }
  return false;
}

void collapseOperands()
{
  // Pop top operator off stack along with pair of operands and writing new line in output table
  char top = operators.top();
  operators.pop();
  char op2 = operands.top();
  operands.pop();
  char op1 = operands.top();
  operands.pop();

  // get result and push onto operand stack
  char res = result(resNum);
  operands.push(res);


  cout << setw(15) << top << setw(15) << op1 << setw(15) << op2 << setw(15) << res << endl;
}

void table(string expr)
{
  char current;
  char topOp;


  cout << setw(15) << "Operator" << setw(15) << "Operand1" << setw(15) << "Operand2" << setw(15) << "Result" << endl;
  cout << setw(15) << "--------" << setw(15) << "--------" << setw(15) << "--------" << setw(15) << "------" << endl;

  for (int i = 0; i < expr.length(); i++)
  {
    current = expr[i];

    // If current is blank, ignore it
    if (isspace(current))
      continue;

    // current cannot be blank

    // If current not blank, operand, or operator then display error and exit
    if (!isOperand(current) && !isOperator(current))
    {
      cout << "Error: Not an Operand or Operator" << endl;
      break;
    }

    // If operand push onto operand stack
    if (isOperand(current))
    {
      operands.push(current);
      continue;
    }

    // If operator, compare precedence to operator at top of stack

    if (isOperator(current))
    {
      if (operators.empty())
      {
        operators.push(current);
        continue;
      }

      topOp = operators.top();
      while (true)
      {

        // If current operator has higher precendence than top push onto stack
        if (currentHasPrecendence(current, topOp))
        {
          operators.push(current);
          break;
        }
         // if current has same or lower precedence, need to evaluate operator on top of stack
        else
        {

          collapseOperands();

          // next, compare current op to topOp
          if (!operators.empty())
          {
            topOp = operators.top();
            continue;
          }
          {
            // no more operators in stack
            // at this point, push current operator onto top of stack and examine next character in string
            operators.push(current);

            break;
          }
         }
      }
    }
  }
  // outside for loop
  // when end of string is reached, pop remaining operator and operand pair and print
  while (!operators.empty()) {
    collapseOperands();
  }
}
