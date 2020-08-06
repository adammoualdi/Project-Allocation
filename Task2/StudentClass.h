#ifndef __STUDENTCLASS_H_
#define __STUDENTCLASS_H_

#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <memory>
#include <fstream>
#include "ProjectsClass.h"
using namespace std;

class Student {
public:

  Student() {
    id_ = "";
    projects_ = {};
    projectsIds_.clear();
  }

  Student(string id, vector<shared_ptr<Project>> projects, vector<string> projectsInt) {
    id_ = id;
    projects_ = projects;
    projectsIds_ = projectsInt;
  }

  ~Student() {
    projects_ =  {};
    projectsIds_.clear();
  }

  string getId() {
    return id_;
  }

  void setId(string id) {
    id_ = id;
  }

  vector<shared_ptr<Project>> getProjects() {
    return projects_;
  }

  void setProjects(vector<shared_ptr<Project>> projects) {
    projects_ = projects;
  }

  vector<string> getProjectsIds() {
    return projectsIds_;
  }

  void setProjectsIds(vector<string> projectsInt) {
    projectsIds_ = projectsInt;
  }

private:
	string id_;
  vector<shared_ptr<Project>> projects_;
  vector<string> projectsIds_;

};

class Students {
public:

	Students();

  Students(vector<Student> students);

	~Students();

	void ReadStudentFile(string filename, Projects projectsInfo);

	Student addProjects(Projects projects, Student student);

  vector<Student> getStudents();

  void printProjectIds();

  void print();

	void printAll();

private:
  vector<Student> students_;
  // friend class Allocation;
};

#endif
