// Program to calculate grades for multiple students
#include <iostream>
#include <iomanip>
#include <string>

const int SUBJECTS = 5;
const int STUDENTS = 5;

// Function to get valid mark input
int getMark(int studentNumber, int subjectNumber) {
    int mark;
    do {
        std::cout << "Student " << studentNumber << ", Subject " << subjectNumber << ": ";
        if (!(std::cin >> mark)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input! Please enter a number.\n";
            mark = -1;
            continue;
        }
        if (mark < 0 || mark > 100) {
            std::cout << "Mark must be between 0 and 100!\n";
        }
    } while (mark < 0 || mark > 100);
    return mark;
}

// Function to calculate total marks for one student
int calculateTotal(const int marks[]) {
    int total = 0;
    for (int i = 0; i < SUBJECTS; i++) {
        total += marks[i];
    }
    return total;
}

// Function to calculate average
double calculateAverage(int total) {
    return static_cast<double>(total) / SUBJECTS;
}

// Function to determine grade
char determineGrade(double average) {
    if (average > 90) return 'A';
    if (average > 80) return 'B';
    if (average > 60) return 'C';
    if (average > 40) return 'D';
    return 'E';
}

// Function to display results for one student
void displayResults(int studentNum, int total, double average, char grade) {
    std::cout << "\nResults for Student " << studentNum << ":\n";
    std::cout << "----------------\n";
    std::cout << "Total Marks : " << total << "/" << SUBJECTS * 100 << "\n";
    std::cout << "Average     : " << std::fixed << std::setprecision(2) << average << "%\n";
    std::cout << "Grade       : " << grade << "\n";
    std::cout << "----------------\n";
}

int main() {
    int marks[STUDENTS][SUBJECTS];  // 2D array for 5 students, 5 subjects each
    
    std::cout << "Enter marks for " << STUDENTS << " students (" << SUBJECTS << " subjects each, 0-100):\n\n";
    
    // Get marks for each student and subject
    for (int student = 0; student < STUDENTS; student++) {
        std::cout << "\nEnter marks for Student " << student + 1 << ":\n";
        for (int subject = 0; subject < SUBJECTS; subject++) {
            marks[student][subject] = getMark(student + 1, subject + 1);
        }
    }
    
    // Calculate and display results for each student
    for (int student = 0; student < STUDENTS; student++) {
        int total = calculateTotal(marks[student]);
        double average = calculateAverage(total);
        char grade = determineGrade(average);
        
        displayResults(student + 1, total, average, grade);
    }
    
    
    // Display class summary
    std::cout << "\nClass Summary:\n";
    std::cout << "==============\n";
    int totalPassed = 0;
    for (int student = 0; student < STUDENTS; student++) {
        int total = calculateTotal(marks[student]);
        double average = calculateAverage(total);
        if (average >= 40) totalPassed++;
    }
    std::cout << "Total Students: " << STUDENTS << "\n";
    std::cout << "Passed: " << totalPassed << "\n";
    std::cout << "Failed: " << STUDENTS - totalPassed << "\n";
    std::cout << "Pass Rate: " << std::fixed << std::setprecision(1) 
              << (static_cast<double>(totalPassed) / STUDENTS * 100) << "%\n";
    
    return 0;
}

