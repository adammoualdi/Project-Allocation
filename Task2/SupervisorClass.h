#ifndef __SUPERVISORCLASS_H_
#define __SUPERVISORCLASS_H_

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <map>
using namespace std;

class Supervisor {
public:

	Supervisor() {
		load_ = 0;
		loadCounter_ = 0;
	}

	Supervisor(const string& id, const int& load) {
		id_ = id;
		load_ = load;
		loadCounter_ = load_;
	}

	~Supervisor() {
		load_ = 0;
		loadCounter_ = 0;
	}

	void setId(string id) {
		id_ = id;
	}

	string getId() {
		return id_;
	}

	void setLoad(int load) {
		load_ = load;
		loadCounter_ = load_;
	}

	int getLoad() {
		return load_;
	}

	void setLoadCounter(int counter) {
		loadCounter_ = counter;
	}

	int getLoadCounter() {
		return loadCounter_;
	}

	void print() {
		cout << "ID: " << getId() << " load: " << getLoad() << endl;
	}

private:
	string id_;
	int load_;
	int loadCounter_;
};

class Supervisors {
public:

	Supervisors();

	Supervisors(vector<shared_ptr<Supervisor>>);

	~Supervisors();

	vector<shared_ptr<Supervisor>> ReadSupervisorFile(string filename);

	vector<shared_ptr<Supervisor>> getSupervisors();

	map<string, shared_ptr<Supervisor>> getSupervisorMap();

	void setSupervisorMap(map<string, shared_ptr<Supervisor>>);

	void print();

	void printAll();

private:
  vector<shared_ptr<Supervisor>> supervisors_;
	map<string, shared_ptr<Supervisor>> pointerSupervisorMap_;
};

#endif
