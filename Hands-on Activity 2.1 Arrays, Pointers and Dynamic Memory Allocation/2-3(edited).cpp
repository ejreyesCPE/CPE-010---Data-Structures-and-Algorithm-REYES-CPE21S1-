#include <iostream>
#include <string>

class Student {
    private:
        std::string studentName;
        int studentAge;
    public:
        // Constructor
        Student(std::string newName = "John Doe", int newAge = 18) {
            studentName = std::move(newName);
            studentAge = newAge;
            std::cout << "Constructor Called for " << studentName << std::endl;
        }

        // Deconstructor
        ~Student() {
            std::cout << "Destructor Called for " << studentName << std::endl;
        }

        // Copy Constructor
        Student(const Student &copyStudent) {
            std::cout << "Copy Constructor Called" << std::endl;
            studentName = copyStudent.studentName;
            studentAge = copyStudent.studentAge;
        }

        // Display Attributes
        void printDetails() {
            std::cout << this->studentName << " " << this->studentAge << std::endl;
        }

};

int main() {
    const size_t j = 5;

    Student studentList[j] = {}; // This is what causes the extra 5 Constructors to pop up on output.
    std::string namesList[j] = {"Carly", "Freddy", "Sam", "Zack", "Cody"};
    int ageList[j] = {15, 16, 18, 19, 16};

    for(int i = 0; i < j; i++) { // loop A
        Student *ptr = new Student(namesList[i], ageList[i]);
        studentList[i] = *ptr;
        delete ptr; // 
    }

    std::cout << std::endl; // Seperating the list of names from the constructor and destructor 

    for(int i = 0; i < j; i++) { // loop B
        studentList[i].printDetails();
    }

    std::cout << std::endl;

    return 0;
}

