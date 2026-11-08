#include <iostream>
using namespace std;

const int MAX_STUDENTS = 100;
const int MAX_EXAMS = 30;

struct Date {
    int dd, mm, yy;
};

struct StudentRecord {
    char surname[25];
    char name[25];
    int studentId;
    int academicYear;
    
    enum Enrollment {
        PT,  // within prescribed time
        OPT  // outside prescribed time
    } enrollmentStatus;
};

struct ExamRecord {
    char examName[25];
    int studentId;
    int score;
    
    enum Laude {
        YES,
        NO
    } laudeStatus;
    
    Date examDate;
};

struct reportStudents {
    int studentId;
    int examCount;
    float averageScore;
};

void displayMenu() {
    cout << "==== CLASS REGISTER == " << endl;
    cout << "Actions available :" << endl;
    cout << "1) Enter a new student" << endl;
    cout << "2) Search for a student by studentId" << endl;
    cout << "3) Student exam insertion" << endl;
    cout << "4) Display exam and student average" << endl;
    cout << "5) Search students by average" << endl;
    cout << "6) Exit" << endl << endl;
    cout << "Which action do you want to execute ? == > ";
}

void printStudentDetails(StudentRecord stud) {
    cout << "Data of the student " << stud.surname << " " << stud.name << ": " << endl;
    cout << "- Student ID: " << stud.studentId << endl;
    cout << "- Academic Year: " << stud.academicYear << endl;
    cout << "- Enrollment Status: ";
    
    if (stud.enrollmentStatus == StudentRecord::PT)
        cout << "within prescribed time" << endl;
    else
        cout << "outside prescribed time" << endl;
}

Date inputDate() {
    Date nuovaData;
    
    cout << endl << "- Day: ";
    cin >> nuovaData.dd;
    cout << "- Month: ";
    cin >> nuovaData.mm;
    cout << "- Year: ";
    cin >> nuovaData.yy;
    
    return nuovaData;
}

StudentRecord inputStudentData() {
    StudentRecord newStud;
    char enrollmentFlag;
    
    cout << "Data of a new student: ";
    cout << endl << "- Name: ";
    cin >> newStud.name;
    cout << "- Surname: ";
    cin >> newStud.surname;
    cout << "- Student ID: ";
    cin >> newStud.studentId;
    cout << "- Academic Year: ";
    cin >> newStud.academicYear;
    
    do {
        cout << "- Within prescribed time (Y/N): ";
        cin >> enrollmentFlag;
        
        if (enrollmentFlag == 'Y')
            newStud.enrollmentStatus = StudentRecord::PT;
        else
            newStud.enrollmentStatus = StudentRecord::OPT;
    } while (enrollmentFlag != 'Y' && enrollmentFlag != 'N');
    
    return newStud;
}

ExamRecord inputExamDetails() {
    ExamRecord newExam;
    char laudeStatus;
    
    cout << "Data of a new exam: ";
    cout << endl << "- Exam name: ";
    cin >> newExam.examName;
    cout << "- Score: ";
    
    do {
        cin >> newExam.score;
        
        if (newExam.score < 18 || newExam.score > 30) {
            cout << "Invalid mark, please enter a mark between 18 and 30: ";
        }
        else if (newExam.score == 30) {
            do {
                cout << "- Cum Laude (Y/N): ";
                cin >> laudeStatus;
                
                if (laudeStatus == 'Y')
                    newExam.laudeStatus = ExamRecord::YES;
                else
                    newExam.laudeStatus = ExamRecord::NO;
            } while (laudeStatus != 'Y' && laudeStatus != 'N');
        }
        else {
            newExam.laudeStatus = ExamRecord::NO;
        }
    } while (newExam.score < 18 || newExam.score > 30);
    
    cout << "- Exam Date: ";
    newExam.examDate = inputDate();
    
    return newExam;
}

int findStudent(StudentRecord studentRecords[], int numStudents, int studentId) {
    for (int i = 0; i < numStudents; i++) {
        if (studentRecords[i].studentId == studentId) {
            return i;
        }
    }
    return -1;
}

int insertStudent(StudentRecord studentRecords[], int numStudents) {
    StudentRecord newStudent;
    
    do {
        newStudent = inputStudentData();
        
        if (findStudent(studentRecords, numStudents, newStudent.studentId) >= 0)
            cout << "The entered Student ID already exists. Please try again.";
    } while (findStudent(studentRecords, numStudents, newStudent.studentId) >= 0);
    
    studentRecords[numStudents] = newStudent;
    cout << "Successful entry!" << endl;
    printStudentDetails(newStudent);
    
    return numStudents + 1;
}

int insertStudentExam(ExamRecord examRecords[], int examCount, int studentId) {
    ExamRecord nuovoEsame = inputExamDetails();
    nuovoEsame.studentId = studentId;
    examRecords[examCount] = nuovoEsame;
    
    return examCount + 1;
}

reportStudents createStudentReport(ExamRecord examRecords[], int examCount, int studentId) {
    reportStudents report;
    report.studentId = studentId;
    report.examCount = 0;
    report.averageScore = 0;
    
    for (int i = 0; i < examCount; i++) {
        if (examRecords[i].studentId == studentId) {
            report.examCount++;
            report.averageScore += examRecords[i].score;
        }
    }
    
    report.averageScore /= report.examCount;
    return report;
}

void displayExamCountAndAverageScore(ExamRecord examRecords[], int examCount, int studentId) {
    reportStudents report = createStudentReport(examRecords, examCount, studentId);
    
    cout << "Exam number: " << report.examCount << endl;
    cout << "Scores average: " << report.averageScore << endl;
}

void findStudentsAboveAverage(StudentRecord studentRecords[], int numStudents,
                             ExamRecord examRecords[], int examCount, float averageScore) {
    cout << "Students with scores averages higher than " << averageScore << ": " << endl;
    
    for (int i = 0; i < numStudents; i++) {
        reportStudents report = createStudentReport(examRecords, examCount, studentRecords[i].studentId);
        
        if (report.averageScore > averageScore) {
            cout << "- " << studentRecords[i].surname << " " << studentRecords[i].name << endl;
        }
    }
}

int main() {
    int userChoice;
    bool exitFlag = false;
    int numStudents = 0;
    int examCount = 0;
    int studentId;
    int studIndex = -1;
    float score;
    
    StudentRecord studentRecords[MAX_STUDENTS];
    ExamRecord examRecords[MAX_STUDENTS * MAX_EXAMS];
    
    do {
        do {
            displayMenu();
            cin >> userChoice;
            
            switch (userChoice) {
                case 1:
                    numStudents = insertStudent(studentRecords, numStudents);
                    break;
                    
                case 2:
                    cout << "Student ID to be looked for: ";
                    cin >> studentId;
                    studIndex = findStudent(studentRecords, numStudents, studentId);
                    
                    if (studIndex >= 0)
                        printStudentDetails(studentRecords[studIndex]);
                    else
                        cout << "The searched Student ID is not present in the register." << endl;
                    break;
                    
                case 3:
                    cout << "Student ID whose examination is to be recorded: ";
                    cin >> studentId;
                    
                    if (findStudent(studentRecords, numStudents, studentId) >= 0)
                        examCount = insertStudentExam(examRecords, examCount, studentId);
                    else
                        cout << "The searched Student ID is not present in the register." << endl;
                    break;
                    
                case 4:
                    cout << "Student ID: ";
                    cin >> studentId;
                    
                    if (findStudent(studentRecords, numStudents, studentId) >= 0)
                        displayExamCountAndAverageScore(examRecords, examCount, studentId);
                    else
                        cout << "The searched Student ID is not present in the register." << endl;
                    break;
                    
                case 5:
                    do {
                        cout << "Minimum average (>): ";
                        cin >> score;
                    } while (score < 0 || score > 30);
                    
                    findStudentsAboveAverage(studentRecords, numStudents, examRecords, examCount, score);
                    break;
                    
                case 6:
                    exitFlag = true;
                    break;
                    
                default:
                    cout << "The selected option does not exist. Please try again." << endl;
            }
        } while (userChoice < 0 || userChoice > 6);
    } while (!exitFlag);
    
    return 0;
}