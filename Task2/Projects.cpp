#include <iostream>
#include <iostream>
#include <vector>
#include <memory>
#include "ProjectsClass.h"
// #include "SupervisorClass.h"


Projects::Projects() {
  projects_ = {};
}

Projects::Projects(vector<shared_ptr<Project>> p) {
  projects_ = p;
}

Projects::~Projects() {
	projects_ = {};
}

vector<shared_ptr<Project>> Projects::getProjects() {
  return projects_;
}

map<string, shared_ptr<Project>> Projects::getPointerProjectsMap() {
  return pointerProjectsMap_;
}

void Projects::ReadProjectFile(string filename, Supervisors supervisors) {
  const char DELIMITER = ' ';
  string id = "";
  string supervisorId = "";
  int multiplicity = -1;
  string title = "";
  ifstream in(filename);
  // create a list of Project pointers to use for student object.
  while (in) {
    // Read the next data set
    string line = "";
    getline(in, id, DELIMITER);
    in >> supervisorId;
    in >> multiplicity;
    in >> title;
    // check if at last entry of file
    if (!id.empty()) {
      Project project;
      project.setId(id);
      project.setSupervisorId(supervisorId);
      // Get supervisor pointer from map.
      project.setSupervisor(supervisors.getSupervisorMap().at(supervisorId));
      project.setMultiplicity(multiplicity);
      project.setTitle(title);
      in.ignore(INT16_MAX, '\n');
      shared_ptr<Project> projectPointer = make_shared<Project>(project);
      // Add project pointer to a map for the Student object.
      pointerProjectsMap_[id] = projectPointer;
      projects_.push_back(projectPointer);
    }
  }
}

void Projects::printAll() {
  for (int i = 0; i < projects_.size(); i++) {
    cout << "ID: " << projects_[i]->getId() << " Supervisor ID: " << projects_[i]->getSupervisorId() << " Multiplicity: " << projects_[i]->getMultiplicity() << " Title: " << projects_[i]->getTitle() << endl;
  }
}
