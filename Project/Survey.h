#pragma once
#include "Inheritance.h"

class Survey
{
private:
	int size;
	Person** stuList;
	int numGamStu;
	int numNonGameStu;

	std::string mostUseStreamServ;
	std::string mostUseGamingDev;

	double avgHoursNGS = 0;
	double avgHoursGS = 0;

public:
	// why fill the list?
	Survey(int amountStudents, Person* students[])
	{
		setSize(amountStudents);
		setStuList(students);
		setNumGamStu();
		setNonNumGamStu();

		fillList();
	}
	~Survey() = default;
	
	int getRandNum(int max, int min = 0) { return rand() % max + min; }
	void setSize(int size);
	int getSize() const;
	void setStuList(Person** list);
	Person** getStuList() const;
	void setNumGamStu();
	int getNumGamStu() const;
	void setNonNumGamStu();
	int getNonNumGamStu() const;

	// fill the list with rand data
	void fillList();

	// convention Gamer Students = GS, NON Gamer Students = NGS
	double getNGS_AvgAge();
	std::string getNGS_PopStreamServ();
	double getNGS_AvgHours();

	double getGS_AvgAge();
	std::string getGS_PopGamingDev() const;
	double getGS_AvgHours() const;

	// funtion of display info
	void displayInfo();
};

