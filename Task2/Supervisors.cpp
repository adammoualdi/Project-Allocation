#include <iostream>
#include <iostream>
#include <vector>
#include <memory>
#include "SupervisorClass.h"


Supervisors::Supervisors() {
  supervisors_ = {};
}

Supervisors::Supervisors(vector<shared_ptr<Supervisor>> s) {
  supervisors_ = s;
}

Supervisors::~Supervisors() {
	supervisors_ = {};
}

vector<shared_ptr<Supervisor>> Supervisors::ReadSupervisorFile(string filename) {
  const char DELIMITER = ' ';
  string id = "";
  int load = -1;
  ifstream in(filename);
  Supervisors ss;
  while (in) {
    // Read the next data set
    getline(in, id, DELIMITER);
    in >> load;
    // check if at last entry of file
    if (!id.empty()) {
      Supervisor supervisor;
      in.ignore(INT16_MAX, '\n');
      supervisor.setId(id);
      supervisor.setLoad(load);
      // make shared pointer for projects object
      shared_ptr<Supervisor> supervisorPointer = make_shared<Supervisor>(supervisor);
      // map can be used to map supervisors to projects
      pointerSupervisorMap_[id] = supervisorPointer;
      supervisors_.push_back(supervisorPointer);
    }
  }
  return supervisors_;
}

vector<shared_ptr<Supervisor>> Supervisors::getSupervisors() {
  return supervisors_;
}

map<string, shared_ptr<Supervisor>> Supervisors::getSupervisorMap() {
  return pointerSupervisorMap_;
}

void Supervisors::setSupervisorMap(map<string, shared_ptr<Supervisor>> supervisorMap) {
  pointerSupervisorMap_ = supervisorMap;
}


void Supervisors::printAll() {
  for (int i = 0; i < supervisors_.size(); i++) {
    cout << "ID: " << supervisors_[i]->getId() << " load: " << supervisors_[i]->getLoad() << endl;
  }
}
