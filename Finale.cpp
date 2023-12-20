#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <cstring>
#include <limits>
#include <fstream>
#include <ctime>
#include <algorithm>

using namespace std;
/*******************************FUNCTIONS****************************************/
void header();
void setConsoleColor(int color);
void resetConsoleColor();
int loading();
bool checkInt(string check);
bool validPassword(string pasword);
bool ValidUserName(string username);
void bottom(int x, int y);
void typeReligious();
void typeFantasy();
void typeHistory();
void typeNovel();
void gotoxy(int x, int y);
void firstPage(int x, int y);
bool empty(string check);
string getCurrentTimestamp();
void homeAnimation();
void welcomeAnimation();
void Sider();
void signUpBox();
void loginBox();
void welcomeAdmin();
void teacherBox();
void studentBox();
void invalid();
// FILE HANDELING FOR SIGNUP
void readDataForSignup(string username[], string role[], string password[], int &couunt);
void updateDataForSigunp(string username[], string role[], string password[], int &couunt);
string getField(string record, int field);
// FILE HANDELING FOR "STUDENT DATA"
void readStudentData(string name[], string id[], string adress[], string Section[], string contact[], int &total);
void updateSignupData(string name[], string id[], string adress[], string Section[], string contact[], int total);
// FILE HANDELING FOR "TEACHER DATA"
void readTeacherData(string teacherName[], string teacherID[], string teacherAge[], string teacherGender[], string teacherContact[], string teacherAddress[], int &totalTeachers);
void updateTeacherData(string teacherName[], string teacherID[], string teacherAge[], string teacherGender[], string teacherContact[], string teacherAddress[], int &totalTeachers);
// FILE HANDELING FOR FEEDBACK
void readFeedbackData(string feedbackArray[], string feedbackTimestamps[], int &feedbackIndex);
void updateFeedbackData(string feedbackArray[], string feedbackTimestamps[], int &feedbackIndex);
// FILE HANDELING FOR ANNOUNCEMENTS
void readAnnouncementData(string senders[], string contents[], string timestamps[], int &announcementCount);
void updateAnnouncementData(string senders[], string contents[], string timestamps[], int &announcementCount);
// FILE HANDELING FOR REGISTER SUBJETCS
void readStudentData(string studentIDs[], string studentSubjects[], string studentNames[], int total);
void updateStudentData(string studentIDs[], string studentSubjects[], string studentNames[], int total);
// FILE HANDELING FOR STUDENT ATTENDANCE
void readAttendanceData(string studentIDs[], string attendanceStatuses[], string timestamps[], int total);
void updateAttendanceData(string studentIDs[], string attendanceStatuses[], string timestamps[], int total);

int findStudentIndex(string &studentID, string id[], int total);
void displayAttendanceToStudent(string &studentID, string &studentName, string &attendanceStatus);
void manageAttendance(int &total, string name[], string id[], string adress[], string Section[], string contact[], string studentNames[], string studentIDs[], string attendanceStatus[]);
void markAttendance(int &total, string name[], string id[], string adress[], string Section[], string contact[], string studentNames[], string studentIDs[], string attendanceStatus[]);
void viewAttendane(int &total, string name[], string id[], string adress[], string Section[], string contact[], string studentNames[], string studentIDs[], string attendanceStatus[]);
void announcementMenu(string senders[], string contents[], string timestamps[], int &announcementCount, const string &adminName);
void deleteAnnouncement(string senders[], string contents[], string timestamps[], int &announcementCount);
void addAnnouncement(string senders[], string contents[], string timestamps[], int &announcementCount, const string &adminName, const string &announcement);
void displayAnnouncements(string senders[], string contents[], string timestamps[], int announcementCount);

void adminMenu(int &totalTeachers, int &feedbackIndex, int &total, int x, int y, string name[], string id[], string adress[], string Section[], string contact[],
               string feedbackArray[], string teacherName[], string teacherID[], string teacherAge[], string teacherGender[], string teacherContact[], string teacherAddress[],
               int &Logout, int &exit, string senders[], string contents[], string timestamps[], int &announcementCount, const string &adminName, string feedbackTimestamps[]);

void manageStudent(int totalTeachers, int &feedbackIndex, int &total, int x, int y, string name[], string id[], string adress[], string Section[], string contact[],
                   string feedbackArray[], string teacherName[], string teacherID[], string teacherAge[], string teacherGender[], string teacherContact[], string teacherAddress[], int &Logout, int &exit);

void enterStudentDataByAdmin(int totalTeachers, int &feedbackIndex, int &total, int x, int y, string name[], string id[], string adress[], string Section[], string contact[], string feedbackArray[], string teacherName[], string teacherID[], string teacherAge[], string teacherGender[], string teacherContact[], string teacherAddress[], int &Logout, int &exit);

void showStudentDataByAdmin(int totalTeachers, int &feedbackIndex, int total, int x, int y, string name[], string id[], string adress[], string Section[], string contact[]);

void searchStudentDataByAdminn(int totalTeachers, int &feedbackIndex, int total, int x, int y, string name[], string id[], string adress[], string Section[], string contact[]);

void updateStudentdataByAdmin(int totalTeachers, int &feedbackIndex, int &total, int x, int y, string name[], string id[], string adress[], string Section[], string contact[]);

void deleteStudentDataByAdmin(int totalTeachers, int &feedbackIndex, int &total, int x, int y, string name[], string id[], string adress[], string Section[], string contact[]);

void displayRegisteredSubjects(int studentID, string name[], string id[], string adress[], string Section[], string contact[], string studentNames[], string subjects[], int SubjectID[], int studentSubjects[]);

void studentMenu(int totalTeachers, int &feedbackIndex, int &total, int x, int y, string name[], string id[], string adress[], string Section[], string contact[],
                 string studentNames[], string subjects[], int SubjectID[], int studentSubjects[], string studentIDs[], string feedbackArray[], int &Logout, int &exit,
                 string senders[], string contents[], string timestamps[], int announcementCount, string feedbackTimestamps[], string attendanceStatus[]);

void Register(int totalTeachers, int &feedbackIndex, int total, int x, int y, string name[], string id[], string adress[], string Section[], string contact[], string studentNames[], string subjects[], int SubjectID[], int studentSubjects[], string studentIDs[], string feedbackArray[]);

void RegisterSubject(int studentID, int subjectID, int totalTeachers, int &feedbackIndex, int total, int x, int y, string name[], string id[], string adress[],
                     string Section[], string contact[], string studentNames[], string subjects[], int SubjectID[], int studentSubjects[], string studentIDs[], string feedbackArray[]);
// bool isPasswordUnique(string newpassword,int couunt,string adminUsername[],string adminPassword[],string username[],string role[],string password[]);

void displayAvailableStudents(string studentNames[], string subjects[], int SubjectID[], int studentSubjects[], int totalTeachers, int &feedbackIndex, int total, int x, int y, string name[], string id[], string adress[], string Section[], string contact[], string studentIDs[], string feedbackArray[]);
void Library(int totalTeachers, int &feedbackIndex, int total, int x, int y, string name[], string id[], string adress[], string Section[], string contact[], string studentNames[],
             string subjects[], int SubjectID[], int studentSubjects[], string studentIDs[], string feedbackArray[]);

void addFeedback(int totalTeachers, int &feedbackIndex, int total, int x, int y, string feedbackArray[], string feedbackTimestamps[]);
void displayFeedback(int totalTeachers, int &feedbackIndex, int total, int x, int y, string feedbackArray[], string feedbackTimestamps[]);
void deleteFeedback(int totalTeachers, int &feedbackIndex, int total, int x, int y, string feedbackArray[]);

void teacherMenu(int &totalTeachers, int &feedbackIndex, int total, int x, int y, string name[], string id[], string adress[], string Section[], string contact[], string studentNames[],
                 string subjects[], int SubjectID[], int studentSubjects[], string studentIDs[], string feedbackArray[], string teacherName[], string teacherID[], string teacherAge[],
                 string teacherGender[], string teacherContact[], string teacherAddress[], int &Logout, int &exit, string senders[], string contents[], string timestamps[],
                 int announcementCount, string feedbackTimestamps[], string attendanceStatus[]);

void viewProfile(int totalTeachers, int &feedbackIndex, int total, int x, int y, string name[], string id[], string adress[], string Section[], string contact[], string studentNames[],
                 string subjects[], int SubjectID[], int studentSubjects[], string studentIDs[], string feedbackArray[], int &Logout, int &exit, string senders[], string contents[],
                 string timestamps[], int announcementCount, string feedbackTimestamps[], string attendanceStatus[]);

void updateStudentInformation(int &totalTeachers, int &feedbackIndex, int &total, int x, int y, string name[], string id[], string adress[], string Section[], string contact[],
                              string studentNames[], string subjects[], int SubjectID[], int studentSubjects[], string studentIDs[], string feedbackArray[]);

void signupPage(int totalTeachers, int &feedbackIndex, int total, int x, int y, int &couunt, string adminUsername[], string adminPassword[], string username[], string role[], string password[], string studentNames[], string subjects[],
                int SubjectID[], int studentSubjects[], string name[], string id[], string adress[], string Section[], string contact[], string studentIDs[]);
void signInConditions(string name1, string key, int x, int y, int &totalTeachers, int &feedbackIndex, int &total, int &couunt, string adminUsername[], string adminPassword[], string username[], string name[], string role[], string password[], string id[],
                      string adress[], string Section[], string contact[], string studentNames[], string subjects[], int SubjectID[], int studentSubjects[], string studentIDs[], string feedbackArray[], string teacherName[], string teacherID[], string teacherAge[],
                      string teacherGender[], string teacherContact[], string teacherAddress[], int &Logout, int &exit, string loginUsername, string senders[], string contents[], string timestamps[], int &announcementCount, const string &adminName, string feedbackTimestamps[], string attendanceStatus[]);

void manageTeacher(int &totalTeachers, int &feedbackIndex, int total, int x, int y, string name[], string id[], string adress[], string Section[], string contact[],
                   string feedbackArray[], string teacherName[], string teacherID[], string teacherAge[], string teacherGender[], string teacherContact[], string teacherAddress[], int &Logout, int &exit);

void addTeacher(int &totalTeachers, int &feedbackIndex, int total, int x, int y, string teacherName[], string teacherID[], string teacherAge[], string teacherGender[], string teacherContact[], string teacherAddress[], string name[], string id[], string adress[], string Section[], string contact[], string feedbackArray[], int &Logout, int &exit);

void showTeacherData(int totalTeachers, int &feedbackIndex, int total, int x, int y, string teacherName[], string teacherID[], string teacherAge[], string teacherGender[], string teacherContact[], string teacherAddress[], string name[], string id[], string adress[], string Section[], string contact[], string feedbackArray[], int &Logout, int &exit);

void searchTeacherData(int totalTeachers, int &feedbackIndex, int total, int x, int y, string teacherName[], string teacherID[], string teacherAge[], string teacherGender[], string teacherContact[], string teacherAddress[], string name[], string id[], string adress[], string Section[], string contact[], string feedbackArray[], int &Logout, int &exit);

void updateTeacherData(int &totalTeachers, int &feedbackIndex, int total, int x, int y, string teacherName[], string teacherID[], string teacherAge[], string teacherGender[], string teacherContact[], string teacherAddress[], string name[], string id[], string adress[], string Section[], string contact[], string feedbackArray[], int &Logout, int &exit);

void deleteTeacherData(int &totalTeachers, int &feedbackIndex, int total, int x, int y, string teacherName[], string teacherID[], string teacherAge[], string teacherGender[], string teacherContact[], string teacherAddress[], string name[], string id[], string adress[], string Section[], string contact[], string feedbackArray[], int &Logout, int &exit);

void viewStudentProfile(int totalTeachers, int &feedbackIndex, int total, int x, int y, string teacherName[], string teacherID[], string teacherAge[], string teacherGender[],
                        string teacherContact[], string teacherAddress[], string name[], string id[], string adress[], string Section[], string contact[], string studentNames[],
                        string subjects[], int SubjectID[], int studentSubjects[], string studentIDs[], string feedbackArray[]);

void updateTeacherInformation(int &totalTeachers, int &feedbackIndex, int total, int x, int y, string teacherName[], string teacherID[], string teacherAge[], string teacherGender[],
                              string teacherContact[], string teacherAddress[], string name[], string id[], string adress[], string Section[], string contact[], string studentNames[],
                              string subjects[], int SubjectID[], int studentSubjects[], string studentIDs[], string feedbackArray[]);

///////////********************************************************************MAIN************************************************************
int main()
{
    // Arrays to store student information
    string name[100];
    string id[100];
    string adress[100];
    string Section[100];
    string contact[100];
    string studentIDs[100];
    string studentNames[100];

    // Subjects and IDs for each subject
    string subjects[5] = {"Programing", "AICT", "Math", "Physics", "History"};
    int SubjectID[5] = {1, 2, 3, 4, 5};
    // Array to track which subjects each student is enrolled in
    int studentSubjects[100 * 5] = {0};
    // Arrays to store admin information
    string adminUsername[10];
    string adminPassword[10];
    // Array to store feedback from users
    string feedbackArray[10];
    // Arrays to store teacher information
    string teacherName[100];
    string teacherID[100];
    string teacherAge[100];
    string teacherGender[100];
    string teacherContact[100];
    string teacherAddress[100];
    // Arrays for announcements
    string senders[100];
    string contents[100];
    string timestamps[100];
    int announcementCount = 0;
    // Admin username and total teacher count
    const string adminName = "ADMIN";
    int totalTeachers = 0;
    // Feedback index for tracking feedback entries
    int feedbackIndex = 0;
    string feedbackTimestamps[100];
    // Signup Arrays
    int couunt = 0;
    string username[100];
    string role[100];
    string password[100];
    string attendanceStatus[100];
    // Initialize all elements with a default value (e.g., "Not Marked")
    for (int i = 0; i < 100; ++i)
    {
        attendanceStatus[i] = "Not Marked";
    }

    // Total students count
    int total = 0;

    // Coordinates for display
    int x, y;

    // Logout and exit flags
    int Logout = 0;
    int exit = 0;
    ///////////////////////////////// D A T A   R E A D I N G   F R O M   F I L E S \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
    // READ DATA FOR SIGNUP
    readDataForSignup(username, role, password, couunt);
    // READ DATA FOR "ENTER STUDENT DATA"
    readStudentData(name, id, adress, Section, contact, total);
    // READ DATA FOR TEACHER DATA
    readTeacherData(teacherName, teacherID, teacherAge, teacherGender, teacherContact, teacherAddress, totalTeachers);
    // READ DATA FOR FEEDBACK
    readFeedbackData(feedbackArray, feedbackTimestamps, feedbackIndex);
    // READ DATA FOR ANNOUNCEMENTS
    readAnnouncementData(senders, contents, timestamps, announcementCount);
    // READ DATA FOR REGISTER SUBJECTS
    readStudentData(id, subjects, name, total);
    // READ DATA FOR MARKING ATTENDANCE
    readAttendanceData(studentIDs, attendanceStatus, timestamps, total);
    // Main loop for program execution
    welcomeAnimation();
    homeAnimation();
    while (exit == 0)
    {
        // Clear the console and display the first page

        firstPage(x, y);

        // Get user input
        char input = getch();

        // Check user input
        if (input == '1')
        {
            // Navigate to Signup Page
            signupPage(totalTeachers, feedbackIndex, total, x, y, couunt, adminUsername, adminPassword, username, role, password, studentNames, subjects,
                       SubjectID, studentSubjects, name, id, adress, Section, contact, studentIDs);
        }
        else if (input == '2')
        {
            // User Login
            Logout = 0;
            string loginUsername, key;

            // Login loop
            while (Logout == 0)
            {
                header();
                loginBox();

                // Input Username
                while (1)
                {
                    cout << "\n\n\t\t\t\t\t\t\t\tENTER USERNAME: ";
                    getline(cin, loginUsername);

                    if (empty(loginUsername) == 1)
                    {
                        invalid();
                    }
                    else
                        break;
                }

                // Input Password
                while (1)
                {
                    cout << "\n\n\t\t\t\t\t\t\t\tENTER PASSWORD: ";
                    getline(cin, key);

                    if (empty(key) == 1)
                    {
                        invalid();
                    }
                    else
                        break;
                }

                // Sign In Conditions
                signInConditions(loginUsername, key, x, y, totalTeachers, feedbackIndex, total, couunt, adminUsername, adminPassword, username, name, role, password, id,
                                 adress, Section, contact, studentNames, subjects, SubjectID, studentSubjects, studentIDs, feedbackArray, teacherName, teacherID, teacherAge,
                                 teacherGender, teacherContact, teacherAddress, Logout, exit, loginUsername, senders, contents, timestamps, announcementCount, adminName, feedbackTimestamps, attendanceStatus);
            }
        }
        else if (input == '3')
        {
            // Exit the program
            cout << "\n\t\t\t\t\t\t\t Exiting ";
            loading();
            system("cls");
            Logout = 1;
            exit = 1;
        }
        else
        {
            // invalid choice
            invalid();
        }
    }
    ///////////////////////////////// D A T A   U P D A T I N G   I N   F I L E S \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
    // UPDATE DATA FOR SIGNUP
    updateDataForSigunp(username, role, password, couunt);
    // UPDATE DATA FOR Student data
    updateSignupData(name, id, adress, Section, contact, total);
    // UPDATE DATA FOR teacher data
    updateTeacherData(teacherName, teacherID, teacherAge, teacherGender, teacherContact, teacherAddress, totalTeachers);
    // UPDATE FEEDBACK DATA
    updateFeedbackData(feedbackArray, feedbackTimestamps, feedbackIndex);
    // UPDATE DATA FOR ANNOUNCEMENTS
    updateAnnouncementData(senders, contents, timestamps, announcementCount);
    // UPDATE DATA FOR REGISTER SUBJECTS
    updateStudentData(id, subjects, name, total);
    // UPDATA DATA FOR ATTENDANCE
    updateAttendanceData(studentIDs, attendanceStatus, timestamps, total);
}

/////////////////////////////////////////////*******************************FUNCTION DEFINATIONS****************************************/
void setConsoleColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void resetConsoleColor()
{
    setConsoleColor(7); // Set color back to default (white on black)
}
void header()
{

    system("cls");
    Sider();
    // Set text color to purple
    setConsoleColor(9);
    cout << "\n\t\t\t\t    88888888888          88                 ,ad8888ba,                                                             88" << endl;
    cout << "\t\t\t\t    88                   88                d8        8b                            ,d                              88" << endl;
    cout << "\t\t\t\t    88                   88               d8'                                      88                              88" << endl;
    cout << "\t\t\t\t    88aaaaaaaa   ,adPPYb,88  88       88  88              ,adPPYba,  8b,dPPYba,  MM88MMM  8b,dPPYba,  ,adPPYYba,   88" << endl;
    cout << "\t\t\t\t    88           a8     Y88  88       88  88             a8P_____88  88P      8a   88     88P    *Y8  **      Y8   88" << endl;
    cout << "\t\t\t\t    88          8b       88  88       88  Y8,            8PP******   88       88   88     88          ,adPPPPP88   88" << endl;
    cout << "\t\t\t\t    88          8a,    ,d88  *8a,   ,a88   Y8a.    .a8P  *8b,   ,aa  88       88   88,    88          88,    ,88   88" << endl;
    cout << "\t\t\t\t    88888888888  *8bbdP *Y8    *YbbdP Y8     *Y8888Y*      *Ybbd8*   88       88   *Y888  88           *8bbdP**Y8  88" << endl;
    cout << "\t\t\t\t    ";
    char line = 220;
    setConsoleColor(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
    for (int i = 0; i < 114; i++)
    {
        cout << line;
    }
    resetConsoleColor();
    cout << endl;
}

void adminMenu(int &totalTeachers, int &feedbackIndex, int &total, int x, int y, string name[], string id[], string adress[], string Section[], string contact[],
               string feedbackArray[], string teacherName[], string teacherID[], string teacherAge[], string teacherGender[], string teacherContact[], string teacherAddress[],
               int &Logout, int &exit, string senders[], string contents[], string timestamps[], int &announcementCount, const string &adminName, string feedbackTimestamps[])
{

    // Admin menu loop
    while (Logout == 0)
    {
        // Display Admin Page options
        header();
        welcomeAdmin();
        setConsoleColor(11);
        cout << "\n\n\t\t\t\t\t\t\t\t\t\t PRESS 1 TO MANAGE STUDENT";
        cout << "\n\t\t\t\t\t\t\t\t\t\t PRESS 2 TO MANAGE TEACHER";
        cout << "\n\t\t\t\t\t\t\t\t\t\t PRESS 3 TO VIEW FEEDBACK.";
        cout << "\n\t\t\t\t\t\t\t\t\t\t PRESS 4 TO MAKE AN ANNOUNCEMENT.";
        cout << "\n\t\t\t\t\t\t\t\t\t\t PRESS 5 TO LOGOUT.";
        cout << "\n\t\t\t\t\t\t\t\t\t\t PRESS 6 TO EXIT.";
        resetConsoleColor();

        // Get admin's choice
        char adminOption = getch();

        // Process admin's choice
        switch (adminOption)
        {
        case '1':
            // Manage Student
            manageStudent(totalTeachers, feedbackIndex, total, x, y, name, id, adress, Section, contact,
                          feedbackArray, teacherName, teacherID, teacherAge, teacherGender, teacherContact, teacherAddress, Logout, exit);
            break;

        case '2':
            // Manage Teacher
            manageTeacher(totalTeachers, feedbackIndex, total, x, y, name, id, adress, Section, contact,
                          feedbackArray, teacherName, teacherID, teacherAge, teacherGender, teacherContact, teacherAddress, Logout, exit);
            break;

        case '3':
            // Display Feedback
            displayFeedback(totalTeachers, feedbackIndex, total, x, y, feedbackArray, feedbackTimestamps);
            break;

        case '4':
            // Make an Announcement
            announcementMenu(senders, contents, timestamps, announcementCount, adminName);
            break;

        case '5':
            // Logout
            cout << "\n\n\t\t\t\t\t LOGGING OUT ";
            loading();
            Logout = 1;
            break;

        case '6':
            // Exit
            cout << "\n\t\t\t\t\tExiting ";
            loading();
            system("cls");
            Logout = 1;
            exit = 1;
            break;

        default:
            // invalid Input
            setConsoleColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
            invalid();
            resetConsoleColor();
            break;
        }
    }
}
void manageTeacher(int &totalTeachers, int &feedbackIndex, int total, int x, int y, string name[], string id[], string adress[], string Section[], string contact[],
                   string feedbackArray[], string teacherName[], string teacherID[], string teacherAge[], string teacherGender[], string teacherContact[], string teacherAddress[], int &Logout, int &exit)
{
    // Display header and options for managing teacher data
    header();
    setConsoleColor(3);
    cout << "\n\n\n\t\t\t\t\t\t\t\t\t ********** MANAGE TEACHERS **********\n";
    x = 70, y = 20;
    gotoxy(x, y);
    setConsoleColor(10);
    cout << "PRESS 1 TO ADD TEACHER DATA." << endl;
    gotoxy(x, y + 1);
    cout << "PRESS 2 TO SHOW TEACHER DATA." << endl;
    gotoxy(x, y + 2);
    cout << "PRESS 3 TO SEARCH TEACHER DATA." << endl;
    gotoxy(x, y + 3);
    cout << "PRESS 4 TO UPDATE TEACHER DATA." << endl;
    gotoxy(x, y + 4);
    cout << "PRESS 5 TO DELETE TEACHER DATA." << endl;
    resetConsoleColor();

    // Get user input for chosen option
    char user = getch();

    // Process user's choice
    if (user == '1')
    {
        // Add Teacher Data
        addTeacher(totalTeachers, feedbackIndex, total, x, y, teacherName, teacherID, teacherAge, teacherGender, teacherContact, teacherAddress, name, id, adress, Section, contact, feedbackArray, Logout, exit);
    }
    else if (user == '2')
    {
        // Show Teacher Data
        showTeacherData(totalTeachers, feedbackIndex, total, x, y, teacherName, teacherID, teacherAge, teacherGender, teacherContact, teacherAddress, name, id, adress, Section, contact, feedbackArray, Logout, exit);
    }
    else if (user == '3')
    {
        // Search Teacher Data
        searchTeacherData(totalTeachers, feedbackIndex, total, x, y, teacherName, teacherID, teacherAge, teacherGender, teacherContact, teacherAddress, name, id, adress, Section, contact, feedbackArray, Logout, exit);
    }
    else if (user == '4')
    {
        // Update Teacher Data
        updateTeacherData(totalTeachers, feedbackIndex, total, x, y, teacherName, teacherID, teacherAge, teacherGender, teacherContact, teacherAddress, name, id, adress, Section, contact, feedbackArray, Logout, exit);
    }
    else if (user == '5')
    {
        // Delete Teacher Data
        deleteTeacherData(totalTeachers, feedbackIndex, total, x, y, teacherName, teacherID, teacherAge, teacherGender, teacherContact, teacherAddress, name, id, adress, Section, contact, feedbackArray, Logout, exit);
    }
    else
    {
        // invalid Input
        setConsoleColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        invalid();
        resetConsoleColor();
    }
}
void addTeacher(int &totalTeachers, int &feedbackIndex, int total, int x, int y, string teacherName[], string teacherID[], string teacherAge[], string teacherGender[], string teacherContact[], string teacherAddress[], string name[], string id[], string adress[], string Section[], string contact[], string feedbackArray[], int &Logout, int &exit)
{
    // Get and validate Teacher's Name
    while (1)
    {
        cout << "\n\t\t\t\t\t\t Enter name of Teacher: ";
        getline(cin, teacherName[totalTeachers]);
        if ((empty(teacherName[totalTeachers])) == 1)
        {
            invalid();
        }
        else
        {
            break;
        }
    }

    // Get and validate Teacher's ID
    while (true)
    {
        cout << "\n\t\t\t\t\t\t Enter the ID of Teacher: ";
        getline(cin, teacherID[totalTeachers]);

        // Check if the entered ID already exists
        bool idExists = false;
        for (int j = 0; j < totalTeachers; j++)
        {
            if (teacherID[totalTeachers] == teacherID[j])
            {
                idExists = true;
                cout << "\n\t\t\t\t\t\tID already exists. Please enter again." << endl;
                break; // No need to continue checking once a match is found
            }
        }

        if (idExists)
        {
            continue; // Ask the user to enter the ID again
        }

        // Check if the entered ID is empty or contains non-numeric characters
        if (empty(teacherID[totalTeachers]) == 1 || checkInt(teacherID[totalTeachers]) == 1)
        {
            invalid();
            continue; // Ask the user to enter the ID again
        }

        // If all checks pass, break out of the loop
        break;
    }
    // Get and validate Teacher's Age
    while (1)
    {
        cout << "\n\t\t\t\t\t\t Enter the Age of Teacher: ";
        getline(cin, teacherAge[totalTeachers]);
        if (empty(teacherAge[totalTeachers]) == 1)
        {
            invalid();
        }
        else if (checkInt(teacherAge[totalTeachers]) == 1 || (stoi(teacherAge[totalTeachers]) < 16 || stoi(teacherAge[totalTeachers]) > 100))
        {
            setConsoleColor(12);
            cout << "\n\t\t\t\t\t\tinvalid Age format(Enter numbers only between 16 & 100) :";
            resetConsoleColor();
        }
        else
        {
            break;
        }
    }

    // Get and validate Teacher's Gender
    while (1)
    {
        cout << "\n\t\t\t\t\t\t Enter the Gender of Teacher(male/female): ";
        getline(cin, teacherGender[totalTeachers]);
        if (empty(teacherGender[totalTeachers]) == 1)
        {
            invalid();
        }
        else if (teacherGender[totalTeachers] != "male" && teacherGender[totalTeachers] != "female")
        {
            invalid();
        }
        else
            break;
    }

    // Get and validate Teacher's Contact
    while (1)
    {
        cout << "\n\t\t\t\t\t\t Enter the Contact of Teacher: ";
        getline(cin, teacherContact[totalTeachers]);
        if (empty(teacherContact[totalTeachers]) == 1)
        {
            invalid();
        }
        else if (checkInt(teacherContact[totalTeachers]) == 1)
        {
            invalid();
        }
        else
        {
            break;
        }
    }

    // Get and validate Teacher's Address
    while (1)
    {
        cout << "\n\t\t\t\t\t\t Enter the Address of Teacher: ";
        getline(cin, teacherAddress[totalTeachers]);
        if (empty(teacherAddress[totalTeachers]) == 1)
        {
            invalid();
        }
        else
            break;
    }

    // Increment totalTeachers and display success message
    totalTeachers++;
    cout << "\t\t\t\t\t\t Teacher Added Successfully, Redirecting to menu.";
    loading();
    system("cls");
    return;
}

// Display Teacher data
void showTeacherData(int totalTeachers, int &feedbackIndex, int total, int x, int y, string teacherName[], string teacherID[], string teacherAge[], string teacherGender[], string teacherContact[], string teacherAddress[], string name[], string id[], string adress[], string Section[], string contact[], string feedbackArray[], int &Logout, int &exit)
{
    readStudentData(name, id, adress, Section, contact, total);
    if (totalTeachers == 0)
    {
        // If there is no teacher data, show a message
        cout << "\n\t\t\t\t\t\t No teacher data till now ";
    }
    else
    {
        // Display Teacher data for each teacher
        cout << "\n\t\t\t\t\t\t\t ********* Teacher Data *********\n";
        for (int i = 0; i < totalTeachers; i++)
        {
            cout << "\n\t\t\t\t\t\t DATA OF TEACHER " << i + 1 << ":\n";
            cout << "\n\t\t\t\t\t\t Name: " << teacherName[i] << "\n";
            cout << "\t\t\t\t\t\t ID: " << teacherID[i] << "\n";
            cout << "\t\t\t\t\t\t Age: " << teacherAge[i] << "\n";
            cout << "\t\t\t\t\t\t Gender: " << teacherGender[i] << "\n";
            cout << "\t\t\t\t\t\t Contact: " << teacherContact[i] << "\n";
            cout << "\t\t\t\t\t\t Address: " << teacherAddress[i] << "\n";
        }
    }

    cout << "\n\t\t\t\t\t\t Press any key to return to the menu.";
    getch();
    return;
}

// Search for Teacher data by ID
void searchTeacherData(int totalTeachers, int &feedbackIndex, int total, int x, int y, string teacherName[], string teacherID[], string teacherAge[], string teacherGender[], string teacherContact[], string teacherAddress[], string name[], string id[], string adress[], string Section[], string contact[], string feedbackArray[], int &Logout, int &exit)
{
    if (totalTeachers == 0)
    {
        // If there are no teachers, display a message
        cout << "\n\t\t\t\t\t\t No teachers data available for searching.";
    }
    else
    {
        // Get the ID to search for
        cout << "\n\t\t\t\t\t\t Enter the ID of the teacher you want to search: ";
        string searchID;
        getline(cin, searchID);

        int index = -1; // To store the index of the teacher to be searched

        // Search for the teacher with the given ID
        for (int i = 0; i < totalTeachers; i++)
        {
            if (teacherID[i] == searchID)
            {
                index = i;
                break;
            }
        }

        if (index == -1)
        {
            // If teacher not found, display a message
            setConsoleColor(12);
            cout << "\n\t\t\t\t\t\t Teacher with ID " << searchID << " not found.";
            resetConsoleColor();
        }
        else
        {
            // Display the found teacher's data
            cout << "\n\t\t\t\t\t\t Teacher found:\n";
            cout << "\n\n\t\t\t\t\t\t Name: " << teacherName[index] << "\n";
            cout << "\t\t\t\t\t\t Age: " << teacherAge[index] << "\n";
            cout << "\t\t\t\t\t\t Gender: " << teacherGender[index] << "\n";
            cout << "\t\t\t\t\t\t Contact: " << teacherContact[index] << "\n";
            cout << "\t\t\t\t\t\t Address: " << teacherAddress[index] << "\n";
        }
    }

    cout << "\n\t\t\t\t\t\t Press any key to return to the menu.";
    getch();
    system("cls");
    return;
}

void updateTeacherData(int &totalTeachers, int &feedbackIndex, int total, int x, int y, string teacherName[], string teacherID[], string teacherAge[], string teacherGender[], string teacherContact[], string teacherAddress[], string name[], string id[], string adress[], string Section[], string contact[], string feedbackArray[], int &Logout, int &exit)
{
    if (totalTeachers == 0)
    {
        cout << "\n\t\t\t\t\t\t No teachers data available for updating.";
    }
    else
    {
        cout << "\n\t\t\t\t\t\t Enter the ID of the teacher you want to update: ";
        string updateID;
        getline(cin, updateID);

        int index = -1; // To store the index of the teacher to be updated

        // Search for the teacher with the given ID
        for (int i = 0; i < totalTeachers; i++)
        {
            if (teacherID[i] == updateID)
            {
                index = i;
                break;
            }
        }

        if (index == -1)
        {
            setConsoleColor(12);
            cout << "\n\t\t\t\t\t\t Teacher with ID " << updateID << " not found.";
            resetConsoleColor();
        }
        else
        {
            cout << "\n\t\t\t\t\t\t Previous information for Teacher with ID " << updateID << ":\n";
            cout << "\n\t\t\t\t\t\t Name: " << teacherName[index] << "\n";
            cout << "\t\t\t\t\t\t Age: " << teacherAge[index] << "\n";
            cout << "\t\t\t\t\t\t Gender: " << teacherGender[index] << "\n";
            cout << "\t\t\t\t\t\t Contact: " << teacherContact[index] << "\n";
            cout << "\t\t\t\t\t\t Address: " << teacherAddress[index] << "\n";

            cout << "\n\t\t\t\t\t\t Enter updated information for Teacher with ID " << updateID << ":\n";
            while (1)
            {
                cout << "\n\t\t\t\t\t\t Enter updated name: ";
                getline(cin, teacherName[index]);
                if (empty(teacherName[index]) == 1)
                {
                    invalid();
                }
                else
                {
                    break;
                }
            }
            while (true)
            {
                cout << "\n\t\t\t\t\t\t Enter the ID of Teacher: ";
                getline(cin, teacherID[index]);
                // Check if the entered ID is empty or contains non-numeric characters
                if (empty(teacherID[index]) || checkInt(teacherID[index]))
                {
                    invalid();
                }
                else
                {
                    // If all checks pass, break out of the loop
                    break;
                }
            }
            while (1)
            {
                cout << "\n\t\t\t\t\t\t Enter updated age: ";
                getline(cin, teacherAge[index]);
                if (empty(teacherAge[index]) == 1)
                {
                    invalid();
                }
                else if (checkInt(teacherAge[index]) == 1 || (stoi(teacherAge[totalTeachers]) < 16 || stoi(teacherAge[totalTeachers]) > 100))
                {
                    cout << "\n\t\t\t\t\t\tinvalid Age format(Enter numbers only between 16 & 100) :";
                }
                else
                {
                    break;
                }
            }
            while (1)
            {
                cout << "\n\t\t\t\t\t\t Enter updated gender: ";
                getline(cin, teacherGender[index]);
                if (empty(teacherGender[index]) == 1)
                {
                    invalid();
                }
                else if (teacherGender[index] != "male" && teacherGender[index] != "female")
                {
                    invalid();
                }
                else
                {
                    break;
                }
            }
            while (1)
            {
                cout << "\n\t\t\t\t\t\t Enter updated contact: ";
                getline(cin, teacherContact[index]);
                if (empty(teacherContact[index]) == 1)
                {
                    invalid();
                }
                else if (checkInt(teacherContact[index]) == 1)
                {
                    setConsoleColor(12);
                    cout << "\n\t\t\t\t\t\tinvalid Contact format(Enter numbers only) :";
                    resetConsoleColor();
                }
                else
                {
                    break;
                }
            }
            while (1)
            {
                cout << "\n\t\t\t\t\t\t Enter updated address: ";
                getline(cin, teacherAddress[index]);
                if (empty(teacherAddress[index]) == 1)
                {
                    invalid();
                }
                else
                {
                    break;
                }
            }
            cout << "\n\t\t\t\t\t\t Updating";
            loading();
            cout << "\n\t\t\t\t\t\t Teacher data updated successfully.";
        }
    }

    cout << "\n\t\t\t\t\t\t Press any key to return to the menu.";
    getch();
    system("cls");
    return;
}
void deleteTeacherData(int &totalTeachers, int &feedbackIndex, int total, int x, int y, string teacherName[], string teacherID[], string teacherAge[], string teacherGender[], string teacherContact[], string teacherAddress[], string name[], string id[], string adress[], string Section[], string contact[], string feedbackArray[], int &Logout, int &exit)
{
    if (totalTeachers == 0)
    {
        cout << "\n\t\t\t\t\t\t No teachers data available for deletion.";
    }
    else
    {
        cout << "\n\t\t\t\t\t\t Press 1 to delete all teachers' data !";
        cout << "\n\t\t\t\t\t\t Press 2 to delete specific teachers' data ! ";
        char deleteChoice = getch();

        if (deleteChoice == '1')
        {
            // Delete all teachers' data
            totalTeachers = 0;
            cout << "\n\t\t\t\t\t\t All teachers' data deleted successfully.";
        }
        else if (deleteChoice == '2')
        {
            cout << "\n\t\t\t\t\t\t Enter the ID of the teacher you want to delete: ";
            string deleteID;
            getline(cin, deleteID);

            int index = -1; // To store the index of the teacher to be deleted

            // Search for the teacher with the given ID
            for (int i = 0; i < totalTeachers; i++)
            {
                if (teacherID[i] == deleteID)
                {
                    index = i;
                    break;
                }
            }

            if (index == -1)
            {
                setConsoleColor(12);
                cout << "\n\t\t\t\t\t\t Teacher with ID " << deleteID << " not found.";
                resetConsoleColor();
            }
            else
            {
                // Delete the specific teacher's data
                for (int i = index; i < totalTeachers - 1; i++)
                {
                    teacherName[i] = teacherName[i + 1];
                    teacherID[i] = teacherID[i + 1];
                    teacherAge[i] = teacherAge[i + 1];
                    teacherGender[i] = teacherGender[i + 1];
                    teacherContact[i] = teacherContact[i + 1];
                    teacherAddress[i] = teacherAddress[i + 1];
                }

                totalTeachers--;

                cout << "\n\t\t\t\t\t\t Teacher with ID " << deleteID << " deleted successfully.";
            }
        }
        else
        {
            invalid();
        }
    }

    cout << "\n\t\t\t\t\t\t Press any key to return to the menu.";
    getch();
    system("cls");
    return;
}
bool ValidUserName(string username)
{
    int alphabets = 0;
    int numbers = 0;
    bool answer = false;

    for (int idx = 0; username[idx] != 0; idx++)
    {
        int x = username[idx];
        if (x >= 48 && x < 58)
        {
            numbers++;
        }
        {
            alphabets++;
        }
    }
    if (!alphabets || !numbers || username.length() < 6)
    {
        answer = false;
    }
    else
        answer = true;
    return answer;
}
bool validPassword(string pasword)
{
    int alphabets = 0;
    int numbers = 0;
    int special = 0;
    bool answer = false;

    for (int idx = 0; pasword[idx] != '\0'; idx++)
    {
        int x = pasword[idx];
        if (x >= 48 && x < 58)
        {
            numbers++;
        }
        else if ((x >= 65 && x < 91) || (x >= 97 && x < 123))
        {
            alphabets++;
        }
        else
        {
            special++;
        }
    }
    if (!alphabets || !numbers || !special || pasword.length() < 6)
    {
        answer = false;
    }
    else
        answer = true;
    return answer;
}
bool empty(string check)
{
    // Check if the string is empty or contains only spaces
    if (check.find_first_not_of(' ') == string::npos)
    {
        return true;
    }

    // Check if the string contains the '|' symbol
    if (check.find('|') != string::npos)
    {
        return true;
    }

    return false;
}
void manageStudent(int totalTeachers, int &feedbackIndex, int &total, int x, int y, string name[], string id[], string adress[], string Section[], string contact[],
                   string feedbackArray[], string teacherName[], string teacherID[], string teacherAge[], string teacherGender[], string teacherContact[], string teacherAddress[], int &Logout, int &exit)
{
    header();
    setConsoleColor(3);
    cout << "\n\n\n\t\t\t\t\t\t\t\t\t ********** MANAGE STUDENTS **********\n";
    x = 70, y = 20;
    gotoxy(x, y);
    setConsoleColor(10);
    cout << "PRESS 1 TO ENTER STUDENT DATA." << endl;
    gotoxy(x, y + 1);
    cout << "PRESS 2 TO SHOW STUDENT DATA." << endl;
    gotoxy(x, y + 2);
    cout << "PRESS 3 TO SEARCH STUDENT DATA." << endl;
    gotoxy(x, y + 3);
    cout << "PRESS 4 TO UPDATE STUDENT DATA." << endl;
    gotoxy(x, y + 4);
    cout << "PRESS 5 TO DELETE STUDENT DATA." << endl;
    resetConsoleColor();
    char user = getch();
    if (user == '1')

        enterStudentDataByAdmin(totalTeachers, feedbackIndex, total, x, y, name, id, adress, Section, contact,
                                feedbackArray, teacherName, teacherID, teacherAge, teacherGender, teacherContact, teacherAddress, Logout, exit);

    else if (user == '2')
    {
        showStudentDataByAdmin(totalTeachers, feedbackIndex, total, x, y, name, id, adress, Section, contact);
        getch();
    }
    else if (user == '3')
    {
        searchStudentDataByAdminn(totalTeachers, feedbackIndex, total, x, y, name, id, adress, Section, contact);
        getch();
    }
    else if (user == '4')
    {
        updateStudentdataByAdmin(totalTeachers, feedbackIndex, total, x, y, name, id, adress, Section, contact);
        getch();
    }
    else if (user == '5')
    {
        deleteStudentDataByAdmin(totalTeachers, feedbackIndex, total, x, y, name, id, adress, Section, contact);
        getch();
    }
    else
    {
        invalid();
    }
}

void enterStudentDataByAdmin(int totalTeachers, int &feedbackIndex, int &total, int x, int y, string name[], string id[], string adress[], string Section[], string contact[], string feedbackArray[], string teacherName[], string teacherID[], string teacherAge[], string teacherGender[], string teacherContact[], string teacherAddress[], int &Logout, int &exit)
{
    string choice1;
    while (1)
    {
        cout << "\n\t\t\t\t\t\t\t How many students do you want to enter? ";
        getline(cin, choice1);
        int integer = 0;
        if (empty(choice1) == 1)
        {
            invalid();
            getch();
        }
        else if (checkInt(choice1) == 1)
        {
            invalid();
        }

        else if (stoi(choice1) < 1)
        {
            invalid();
        }
        else if (stoi(choice1) > 100)
        {
            invalid();
        }
        else
        {
            break;
        }
    }

    int choice = stoi(choice1);
    for (int i = total; i < total + choice; i++)
    {
        while (1)
        {
            cout << "\n\n\t\t\t\t\t\t\t\t Enter name of Student " << i + 1 << " : ";
            getline(cin, name[i]);
            if (empty(name[i]) == 1)
            {
                invalid();
            }
            else
            {
                break;
            }
        }

        while (1)
        {
            cout << "\n\t\t\t\t\t\t\t Enter the ID of Student:";
            getline(cin, id[i]);

            // Check if the entered ID already exists
            bool idExists = false;
            for (int j = 0; j < i; j++)
            {
                if (id[i] == id[j])
                {
                    idExists = true;
                    cout << "\n\t\t\t\t\t\t\t\tStudent with ID " << id[i] << " already exists." << endl;
                    break; // No need to continue checking once a match is found
                }
            }

            if (idExists)
            {
                continue; // Ask the user to enter the ID again
            }

            // Additional checks (if needed)
            if (empty(id[i]) == 1)
            {
                invalid();
                cout << "\n\t\t\t\t\t\t\t\t Enter the ID of Student: ";
                continue; // Ask the user to enter the ID again
            }
            else if (checkInt(id[i]) == 1)
            {
                setConsoleColor(12);
                cout << "\n\t\t\t\t\t\t\t\tinvalid ID format (Enter numbers only):";
                resetConsoleColor();
                continue; // Ask the user to enter the ID again
            }
            // If all checks pass, break out of the loop
            break;
        }

        while (1)
        {
            cout << "\n\t\t\t\t\t\t\t Enter the address of Student: ";
            getline(cin, adress[i]);
            if (empty(adress[i]) == 1)
            {
                setConsoleColor(12);
                cout << "\n\t\t\t\t\t\t invalid format,Enter Again.";
                resetConsoleColor();
            }
            else
            {
                break;
            }
        }
        while (1)
        {
            cout << "\n\t\t\t\t\t\t\t\t Enter the contact of Student: ";
            getline(cin, contact[i]);
            if (empty(contact[i]) == 1)
            {
                setConsoleColor(12);
                cout << "\n\t\t\t\t\t\t\t\t invalid format,Enter Again.";
                resetConsoleColor();
            }
            else if (checkInt(contact[i]) == 1)
            {
                setConsoleColor(12);
                cout << "\n\t\t\t\t\t\t\t\t invalid format,Enter numbers only: ";
                resetConsoleColor();
            }
            else
            {
                break;
            }
        }
        while (1)
        {
            cout << "\n\t\t\t\t\t\t\t Enter the Section of Student: ";
            getline(cin, Section[i]);
            if (empty(Section[i]) == 1)
            {
                setConsoleColor(12);
                cout << "\n\t\t\t\t\t\tinvalid format,Enter Again.";
                resetConsoleColor();
            }
            else if ((Section[i] != "A" && Section[i] != "a") && (Section[i] != "B" && Section[i] != "b") && (Section[i] != "C" && Section[i] != "c") && (Section[i] != "D" && Section[i] != "d"))
            {
                setConsoleColor(12);
                cout << "\n\t\t\t\t\t\tinvalid format,Enter Again (A,B,C,D only) :";
                resetConsoleColor();
            }
            else
            {
                break;
            }
        }
    }

    total = total + choice;
    cout << "\t\t\t\t\t\t\t Data Entered Successfully, Redirecting to menu.";
    loading();
    system("cls");
    return;
}
void showStudentDataByAdmin(int totalTeachers, int &feedbackIndex, int total, int x, int y, string name[], string id[], string adress[], string Section[], string contact[])
{
    while (true)
    {
        if (total == 0)
        {
            setConsoleColor(12);
            cout << "\t\t\t\t\t\tNo data entered. Please enter data first." << endl;
            resetConsoleColor();
            return;
        }
        for (int i = 0; i < total; i++)
        {
            cout << endl;
            setConsoleColor(10);
            cout << "\t\t\t\t Data of Student " << i + 1 << endl;
            resetConsoleColor();
            cout << "\n\t\t\t\t Name:" << name[i] << endl;
            cout << "\t\t\t\t ID:" << id[i] << endl;
            cout << "\t\t\t\t Address:" << adress[i] << endl; // Fixed typo in variable name
            cout << "\t\t\t\t Contact:" << contact[i] << endl;
            cout << "\t\t\t\t Section:" << Section[i] << endl;
            cout << endl;
        }

        cout << "\n\t\t\t\tPress any key to go back to the menu. ";

        break; // Exit the loop after displaying data
    }
}
void searchStudentDataByAdminn(int totalTeachers, int &feedbackIndex, int total, int x, int y, string name[], string id[], string adress[], string Section[], string contact[])
{
    if (total == 0)
    {
        cout << "\t\t\t\t\t\tNo data entered. Please enter data first." << endl;
        return;
    }
    string ID;
    bool found = false;

    do
    {
        cout << "\t\t\t\t\t\t Enter ID of data you want to search (or type 'exit' to return): ";
        getline(cin, ID);

        if (ID == "exit")
        {
            return; // Exit the function if the user types 'exit'
        }

        for (int i = 0; i < total; i++)
        {
            if (ID == id[i])
            {
                cout << "\n\t\t\t\t\t\t Data of Student :" << i + 1 << endl;
                cout << "\t\t\t\t\t\t Name:" << name[i] << endl;
                cout << "\t\t\t\t\t\t ID:" << id[i] << endl;
                cout << "\t\t\t\t\t\t Address:" << adress[i] << endl; // Fixed typo in variable name
                cout << "\t\t\t\t\t\t Contact:" << contact[i] << endl;
                cout << "\t\t\t\t\t\t Section:" << Section[i] << endl;
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "\t\t\t\t\t\t No ID found." << endl;
        }

    } while (!found);
}
void updateStudentdataByAdmin(int totalTeachers, int &feedbackIndex, int &total, int x, int y, string name[], string id[], string adress[], string Section[], string contact[])
{
    if (total == 0)
    {
        cout << "\n\t\t\t\t\t\tNo data entered. Please enter data first." << endl;
        return;
    }
    bool found = false;
    string ID;
    cout << "\t\t\t\t\t\t Enter ID of data you want to Update.";
    getline(cin, ID);
    for (int i = 0; i < total; i++)
    {
        if (ID == id[i])
        {
            found = true;
            cout << "\t\t\t\t\t\t Previous record:" << endl;
            cout << endl;
            cout << "\t\t\t\t\t\t Data of Student " << i + 1 << endl;
            cout << "\t\t\t\t\t\t Name:" << name[i + 1] << endl;
            cout << "\t\t\t\t\t\t ID:" << id[i] << endl;
            cout << "\t\t\t\t\t\t Adress:" << adress[i] << endl;
            cout << "\t\t\t\t\t\t Contact:" << contact[i] << endl;
            cout << "\t\t\t\t\t\t Section:" << Section[i] << endl;
            cout << endl;
            cout << endl;
            setConsoleColor(10);
            cout << "\n\t\t\t\t\t\t New Record:" << endl;
            resetConsoleColor();

            while (1)
            {

                cout << "\n\t\t\t\t\t\t Enter name of Student " << i + 1 << " :";
                getline(cin, name[i]);
                if (empty(name[i]) == 1)
                {
                    invalid();
                }
                else
                {
                    break;
                }
            }
            while (1)
            {
                cout << "\n\t\t\t\t\t\t Enter the ID of Student:";
                getline(cin, id[i]);

                // Check if the entered ID already exists
                bool idExists = false;
                for (int j = 0; j < i; j++)
                {
                    if (id[j] == id[i])
                    {
                        idExists = true;
                        cout << "\n\t\t\t\t\t\t Student with ID " << id[i] << " already exists." << endl;
                        cout << "\n\t\t\t\t\t\t Enter the ID of Student: ";
                        break; // No need to continue checking once a match is found
                    }
                }

                if (empty(id[i]) == 1)
                {
                    invalid();
                    cout << "\n\t\t\t\t\t\t Enter the ID of Student: ";
                }
                else if (checkInt(id[i]) == 1)
                {
                    setConsoleColor(12);
                    cout << "\n\t\t\t\t\t\t invalid ID format (Enter numbers only):";
                    resetConsoleColor();
                }
                else
                {
                    // If all checks pass, break out of the loop
                    break;
                }
            }
            while (1)
            {
                cout << "\n\t\t\t\t\t\t Enter the adress of Student:";
                getline(cin, adress[i]);
                if (empty(adress[i]) == 1)
                {
                    invalid();
                }
                else
                {
                    break;
                }
            }
            while (1)
            {
                cout << "\n\t\t\t\t\t\t Enter the contact of Student:";
                getline(cin, contact[i]);
                if (empty(contact[i]) == 1)
                {
                    invalid();
                }
                else if (checkInt(contact[i]) == 1)
                {
                    invalid();
                }
                else
                {
                    break;
                }
            }
            while (1)
            {
                cout << "\n\t\t\t\t\t\t\t Enter the Section of Student: ";
                getline(cin, Section[i]);
                if (empty(Section[i]) == 1)
                {
                    setConsoleColor(12);
                    cout << "\n\t\t\t\t\t\tinvalid format,Enter Again.";
                    resetConsoleColor();
                }
                else if ((Section[i] != "A" && Section[i] != "a") && (Section[i] != "B" && Section[i] != "b") && (Section[i] != "C" && Section[i] != "c") && (Section[i] != "D" && Section[i] != "d"))
                {
                    setConsoleColor(12);
                    cout << "\n\t\t\t\t\t\tinvalid format,Enter Again (A,B,C,D only) :";
                    resetConsoleColor();
                }
                else
                {
                    break;
                }
            }
            cout << "\n\t\t\t\t\t\t Updating Student Record";
            loading();
            break;
        }
    }
    if (found == false)
    {
        cout << "\n\t\t\t\t\t\tNo ID Found,Please Enter Again.";
        Sleep(500);
    }
}
void deleteStudentDataByAdmin(int totalTeachers, int &feedbackIndex, int &total, int x, int y, string name[], string id[], string adress[], string Section[], string contact[])
{
    if (total == 0)
    {
        cout << "\n\t\t\t\t\t\tNo data entered. Please enter data first." << endl;
        return;
    }
    cout << "\t\t\t\t\t\t Press 1, if you want to delete the full record." << endl;
    cout << "\t\t\t\t\t\t Press 2, if you want to delete a specific record." << endl;
    char user;
    user = getch();
    if (user == '1')
    {
        cout << "\n\t\t\t\t\t\t Deleting";
        loading();
        total = 0;
        cout << "\n\t\t\t\t\t\t All records deleted successfully...!" << endl;
    }
    else if (user == '2')
    {
        if (total == 0)
        {
            cout << "\n\t\t\t\t\t\tNo data entered. Please enter data first." << endl;
            return;
        }
        string ID;
        cout << "\n\t\t\t\t\t\t Enter ID of data you want to delete: ";
        getline(cin, ID);

        int index = -1; // To store the index of the record to be deleted

        for (int i = 0; i < total; i++)
        {
            if (ID == id[i])
            {
                index = i;
                break; // Record found, no need to continue searching
            }
        }

        if (index != -1)
        {
            // Shift elements to the left to remove the record at index
            for (int j = index; j < total - 1; j++)
            {
                name[j] = name[j + 1];
                id[j] = id[j + 1];
                adress[j] = adress[j + 1];
                contact[j] = contact[j + 1];
                Section[j] = Section[j + 1];
            }
            total--;
            cout << "\t\t\t\t\t\t Record deleted successfully!" << endl;
        }
        else
        {
            setConsoleColor(12);
            cout << "\t\t\t\t\t\t Record not found!" << endl;
            resetConsoleColor();
        }
    }
}
void printColorText(const string &text, int colorCode)
{
    cout << "\x1B[" << colorCode << "m" << text << "\x1B[0m";
}

int loading()
{
    char box = 220;
    for (int i = 0; i < 2; i++)
    {                                        // Repeat the process twice
        int printColor = (i == 0) ? 36 : 31; // Cyan when printing, Red when erasing

        for (int k = 0; k < 55; k++)
        {
            printColorText(string(1, box), printColor);
            Sleep(10);
            cout.flush();
        }

        if (i == 1)
        {
            break;
        }

        for (int k = 0; k < 55; k++)
        {
            printColorText("\b \b", 31); // Erase using Red color
            Sleep(10);
            cout.flush();
        }
    }

    cout << endl;

    return 0;
}
void resizeConsole()
{
    COORD coord;
    SMALL_RECT rect;
    HWND console = GetConsoleWindow();
    coord.X = 1920;
    coord.Y = 1080;
    rect.Left = 0;
    rect.Top = 0;
    rect.Right = 1919;
    rect.Bottom = 1079;
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &rect);
    ShowWindow(console, SW_MAXIMIZE);
}
void signupPage(int totalTeachers, int &feedbackIndex, int total, int x, int y, int &couunt, string adminUsername[], string adminPassword[], string username[], string role[], string password[], string studentNames[], string subjects[],
                int SubjectID[], int studentSubjects[], string name[], string id[], string adress[], string Section[], string contact[], string studentIDs[])
{

    header();
    signUpBox();
    while (1)
    {
        cout << "\n\n\t\t\t\t\t\t\t\tENTER USERNAME: ";
        getline(cin, username[couunt]);
        if (empty(username[couunt]) == 1)
        {
            invalid();
        }
        else if (!ValidUserName(username[couunt]))
        {
            setConsoleColor(12);
            cout << "\n\n\t\t\t\t\t\tThe Username format is invalid.(It should include numbers and alphabets and minimum length is 6 characters.)\n";
            resetConsoleColor();
        }

        else
            break;
    }

    while (1)
    {

        bool flag = false;
        cout << "\n\t\t\t\t\t\t\t\tENTER PASSWORD: ";
        getline(cin, password[couunt]);
        // Check password uniqueness
        for (int i = 0; i < couunt; ++i)
        {
            if (password[couunt] == password[i])
            {
                y = 18;
                setConsoleColor(12);
                cout << "\n\t\t\t\t\t\t The Password format is invalid.(It should include numbers, alphabets and special\n\t\t\t\t\t\t characters and minimum length is 6 characters. Also It should be unique and not 'admin')" << endl;
                resetConsoleColor();
                y = y + 2;
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            // Check password Validity
            if (validPassword(password[couunt]) || (password[couunt]) == "admin" || (empty(password[couunt]) == 1))
            {
                setConsoleColor(12);
                cout << "\n\t\t\t\t\t\tThe Password format is invalid.(It should include numbers and alphabets only \n\t\t\t\t\t\t and minimum length is 6 characters. Also It should be unique and not 'admin')" << endl;
                resetConsoleColor();
            }
            else
                break;
        }
    }

    cout << "\n\t\t\t\t\t\t\t\tSIGNUP AS (STUDENT,TEACHER): ";
    getline(cin, role[couunt]);
    // Convert input to uppercase for case-insensitivity
    for (char &c : role[couunt])
    {
        c = toupper(c);
    }
    while (role[couunt] != "STUDENT" && role[couunt] != "TEACHER")
    {

        setConsoleColor(12);
        cout << "\n\t\t\t\t\t\t\t\tinvalid USER CHOICE, PLEASE ENTER A VALID USER CHOICE:";
        resetConsoleColor();
        getline(cin, role[couunt]);
        for (char &c : role[couunt])
        {
            c = toupper(c);
        }
        y = y + 2;
    }
    cout << "\n\t\t\t\t\t Creating Account ";
    loading();
    setConsoleColor(10);
    cout << "\n\n\t\t\t\t\t\t\t Account Created Sucessfully !";
    getch();
    resetConsoleColor();
    couunt++;
    return;
}
void signInConditions(string name1, string key, int x, int y, int &totalTeachers, int &feedbackIndex, int &total, int &couunt, string adminUsername[], string adminPassword[], string username[], string name[], string role[], string password[], string id[],
                      string adress[], string Section[], string contact[], string studentNames[], string subjects[], int SubjectID[], int studentSubjects[], string studentIDs[], string feedbackArray[], string teacherName[], string teacherID[], string teacherAge[],
                      string teacherGender[], string teacherContact[], string teacherAddress[], int &Logout, int &exit, string loginUsername, string senders[], string contents[], string timestamps[], int &announcementCount, const string &adminName, string feedbackTimestamps[], string attendanceStatus[])
{
    while (Logout == 0)
    {
        int num = 0;
        for (int i = 0; i <= couunt; i++)
        {
            if (name1 == "admin" && key == "admin")
            {
                adminMenu(totalTeachers, feedbackIndex, total, x, y, name, id, adress, Section, contact, feedbackArray, teacherName,
                          teacherID, teacherAge, teacherGender, teacherContact, teacherAddress, Logout, exit, senders, contents, timestamps, announcementCount, adminName, feedbackTimestamps);
                num++;
                break;
            }
            else if (username[i] == name1 && password[i] == key && role[i] == "TEACHER")
            {
                teacherMenu(totalTeachers, feedbackIndex, total, x, y, name, id, adress, Section, contact, studentNames,
                            subjects, SubjectID, studentSubjects, studentIDs, feedbackArray, teacherName, teacherID, teacherAge,
                            teacherGender, teacherContact, teacherAddress, Logout, exit, senders, contents, timestamps, announcementCount, feedbackTimestamps, attendanceStatus);
                num++;
                break;
            }
            else if (username[i] == name1 && password[i] == key && role[i] == "STUDENT")
            {
                studentMenu(totalTeachers, feedbackIndex, total, x, y, name, id, adress, Section, contact,
                            studentNames, subjects, SubjectID, studentSubjects, studentIDs, feedbackArray, Logout, exit, senders, contents, timestamps, announcementCount, feedbackTimestamps, attendanceStatus);
                num++;
                break;
            }
        }
        // If the credentials don't match with any user
        if (num == 0)
        {
            // Check if the entered username exists in the registration records
            bool isRegistered = false;
            for (int i = 0; i < couunt; i++)
            {
                if (username[i] == name1)
                {
                    isRegistered = true;
                    break;
                }
            }

            if (isRegistered)
            {
                // The username exists, but the password or role is incorrect
                gotoxy(x, y);
                setConsoleColor(12);
                cout << "\n\t\t\t\t\t\t\t\t invalid Password or Role for the entered username." << endl;
                resetConsoleColor();
            }
            else
            {
                // The username does not exist in the registration records
                gotoxy(x, y);
                setConsoleColor(12);
                cout << "\n\t\t\t\t\t\t\t User with the username '" << name1 << "' is not registered." << endl;
                resetConsoleColor();
            }
            cout << "\n\n\t\t\t\t\t\t\t Press SPACEBAR to Go Back, Press any Other Key to Re-Enter Credentials";
            char GoBack = getch();
            if (GoBack == VK_SPACE)
            {
                cout << "\n\t\t\t\t\t\tGoing Back,Please wait ";
                loading();
                Logout = 1;
                break;
            }
            while (1)
            {
                cout << "\n\n\t\t\t\t\t\t\t\tENTER USERNAME: ";
                getline(cin, name1);

                if (empty(name1) == 1)
                {
                    invalid();
                }
                else
                    break;
            }
            while (1)
            {
                cout << "\n\n\t\t\t\t\t\t\t\tENTER PASSWORD: ";
                getline(cin, key);
                if (empty(key) == 1)
                {
                    invalid();
                }
                else
                    break;
            }

            y = y + 6;
        }
    }
}

void firstPage(int x, int y)
{
    header();
    bottom(x, y);
    setConsoleColor(10);
    cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t\t+==============================================+" << endl;
    cout << "\t\t\t\t\t\t\t\t\t|                                              |" << endl;
    cout << "\t\t\t\t\t\t\t\t\t|                                              |" << endl;
    cout << "\t\t\t\t\t\t\t\t\t|                                              |" << endl;
    cout << "\t\t\t\t\t\t\t\t\t|    "
         << "          1. SIGN UP. --->                "
         << "|    " << endl;
    cout << "\t\t\t\t\t\t\t\t\t|    "
         << "          2. LOGIN... --->            "
         << "    |" << endl;
    cout << "\t\t\t\t\t\t\t\t\t|    "
         << "          3. EXIT.... --->                "
         << "|    " << endl;
    cout << "\t\t\t\t\t\t\t\t\t|                                              |" << endl;
    cout << "\t\t\t\t\t\t\t\t\t|                                              |" << endl;
    cout << "\t\t\t\t\t\t\t\t\t|                                              |" << endl;
    cout << "\t\t\t\t\t\t\t\t\t+==============================================+" << endl;
    resetConsoleColor();
    gotoxy(1, 53);
    char footer = 219;
    setConsoleColor(13);
    for (int i = 0; i < 196; i++)
    {
        cout << footer;
    }
    resetConsoleColor();
    gotoxy(60, 43);
}

void bottom(int x, int y)
{
    setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    x = 58, y = 12;
    gotoxy(x, y + 1);
    cout << "*****************************************************************************" << endl;
    gotoxy(x, y + 2);
    cout << "*****************************************************************************" << endl;
    gotoxy(x, y + 3);
    cout << "*********************** COLLEGE MANAGEMENT SYSTEM ***************************" << endl;
    gotoxy(x, y + 4);
    cout << "*****************************************************************************" << endl;
    gotoxy(x, y + 5);
    cout << "*****************************************************************************" << endl;
    resetConsoleColor(); // Reset text color to default
}
void gotoxy(int x, int y)
{

    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
//************************** STUDENT INTERFACE*********************************
void studentMenu(int totalTeachers, int &feedbackIndex, int &total, int x, int y, string name[], string id[], string adress[], string Section[], string contact[],
                 string studentNames[], string subjects[], int SubjectID[], int studentSubjects[], string studentIDs[], string feedbackArray[], int &Logout, int &exit,
                 string senders[], string contents[], string timestamps[], int announcementCount, string feedbackTimestamps[], string attendanceStatus[])
{
    while (Logout == 0)
    {
        header();
        studentBox();

        setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "\n\n\n\t\t\t\t\t\t\t\t\t PRESS 1 TO VIEW PERSONAL PROFILE." << endl;
        cout << "\t\t\t\t\t\t\t\t\t PRESS 2 TO UPDATE INFORMATION" << endl;
        cout << "\t\t\t\t\t\t\t\t\t PRESS 3 TO REGISTER SUBJECTS." << endl;
        cout << "\t\t\t\t\t\t\t\t\t PRESS 4 TO VIEW ATTENDANCE DETAILS." << endl;
        cout << "\t\t\t\t\t\t\t\t\t PRESS 5 TO VISIT LIBRARY." << endl;
        cout << "\t\t\t\t\t\t\t\t\t PRESS 6 TO LEAVE A FEEDBACK." << endl;
        cout << "\t\t\t\t\t\t\t\t\t PRESS 7 TO VIEW ANNOUNCMENT." << endl;
        cout << "\t\t\t\t\t\t\t\t\t PRESS 8 TO LOGOUT." << endl;
        cout << "\t\t\t\t\t\t\t\t\t PRESS 9 TO EXIT." << endl;
        resetConsoleColor();
        char studentChoice = getch();
        if (studentChoice == '1')
        {

            viewProfile(totalTeachers, feedbackIndex, total, x, y, name, id, adress, Section, contact, studentNames, subjects,
                        SubjectID, studentSubjects, studentIDs, feedbackArray, Logout, exit, senders, contents, timestamps, announcementCount, feedbackTimestamps, attendanceStatus);
        }
        else if (studentChoice == '2')
        {
            updateStudentInformation(totalTeachers, feedbackIndex, total, x, y, name, id, adress, Section, contact,
                                     studentNames, subjects, SubjectID, studentSubjects, studentIDs, feedbackArray);
        }
        else if (studentChoice == '3')
        {
            Register(totalTeachers, feedbackIndex, total, x, y, name, id, adress, Section, contact, studentNames, subjects, SubjectID, studentSubjects, studentIDs, feedbackArray);
        }
        else if (studentChoice == '4')
        {
            header();
            setConsoleColor(11);
            cout << "\n\n\t\t\t\t\t\t ********** VIEW ATTENDANCE **********\n";
            string studentID;
            setConsoleColor(11);
            cout << "\n\n\t\t\t\t\t\t\t\tEnter your ID: ";
            getline(cin, studentID);

            int studentIndex = findStudentIndex(studentID, id, total);
            if (studentIndex != -1)
            {
                string studentName = name[studentIndex];
                string attendanceStatus = studentNames[studentIndex];
                // Call the function to display attendance to the student
                displayAttendanceToStudent(studentID, studentName, attendanceStatus);
            }
            else
            {
                setConsoleColor(12);
                cout << "\n\n\t\t\t\t\t\t\t\tStudent not found.";
                resetConsoleColor();
                getch();
            }
        }
        else if (studentChoice == '5')
        {
            Library(totalTeachers, feedbackIndex, total, x, y, name, id, adress, Section, contact, studentNames,
                    subjects, SubjectID, studentSubjects, studentIDs, feedbackArray);
        }
        else if (studentChoice == '6')
        {
            string studentFeedback[1];
            while (true)
            {

                header();
                setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                cout << "\n\n\n\t\t\t\t\t\t\t\t ********** FEEDBACK SYSTEM **********\n";
                resetConsoleColor();
                setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                cout << "\n\n\t\t\t\t\t\t\t\t 1. Enter Feedback\n";
                cout << "\t\t\t\t\t\t\t\t 2. View Feedback\n";
                cout << "\t\t\t\t\t\t\t\t 3. Delete Feedback\n";
                cout << "\t\t\t\t\t\t\t\t 4. Go back\n";
                resetConsoleColor();
                char choice = getch();

                switch (choice)
                {
                case '1':
                    addFeedback(totalTeachers, feedbackIndex, total, x, y, feedbackArray, feedbackTimestamps);
                    break;

                case '2':
                    displayFeedback(totalTeachers, feedbackIndex, total, x, y, feedbackArray, feedbackTimestamps);
                    break;

                case '3':
                    deleteFeedback(totalTeachers, feedbackIndex, total, x, y, feedbackArray);
                    break;

                case '4':
                    return;
                    break;

                default:

                    setConsoleColor(12);
                    cout << "\n\t\t\t\t\t\t\t invalid choice. Please try again.\n";
                    resetConsoleColor();
                    getch();
                }
            }
        }
        else if (studentChoice == '7')
        {
            displayAnnouncements(senders, contents, timestamps, announcementCount);
        }
        else if (studentChoice == '8')
        {
            Logout = 1;
            cout << "\n\t\t\t\t\t\tLogging Out ";
            loading();
        }
        else if (studentChoice == '9')
        {
            cout << "\n\t\t\t\t\t\tExiting ";
            loading();
            system("cls");
            Logout = 1;
            exit = 1;
        }
        else
        {
            invalid();
            return;
            ;
        }
    }
}
void viewProfile(int totalTeachers, int &feedbackIndex, int total, int x, int y, string name[], string id[], string adress[], string Section[], string contact[],
                 string studentNames[], string subjects[], int SubjectID[], int studentSubjects[], string studentIDs[], string feedbackArray[], int &Logout, int &exit, string senders[],
                 string contents[], string timestamps[], int announcementCount, string feedbackTimestamps[], string attendanceStatus[])
{

    header();
    setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t\t********** VIEW PROFILE **********";
    resetConsoleColor(); // Reset text color to default
    setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    string enteredID;
    cout << "\n\n\n\n\n\t\t\t\t\t\t\t Enter your ID to view your profile: ";
    getline(cin, enteredID);

    bool found = false;
    for (int i = 0; i < total; i++)
    {
        if (enteredID == id[i])
        {
            found = true;
            cout << "\n\n\t\t\t\t\t\t Profile for Student with ID " << enteredID << ":" << endl;
            cout << "\t\t\t\t\t\t Name:-> " << name[i] << endl;
            cout << "\t\t\t\t\t\t ID:-> " << id[i] << endl;
            cout << "\t\t\t\t\t\t Address:-> " << adress[i] << endl;
            cout << "\t\t\t\t\t\t Contact:-> " << contact[i] << endl;
            cout << "\t\t\t\t\t\t Section:-> " << Section[i] << endl;
            displayRegisteredSubjects(stoi(enteredID), name, id, adress, Section, contact, studentNames, subjects, SubjectID, studentSubjects);
            getch();
            return;
        }
    }

    if (!found)
    {
        cout << "\t\t\t\t\t\t No data found for the entered ID.(Ask Admin to Enter Your Data)" << endl;
        Sleep(1000);
        return;
    }
}
void updateStudentInformation(int &totalTeachers, int &feedbackIndex, int &total, int x, int y, string name[], string id[], string adress[], string Section[], string contact[],
                              string studentNames[], string subjects[], int SubjectID[], int studentSubjects[], string studentIDs[], string feedbackArray[])
{
    header();
    setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "\n\n\n\t\t\t\t\t\t\t\t\t**********UPDATE INFORMATION**********";
    resetConsoleColor(); // Reset text color to default

    string ID;
    cout << "\n\n\n\t\t\t\t\t\t\t\t Enter your ID to update profile: ";
    getline(cin, ID);

    int index = -1; // To store the index of the student's record

    for (int i = 0; i < total; i++)
    {
        if (ID == id[i])
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        // Display the current profile information
        cout << "\n\t\t\t\t\t\t\t\t Current Profile Information:\n";
        cout << "\t\t\t\t\t\t\t\t Name: " << name[index] << endl;
        cout << "\t\t\t\t\t\t\t\t ID: " << id[index] << endl;
        cout << "\t\t\t\t\t\t\t\t Adress: " << adress[index] << endl;
        cout << "\t\t\t\t\t\t\t\t Contact: " << contact[index] << endl;
        cout << "\t\t\t\t\t\t\t\t Section: " << Section[index] << endl;

        // Allow the student to update information
        setConsoleColor(10);
        cout << "\n\n\t\t\t\t\t\t\t\t Enter new information:\n";
        resetConsoleColor();
        cout << "\t\t\t\t\t\t\t\t ID(Cannot be Changed): " << id[index] << endl;
        while (1)
        {

            cout << "\n\t\t\t\t\t\t\t Enter name of Student " << index + 1 << " :";
            getline(cin, name[index]);
            if (empty(name[index]) == 1)
            {
                invalid();
            }
            else
            {
                break;
            }
        }
        while (1)
        {
            cout << "\n\t\t\t\t\t\t\t Enter the adress of Student:";
            getline(cin, adress[index]);
            if (empty(adress[index]) == 1)
            {
                invalid();
            }
            else
            {
                break;
            }
        }
        while (1)
        {
            cout << "\n\t\t\t\t\t\t Enter the contact of Student:";
            getline(cin, contact[index]);
            if (empty(contact[index]) == 1)
            {
                invalid();
            }
            else
            {
                break;
            }
        }
        while (1)
        {
            cout << "\n\t\t\t\t\t\t\t Enter the Section of Student:";
            getline(cin, Section[index]);
            if (empty(Section[index]) == 1)
            {
                invalid();
            }
            else
            {
                break;
            }
            break;
        }
        cout << "\n\t\t\t\t\t Profile updateding ";
        loading();
        cout << "\n\n\t\t\t\t\t\t\t\t Profile updated successfully!\n";
        getch();
        return;
    }
    else
    {
        setConsoleColor(12);
        cout << "\n\t\t\t\t\t\t\t Student with ID " << ID << " not found.\n";
        cout << "\n\t\t\t\t\t\t\tPress any key to go back";
        resetConsoleColor();
        getch();
        return;
    }
}
void Register(int totalTeachers, int &feedbackIndex, int total, int x, int y, string name[], string id[], string adress[], string Section[], string contact[], string studentNames[], string subjects[], int SubjectID[], int studentSubjects[], string studentIDs[], string feedbackArray[])
{
    header();
    setConsoleColor(10);
    cout << "\n\n\t\t\t\t\t\t\t\t\t ********* REGISTER SUBJECT **********";
    setConsoleColor(11);
    cout << "\n\n\n\t\t\t\t\t\t\t\tPress 1 if you want to see available subjects";
    cout << "\n\t\t\t\t\t\t\t\tPress 2 if you want to Register subjects";
    cout << "\n\t\t\t\t\t\t\t\tPress 3 if you want to Go Back.";
    resetConsoleColor();
    char input = getch();
    if (input == '1')
    {
        displayAvailableStudents(studentNames, subjects, SubjectID, studentSubjects, totalTeachers, feedbackIndex, total, x, y, name, id, adress, Section, contact, studentIDs, feedbackArray);
    }
    else if (input == '2')
    {
        string stdID, sbjID;
        while (1)
        {
            cout << "\n\n\t\t\t\t\t\t\tEnter your ID.";
            getline(cin, stdID);
            if (empty(stdID) == 1)
            {
                invalid();
            }
            else if (checkInt(stdID) == 1)
            {
                setConsoleColor(12);
                cout << "\n\t\t\t\t\t\t\t\tinvalid ID format(Enter numbers only) :";
                resetConsoleColor();
            }
            else
            {
                break;
            }
        }

        while (1)
        {
            cout << "\n\t\t\t\t\t\t\tEnter subject ID.";
            getline(cin, sbjID);
            if (empty(sbjID) == 1)
            {
                setConsoleColor(12);
                cout << "\n\t\t\t\t\t\t\t\tinvalid ID format,Enter Again.";
                resetConsoleColor();
            }
            else if (checkInt(sbjID) == 1)
            {
                setConsoleColor(12);
                cout << "\n\t\t\t\t\t\t\t\tinvalid ID format(Enter numbers only) :";
                resetConsoleColor();
            }
            else
            {
                break;
            }
        }

        RegisterSubject(stoi(stdID), stoi(sbjID), totalTeachers, feedbackIndex, total, x, y, name, id, adress,
                        Section, contact, studentNames, subjects, SubjectID, studentSubjects, studentIDs, feedbackArray);
    }
    else if (input == '3')
    {
        return;
    }
    else
    {
        invalid();
        return;
    }
}
void displayRegisteredSubjects(int studentID, string name[], string id[], string adress[], string Section[], string contact[], string studentNames[], string subjects[], int SubjectID[], int studentSubjects[])
{
    // Check if the entered student ID exists
    bool validID = false;
    for (int i = 0; i < 100; ++i)
    {
        if (id[i] == to_string(studentID))
        {
            validID = true;
            break;
        }
    }

    if (!validID)
    {
        setConsoleColor(12);
        cout << "\n\t\t\tinvalid student ID. This ID does not exist.\n";
        getch();
        resetConsoleColor();
        // You may choose to return or take appropriate action based on your program flow
        return;
    }

    // Display registered subjects
    bool subjectsRegistered = false;
    setConsoleColor(12);
    cout << "\n\t\t\t\t\t\tRegistered Subjects.";
    resetConsoleColor();
    for (int i = 0; i < 5; ++i)
    {
        if (studentSubjects[(studentID - 1) * 5 + i] != 0)
        {
            // Assuming you have an array for subject names, modify as needed
            cout << "\n\t\t\t\t\t\tSubject " << (i + 1) << ": " << subjects[studentSubjects[(studentID - 1) * 5 + i] - 1] << endl;
            subjectsRegistered = true;
        }
    }

    if (!subjectsRegistered)
    {
        cout << "\t\t\tNo subject registered.\n";
        getch();
    }
}
void RegisterSubject(int studentID, int subjectID, int totalTeachers, int &feedbackIndex, int total, int x, int y,
                     string name[], string id[], string adress[], string Section[], string contact[],
                     string studentNames[], string subjects[], int SubjectID[], int studentSubjects[], string studentIDs[], string feedbackArray[])
{
    // Check if the entered student ID already exists
    int studentIndex = -1;
    for (int i = 0; i < total; ++i)
    {
        if (id[i] == to_string(studentID))
        {
            studentIndex = i;
            break;
        }
    }

    if (studentIndex == -1)
    {
        setConsoleColor(12);
        cout << "\n\t\t\tinvalid student ID. This ID does not exist.\n";
        getch();
        resetConsoleColor();
        return;
    }

    // Check if the subject ID is valid
    else if (subjectID < 1 or subjectID > 5)
    {
        setConsoleColor(12);
        cout << "\n\t\t\tinvalid subject ID.\n";
        resetConsoleColor();
        getch();
        return;
    }

    // Assign the subject to the student
    else
    {
        studentIDs[studentIndex] = id[studentIndex]; // Assuming studentIDs is a parallel array to id

        // Check if the maximum subjects are already registered
        bool subjectsRegistered = false;
        for (int i = 0; i < 5; ++i)
        {
            if (studentSubjects[studentIndex * 5 + i] == 0)
            {
                studentSubjects[studentIndex * 5 + i] = subjectID;
                subjectsRegistered = true;
                break;
            }
        }

        // Display messages based on the result
        if (subjectsRegistered)
        {
            cout << "\n\n\t\t\t\t\tAssigning Subject";
            loading();
            cout << "\t\t\t\t\t\tSubject assigned successfully.";
            getch();
            return;
        }
        else
        {
            cout << "\t\t\t\t\t\t MAXIMUM SUBJECTS ARE ALREADY REGISTERED";
            getch();
        }
    }
}

void displayAvailableStudents(string studentNames[], string subjects[], int SubjectID[], int studentSubjects[], int totalTeachers, int &feedbackIndex, int total, int x, int y, string name[],
                              string id[], string adress[], string Section[], string contact[], string studentIDs[], string feedbackArray[])
{
    header();
    setConsoleColor(12);
    cout << "\n\n\t\t\t\t\t\t\t\t ********** Available Subjects **********";
    resetConsoleColor();
    cout << endl
         << endl
         << endl;
    setConsoleColor(10);
    cout << "\n\t\t\t\t\t SUBJECT: \t\t\t\t ID\n";
    resetConsoleColor();
    for (int i = 0; i < 5; ++i)
    {
        cout << "\n\t\t\t\t\t " << subjects[i] << "\t\t\t\t " << SubjectID[i] << endl;
    }
    getch();
    return;
}
void Library(int totalTeachers, int &feedbackIndex, int total, int x, int y, string name[], string id[], string adress[], string Section[], string contact[], string studentNames[],
             string subjects[], int SubjectID[], int studentSubjects[], string studentIDs[], string feedbackArray[])
{
    header();
    setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "\n\n\t\t\t\t\t\t\t\t********** WELCOME TO LIBRARY **********";
    resetConsoleColor(); // Reset text color to default
    setConsoleColor(10);
    cout << "\n\n\t\t\t\t\t\t\t\t 1.--> SEE ALL BOOKS.";
    cout << "\n\t\t\t\t\t\t\t\t 2.--> SEE BOOKS GENRE.";
    cout << "\n\t\t\t\t\t\t\t\t 3.--> GO BACK TO MAIN MENUE.";
    resetConsoleColor();
    bool flag = false;
    char books = getch();
    if (books == '1')
    {
        flag = true;
        header();
        setConsoleColor(6);
        cout << "\n\n\t\t\t\t\t\t\t\t ********** ALL BOOKS **********" << endl;
        resetConsoleColor();
        typeHistory();
        typeFantasy();
        typeReligious();
        typeNovel();
        cout << "\n\t\t\t\t\t\t\t Press any Key to Go Back";
        getch();
        return;
    }
    if (books == '2')
    {
        flag = true;
        setConsoleColor(10);
        cout << "\n\n\t\t\t\t\t\t\t\t1--> FANTASY";
        cout << "\n\t\t\t\t\t\t\t\t2--> HISTORY";
        cout << "\n\t\t\t\t\t\t\t\t3--> NOVEL";
        cout << "\n\t\t\t\t\t\t\t\t4--> RELIGIOUS";
        resetConsoleColor();
        char genre = getch();

        switch (genre)
        {
        case '1':
            typeFantasy();
            getch();
            break;
        case '2':
            typeHistory();
            getch();
            break;
        case '3':
            typeNovel();
            getch();
            break;
        case '4':
            typeReligious();
            getch();
            break;
        default:
        {
            invalid();
            return;
        }
        break;
        }
    }
    if (books == '3')
    {
        flag = true;
        cout << "\n\t\t\t\t\t\t loading";
        loading();
        return;
    }

    else
    {
        if (flag == false)
        {
            invalid();
            getch();
            return;
        }
    }
}
void typeReligious()
{
    setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "\n\n\t\t\t\t\t\t\t\t\t ********** RELIGIOUS BOOKS **********" << endl;
    resetConsoleColor();
    setConsoleColor(10);
    cout << "\n\n\t\t\t\t\t\t\t1) THE HOLY QURAN" << endl;
    cout << "\n\t\t\t\t\t\t\t2) THE SPIRIT OF ISLAM by SYED AMEER ALI" << endl;
    cout << "\n\t\t\t\t\t\t\t3) THE BIBLE" << endl;
    resetConsoleColor();
}
void typeNovel()
{
    setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "\n\n\t\t\t\t\t\t\t\t\t ********** NOVEL BOOKS **********" << endl;
    resetConsoleColor();
    setConsoleColor(10);
    cout << "\n\n\t\t\t\t\t\t\t1) The Great Gatsby by F. Scott Fitzgerald. " << endl;
    cout << "\n\t\t\t\t\t\t\t2) Nineteen Eighty Four by George Orwell " << endl;
    cout << "\n\t\t\t\t\t\t\t3) MR. CHIPS by James Hilton " << endl;
    resetConsoleColor();
}
void typeFantasy()
{

    setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "\n\n\t\t\t\t\t\t\t\t\t ********** FANTASY BOOKS **********" << endl;
    resetConsoleColor();
    setConsoleColor(10);
    cout << "\n\n\t\t\t\t\t\t\t1) HARRY POTTER AND DEATHLY HALLOWS:" << endl;
    cout << "\n\t\t\t\t\t\t\t2) THE LORDS OF RINGS" << endl;
    cout << "\n\t\t\t\t\t\t\t3) TWILIGHT-LIFE AND DEATH" << endl;
    cout << "\n\t\t\t\t\t\t\t4) GAME OF THRONES" << endl;
    resetConsoleColor();
}
void typeHistory()
{
    setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "\n\n\t\t\t\t\t\t\t\t\t ********** HISTORIC BOOKS **********" << endl;
    resetConsoleColor();
    setConsoleColor(10);
    cout << "\n\n\t\t\t\t\t\t\t1) MUHAMMAD BIN QASIM by NASEEM IJAZI" << endl;
    cout << "\n\t\t\t\t\t\t\t2) 1776 by David McCullough" << endl;
    cout << "\n\t\t\t\t\t\t\t3) Churchill: Walking with Destiny by Andrew Roberts" << endl;
    cout << "\n\t\t\t\t\t\t\t4) The Communist Manifesto by Karl Marx" << endl;
    resetConsoleColor();
}
void addFeedback(int totalTeachers, int &feedbackIndex, int total, int x, int y, string feedbackArray[], string feedbackTimestamps[])
{
    if (feedbackIndex < 10)
    {
        cout << "\n\t\t\t\t\t\tEnter your feedback: ";
        getline(cin, feedbackArray[feedbackIndex]);
        feedbackTimestamps[feedbackIndex] = getCurrentTimestamp(); // Store timestamp
        ++feedbackIndex;

        cout << "\n\t\t\t\t\t\tFeedback added successfully!\n";
        getch();
    }
    else
    {

        cout << "\n\t\t\t\t\t\tFeedback array is full. Cannot add more feedback.\n";
        getch();
    }
}

void displayFeedback(int totalTeachers, int &feedbackIndex, int total, int x, int y, string feedbackArray[], string feedbackTimestamps[])
{
    header();
    setConsoleColor(10);
    cout << "\n\n\t\t\t\t\t\t\t********** DISPLAY FEEDBACK **********\n\n";
    resetConsoleColor();

    if (feedbackIndex == 0)
    {
        // Display a message if there is no feedback
        cout << "\n\n\t\t\t\t\t\t\tFeedback list is empty.\n";
    }
    else
    {
        cout << "\n\n\n\n\t\t\t\t\t\t\tFeedback Entered By Students:";
        for (int i = 0; i < feedbackIndex; ++i)
        {
            cout << "\n\t\t\t\t\t\t\t" << i + 1 << ". " << feedbackArray[i] << "\t entered" << feedbackTimestamps[i];
        }
    }

    getch();
}
void deleteFeedback(int totalTeachers, int &feedbackIndex, int total, int x, int y, string feedbackArray[])
{
    if (feedbackIndex == 0)
    {
        cout << "\n\t\t\t\t\t\t\tNo feedback to delete.\n";
        getch();
        return;
    }
    setConsoleColor(10);
    cout << "\n\t\t\t\t\t\t\tDo you want to delete:\n";
    resetConsoleColor();
    cout << "\t\t\t\t\t\t\t1. Specific Feedback\n";
    cout << "\t\t\t\t\t\t\t2. All feedback\n";
    char option = getch();
    switch (option)
    {
    case '1':
    { // Delete previously entered feedback
        string idx;
        while (1)
        {
            cout << "\n\t\t\t\t\t\t\tEnter the index of the feedback to delete: ";
            getline(cin, idx);
            if (checkInt(idx) == 1 || empty(idx) == 1)
            {
                invalid();
            }
            else
                break;
        }
        int index = stoi(idx);
        if (index > 0 && index <= feedbackIndex)
        {
            for (int i = index - 1; i < feedbackIndex - 1; ++i)
            {
                feedbackArray[i] = feedbackArray[i + 1];
            }

            --feedbackIndex;
            cout << "\n\t\t\t\t\t\t Deleting ";
            loading();
            cout << "\n\t\t\t\t\t\tFeedback deleted successfully!\n";
            getch();
        }
        else
        {
            setConsoleColor(12);
            cout << "\n\t\t\t\t\t\tinvalid index. No feedback deleted.\n";
            resetConsoleColor();
            getch();
        }
        break;
    }

    case '2':
    { // Delete all feedback
        feedbackIndex = 0;
        cout << "\n\t\t\t\t\t\t Deleting ";
        loading();
        cout << "\n\t\t\t\t\t\tAll feedback deleted successfully!\n";
        getch();
        break;
    }

    default:
        setConsoleColor(12);
        cout << "\n\t\t\t\t\t\tinvalid option. No feedback deleted.\n";
        getch();
        resetConsoleColor();
        break;
    }
}
void teacherMenu(int &totalTeachers, int &feedbackIndex, int total, int x, int y, string name[], string id[], string adress[], string Section[], string contact[], string studentNames[],
                 string subjects[], int SubjectID[], int studentSubjects[], string studentIDs[], string feedbackArray[], string teacherName[], string teacherID[], string teacherAge[],
                 string teacherGender[], string teacherContact[], string teacherAddress[], int &Logout, int &exit, string senders[], string contents[], string timestamps[], int announcementCount, string feedbackTimestamps[], string attendanceStatus[])
{
    char TeacherChoice;

    while (Logout == 0)
    {

        header();
        teacherBox();

        setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "\n\n\n\t\t\t\t\t\t\t\t\tPRESS 1 TO VIEW PERSONAL PROFILE." << endl;
        cout << "\t\t\t\t\t\t\t\t\tPRESS 2 TO UPDATE INFORMATION" << endl;
        cout << "\t\t\t\t\t\t\t\t\tPRESS 3 TO MANAGE ATTENDANCE." << endl;
        cout << "\t\t\t\t\t\t\t\t\tPRESS 4 TO VISIT LIBRARY." << endl;
        cout << "\t\t\t\t\t\t\t\t\tPRESS 5 TO VIEW FEEDBACK." << endl;
        cout << "\t\t\t\t\t\t\t\t\tPRESS 6 TO VIEW ANNOUNCEMENT." << endl;
        cout << "\t\t\t\t\t\t\t\t\tPRESS 7 TO LOGOUT." << endl;
        cout << "\t\t\t\t\t\t\t\t\tPRESS 8 TO EXIT." << endl;
        resetConsoleColor();

        TeacherChoice = getch();
        switch (TeacherChoice)
        {
        case '1':
        {
            viewStudentProfile(totalTeachers, feedbackIndex, total, x, y, teacherName, teacherID, teacherAge, teacherGender, teacherContact, teacherAddress,
                               name, id, adress, Section, contact, studentNames, subjects, SubjectID, studentSubjects, studentIDs, feedbackArray);

            break;
        }
        case '2':
            system("cls");
            updateTeacherInformation(totalTeachers, feedbackIndex, total, x, y, teacherName, teacherID, teacherAge,
                                     teacherGender, teacherContact, teacherAddress, name, id, adress, Section, contact, studentNames,
                                     subjects, SubjectID, studentSubjects, studentIDs, feedbackArray);
            getch();
            break;
        case '3':
            system("cls");
            manageAttendance(total, name, id, adress, Section, contact, studentNames, studentIDs, attendanceStatus);
            break;
        case '4':

            Library(totalTeachers, feedbackIndex, total, x, y, name, id, adress, Section, contact, studentNames,
                    subjects, SubjectID, studentSubjects, studentIDs, feedbackArray);
            break;
        case '5':
            displayFeedback(totalTeachers, feedbackIndex, total, x, y, feedbackArray, feedbackTimestamps);
            break;
        case '6':
            displayAnnouncements(senders, contents, timestamps, announcementCount);
            break;
        case '7':
            cout << "\n\t\t\tLogging out ";
            loading();
            Logout = 1;
            break;
        case '8':
            cout << "\n\t\t\tExiting ";
            loading();
            Logout = 1;
            exit = 1;
            break;
        default:
            invalid();
            getch();
            break;
        }
    }
}

void viewStudentProfile(int totalTeachers, int &feedbackIndex, int total, int x, int y, string teacherName[], string teacherID[], string teacherAge[], string teacherGender[],
                        string teacherContact[], string teacherAddress[], string name[], string id[], string adress[], string Section[], string contact[], string studentNames[],
                        string subjects[], int SubjectID[], int studentSubjects[], string studentIDs[], string feedbackArray[])
{
    header();
    setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "\n\n\t\t\t\t\t\t\t\t**********VIEW PROFILE**********";
    resetConsoleColor(); // Reset text color to default
    setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    string enteredID;
    cout << "\n\n\n\n\t\t\t\t\t\t Enter your ID to view your profile: ";
    getline(cin, enteredID);
    bool found = false;
    for (int i = 0; i < totalTeachers; i++)
    {
        if (enteredID == teacherID[i])
        {
            found = true;
            cout << "\n\n\t\t\t\t\t\t Profile for Teacher with ID " << enteredID << ":" << endl;
            cout << "\t\t\t\t\t\t Name:-> " << teacherName[i] << endl;
            cout << "\t\t\t\t\t\t ID:-> " << teacherID[i] << endl;
            cout << "\t\t\t\t\t\t Address:-> " << teacherAddress[i] << endl;
            cout << "\t\t\t\t\t\t Contact:-> " << teacherContact[i] << endl;
            cout << "\t\t\t\t\t\t Age:-> " << teacherAge[i] << endl;
            cout << "\t\t\t\t\t\t Gender:-> " << teacherGender[i] << endl;
            getch();
            return;
            break;
        }
    }

    if (!found)
    {
        cout << "\t\t\t\t\t\t No data found for the entered ID.(Ask Admin to Enter Your Data)" << endl;
        getch();
        return;
    }
}
void updateTeacherInformation(int &totalTeachers, int &feedbackIndex, int total, int x, int y, string teacherName[], string teacherID[], string teacherAge[], string teacherGender[],
                              string teacherContact[], string teacherAddress[], string name[], string id[], string adress[], string Section[], string contact[], string studentNames[],
                              string subjects[], int SubjectID[], int studentSubjects[], string studentIDs[], string feedbackArray[])
{
    header();
    setConsoleColor(14);
    cout << "\n\n\t\t\t\t\t\t\t\t\t********** UPDATE INFORMATION **********";
    resetConsoleColor(); // Reset text color to default

    string ID;
    setConsoleColor(3);
    cout << "\n\n\t\t\t\t\t\t Enter your ID to update profile: ";
    getline(cin, ID);

    int index = -1; // To store the index of the Teacher's record

    for (int i = 0; i < totalTeachers; i++)
    {
        if (ID == teacherID[i])
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        setConsoleColor(10);
        // Display the current profile information
        cout << "\n\t\t\t\t\t\t Current Profile Information:\n";
        cout << "\t\t\t\t\t\t Name: " << teacherName[index] << endl;
        cout << "\t\t\t\t\t\t ID: " << teacherID[index] << endl;
        cout << "\t\t\t\t\t\t Adress: " << teacherAddress[index] << endl;
        cout << "\t\t\t\t\t\t Contact: " << teacherContact[index] << endl;
        cout << "\t\t\t\t\t\t Age: " << teacherAge[index] << endl;
        cout << "\t\t\t\t\t\t Gender: " << teacherGender[index] << endl;
        // Allow the Teacher to update information
        cout << "\n\n\t\t\t\t\t\t Enter new information:\n";
        setConsoleColor(12);
        cout << "\t\t\t\t\t\t ID(Cannot be Changed): " << teacherID[index] << endl;
        setConsoleColor(11);
        cout << "\n\t\t\t\t\t\t Enter updated information for Teacher with ID " << teacherID[index] << ":\n";
        while (1)
        {
            cout << "\n\t\t\t\t\t\t Enter updated name: ";
            getline(cin, teacherName[index]);
            if (empty(teacherName[index]) == 1)
            {
                invalid();
            }
            else
            {
                break;
            }
        }
        while (1)
        {
            cout << "\n\t\t\t\t\t\t Enter the New Age : ";
            getline(cin, teacherAge[index]);
            if (empty(teacherAge[index]) == 1)
            {
                invalid();
            }
            else if (checkInt(teacherAge[index]) == 1)
            {
                setConsoleColor(12);
                cout << "\n\t\t\t\t\t\tinvalid Age format(Enter numbers only) :";
                resetConsoleColor();
            }
            else
            {
                break;
            }
        }
        while (1)
        {
            cout << "\n\t\t\t\t\t\t Enter the Gender(male/female): ";
            getline(cin, teacherGender[index]);
            if (empty(teacherGender[index]) == 1)
            {
                invalid();
            }
            else if (teacherGender[index] != "male" && teacherGender[index] != "female")
            {
                invalid();
            }

            else
                break;
        }
        while (1)
        {
            cout << "\n\t\t\t\t\t\t Enter the Contact: ";
            getline(cin, teacherContact[index]);
            if (empty(teacherContact[index]) == 1)
            {
                cout << "\n\t\t\t\t\t\tinvalid INPUT,Enter Again.";
            }
            else if (checkInt(teacherContact[index]) == 1)
            {
                setConsoleColor(12);
                cout << "\n\t\t\t\t\t\tinvalid Contact format(Enter numbers only) :";
                getch();
                resetConsoleColor();
            }
            else
            {
                break;
            }
        }
        while (1)
        {
            cout << "\n\t\t\t\t\t\t Enter the Address: ";
            getline(cin, teacherAddress[index]);
            if (empty(teacherAddress[index]) == 1)
            {
                invalid();
            }
            else
                break;
        }

        cout << "\n\t\t\t\t\t\t Profile updateding";
        loading();
        cout << "\n\n\t\t\t\t\t\t Profile updated successfully!\n";
        resetConsoleColor();
        getch();
        return;
    }
    else
    {
        setConsoleColor(12);
        cout << "\n\t\t\t\t\t\t Teacher with ID " << ID << " not found.\n";
        cout << "\n\t\t\t\t\t\tPress any key to go back";
        resetConsoleColor();
        getch();
        return;
    }
}

bool checkInt(string check)
{
    for (int q = 0; check[q] != '\0'; q++)
    {

        int b = check[q];
        if (b != 48 && b != 49 && b != 50 && b != 51 && b != 52 && b != 53 && b != 54 && b != 55 && b != 56 && b != 57)
        {

            return 1; // not a string
        }
    }
    return 0; // is a string
}
void manageAttendance(int &total, string name[], string id[], string adress[], string Section[], string contact[], string studentNames[], string studentIDs[], string attendanceStatus[])
{
    while (1)
    {
        header();
        setConsoleColor(14);
        cout << "\n\n\t\t\t\t\t\t\t\t ********** ATTENDANCE MANAGEMENT *********";
        setConsoleColor(10);
        cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t Press 1 to Mark Attendance.";
        cout << "\n\t\t\t\t\t\t\t\t\t Press 2 to View Attendance.";
        resetConsoleColor();
        char att = getch();
        switch (att)
        {
        case '1':
            markAttendance(total, name, id, adress, Section, contact, studentNames, studentIDs, attendanceStatus);
            break;
        case '2':
            viewAttendane(total, name, id, adress, Section, contact, studentNames, studentIDs, attendanceStatus);
            getch();
            break;
        default:
            break;
        }
        break;
    }
}
void markAttendance(int &total, string name[], string id[], string adress[], string Section[], string contact[], string studentNames[], string studentIDs[], string attendanceStatus[])
{
    header();
    cout << "\n\t\t\t\t\t\t\t\t ********** MARK ATTENDANCE **********";

    while (true)
    {
        if (total == 0)
        {
            cout << "\n\n\t\t\t\t\t NO STUDENTS AVAILABLE TO MARK ATTENDANCE." << endl;
            getch();
            return;
        }

        // Display the list of students
        setConsoleColor(10);
        cout << "\n\n\t\t\t\t\t\t\tNAME\t\t\t ID";
        resetConsoleColor();
        for (int i = 0; i < total; i++)
        {
            cout << "\n\n\t\t\t\t\t\t\t" << name[i] << "\t\t\t" << id[i];
        }
        setConsoleColor(11);
        string studentIDToMark;
        while (1)
        {
            cout << "\n\t\t\t\t\t\t\tEnter the student ID to mark attendance : ";
            getline(cin, studentIDToMark);
            if (empty(studentIDToMark) == 1)
                invalid();
            else
                break;
        }
        // Search for the entered student ID
        int studentIndex = -1;
        for (int i = 0; i < total; i++)
        {
            if (id[i] == studentIDToMark)
            {
                studentIndex = i;
                break;
            }
        }

        if (studentIndex != -1)
        {
            // Ask the user to input attendance (PRESENT or ABSENT)

            while (1)
            {
                cout << "\n\n\n\t\t\t\t\t\tEnter attendance status (PRESENT or ABSENT): ";
                getline(cin, attendanceStatus[studentIndex]);

                // Convert input to uppercase for case-insensitivity
                for (char &c : attendanceStatus[studentIndex])
                {
                    c = toupper(c);
                }

                if (attendanceStatus[studentIndex] == "PRESENT" || attendanceStatus[studentIndex] == "ABSENT")
                {
                    break;
                }
                else
                {
                    setConsoleColor(12);
                    cout << "\n\t\t\t\tinvalid input. Please enter either PRESENT or ABSENT.\n";
                    resetConsoleColor();
                }
            }

            // Update attendance status for the found student
            cout << "\n\t\t\t\t\t\tMarking attendance for " << name[studentIndex] << " (ID: " << id[studentIndex] << ") as " << attendanceStatus[studentIndex] << " ";
            loading();

            // Update status in the array
            studentNames[studentIndex] = attendanceStatus[studentIndex];

            // Get the current timestamp
            string timestamp = getCurrentTimestamp();
            cout << "\n\t\t\t\t\t\ttAttendance marked successfully at " << timestamp;
        }
        else
        {
            // Display a message if the entered student ID is not found
            setConsoleColor(12);
            cout << "\n\t\t\t\t\t\tStudent with ID " << studentIDToMark << " not found.";
            resetConsoleColor();
        }

        cout << "\n\n\t\t\t\t\t\t Press any key to go back to the menu. ";
        resetConsoleColor();
        getch();
        break; // Exit the loop after marking attendance for one student
    }
}
void viewAttendane(int &total, string name[], string id[], string adress[], string Section[], string contact[], string studentNames[], string studentIDs[], string attendanceStatus[])
{
    header();
    setConsoleColor(6);
    cout << "\n\t\t\t\t\t\t\t\t ********** VIEW ATTENDANCE **********";
    resetConsoleColor();
    while (true)
    {
        if (total == 0)
        {

            cout << "\n\n\t\t\t\t\t NO STUDENTS AVAILABLE TO VIEW ATTENDANCE." << endl;
            getch();
            return;
        }

        // Display the list of students with attendance status
        setConsoleColor(13);
        cout << "\n\n\t\t\t\t\t\t\tNAME\t\t\t ID \t\t\t ATTENDANCE";
        resetConsoleColor();
        for (int i = 0; i < total; i++)
        {
            cout << "\n\n\t\t\t\t\t\t\t" << name[i] << "\t\t\t" << id[i] << "\t\t\t";

            if (studentNames[i].empty())
            {
                setConsoleColor(12);
                cout << "Not Marked";
                resetConsoleColor();
            }
            else
            {
                cout << studentNames[i];
            }
        }
        resetConsoleColor();
        cout << "\n\n\t\t\t\t\t\tPress any key to go back to the menu. ";
        getch();
        break; // Exit the loop after displaying attendance
    }
}
void displayAttendanceToStudent(string &studentID, string &studentName, string &attendanceStatus)
{
    header();
    cout << "\n\t\t\t\t\t\t\t\t ********** ATTENDANCE DETAILS **********";

    // Display student information
    setConsoleColor(10);
    cout << "\n\n\t\t\t\t\t\tSTUDENT ID: " << studentID;
    cout << "\n\t\t\t\t\t\tSTUDENT NAME: " << studentName;
    resetConsoleColor();

    // Display attendance status
    cout << "\n\n\t\t\t\t\tATTENDANCE STATUS: ";
    if (!attendanceStatus.empty())
    {
        // Display attendance creatively
        cout << "\n\n\t\t\t\t\tYour attendance is " << attendanceStatus << "!";
    }
    else
    {
        setConsoleColor(12);
        cout << "\n\n\t\t\t\t\tAttendance not marked yet.";
        resetConsoleColor();
    }

    cout << "\n\n\t\t\t\t\tPress any key to go back to the menu. ";
    getch();
}

// Function to get the current timestamp as a string
string getCurrentTimestamp()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    // Format: "at HH:MM:SS on DD/MM/YYYY"
    char timestamp[30];
    strftime(timestamp, sizeof(timestamp), "at %H:%M:%S on %d/%m/%Y", ltm);

    return string(timestamp);
}

int findStudentIndex(string &studentID, string id[], int total)
{
    for (int i = 0; i < total; i++)
    {
        if (id[i] == studentID)
        {
            return i; // Return the index if the student ID is found
        }
    }
    return -1; // Return -1 if the student ID is not found
}
void displayAnnouncements(string senders[], string contents[], string timestamps[], int announcementCount)
{
    header();
    cout << "\n\n\t\t\t\t\t\t\t\t ********** ANNOUNCEMENTS **********\n\n";

    if (announcementCount == 0)
    {
        cout << "\n\t\t\t\t\t\t\t\t No announcements available.\n";
        getch();
        return;
    }
    setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "\n\t\t\t\t\t\t\t ADMIN";
    resetConsoleColor();

    for (int i = 0; i < announcementCount; ++i)
    {
        setConsoleColor(11);
        cout << "\n\t\t\t\t\t\t\t" << i + 1 << ":" << contents[i];
        resetConsoleColor();
        cout << "\n\t\t\t\t\t\t\t(" << timestamps[i] << ")\n\n";
    }
    getch();
}

void addAnnouncement(string senders[], string contents[], string timestamps[], int &announcementCount,
                     const string &adminName, const string &announcement)
{
    if (announcementCount < 100)
    {
        senders[announcementCount] = adminName;
        contents[announcementCount] = announcement;
        timestamps[announcementCount] = getCurrentTimestamp();
        ++announcementCount;
        // Displaying the timestamp when adding an announcement is optional.
        // You can choose to comment or remove the following line if you don't want it.
        cout << "\n\t\t\t\t\t\tAdding Announcement.";
        loading();
        cout << "\n\t\t\t\t\t\tAnnouncement added successfully at " << timestamps[announcementCount - 1] << "\n";
        getch();
    }
    else
    {
        setConsoleColor(12);
        cout << "\n\t\t\t\t\t\tAnnouncement limit reached. Cannot add more announcements.\n";
        resetConsoleColor();
        getch();
    }
}

void deleteAnnouncement(string senders[], string contents[], string timestamps[], int &announcementCount)
{
    if (announcementCount > 0)
    {
        // Display announcements for the admin to choose which one to delete
        displayAnnouncements(senders, contents, timestamps, announcementCount);

        string choice1;
        cout << "\n\t\t\t\t\t\tEnter the number of the announcement to delete (0 to cancel): ";
        getline(cin, choice1);
        if (checkInt(choice1) == 1 || empty(choice1) == 1)
        {
            invalid();
            return;
        }
        int choice = stoi(choice1);
        if (choice >= 1 && choice <= announcementCount)
        {
            // Shift the remaining announcements to overwrite the deleted one
            for (int i = choice - 1; i < announcementCount - 1; ++i)
            {
                senders[i] = senders[i + 1];
                contents[i] = contents[i + 1];
                timestamps[i] = timestamps[i + 1];
            }

            --announcementCount;
            cout << "\n\t\t\t\t\t\t Deleting Announcement ";
            loading();
        }
        else if (choice != 0)
        {
            invalid();
        }
    }
    else
    {
        setConsoleColor(12);
        cout << "\n\t\t\t\t\t\tNo announcements available to delete.\n";
        resetConsoleColor();
        getch();
    }
}

void announcementMenu(string senders[], string contents[], string timestamps[], int &announcementCount,
                      const string &adminName)
{
    while (true)
    {
        header();
        setConsoleColor(9);
        cout << "\n\n\t\t\t\t\t\t\t\t\t ********** ANNOUNCEMENT MENU **********\n";
        setConsoleColor(10);
        cout << "\n\n\n\t\t\t\t\t\t\t 1. View Announcements\n";
        cout << "\t\t\t\t\t\t\t 2. Add Announcement\n";
        cout << "\t\t\t\t\t\t\t 3. Delete Announcement\n";
        cout << "\t\t\t\t\t\t\t 4. Go Back\n";
        resetConsoleColor();

        int choice = getch();
        switch (choice)
        {
        case '1':
            displayAnnouncements(senders, contents, timestamps, announcementCount);
            break;
        case '2':
        {
            string announcement;
        while(1)
        {   
            cout << "\n\t\t\t\t\t\tEnter the announcement: ";
            getline(cin, announcement);
            if(empty(announcement)==1)
            {
               invalid(); 
               getch();
            }
            else
            addAnnouncement(senders, contents, timestamps, announcementCount, adminName, announcement);
            break;
        }
            break;
        }
        case '3':
            deleteAnnouncement(senders, contents, timestamps, announcementCount);
            break;
        case '4':
            return;
        default:
            invalid();
        }
    }
}

// Function for reading data from file in parallel arrays
void readDataForSignup(string username[], string role[], string password[], int &couunt)
{
    string record;
    fstream data;
    data.open("SignUp Credentials.txt", ios::in);

    while (getline(data, record))
    {
        if (count(record.begin(), record.end(), '|') != 2)
        {
            // Skip the line if it doesn't have exactly 2 lines
            continue;
        }
        // assgin the data according to their respective arrays
        username[couunt] = getField(record, 1);
        password[couunt] = getField(record, 2);
        role[couunt] = getField(record, 3);
        couunt++;
    }

    data.close();
}
string getField(string record, int field)
{
    int BarCount = 1;
    string item;
    for (int x = 0; x < record.length(); x++)
    {
        if (record[x] == '|')
        {
            BarCount = BarCount + 1;
        }
        else if (BarCount == field)
        {
            item = item + record[x];
        }
    }
    return item;
}
void updateDataForSigunp(string username[], string role[], string password[], int &couunt)
{
    fstream data;
    data.open("SignUp Credentials.txt", ios::out);

    if (!data)
    {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    for (int i = 0; i < couunt; ++i)
    {
        data << username[i] << "|" << password[i] << "|" << role[i] << "\n";
    }
    couunt++;
    data.close();
}

// Function for updating data in file from parallel arrays
void readStudentData(string name[], string id[], string adress[], string Section[], string contact[], int &total)
{
    string record;
    ifstream data;
    data.open("Student Data.txt", ios::in);
    total = 0;
    while (getline(data, record))
    {
        if (count(record.begin(), record.end(), '|') != 4)
        {
            // Skip the line if it doesn't have exactly 4 separators (adjust as needed)
            continue;
        }

        // Assign the data to their respective arrays
        name[total] = getField(record, 1);
        id[total] = getField(record, 2);
        adress[total] = getField(record, 3);
        Section[total] = getField(record, 4);
        contact[total] = getField(record, 5);

        total++;
    }

    data.close();
}

// Function to update student data in the file
void updateSignupData(string name[], string id[], string adress[], string Section[], string contact[], int total)
{
    ofstream data;
    data.open("Student Data.txt", ios::out);

    if (!data)
    {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    for (int i = 0; i < total; ++i)
    {
        // Assuming each student record is separated by a newline
        data << name[i] << "|" << id[i] << "|" << adress[i] << "|" << Section[i] << "|" << contact[i] << endl;
    }

    data.close();
}

void readTeacherData(string teacherName[], string teacherID[], string teacherAge[], string teacherGender[], string teacherContact[], string teacherAddress[], int &totalTeachers)
{
    string record;
    fstream data;
    data.open("Teachers Data.txt", ios::in);

    while (getline(data, record))
    {
        if (count(record.begin(), record.end(), '|') != 5)
        {
            // Skip the line if it doesn't have exactly 5 separators (adjust as needed)
            continue;
        }

        // Assign the data to their respective arrays
        teacherName[totalTeachers] = getField(record, 1);
        teacherID[totalTeachers] = getField(record, 2);
        teacherAge[totalTeachers] = getField(record, 3);
        teacherGender[totalTeachers] = getField(record, 4);
        teacherContact[totalTeachers] = getField(record, 5);
        teacherAddress[totalTeachers] = getField(record, 6);
        totalTeachers++;
    }

    data.close();
}

void updateTeacherData(string teacherName[], string teacherID[], string teacherAge[], string teacherGender[], string teacherContact[], string teacherAddress[], int &totalTeachers)
{
    ofstream data;
    data.open("Teachers Data.txt", ios::out);

    if (!data)
    {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    for (int i = 0; i < totalTeachers; ++i)
    {
        data << teacherName[i] << "|" << teacherID[i] << "|" << teacherAge[i] << "|"
             << teacherGender[i] << "|" << teacherContact[i] << "|" << teacherAddress[i] << "\n";
    }

    data.close();
}

void readFeedbackData(string feedbackArray[], string feedbackTimestamps[], int &feedbackIndex)
{
    string record;
    ifstream data;
    data.open("FeedbackData.txt", ios::in);

    while (getline(data, record))
    {
        if (count(record.begin(), record.end(), '|') != 1)
        {
            // Skip the line if it doesn't have exactly 1 separator (adjust as needed)
            continue;
        }

        // Assign the data to their respective arrays
        feedbackArray[feedbackIndex] = getField(record, 1);
        feedbackTimestamps[feedbackIndex++] = getField(record, 2);
    }

    data.close();
}

void updateFeedbackData(string feedbackArray[], string feedbackTimestamps[], int &feedbackIndex)
{
    ofstream data;
    data.open("FeedbackData.txt", ios::out);

    if (!data)
    {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    for (int i = 0; i < feedbackIndex; ++i)
    {
        // Assuming each feedback record is separated by a newline
        data << feedbackArray[i] << "|" << feedbackTimestamps[i] << "\n";
    }

    data.close();
}

void readAnnouncementData(string senders[], string contents[], string timestamps[], int &announcementCount)
{
    string record;
    ifstream data;
    data.open("AnnouncementsData.txt", ios::in);

    while (getline(data, record))
    {
        if (count(record.begin(), record.end(), '|') != 2)
        {
            // Skip the line if it doesn't have exactly 2 separators (adjust as needed)
            continue;
        }

        // Assign the data to their respective arrays
        senders[announcementCount] = getField(record, 1);
        contents[announcementCount] = getField(record, 2);
        timestamps[announcementCount] = getField(record, 3);
        ++announcementCount;
    }

    data.close();
}

void updateAnnouncementData(string senders[], string contents[], string timestamps[], int &announcementCount)
{
    ofstream data;
    data.open("AnnouncementsData.txt", ios::out);

    if (!data)
    {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    for (int i = 0; i < announcementCount; ++i)
    {
        // Assuming each announcement record is separated by a newline
        data << senders[i] << "|" << contents[i] << "|" << timestamps[i] << "\n";
    }

    data.close();
}

void readStudentData(string studentIDs[], string studentSubjects[], string studentNames[], int total)
{
    string record;
    ifstream data;
    data.open("StudentSubjectsData.txt", ios::in);

    while (getline(data, record))
    {
        if (count(record.begin(), record.end(), '|') != 2)
        {
            // Skip the line if it doesn't have exactly 3 separators (adjust as needed)
            continue;
        }

        // Assign the data to their respective arrays
        studentIDs[total] = getField(record, 1);
        studentNames[total] = getField(record, 3);

        // Convert the string to an integer only if it's a valid integer
        try
        {
            studentSubjects[total] = getField(record, 2);
        }
        catch (const invalid_argument &e)
        {
            cerr << "Error converting string to integer: " << e.what() << endl;
            // Handle the error or skip this record
            continue;
        }

        total++;
    }

    data.close();
}

// Function to update student subjects data in the file
void updateStudentData(string studentIDs[], string studentSubjects[], string studentNames[], int total)
{
    ofstream data;
    data.open("StudentSubjectsData.txt", ios::out);

    if (!data)
    {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    for (int i = 0; i < total; ++i)
    {
        // Assuming each student subjects record is separated by a newline
        data << studentIDs[i] << "|" << studentSubjects[i] << "|" << studentNames[i] << "\n";
    }

    data.close();
}
void readAttendanceData(string studentIDs[], string attendanceStatuses[], string timestamps[], int total)
{
    string record;
    ifstream data;
    data.open("AttendanceData.txt", ios::in);
    while (getline(data, record))
    {
        if (count(record.begin(), record.end(), '|') != 2)
        {
            // Skip the line if it doesn't have exactly 3 separators (adjust as needed)
            continue;
        }

        // Assign the data to their respective arrays
        studentIDs[total] = getField(record, 1);
        attendanceStatuses[total] = getField(record, 2);
        timestamps[total] = getField(record, 3);

        total++;
    }

    data.close();
}

// Function to update attendance data in the file
void updateAttendanceData(string studentIDs[], string attendanceStatuses[], string timestamps[], int total)
{
    ofstream data;
    data.open("AttendanceData.txt", ios::out);

    if (!data)
    {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    for (int i = 0; i < total; ++i)
    {
        // Assuming each attendance record is separated by a newline
        data << studentIDs[i] << "|" << attendanceStatuses[i] << "|" << timestamps[i] << "\n";
    }

    data.close();
}

void homeAnimation()
{
    system("cls");
    printColorText("\n\n\n\n\n\n\t\t\t\t\t                                               .@@@@@                                               ", 33); // Cyan (Building Base)
    cout << endl;
    printColorText("\t\t\t\t\t                                              @@   #@@=                                           ", 33); // Cyan (Building Base)
    cout << endl;
    printColorText("\t\t\t\t\t                                           :@@@.  :#   :@@@.                                        ", 33); // Cyan (Building Base)
    cout << endl;
    printColorText("\t\t\t\t\t                                         #@@+   #@@@@@=   #@@+                                      ", 33); // Cyan (Building Base)
    cout << endl;
    printColorText("\t\t\t\t\t                                      :@@@   :@@@.   -@@%.  -@@@.                                   ", 33); // Cyan (Building Base)
    cout << endl;
    printColorText("\t\t\t\t\t                                    %@@=   #@@=         #@@+   #@@+                                 ", 33); // Cyan (Building Base)
    cout << endl;
    printColorText("\t\t\t\t\t                                 :@@@   .@@@   %@@@@@@@*  :@@@   .@@@                               ", 33); // Cyan (Building Base)
    cout << endl;
    printColorText("\t\t\t\t\t                                =@*   *@@+   =@@   =  :@@    #@@=   @@:                             ", 33); // Cyan (Building Base)
    cout << endl;
    printColorText("\t\t\t\t\t                                :@@%@@@@    .@@   +@.   @@    :@@@@%@@.                             ", 33); // Cyan (Building Base)
    cout << endl;
    printColorText("\t\t\t\t\t                                  =%: @@    -@=   =@%   @@.   :@% -%:                               ", 33); // Cyan (Building Base)
    cout << endl;
    printColorText("\t\t\t\t\t                              :.      @@    .@@     *. .@@    :@@                                   ", 36); // Cyan (Building Base)
    cout << endl;
    printColorText("\t\t\t\t\t                            @@@@@@@@@@@@     :@@:     +@@     :@@@@@@@@@@@#                         ", 36); // Yellow (Windows)
    cout << endl;
    printColorText("\t\t\t\t\t                         :@@@         @@       =@@@@@@@:      :@%        .@@@.                      ", 36); // Yellow (Windows)
    cout << endl;
    printColorText("\t\t\t\t\t                       %@@=           @@                      :@%           @@                    ", 36); // Yellow (Windows)
    cout << endl;
    printColorText("\t\t\t\t\t                    -@@%              @@     -===========-    :@%              @@@                  ", 32); // Green (Roof)
    cout << endl;
    printColorText("\t\t\t\t\t                    @@@@@@@@@@@@@@@@@@@@   .@@@@@@@@@@@@@@@.  :@@@@@@@@@@@@@@@@@@@*                 ", 32); // Green (Roof)
    cout << endl;
    printColorText("\t\t\t\t\t                       %@.            @@   :@-    +@.    %@.  :@%            @                    ", 32); // Green (Roof)
    cout << endl;
    printColorText("\t\t\t\t\t                       #@             @@   :@-    +@.    %@.  :@%            +@+                    ", 32); // Green (Roof)
    cout << endl;
    printColorText("\t\t\t\t\t                       #@   @@@@@@@@  @@    @@@@@@@@@@@@@@@   :@% :@@@@@@@=  +@+                    ", 36); // Cyan (Building Base)
    cout << endl;
    printColorText("\t\t\t\t\t                            @@    *@- @@                      :@% *@-    @@  +@+                    ", 36); // Cyan (Building Base)
    cout << endl;
    printColorText("\t\t\t\t\t                        .   @@    *@- @@                      :@% *@-    @@  +@+                    ", 36); // Cyan (Building Base)
    cout << endl;
    printColorText("\t\t\t\t\t                       #@   =@@@@@@%  @@                      :@%  @@@@@@@   +@+                    ", 36); // Cyan (Building Base)
    cout << endl;
    printColorText("\t\t\t\t\t                       #@             @@    *@@@#######@@@+   :@%            +@+                    ", 36); // Cyan (Building Base)
    cout << endl;
    printColorText("\t\t\t\t\t                       #@    +####*   @@     %@-       +@-    :@%  :#####-   +@+                    ", 36); // Cyan (Building Base)
    cout << endl;
    printColorText("\t\t\t\t\t                       #@   @@@%%%@@: @@     %@-       +@-    :@% +@@%%%@@@  :@:                    ", 36); // Cyan (Building Base)
    cout << endl;
    printColorText("\t\t\t\t\t                       #@   @@    *@- @@     %@-       +@-    :@% *@-    @@  #@                   ", 36); // Cyan (Building Base)
    cout << endl;
    printColorText("\t\t\t\t\t                       #@   @@@@@@@@. @@     %@-       +@-    :@% +@@@@@@@%  =@-                   ", 36); // Cyan (Building Base)
    cout << endl;
    printColorText("\t\t\t\t\t                       #@             @@     %@-       +@-    :@%            +@+                   ", 36); // Cyan (Building Base)
    cout << endl;
    printColorText("\t\t\t\t\t                      .@@=:::::::::::-@@=::::@@*:::::::%@#::::*@@::::::::::::%@%                   ", 36); // Cyan (Building Base)
    cout << endl;
    printColorText("\t\t\t\t\t                    +@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.                    ", 33); // Cyan (Building Base)
    cout << endl;
    printColorText("\t\t\t\t\t                    @@                        EDU CENTRAL                   =@%                   ", 33); // Green (Roof)
    cout << endl;
    printColorText("\t\t\t\t\t                     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#                     ", 33); // Green (Roof)
    cout << endl;
    cout << "\n\t\t\t\t\t\t\tLoading ";
    loading();
}
void welcomeAnimation()

{
    system("cls");
    // First Line
    printColorText("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t @@@   @@@    @@@  @@@@@@@@@   @@@         @@@@@       @@@@@@      @@@    @@@     @@@@@@@@\n", 31);

    // Second Line
    printColorText("\t\t\t\t\t @@@@  @@@@  @@@@  @@@@       @@@@@      @@@@@@@@   @@@@@@@@@@@   @@@@@  @@@@@    @@@@     \n", 32);

    // Third Line
    printColorText("\t\t\t\t\t  @@@  @@@@  @@@@  @@@@       @@@@@      @@@@      @@@@@   @@@@@  @@@@@  @@ @@@   @@@@    \n", 33);

    // Fourth Line
    printColorText("\t\t\t\t\t  @@@  @@@@  @@@   @@@@@@@@   @@@@@     @@@@       @@@@     @@@@  @@@ @@@@@ @@@   @@@@@@@@\n", 34);

    // Fifth Line
    printColorText("\t\t\t\t\t  @@@ @@ @@  @@    @@@@       @@@@@     @@@@@      @@@@@   @@@@@  @@@ @@@@@ @@@   @@@@    \n", 35);

    // Sixth Line
    printColorText("\t\t\t\t\t   @@@@@ @@@@@     @@@@       @@@@@@@@   @@@@@@@@   @@@@@@@@@@@   @@@  @@@@ @@@   @@@@    \n", 36);

    // Seventh Line
    printColorText("\t\t\t\t\t    @@@   @@@@     @@@@@@@@@   @@@@@@@@@   @@@@@@     @@@@@@@      @@   @@   @@   @@@@@@@@\n", 37);

    cout << endl;
    printColorText("\n\n\t\t\t\t\t\t\t PLEASE PRESS ANY KEY TO CONTINUE !\n", 33);
    getch();
}

void Sider()
{
    gotoxy(3, 13);
    cout << "\033[1;34m";
    cout << "\t  _______ \n";
    cout << "\t /       |\n";
    cout << "\t|  ,----'\n";
    cout << "\t|  |     \n";
    cout << "\t|  `----.\n";
    cout << "\t\\_______|\n\n";
    cout << "\033[0m";

    cout << "\033[1;35m";
    cout << "\n\t.___   ___.\n";
    cout << "\t|   \\/   |\n";
    cout << "\t|  \\  /  |\n";
    cout << "\t|  |\\/|  |\n";
    cout << "\t|  |  |  |\n";
    cout << "\t|__|  |__|\n\n";
    cout << "\033[0m";

    cout << "\033[1;31m";
    cout << "\n\t     ________\n";
    cout << "\t    /       |\n";
    cout << "\t   |   (----`\n";
    cout << "\t    \\   \\  \n";
    cout << "\t.----)   |   \n";
    cout << "\t|_______/    \n";
    cout << "\033[0m";
    int x = 170, y = 13;
    gotoxy(x, y);
    cout << "\033[1;34m";
    cout << "\t  _______ ";
    gotoxy(x, y + 1);
    cout << "\t /       |";
    gotoxy(x, y + 2);
    cout << "\t|  ,----'";
    gotoxy(x, y + 3);
    cout << "\t|  |     ";
    gotoxy(x, y + 4);
    cout << "\t|  `----.";
    gotoxy(x, y + 5);
    cout << "\t \\_______|";
    gotoxy(x, y + 6);
    cout << "\033[0m";

    gotoxy(x, y + 8);
    cout << "\033[1;35m";
    cout << "\t.___   ___.";
    gotoxy(x, y + 9);
    cout << "\t|   \\/   |";
    gotoxy(x, y + 10);
    cout << "\t|  \\  /  |";
    gotoxy(x, y + 11);
    cout << "\t|  |\\/|  |";
    gotoxy(x, y + 12);
    cout << "\t|  |  |  |";
    gotoxy(x, y + 13);
    cout << "\t|__|  |__|";
    cout << "\033[0m";

    gotoxy(x, y + 15);
    cout << "\033[1;31m";
    gotoxy(x, y + 16);
    cout << "\t     ________";
    gotoxy(x, y + 17);
    cout << "\t    /       |";
    gotoxy(x, y + 18);
    cout << "\t   |   (----`";
    gotoxy(x, y + 19);
    cout << "\t    \\   \\  ";
    gotoxy(x, y + 20);
    cout << "\t.----)   |   ";
    gotoxy(x, y + 21);
    cout << "\t|_______/    ";

    gotoxy(1, 1);
}
void signUpBox()
{
    cout << "\033[1;32m"; // Yellow color

    cout << "\t\t\t\t\t\t\t\t\t\t    ____ ___ ____ _   _ _   _ ____     \n";
    cout << "\t\t\t\t\t\t\t\t\t\t   / ___|_ _/ ___| \\ | | | | |  _ \\    \n";
    cout << "\t\t\t\t\t\t\t\t\t\t   \\___ \\| | |  _|  \\| | | | | |_)    \n";
    cout << "\t\t\t\t\t\t\t\t\t\t    ___) | | |_| | |\\  | |_| |  __/    \n";
    cout << "\t\t\t\t\t\t\t\t\t\t   |____/___\\____|_| \\_|\\___/|_|       \n";
    cout << "\033[0m"; // Reset color
}
void loginBox()
{
    cout << "\033[1;32m"; // Yellow color

    cout << "\t\t\t\t\t\t\t\t\t\t    _     ___   ____ ___ _   _  \n";
    cout << "\t\t\t\t\t\t\t\t\t\t   | |   / _ \\ / ___|_ _| \\ | |   \n";
    cout << "\t\t\t\t\t\t\t\t\t\t   | |  | | | | |  _ | ||  \\| |   \n";
    cout << "\t\t\t\t\t\t\t\t\t\t   | |__| |_| | |_| || || |\\  |  \n";
    cout << "\t\t\t\t\t\t\t\t\t\t   |_____\\___/ \\____|___|_| \\_|    \n";
    cout << "\033[0m"; // Reset color
}
void invalid()
{
    setConsoleColor(12);
    cout << "\n\n\t\t\t\t\t\t\t\t invalid Input.\n";
    resetConsoleColor();
}
void welcomeAdmin()
{
    cout << "\033[1;32m"; // Yellow color
    cout << "\n\t\t\t\t\t\t\t\t        ___       _______  .___  ___.  __  .__   __.                         \n";
    cout << "\t\t\t\t\t\t\t\t       /   \\     |       \\ |   \\/   | |  | |  \\ |  |                         \n";
    cout << "\t\t\t\t\t\t\t\t      /  ^  \\    |  .--.  ||  \\  /  | |  | |   \\|  |                         \n";
    cout << "\t\t\t\t\t\t\t\t     /  /_\\  \\   |  |  |  ||  |\\/|  | |  | |  . `  |                         \n";
    cout << "\t\t\t\t\t\t\t\t    /  _____  \\  |  '--'  ||  |  |  | |  | |  |\\   |                         \n";
    cout << "\t\t\t\t\t\t\t\t   /__/     \\__\\ |_______/ |__|  |__| |__| |__| \\__|                         \n";
    cout << "\033[0m"; // Reset color
}
void teacherBox()
{
    setConsoleColor(10);
    cout << "\n\n\t\t\t\t\t\t\t.___________. _______     ___       ______  __    __   _______ .______      \n";
    cout << "\t\t\t\t\t\t\t|           ||   ____|   /   \\     /      ||  |  |  | |   ____||   _  \\     \n";
    cout << "\t\t\t\t\t\t\t`---|  |----`|  |__     /  ^  \\   |  ,----'|  |__|  | |  |__   |  |_)  |    \n";
    cout << "\t\t\t\t\t\t\t    |  |     |   __|   /  /_\\  \\  |  |     |   __   | |   __|  |      /     \n";
    cout << "\t\t\t\t\t\t\t    |  |     |  |____ /  _____  \\ |  `----.|  |  |  | |  |____ |  |\\  \\----.\n";
    cout << "\t\t\t\t\t\t\t    |__|     |_______/__/     \\__\\ \\______||__|  |__| |_______|| _| `._____|\n";
    resetConsoleColor();
}
void studentBox()
{
    setConsoleColor(10);
    cout << "\n\n\t\t\t\t\t\t\t     _______.___________. __    __   _______   _______ .__   __. .___________.\n";
    cout << "\t\t\t\t\t\t\t    /       |           ||  |  |  | |       \\ |   ____||  \\ |  | |           |\n";
    cout << "\t\t\t\t\t\t\t   |   (----`---|  |----`|  |  |  | |  .--.  ||  |__   |   \\|  | `---|  |----`\n";
    cout << "\t\t\t\t\t\t\t    \\   \\       |  |     |  |  |  | |  |  |  ||   __|  |  . `  |     |  |     \n";
    cout << "\t\t\t\t\t\t\t.----)   |      |  |     |  `--'  | |  '--'  ||  |____ |  |\\   |     |  |     \n";
    cout << "\t\t\t\t\t\t\t|_______/       |__|      \\______/  |_______/ |_______||__| \\__|     |__|     \n";
    resetConsoleColor();
}