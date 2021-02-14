#include "Survey.h"


#include <iomanip>
#include <iostream>

void Survey::setSize(int size) { this->size = size; }

int Survey::getSize() const { return this->size; }

void Survey::setStuList(Person** list) { this->stuList = list; }

Person** Survey::getStuList() const { return stuList; }

void Survey::setNumGamStu()
{
	numGamStu = (getSize() * getRandNum(101)/100);
}

int Survey::getNumGamStu() const { return this->numGamStu; }

void Survey::setNonNumGamStu()
{
	numNonGameStu = getSize() - getNumGamStu();
}

int Survey::getNonNumGamStu() const { return this->numNonGameStu; }

void Survey::fillList()
{
	int numFlag;
	int numHours;
	
	int numStuGamers = getNumGamStu();
	int numNonStuGamers = getNonNumGamStu();
	Person** list = getStuList();
	
	const int numNames = 10;
	const int numCollegeNames = 6;
	const int numPrograms = 5;
	const int numStreamServ = 6;
	const int numGamingDev = 5;

	std::string names[numNames] = {"Giuliano","Oscar","Fernando","Samuel",
		"Reuben","Joey","Leonardo","Arturo","Mohammed","Patrick"};
	std::string collegeNames[numCollegeNames] = { "George Brown College","Humber College",
		"Seneca College","Sheridan College","Niagara College","Centennial College"};
	std::string programs[numPrograms] = { "Game Dev","art",
		"Dance","Animation","Jewelery"};
	std::string streamService[numStreamServ] = { "Youtube","Disney +",
		"Netflix","Vimeo","Hulu","Twitch" };
	std::string gamingDevice[numGamingDev] = { "PC","PS",
		"Xbox","Switch","Mobile" };

	int topGamingDev[numGamingDev] = { 0,0,0,0,0 };
	int topStreamServ[numStreamServ] = { 0,0,0,0,0,0 };
	
	for (int i = 0; i < numStuGamers; i++)
	{
		numFlag = getRandNum(numGamingDev);
		numHours = getRandNum(10, 1);
		//std::cout << "numHours: " << numHours << std::endl;
		list[i] = new GamingStudent(names[getRandNum(numNames)], getRandNum(12,18),
			collegeNames[getRandNum(numCollegeNames)], programs[getRandNum(numPrograms)],
			getRandNum(6,1), gamingDevice[numFlag], numHours);
		topGamingDev[numFlag]++;
		avgHoursGS += numHours;
	}
	std::cout << std::setprecision(4);	
	avgHoursGS = avgHoursGS / numStuGamers;
	/*std::cout << "avgHoursGS: " << avgHoursGS << std::endl;
	std::cout << "numStuGamers: " << numStuGamers << std::endl;
	std::cout << "AFTERavgHoursGS: " << avgHoursGS << std::endl;*/
	for (int i = 0; i < numNonStuGamers; i++)
	{
		numFlag = getRandNum(numStreamServ);
		numHours = getRandNum(10, 1);
		list[numStuGamers + i] = new NonGamingStudent(names[getRandNum(numNames)], getRandNum(12, 18),
			collegeNames[getRandNum(numCollegeNames)], programs[getRandNum(numPrograms)],
			getRandNum(6, 1), streamService[numFlag], numHours);
		topStreamServ[numFlag]++;
		avgHoursNGS += numHours;
	}
	avgHoursNGS = avgHoursNGS / numNonStuGamers;
	//std::cout << "avgHoursNGS: " << avgHoursNGS << std::endl;
	// finding the most use stream server and gaming deviced
	int numPop = 0;

	for (int i = 0; i < numGamingDev; i++)
	{
		if (topGamingDev[i] > topGamingDev[numPop])
			numPop = i;
	}
	mostUseGamingDev = gamingDevice[numPop];
	//numPop = 0;
	for (int i = 0; i < numStreamServ; i++)
	{
		if (topStreamServ[i] > topStreamServ[numPop])
			numPop = i;
	}
	mostUseStreamServ = streamService[numPop];
	
	
	
	//debugging
	/*std::cout << numStuGamers << std::endl;

	for (int i = 0; i < numGamingDev; i++)
	{
		std::cout << topGamingDev[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << numNonStuGamers << std::endl;
	for (int i = 0; i < numStreamServ; i++)
	{
		std::cout << topStreamServ[i] << std::endl;
	}*/
}

double Survey::getNGS_AvgAge()
{
	double avgAge = 0;
	for (int i = 0; i < numNonGameStu; i++)
	{
		avgAge += stuList[numGamStu + i]->getAge();
	}
	//std::cout << avgAge << std::endl;
	//std::cout << avgAge / numNonGameStu << std::endl;
	if (numNonGameStu == 0)
		return 0;
	std::cout << std::setprecision(4);
	return avgAge / numNonGameStu;
}

std::string Survey::getNGS_PopStreamServ() { return mostUseStreamServ; }

double Survey::getNGS_AvgHours() { return avgHoursNGS; }

double Survey::getGS_AvgAge()
{
	double avgAge = 0;
	for (int i = 0; i < numGamStu; i++)
	{
		avgAge += stuList[i]->getAge();
	}
	if (numGamStu == 0)
		return 0;
	std::cout << std::setprecision(4);
	return avgAge / numGamStu;
}

std::string Survey::getGS_PopGamingDev() const { return mostUseGamingDev; }

double Survey::getGS_AvgHours() const { return avgHoursGS; }

void Survey::displayInfo()
{
	std::cout << "-------------------------------------------------------------------------------------" << std::endl;
	std::cout << "|Non-Gaming Students' statistics: " << std::endl;
	std::cout << "|\t+Number of Non-Gaming Students: " << numNonGameStu << std::endl;
	std::cout << "|\t\t* Average age: " << getNGS_AvgAge() << std::endl;
	std::cout << "|\t\t* Most preferred streaming service: " << getNGS_PopStreamServ() << std::endl;
	std::cout << "|\t\t* Average hours spent consuming non-gaming entertainment: " << getNGS_AvgHours() << std::endl;
	std::cout << "-------------------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "-------------------------------------------------------------------------------------" << std::endl;
	std::cout << "|Gaming Students' statistics: " << std::endl;
	std::cout << "|\t+Number of Gaming Students: " << numGamStu << std::endl;
	std::cout << "|\t\t* Average age: " << getGS_AvgAge() << std::endl;
	std::cout << "|\t\t* Most preferred gaming device: " << getGS_PopGamingDev() << std::endl;
	std::cout << "|\t\t* Average hours spent consuming gaming entertainment: " << getGS_AvgHours() << std::endl;
	std::cout << "-------------------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}
