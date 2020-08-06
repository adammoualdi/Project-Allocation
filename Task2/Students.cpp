#include <iostream>
#include <iostream>
#include <vector>
#include <set>
#include <memory>
#include "StudentClass.h"

Students::Students() {
  students_ = {};
}

Students::Students(vector<Student> students) {
  students_ = students;
}

Students::~Students() {
	students_ = {};
}

void Students::ReadStudentFile(string filename, Projects projectsInfo) {
  const char DELIMITER = ' ';
  string id = "";
  string projectId = "";
  ifstream in(filename);
  while (in) {
    // Read the next data set
    getline(in, id, DELIMITER);
    if(in.eof()) {
      break;
    }
    Student s;
    vector<shared_ptr<Project>> projectTmp;
    for (int i = 0; i < 4; i++) {
      in >> projectId;
      string project = projectId;
      // get project pointer from map
      shared_ptr<Project> projectPtr = projectsInfo.getPointerProjectsMap().at(project);
      projectTmp.push_back(projectPtr);
    }
    // check if at last entry of file
    if (!id.empty()) {
      // each Student has a list of 4 projects in preferred order.
      vector<string> projects;
      s.setId(id);
      s.setProjects(projectTmp);
      in.ignore(INT16_MAX, '\n');
      students_.push_back(s);
    }
  }
}

vector<Student> Students::getStudents() {
  return students_;
}

void Students::print() {
  for (int i = 0; i < students_.size(); i++) {
    cout << "ID: " << students_[i].getId() << " ProjectIds:" << endl;
    for (int k = 0; k < students_[i].getProjectsIds().size(); k++) {
      cout << students_[i].getProjectsIds()[k];
    }
  }
  cout << endl;
}

void Students::printAll() {
  for (int i = 0; i < students_.size(); i++) {
    cout << "ID: " << students_[i].getId() << endl;
    cout << "Projects: " << endl;
    for (int k = 0; k < students_[i].getProjects().size(); k++) {
      cout << students_[i].getProjects()[k]->getId() << " ";
      cout << students_[i].getProjects()[k]->getSupervisorId() << " ";
      cout << students_[i].getProjects()[k]->getMultiplicity() << " ";
      cout << students_[i].getProjects()[k]->getTitle() << " " << endl;
    }
    cout << endl;
  }
}

void Students::printProjectIds() {
  for (int i = 0; i < students_.size(); i++) {
    cout << "ID: " << students_[i].getId() << " Projects: ";
    for (int k = 0; k < students_[i].getProjectsIds().size(); k++) {
      cout << students_[i].getProjectsIds()[k] << " ";
    }
    cout << endl;
  }
}
