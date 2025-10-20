#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Student {
private:
    vector<double> grades;

public:
    void addGrade(double grade) {
        grades.push_back(grade);
    }

    double getAverageGrade() const {
        if (grades.empty()) {
            return 0.0;
        }
        double sum = accumulate(grades.begin(), grades.end(), 0.0);
        return sum / grades.size();
    }
};

int main() {
    Student student;
    student.addGrade(4.5);
    student.addGrade(5.0);
    student.addGrade(4.0);
    student.addGrade(3.0);
    cout << "Average grade: " << student.getAverageGrade() << endl;

    return 0;
}
