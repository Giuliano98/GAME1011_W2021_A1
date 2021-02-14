#include <iostream>
#include <string>
#include "Inheritance.h"
#include "Survey.h"

using namespace std;


int main()
{	
	srand((unsigned)time(NULL));
	
	int numStudent = -1;
	while (numStudent < 0 || numStudent > 500)
	{
		cout << "Enter number of students (max. 500): ";
		cin >> numStudent;
	}
	// creating the list
	Person** stuList = new Person*[numStudent];
	// init an obj and passing size and p-p list 
	Survey surveyList(numStudent, stuList);

	cout << "\n\n";
	// display info
	surveyList.displayInfo();

	
	/*cout << surveyList.getGS_AvgAge() << endl;
	cout << surveyList.getGS_AvgHours() << endl;
	cout << surveyList.getGS_PopGamingDev() << endl;
	cout << "\n\n";
	cout << surveyList.getNGS_AvgAge() << endl;
	cout << surveyList.getNGS_AvgHours() << endl;
	cout << surveyList.getNGS_PopStreamServ() << endl;*/
	//cout << surveyList.getNGS_AvgAge() << endl;
	return 0;
}