//Elliot Huh
//CS-300
//Module 7
//Course.txt lines 9 and 10 are testers not actual courses.

#include <iostream>
#include <fstream> //for files
#include <algorithm> //for sort
#include <sstream> //for parameters
#include <vector> //for data structure
using namespace std;

//Structure for course object 
struct Course {
  string courseNumber;
  string courseName;
  string prerequisite;
};

//initialize the course vector
vector<Course> courses;


//load courses from file onto course vector function
void loadCourses() {
  //Open the file
  int Count = 0;
  ifstream file("Course.txt");
  string line;
  //Read each line of the file
  while (getline(file, line)) {
    //additional vector to validate parameters
    vector<string> parameters;
    string param;
    stringstream ss(line);
    //split the line by commas
    while (getline(ss, param, ',')) {
      //add line into parameter vector
      parameters.push_back(param);
    }
    //if there is less than two parameters, skip the line
    if (parameters.size() < 2) {
      //let user know which line is invalid
      cout << "\n\n";
      cout << "The following lines were not added" << endl;
      cout << "Failed: " << line << endl;
      continue;
    }
    //create a new course object
    Course newCourse;
    Count++;
    newCourse.courseNumber = parameters[0];
    newCourse.courseName = parameters[1];
    //if there is more than two parameters, set the prerequisite
    if (parameters.size() > 2) {
      newCourse.prerequisite = "";
      //each parameter after the second is a prerequisite
      for (int i = 2; i < parameters.size(); i++) {
        newCourse.prerequisite += parameters[i] + " ";
      }
    }
    //add the new course to the course vector
    courses.push_back(newCourse);
  }
  //Done and close file
  file.close();
  //Notify user of how many courses were added
  cout << "" << endl;
  cout << Count << " Courses successfully loaded" << endl;
  cout << "******************************\n\n\n\n" << endl;
  //return to the menu
  cout << "Welcome back to the menu" << endl;
}


//Print out sample schedule function
void printCourses() {
  //Sort all courses in alphanumeric order 
  sort(courses.begin(), courses.end(), [](const Course& smaller, const Course& bigger) {
    return smaller.courseNumber < bigger.courseNumber;
  });

  cout << "\n\n";
  cout << "********************************" << endl;
  cout << "Here is your sample schedule:\n " << endl;
  for (Course course : courses) {
    //print out course number with their course name
    cout << course.courseNumber << ", " << course.courseName << endl;
    }
  cout << "********************************\n\n\n\n" << endl;
  //return to the menu
  cout << "Welcome back to the menu" << endl;
}


//Search for course and print out specific course info function
void searchCourse() {
  string courseInput;
  //Ask user for course number
  cout << "\n\n";
  cout << "What course do you want to know about: ";
  cin >> courseInput;
  cout << "" << endl;
  //loop until user quits or course is found
  bool found = true;
  while (found == true) {
  //loop to see if course exists in course vector
    for (Course course : courses) {
      //if the course is found, print out the course info
      if (course.courseNumber == courseInput) {
        cout << "Course found: ";
        cout << course.courseNumber << ", " << course.courseName << endl;
        //if course has prerequisite, print them alongside the other info
        if (!course.prerequisite.empty()) {
          cout << "Prerequisite: " << course.prerequisite << endl;
        }
        //return to the menu
        cout << "******************************\n\n\n\n" << endl;
        cout << "Welcome back to the menu" << endl;
        return;
        }
    }
    //if course is not found, ask user to try again
    cout << "Course not found." << endl;
    cout << "Enter 1 to return to the menu" << endl;
    cout << "or enter course number again " << endl;
    cout << "What would you like to do: ";
    cin >> courseInput;
    cout << "" << endl;
    //if user enters 1, return to the menu
    if (courseInput == "1") {
      cout << "******************************\n\n\n" << endl;
      cout << "Welcome back to the menu" << endl;
      found = false;
    }
  }
}


//The menu function
int main() {
  string userInput;
  bool menu = true;
  cout << "Welcome to Course Planner " << endl;
  //loop to diplay menu
  while (menu == true) {
    cout << "_________________________________" << endl;
    cout << "1. Load Data Structure." << endl;
    cout << "2. Print Courses List." << endl;
    cout << "3. Search Course." << endl;
    cout << "9. Exit." << endl;
    cout << "_________________________________\n\n" << endl;
    cout << "What would you like to do: ";
    //users input
    cin >> userInput;

    //if user chooses 1, call to loadCourse funtion
    if (userInput == "1") {
      loadCourses();
    }

    //if user chooses 2, call to printCourse function
    if (userInput == "2") {
      printCourses();
    }

    //if user chooses 3, call to searchCourse function
    if (userInput == "3") {
      searchCourse();
    }

    //if user chooses 9, End the loop and notify user
    if (userInput == "9") {
      cout << "" << endl;
      cout << "Thank you for using the Course Planner";
      menu = false;
    }

    //if the input is invalid, notify user, continue the loop
    if (userInput != "1" && userInput != "2" && userInput != "3" && userInput != "9") {
      cout << " " << endl;
      cout << userInput << " is not a valid option\n\n" << endl;
  }
  }
  return 0;
}