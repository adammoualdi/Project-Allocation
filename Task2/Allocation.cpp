#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include "Allocation.h"
using namespace std;


Allocation::Allocation() {

}

Allocation::Allocation(Students students, Supervisors supervisors, Projects projects) {
  students_ = students;
  supervisors_ = supervisors;
  projects_ = projects;
}

Allocation::~Allocation() {
  // Object destructors are called
}

void Allocation::allocate() {
  ofstream file;
  file.open ("alloc.txt");
  int score = 0;
  // Loop through all students.
  for (int i = 0; i < students_.getStudents().size(); i++) {
    bool found = false;
    // for students chosen projects.
    for (int n = 0; n < 4; n++) {
      // Starts at first project.
      if (students_.getStudents()[i].getProjects()[n]->getMultiplicityCounter() != 0) {
        if (students_.getStudents()[i].getProjects()[n]->getSupervisor()->getLoadCounter() != 0) {
          found = true;
          // Take away 1 from specific supervisor load counter.
          students_.getStudents()[i].getProjects()[n]->getSupervisor()->setLoadCounter(students_.getStudents()[i].getProjects()[n]->getSupervisor()->getLoadCounter() - 1);
          // Take away 1 from specific project multiplicity counter.
          students_.getStudents()[i].getProjects()[n]->setMultiplicityCounter(students_.getStudents()[i].getProjects()[n]->getMultiplicityCounter() - 1);
          score = score + 4-n;
          file << students_.getStudents()[i].getId() << " " << students_.getStudents()[i].getProjects()[n]->getId() << endl;
          break;
        }
      }
    }
    // if allocation not found for that student, return 0.
    if (found == false) {
      file << students_.getStudents()[i].getId() << " 0 " << endl;
    }
  }
  file << score << endl;
}
