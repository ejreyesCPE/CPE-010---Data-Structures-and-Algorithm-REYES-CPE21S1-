#include <iostream>
#include <string>

struct Node {
    char data;
    int position;
    Node* next;
};

Node* top = nullptr;
int i, count = 0;
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
    if (top == nullptr) return true;
    return false;
}

bool isFull() {
    if (count >= i) return true;
    return false;
}

char matchingClose(char openSymbol) {
    if (openSymbol == '(') return ')';
    if (openSymbol == '[') return ']';
    return '}';
}

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
        Node* newNode = new Node{symbol, position, top};
        top = newNode;
        count++;
        return;
    }

    if (isEmpty()) {
        std::cout << "Error";
        if (position >= 0) std::cout << " at position " << position;
        std::cout << ": found closing symbol '" << symbol
                   << "' but the stack is empty (nothing to match it with)." << std::endl;
        errorFound = true;
        return;
    }

    Node* popped = top;
    char poppedChar = popped->data;
    int poppedPos = popped->position;
    top = top->next;
    delete popped;
    count--;

    if (symbol != matchingClose(poppedChar)) {
        std::cout << "Error";
        if (position >= 0) std::cout << " at position " << position;
        std::cout << ": closing symbol '" << symbol << "' does not match '" << poppedChar << "'";
        if (poppedPos >= 0) std::cout << " (opened at position " << poppedPos << ")";
        std::cout << " -- expected '" << matchingClose(poppedChar) << "'." << std::endl;
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
    Node* temp = top;
    std::cout << "Popping: " << temp->data << std::endl;
    top = top->next;
    delete temp;
    count--;
}

void Top() {
    if (isEmpty()) {
        std::cout << "Stack Underflow!" << std::endl;
        return;
    }
    std::cout << "The element on the top of the stack is " << top->data << std::endl;
}

void displayStack() {
    if (isEmpty()) {
        std::cout << "Stack Empty" << std::endl;
        return;
    }
    Node* cur = top;
    bool first = true;
    while (cur != nullptr) {
        if (!first) std::cout << ", ";
        std::cout << cur->data;
        first = false;
        cur = cur->next;
    }
    std::cout << std::endl;
}

void checkExpression() {
    std::string expr;
    std::cout << "Enter an expression to check: ";
    std::cin.ignore();
    std::getline(std::cin, expr);

    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    count = 0;
    errorFound = false;

    for (int position = 0; position < (int)expr.size(); position++) {
        push(expr[position], position);
        if (errorFound) break;
    }

    if (!errorFound && !isEmpty()) {
        std::cout << "Error: expression ended with unmatched opening symbol(s):" << std::endl;
        Node* cur = top;
        while (cur != nullptr) {
            std::cout << "  position " << cur->position << ": '" << cur->data << "' was never closed" << std::endl;
            cur = cur->next;
        }
        errorFound = true;
    }

    std::cout << std::endl;
    std::cout << "Expression: " << expr << std::endl;
    std::cout << "Result: " << (errorFound ? "INVALID (N)" : "VALID (Y)") << std::endl;
}