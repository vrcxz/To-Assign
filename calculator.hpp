#ifndef TO_ASSIGN_CALCULATOR_H_
#define TO_ASSIGN_CALCULATOR_H_

namespace calculator {
	
	int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else {
        return 0;
    }
}

string infixToPostfix(string infix) {
    stack<char> opStack;
    stringstream postfix;
    for (char c : infix) {
        if (isdigit(c)) {
            postfix << c;
        } else if (c == '(') {
            opStack.push(c);
        } else if (c == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                postfix << opStack.top();
                opStack.pop();
            }
            opStack.pop();
        } else {
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(c)) {
                postfix << opStack.top();
                opStack.pop();
            }
            opStack.push(c);
        }
    }
    while (!opStack.empty()) {
        postfix << opStack.top();
        opStack.pop();
    }
    return postfix.str();
}

int evaluatePostfix(string postfix) {
    stack<int> operands;
    for (char c : postfix) {
        if (isdigit(c)) {
            operands.push(c - '0');
        } else {
            if (operands.size() < 2) {
                throw runtime_error("Syntax error");
            }
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();
            switch (c) {
                case '+':
                    operands.push(operand1 + operand2);
                    break;
                case '-':
                    operands.push(operand1 - operand2);
                    break;
                case '*':
                    operands.push(operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        throw runtime_error("Divide by zero");
                    }
                    operands.push(operand1 / operand2);
                    break;
                default:
                    throw runtime_error("Invalid character");
            }
        }
    }
    if (operands.size() != 1) {
        throw runtime_error("Syntax error");
    }
    return operands.top();
}

void main(){
	cout<<"Input 0 to exit:\n";
	
	while(1){
	string infix = "0";
    cin>>infix;
    if(infix=="0")return;
    if (cin.fail()) {
  	      cout << "Invalid input" << endl;
  	      cin.clear();
	        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }
		    string postfix = infixToPostfix(infix);
 		   int result = evaluatePostfix(postfix);
		    cout << "= " << result << endl;
			}
		}
	
}

#endif
