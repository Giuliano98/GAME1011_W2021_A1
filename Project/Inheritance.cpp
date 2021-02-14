#include "Inheritance.h"

#include <string>

Person::Person(std::string name, int age)
{
	setName(name);
	setAge(age);
}

void Person::setName(std::string name) { this->name = name; }

void Person::setAge(int age) { this->age = age; }

int Student::getAge() const { return age; }

void Student::setCollegeName(std::string collegeName) { this->collegeName = collegeName; }

void Student::setProgram(std::string program) { this->program = program; }

void Student::setNumSemester(int numSemester) { this->numSemester = numSemester; }

void NonGamingStudent::setStreamService(std::string streamService) { this->streamService = streamService; }

void NonGamingStudent::setHours(int hours) { this->hours = hours; }

std::string NonGamingStudent::getStreamService() const { return streamService; }

int NonGamingStudent::getHours() const { return hours; }

void GamingStudent::setGamingDevice(std::string gamingDevice) { this->gamingDevice = gamingDevice; }

void GamingStudent::setHours(int hours) { this->hours = hours; }

std::string GamingStudent::getGamingDevice() const { return gamingDevice; }

int GamingStudent::getHours() const { return hours; }
