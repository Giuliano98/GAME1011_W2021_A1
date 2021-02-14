#pragma once
#include <string>

class Person
{
protected:
	std::string name;
	int age = 0;
public:
	Person(std::string name, int age);
	virtual ~Person() = default;
	//virtual std::string getName(std::string name) const = 0;
	virtual int getAge() const = 0;
	void setName(std::string name);
	void setAge(int age);
};

class Student : public Person
{
private:
	std::string collegeName;
	std::string program;
	int numSemester;

public:
	Student(std::string name, int age, std::string college, std::string program, int semester)
	: Person(name, age)
	{
		setCollegeName(college);
		setProgram(program);
		setNumSemester(semester);
	}
	virtual ~Student() = default;
	//virtual std::string getName(std::string name);
	int getAge() const override;
	void setCollegeName(std::string collegeName);
	void setProgram(std::string program);
	void setNumSemester(int numSemester);
};

class NonGamingStudent : public Student
{
private:
	std::string streamService;
	int hours = 0;
public:
	NonGamingStudent(std::string name, int age, std::string college, std::string program, 
		int semester, std::string streamService, int hours)
	: Student(name, age, college, program, semester)
	{
		setStreamService(streamService);
		setHours(hours);
	}
	~NonGamingStudent() = default;
	void setStreamService(std::string streamService);
	void setHours(int hours);
	std::string getStreamService() const;
	int getHours() const;
	
};

class GamingStudent : public Student
{
private:
	std::string gamingDevice;
	int hours;	
public:
	GamingStudent(std::string name, int age, std::string college, std::string program, 
		int semester, std::string gamingDevice, int hours)
	: Student(name, age, college, program, semester)
	{
		setGamingDevice(gamingDevice);
		setHours(hours);
	}
	~GamingStudent() = default;
	void setGamingDevice(std::string gamingDevice);
	void setHours(int hours);
	std::string getGamingDevice() const;
	int getHours() const;
};
