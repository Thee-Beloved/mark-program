#include <iostream>
using namespace std;

int main() {
    int marks[5];
    int total = 0;
    float average;
    char grade;

    // Input marks for 5 subjects
    cout << "Enter marks for 5 subjects (0–100):" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Subject " << i + 1 << ": ";
        cin >> marks[i];

        // Optional: validate input
        if (marks[i] < 0 || marks[i] > 100) {
            cout << "Invalid input. Please enter marks between 0 and 100." << endl;
            return 1;
        }

        total += marks[i];
    }

    // Calculate average
    average = total / 5.0;

    // Use switch-case to assign grade
    switch (static_cast<int>(average) / 10) {
        case 10:
        case 9: grade = 'A'; break;
        case 8: grade = 'B'; break;
        case 7:
        case 6: grade = 'C'; break;
        case 5:
        case 4: grade = 'D'; break;
        default: grade = 'E'; break;
    }

    // Output results
    cout << "\nTotal Marks: " << total << endl;
    cout << "Average Marks: " << average << endl;
    cout << "Grade: " << grade << endl;

    return 0;
}
