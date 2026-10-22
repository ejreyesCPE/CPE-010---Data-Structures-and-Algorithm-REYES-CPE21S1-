#include <iostream>
#include <string>

const size_t maxCap = 100;
char stack[maxCap];
int posStack[maxCap];
int top = -1, i;
bool errorFound = false;

bool isEmpty();
bool isFull();
void push(char symbol, int position);
void push();
void pop();
void Top();
void displayStack();
void checkExpression();

int main() {
    int choice;

    std::cout << "Enter the number of max elements for the new stack: ";
    std::cin >> i;

    while (true) {
        std::cout << "\nStack Operations" << std::endl;
        std::cout << " 1. PUSH \n 2. POP \n 3. TOP \n 4. isEmpty \n 5. DISPLAY STACK \n 6. CHECK EXPRESSION FOR BALANCE \n 7. EXIT" << std::endl;
        std::cin >> choice;
        switch (choice) {
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: Top();
            break;
            case 4: std::cout << isEmpty() << std::endl;
            break;
            case 5: displayStack();
            break;
            case 6: checkExpression();
            break;
            case 7: return 0;
            default: std::cout << "Invalid Choice!" << std::endl;
            break;
        }
    }

    return 0;
}

bool isEmpty() {
    if (top == -1) return true;
    return false;
}

bool isFull() {
    if (top >= i - 1) return true;
    return false;
}

char matchingOpen(char closeSymbol) {
    if (closeSymbol == ')') return '(';
    if (closeSymbol == ']') return '[';
    return '{';
}

char matchingClose(char openSymbol) {
    if (openSymbol == '(') return ')';
    if (openSymbol == '[') return ']';
    return '}';
}

// push(symbol, position) contains ALL of the balance-checking logic.
// position is the index of this character in the original expression,
// used only to make the error messages specific. Pass -1 when there's
// no meaningful position (e.g. manual single-character push from the menu).
void push(char symbol, int position) {
    if (symbol != '(' && symbol != ')' &&
        symbol != '{' && symbol != '}' &&
        symbol != '[' && symbol != ']') {
        return;
    }

    if (symbol == '(' || symbol == '{' || symbol == '[') {
        if (isFull()) {
            std::cout << "Stack Overflow!" << std::endl;
            errorFound = true;
            return;
        }
        stack[++top] = symbol;
        posStack[top] = position;
        return;
    }

    // Closing symbol
    if (isEmpty()) {
        std::cout << "Error";
        if (position >= 0) std::cout << " at position " << position;
        std::cout << ": found closing symbol '" << symbol
                   << "' but the stack is empty (nothing to match it with)." << std::endl;
        errorFound = true;
        return;
    }

    char popped = stack[top];
    int poppedPos = posStack[top];
    top--;

    if (symbol != matchingClose(popped)) {
        std::cout << "Error";
        if (position >= 0) std::cout << " at position " << position;
        std::cout << ": closing symbol '" << symbol << "' does not match '" << popped << "'";
        if (poppedPos >= 0) std::cout << " (opened at position " << poppedPos << ")";
        std::cout << " -- expected '" << matchingClose(popped) << "'." << std::endl;
        errorFound = true;
    }
}

void push() {
    if (isFull()) {
        std::cout << "Stack Overflow!" << std::endl;
        return;
    }

    std::cout << "New symbol to push: ";
    char newData;
    std::cin >> newData;
    push(newData, -1);
}

void pop() {
    if (isEmpty()) {
        std::cout << "Stack Underflow!" << std::endl;
        return;
    }
    std::cout << "Popping: " << stack[top] << std::endl;
    top--;
}

void Top() {
    if (isEmpty()) {
        std::cout << "Stack Underflow!" << std::endl;
        return;
    }
    std::cout << "The element on the top of the stack is " << stack[top] << std::endl;
}

void displayStack() {
    if (isEmpty()) {
        std::cout << "Stack Empty" << std::endl;
        return;
    }
    for (int j = top; j >= 0; j--) {
        if (j < top) {
            std::cout << ", ";
        }
        std::cout << stack[j];
    }
    std::cout << std::endl;
}

void checkExpression() {
    std::string expr;
    std::cout << "Enter an expression to check: ";
    std::cin.ignore();
    std::getline(std::cin, expr);

    top = -1;
    errorFound = false;

    for (int position = 0; position < (int)expr.size(); position++) {
        push(expr[position], position);
        if (errorFound) break;
    }

    if (!errorFound && !isEmpty()) {
        std::cout << "Error: expression ended with unmatched opening symbol(s):" << std::endl;
        for (int j = top; j >= 0; j--) {
            std::cout << "  position " << posStack[j] << ": '" << stack[j] << "' was never closed" << std::endl;
        }
        errorFound = true;
    }

    std::cout << std::endl;
    std::cout << "Expression: " << expr << std::endl;
    std::cout << "Result: " << (errorFound ? "INVALID (N)" : "VALID (Y)") << std::endl;
}