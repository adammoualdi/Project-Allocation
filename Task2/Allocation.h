#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include "StudentClass.h"
#include "ProjectsClass.h"
#include "SupervisorClass.h"
using namespace std;

class Allocation {
public:

	Allocation();

	Allocation(Students students, Supervisors supervisors, Projects projects);

	~Allocation();

  void allocate();

private:
  Students students_;
  Supervisors supervisors_;
  Projects  projects_;
};
