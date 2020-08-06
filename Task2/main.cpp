#include <iostream>
#include <memory>
#include "SupervisorClass.h"
#include "ProjectsClass.h"
#include "StudentClass.h"
#include "Allocation.h"

int main(int argc, char** argv) {
  const string staffTxt = argv[1];
  const string projectTxt = argv[2];
  const string studentTxt = argv[3];

  Supervisors ss;
  vector<shared_ptr<Supervisor>> supervisors;
  supervisors = ss.ReadSupervisorFile(staffTxt);

  cout << "PRINT ALL SUPERVISORS" << endl;
  ss.printAll();

  cout << "PROJECTS" << endl;
  Projects projects;
  projects.ReadProjectFile(projectTxt, ss);

  cout << "PRINT ALL PROJECTS" << endl;
  projects.printAll();

  cout << "STUDENTS" << endl;
  Students students;
  students.ReadStudentFile(studentTxt, projects);

  cout << "PRINT ALL STUDENTS" << endl;
  students.printAll();

  Allocation allocation(students, ss, projects);
  allocation.allocate();

}
