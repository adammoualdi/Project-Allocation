#ifndef __PROJECTSCLASS_H_
#define __PROJECTSCLASS_H_

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <map>
#include "SupervisorClass.h"
using namespace std;

class Project {
public:

	Project() {
    multiplicity_ = 0;
		multiplicityCounter_ = 0;
	}

	Project(const string& id, const string& sId, const int& multiplicity, const string& title) {
		id_ = id;
    supervisorId_ = sId;
    multiplicity_ = multiplicity;
		multiplicityCounter_ = multiplicity_;
    title_ = title;
	}

	Project(const string& id, const string& sId, const shared_ptr<Supervisor> supervisor, const int& multiplicity, const string& title) {
		id_ = id;
    supervisorId_ = sId;
		supervisor_ = supervisor;
    multiplicity_ = multiplicity;
		multiplicityCounter_ = multiplicity_;
    title_ = title;
	}

	// destructor
	~Project() {
    multiplicity_ = 0;
		multiplicityCounter_ = 0;
	}

	void setId(string id) {
		id_ = id;
	}

	string getId() {
		return id_;
	}

  void setSupervisorId(string id) {
    supervisorId_ = id;
  }

  string getSupervisorId() {
    return supervisorId_;
  }

	void setSupervisor(shared_ptr<Supervisor> supervisor) {
		supervisor_ = supervisor;
	}

	shared_ptr<Supervisor> getSupervisor() {
		return supervisor_;
	}

  void setMultiplicity(int multiplicity) {
    multiplicity_ = multiplicity;
		multiplicityCounter_ = multiplicity_;
  }

  int getMultiplicity() {
    return multiplicity_;
  }

	void setMultiplicityCounter(int counter) {
		multiplicityCounter_ = counter;
	}

	int getMultiplicityCounter() {
		return multiplicityCounter_;
	}

  void setTitle(string title) {
    title_ = title;
  }

  string getTitle() {
    return title_;
  }

	void print() {
		cout << "ID: " << getId() << " Supervisor ID: " << getSupervisorId() << " Multiplicity: " << getMultiplicity() << " Title " << getTitle() << endl;
	}

private:
	string id_;
	string supervisorId_;
	shared_ptr<Supervisor> supervisor_;
  int multiplicity_;
  string title_;
	bool full_;
	int multiplicityCounter_;

};

class Projects {
public:

	Projects();

  Projects(vector<shared_ptr<Project>> p);

	// destructor
	~Projects();

	vector<shared_ptr<Project>> getProjects();

	map<string, shared_ptr<Project>> getPointerProjectsMap();

	void ReadProjectFile(string filename, Supervisors supervisors);

	// vector<shared_ptr<Project>>
	void addSupervisor(Supervisors ss);

	void printAll();

private:
  vector<shared_ptr<Project>> projects_;
	map<string, shared_ptr<Project>> pointerProjectsMap_;
};

#endif
