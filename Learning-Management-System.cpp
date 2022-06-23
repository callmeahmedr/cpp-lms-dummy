#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
using namespace std;

class AdminModule{

public:
	// Validate Credit Hour (0-3)
	bool isValidCreditHours(int credit_hours) {
		bool var1 = false;
		if (credit_hours > 0 && credit_hours <= 3) {
			var1 = true;
		}
		return var1;
	}

	// Validate Semester (0-8)
	bool isValidSemester(int semester) {
		bool var = false;
		if (semester > 0 && semester <= 8) {
			var = true;
		}
		return var;
	}

	// Validate Course Name
	bool isValidCourseName(char course_name[]) {
		bool value = true;
		int x = 0;
		while (course_name[x] != '\0') {
			for (char y = '0'; y <= '9'; y++) {
				if (course_name[x] == y) {
					value = false;
				}
			}
			x++;
		}
		return value;
	}

	// Calculate max index of integar array semList
	int max_index(int semList[]) {
		int a = 0, counter = 0;
		while (semList[a] != 0) {
			counter++;
			a++;
		}
		return --counter;
	}

	// Calculate the max index of string array
	int max_index_regNo(string stdRegNoList[]) {
		int a = 0, counter = 0;
		while (stdRegNoList[a] != "\0") {
			counter++;
			a++;
		}
		return --counter;
	}

	// Declare edit_course and delete_course
	string edit_course_code;
	int flag = 0, counter = 0, counter2, flag2 = 0, counter3, flag3 = 0, counter4, check_1 = 0;
	int var;

	// Add Course
	void AddCourse(string codeList[], string nameList[], int crtHrsList[], int semList[], char course_code[], int credit_hours, int semester, char course_name[]) {
		static int n = var + 1;
		static int c = 0;
		int b = 0;
			static int a = counter;
			if (flag == 1) {
				// Add Course (Logic)
				b = counter;
				codeList[b] = course_code;
				crtHrsList[b] = credit_hours;
				semList[b] = semester;
				nameList[b] = course_name;
				cout << "\nCourse has been added successfully" << endl;
				b++;
				flag = 2;
			} else if (var != 0) {
				if (flag == 2) {
					n = a + 1;
					flag = 0;
				}
				// Add Course (Logic x2) - Already Exist
				codeList[n] = course_code;
				crtHrsList[n] = credit_hours;
				semList[n] = semester;
				nameList[n] = course_name;
				cout << "\nCourse has been added successfully" << endl;
				n++;
			} else {
				// Add Course (Logic x3) - None-Already Exist
				if (flag == 2) {
					c = counter + 1;
					flag = 0;
				}

				codeList[c] = course_code;
				crtHrsList[c] = credit_hours;
				semList[c] = semester;
				nameList[c] = course_name;
				cout << "\nCourse has been added successfully" << endl;
				c++;
			}
		if (var == 0) {
			counter2 = c;
			check_1 = 1;
		} else {
			counter2 = n;
			check_1 = 1;
		} if (flag == 2) {
			counter2 = b;
			check_1 = 1;
		}

		ofstream counter;
		counter.open("addCourseCounter.txt");
		counter << counter2 - 1;
		counter.close();
	}

	// Validate Course Code
	int check_course_code(string codeList[], string edit_course_code) {
		bool value = 0;
		for (int x = 0; x < 100; x++) {
			if (codeList[x] == edit_course_code) {
				value = 1;
				break;
			}
		}
		return value;
	}

	// Return index where details of the course(s) is placed
	int index_course_code(string codeList[], string edit_course_code) {
		int index = -1;
		for (int x = 0; x < 100; x++) {
			if (codeList[x] == edit_course_code) {
				index = x;
				break;
			}
		}
		return index;
	}

	// Return index where details of the registration number are placed
	int index_reg_code(string stdRegNoList[], string edit_reNo) {
		int index = -1;
		for (int x = 0; x < 100; x++) {
			if (stdRegNoList[x] == edit_reNo) {
				index = x;
				break;
			}
		}
		return index;
	}

	// Return index where registration number of the student is stored in 2D array
	int index_stdCourseList(string stdCourseList[][100], string reg_No) {
		int index = -1;
		for (int x = 0; x < 100; x++) {
			if (stdCourseList[x][0] == reg_No) {
				index = x;
				break;
			}
		}
		return index;
	}

	// Return index where the course is stored which we want to delete
	int index_delete_code(string codeList[], string delete_course_code) {
		int index;
		for (int x = 0; x < 100; x++) {
			if (codeList[x] == delete_course_code) {
				index = x;
				break;
			}
		}
		return index;
	}

	// Return us the max index of the row of the 2D array
	int index_row(string stdCourseList[][100], string reg_No) {
		int x = 1, counter = 1;
		int variable = index_stdCourseList(stdCourseList, reg_No);
		while (stdCourseList[variable][x] != "\0") {
			counter++;
			x++;
		}
		return counter;
	}

	// Replace a course of the specified course code with another course detail
	void EditCourse(string codeList[], string nameList[], int crtHrsList[], int semList[], char course_code[], int credit_hours, int semester, char course_name[]) {
		cout << "Enter the new details of the course: ";
		cin >> course_code >> credit_hours >> semester;
		cin.get(course_name, 100);
			int n = index_course_code(codeList, edit_course_code);
			codeList[n] = course_code;
			crtHrsList[n] = credit_hours;
			semList[n] = semester;
			nameList[n] = course_name;
			cout << "\nCourse has been edited successfully.\n";
	}

	// Delete a course according to the course code which is given by the user
	void DeleteCourse(string codeList[], string nameList[], int crtHrsList[], int semList[], string delete_course_code) {
		int n = index_delete_code(codeList, delete_course_code);
		int m = max_index(semList);
		for (int x = n; x <= m; x++) {
			codeList[x] = codeList[x + 1];
			nameList[x] = nameList[x + 1];
			crtHrsList[x] = crtHrsList[x + 1];
			semList[x] = semList[x + 1];
		}
		codeList[m] = '\0';
		nameList[m] = '\0';
		crtHrsList[m] = '\0';
		semList[m] = '\0';
		flag = 1;
		counter = m;
		cout << endl << "Course has been deleted successfully" << endl;
	}

	int max_index_2(int crtHrsList[]) {
		int a = 0, counter = 0;
		while (crtHrsList[a] != 0) {
			counter++;
			a++;
		}
		return counter;
	}

	// Display all the courses of a specific semester
	void ViewSemesterCourse(string codeList[], string nameList[], int crtHrsList[], int semList[], int semester) {
		int size = max_index(semList);
		cout << "Enter the semester of which you want to display course: ";
		cin >> semester;
		cout << endl;
		cout << left;

		cout << setw(15) << "\tCourse Code" << setw(30) << "Name" << setw(20) << "Credit Hours" << endl;
		int index, x = 0;

		while (semList[x] != 0) {
			if (semList[x] == semester) {
				cout << "\t" << setw(13) << codeList[x] << setw(31) << nameList[x] << setw(20) << crtHrsList[x] << endl;
			}
			x++;
		}
	}

	// Save all the added courses in the file when we exit the program
	bool saveCourses(string codeList[], string nameList[], int crtHrsList[], int semList[], int semester) {
		bool value = 0;
		ofstream outData;
		outData.open("coursesInformation.txt");
		int size = max_index(semList);

		for (int x = 0; x <= size; x++) {
			outData << codeList[x] << "," << nameList[x] << "," << crtHrsList[x] << "," << semList[x] << endl;
			value = 1;
		}
		outData.close();
		return value;
	}

	// Load courses in memory when program is being loaded
	bool loadCourses(string codeList[], string nameList[], int crtHrsList[], int semList[]) {
		ifstream check, op;
		check.open("checkLoadCourses.txt");
		int a, value1 = 0;
		check >> a;
		check.close();

		op.open("addCourseCounter.txt");
		int var;
		op >> var;
		op.close();

		if (a == 1) {
			value1 = 1;
		}

		int x = 0, y = 0, creditHour, Semester, counter = 0;
		string data;

		ifstream inData;
		inData.open("coursesInformation.txt");

		while (value1 == 1) {
			char courseCode[6] = {'\0'}, courseName[50] = {'\0'};
			getline(inData, data);
			while (data[x] != ',') {
				courseCode[y] = data[x];
				y++;
				x++;
			}

			codeList[counter] = courseCode;

			x++;
			y = 0;
			while (data[x] != ',') {
				courseName[y] = data[x];
				x++;
				y++;
			}

			nameList[counter] = courseName;

			x++;

			while (data[x] != ',') {
				char conversion;
				conversion = data[x];
				creditHour = conversion - 48;
				break;
			}
			crtHrsList[counter] = creditHour;

			x += 2;

			while (data[x] != '\0') {
				char con;
				con = data[x];
				Semester = con - 48;
				break;
			}

			x++;
			semList[counter] = Semester;

			x = 0;
			y = 0;
			counter++;

			if (counter > var) {
				break;
			}
		}

		inData.close();

		if (a == 0) {
			return 0;
		} else {
			return 1;
		}
	}

	//this function will display all the courses ,which are added, on console
	void ViewCourses(string codeList[], string nameList[], int crtHrsList[], int semList[])
	{
		int size;

		size = max_index(semList);

		cout << left;
		cout << setw(15) << "\tCourse Code" << setw(30) << "Name" << setw(20) << "Credit Hours" << setw(20) << "Semester" << endl;

		for (int i = 0; i <= size; i++)
		{
			cout << left;
			cout << "\t" << setw(13) << codeList[i] << setw(31) << nameList[i] << setw(20) << crtHrsList[i] << setw(20) << semList[i] << endl;
		}
	}

	//this function will check whether the inputed credentials are true or not
	bool loadUsers(char usersList[], char passwordsList[])
	{
		ifstream users;
		bool value = 0, value2 = 0;
		char username[200] = {'\0'}, password[200] = {'\0'};
		int x = 0;
		string user;

		cout << "Username: ";
		cin >> username;
		cout << "Password: ";
		cin >> password;
		users.open("adminCredentials.txt");

		while (value == 0 && value2 == 0)
		{

			getline(users, user);

			while (user[x] != ',')
			{

				if (user[x] == username[x])
				{
					value = 1;
				}
				else
				{
					value = 0;
					break;
				}
				x++;
			}

			if (username[x] != '\0')
			{
				value = 0;
			}

			x++;
			int y = 0;

			while (user[x] != '\0')
			{
				if (user[x] == password[y])
				{
					value2 = 1;
				}
				else
				{
					value2 = 0;
					break;
				}
				x++;
				y++;
			}

			if (password[y] != '\0')
			{
				value2 = 0;
			}

			if (value == 1 && value2 == 1)
			{
				break;
			}
			if (user[x] == '\0')
			{
				break;
			}
		}

		users.close();
		if (value == 1 && value2 == 1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	//this function checks whether the entered student name is valid or not
	bool isValidStudentName(char studentName[])
	{
		bool value = true;
		int x = 0;
		while (studentName[x] != '\0')
		{
			for (char y = '0'; y <= '9'; y++)
			{
				if (studentName[x] == y)
				{
					value = false;
				}
			}
			x++;
		}
		return value;
	}

	int var4, var6;
	//this function will addstudent in an stdNameList
	void addStudent(string stdNameList[], string stdRegNoList[], char studentName[], char regNo[])
	{
		static int variable = 0;
		int a = counter3;
		int b = counter3;
		int an_flag = 0;
		static int n = var6;
			if (flag2 == 1)
			{
				//when a student is deleted, addStudent function will use this logic to add student

				stdNameList[a] = studentName;
				stdRegNoList[a] = regNo;
				cout << "\nStudent has been added successfully" << endl;
				a++;
				flag2 = 2;
			}
			else if (var6 != 0)
			{
				if (flag2 == 2)
				{
					n = counter3 + 1;
					flag2 = 0;
				}

				stdNameList[n] = studentName;
				stdRegNoList[n] = regNo;
				n++;
				cout << "\nStudent has been added successfully" << endl;
			}
			else
			{
				//when we have to add students in the memory
				if (flag2 == 2)
				{
					variable = counter3 + 1;
					flag2 = 0;
				}

				stdNameList[variable] = studentName;
				stdRegNoList[variable] = regNo;
				variable++;
				cout << "\nStudent has been added successfully" << endl;
			}

		if (var6 != 0)
		{
			var4 = n;
			ofstream OUTDATA;
			OUTDATA.open("addStudentCounter.txt");
			OUTDATA << n;
			OUTDATA.close();
		}
		else
		{
			var4 = variable;
			ofstream OUTDATA;
			OUTDATA.open("addStudentCounter.txt");
			OUTDATA << variable;
			OUTDATA.close();
		}
	}

	string edit_reNo;

	//this function will edit the student in the list
	void updateStudent(string stdNameList[], string stdRegNoList[], char studentName[], char regNo[])
	{
			int variable = index_reg_code(stdRegNoList, edit_reNo);
			stdNameList[variable] = studentName;
			stdRegNoList[variable] = regNo;
			cout << "\nStudent details have been edited successfully.\n";
	}

	int var7;
	//this function will register courses for the student
	void registerCourse(string stdRegNoList[], string stdCourseList[][100], string codeList[], string reg_No, string courseCode)
	{
		if (index_course_code(codeList, courseCode) == -1)
		{
			cout << "There is no course by this course code." << endl;
		}

		else
		{
			static int n = var7;

			//when we add courses in new student registration number in stdCourseList
			if (index_stdCourseList(stdCourseList, reg_No) == -1)
			{
				//this condition will be used to add courses in the index of deleted courses
				if (flag3)
				{
					stdCourseList[counter4][0] = reg_No;
					stdCourseList[counter4][1] = courseCode;
					flag3 = 0;
				}

				else
				{
					if (var7 != 0)
					{
						static int x = n;
						int y = 0;
						stdCourseList[x][y] = reg_No;
						y++;
						stdCourseList[x][y] = courseCode;
						x++;
					}
					else
					{
						static int x = 0;
						int y = 0;
						stdCourseList[x][y] = reg_No;
						y++;
						stdCourseList[x][y] = courseCode;
						x++;
					}
				}
			}
			else if (var7 != 0)
			{
				int variable = index_stdCourseList(stdCourseList, reg_No);
				if (variable != -1 && index_row(stdCourseList, reg_No) == 1)
				{
					stdCourseList[variable][1] = courseCode;
				}
				else if (variable != -1 && index_row(stdCourseList, reg_No) != 1)
				{
					int y = index_row(stdCourseList, reg_No);
					stdCourseList[variable][y] = courseCode;
				}
				else
				{
					stdCourseList[n][0] = reg_No;
					stdCourseList[n][1] = courseCode;
					n++;
				}
			}
			//when we add courses in existing student registration number
			else
			{
				int variable = index_stdCourseList(stdCourseList, reg_No);
				int y = index_row(stdCourseList, reg_No);
				stdCourseList[variable][y] = courseCode;
			}

			cout << "Course has been registered for the student." << endl;
		}
	}

	//this function will delete the student from the studentlist
	void deleteStudent(string stdNameList[], string stdRegNoList[], string stdCourseList[][100], string reg_no)
	{
		int variable = index_reg_code(stdRegNoList, reg_no);
		int variable2 = max_index_regNo(stdRegNoList);

		for (int x = variable; x <= variable2; x++)
		{
			stdRegNoList[x] = stdRegNoList[x + 1];
			stdNameList[x] = stdNameList[x + 1];
		}
		stdRegNoList[variable2] = "\0";
		stdNameList[variable2] = "\0";
		flag2 = 1;
		counter3 = variable2;

		//this condition will delete student reg number and his/her registered courses from the stdCourseList
		if (index_stdCourseList(stdCourseList, reg_no) == -1)
		{
		}
		else
		{
			int variable3 = index_stdCourseList(stdCourseList, reg_no);
			int y = index_row(stdCourseList, reg_no);
			counter4 = variable3;

			for (int x = 0; stdCourseList[variable][x] != "\0"; x++)
			{
				stdCourseList[variable3][x] = "\0";
				flag3 = 1;
			}
		}

		cout << endl
			<< "Student has been deleted successfully" << endl;
	}

	//this function will unregister the course for the student
	void unRegisterCourse(string stdRegNoList[], string stdCourseList[][100], string reg_no, string courseCode)
	{
		int variable = index_reg_code(stdRegNoList, reg_no);
		bool value = 1;

		for (int i = 0; stdCourseList[variable][i] != "\0"; i++)
		{
			if (stdCourseList[variable][i] == courseCode)
			{
				stdCourseList[variable][i] = "\0";
				value = 1;
				break;
			}
			else
			{
				value = 0;
			}
		}
		if (value == 0)
		{
			cout << endl
				<< "There is no course registered for the student by this course code.\n";
		}
		else
		{
			cout << endl
				<< "Course has been unregistered successfully.\n";
		}
	}
	//this function will display all the registered students
	void viewstudents(string stdRegNoList[], string stdNameList[])
	{
		cout << left;
		cout << setw(30) << "\t Student Name"
			<< "Registration Number" << endl;
		for (int x = 0; stdRegNoList[x] != "\0"; x++)
		{
			cout << left;
			cout << "\t" << setw(29) << stdNameList[x] << stdRegNoList[x] << endl;
		}
	}

	//this function will return the index where details of the registration number are placed in 2D array
	int index_cou_code(string stdCourseList[][100], string edit_reNo)
	{
		int index = -1;
		for (int x = 0; x < 100; x++)
		{
			if (stdCourseList[x][0] == edit_reNo)
			{
				index = x;
				break;
			}
		}
		return index;
	}

	//this function will calculate the length of the name
	int length_of_name(string studentName)
	{
		int e = 0, y = 0;
		while (studentName[e] != '\0')
		{
			y++;
			e++;
		}
		return --y;
	}

	ofstream DATA;
	//this function will save student credentials in an external file
	void std_cre(string stdNameList[], string stdRegNoList[])
	{
		DATA.open("stdCredentials.txt");
		int x = 0;

		while (stdRegNoList[x] != "\0")
		{
			string studentName, regNo;
			studentName = stdNameList[x];
			regNo = stdRegNoList[x];
			int b = length_of_name(studentName);
			DATA << studentName << ",";
			DATA << regNo << endl;
			x++;
		}
		DATA.close();
	}

	//this function will save students in an external file
	void saveStudents(string stdRegNoList[], string stdNameList[], string stdCourseList[][100])
	{
		ofstream outdata;
		outdata.open("stdInformation.txt");
		for (int x = 0; stdRegNoList[x] != "\0"; x++)
		{
			string f = stdRegNoList[x];
			outdata << stdRegNoList[x] << "," << stdNameList[x] << endl;

			if (index_cou_code(stdCourseList, f) == -1)
			{
				outdata << endl;
			}
			else
			{
				int j = index_cou_code(stdCourseList, f);
				for (int i = 1; stdCourseList[j][i] != "\0"; i++)
				{
					outdata << stdCourseList[j][i];
					if (stdCourseList[j][i + 1] != "\0")
					{
						outdata << ",";
					}
				}
				outdata << endl;
			}
		}
		outdata.close();
	}

	//this function will load the students in the external file in the memory
	void loadsStudents(string stdRegNoList[], string stdNameList[], string stdCourseList[][100])
	{

		ifstream check, op;
		check.open("checkStudent.txt");
		int a, value1 = 0;
		check >> a;
		check.close();

		if (a == 1)
		{
			value1 = 1;
		}

		op.open("addStudentCounter.txt");
		int var5;
		op >> var5;
		op.close();

		int x = 0, y = 0, counter = 0;
		string data;

		ifstream inData;
		inData.open("stdInformation.txt");

		while (value1 == 1)
		{
			char stdregno[12] = {'\0'}, stdname[50] = {'\0'}, courses[6] = {'\0'};
			getline(inData, data);

			while (data[x] != ',')
			{
				stdregno[y] = data[x];
				y++;
				x++;
			}

			stdRegNoList[counter] = stdregno;
			x++;
			y = 0;

			while (data[x] != '\0')
			{
				stdname[y] = data[x];
				x++;
				y++;
			}

			stdNameList[counter] = stdname;
			stdCourseList[counter][0] = stdRegNoList[counter];

			getline(inData, data);
			x = 0;
			y = 0;
			int j = 1;
			while (data[x] != '\0')
			{
				y = 0;
				while (data[x] != ',' && data[x + 1] != '\0')
				{
					courses[y] = data[x];
					x++;
					y++;
					if (data[x + 1] == '\0')
					{
						courses[y] = data[x];
					}
				}
				x++;
				stdCourseList[counter][j] = courses;
				j++;
			}

			x = 0;
			y = 0;
			counter++;

			if (counter == var5)
			{
				break;
			}
		}
		inData.close();
	}
};


class StudentModule : public AdminModule {

public :

	// Validate Student Credentials
	bool loadStudent(string registration_no, string password) {
		ifstream Data;
		Data.open("stdCredentials.txt");
		int a = 1;
		string cred;
		char pas[12] = {'\0'}, regno[12] = {'\0'};

		while (a) {
			getline(Data, cred);
			if (cred == "\0") {
				break;
			}
			int x = 0;

			while (cred[x] != ',') {
				pas[x] = cred[x];
				x++;
			}

			x++;
			int y = 0;
			while (cred[x] != '\0') {
				regno[y] = cred[x];
				y++;
				x++;
			}

			if (registration_no == regno && password == pas) {
				break;
			}
		}
		Data.close();
		if (registration_no == regno && password == pas) {
			return 1;
		} else {
			return 0;
		}
	}

	// OVERRIDE - Return index where registration number of the student is stored in 2D array
	int index_stdCourseList(string stdCourseList[][100], string reg_No) {
		int index = -1;
		for (int x = 0; x < 100; x++) {
			if (stdCourseList[x][0] == reg_No) {
				index = x;
				break;
			}
		}
		return index;
	}

	// OVERRIDE - Return index where details of the registration number are placed
	int index_reg_code(string stdRegNoList[], string edit_reNo) {
		int index = -1;
		for (int x = 0; x < 100; x++) {
			if (stdRegNoList[x] == edit_reNo) {
				index = x;
				break;
			}
		}
		return index;
	}

};




int main()
{

	// Initializing AdminModule Class using "l"
	AdminModule l;

	// Initializing StudentModule Class using "student"
	StudentModule student;

	system("CLS");
	int option, credit_hours, semester, check_user = 1, check_st = 1, loop = 0, tab = 0, option_1;
	char course_code[6], course_name[50], usersList[1000] = {'\0'}, passwordsList[1000] = {'\0'}, studentName[100] = {'\0'};
	char regNo[12] = {'\0'};
	string delete_course_code, codeList[100], nameList[100], stdNameList[100], stdRegNoList[100] = {"\0"}, stdCourseList[100][100], reg_no, courseCode;
	int a = 1, crtHrsList[100], semList[100], c = 0, another_var;

	ifstream file;
	file.open("checkStudent.txt");
	file >> another_var;
	file.close();

	ifstream op;
	op.open("addCourseCounter.txt");
	op >> l.var;
	op.close();

	ifstream opi;
	opi.open("addStudentCounter.txt");
	opi >> l.var6;
	opi.close();

	ifstream opid;
	opid.open("addStudentCounter.txt");
	opid >> l.var7;
	opid.close();

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			stdCourseList[i][j] = "\0";
		}
	}

	if (another_var)
	{
		l.loadsStudents(stdRegNoList, stdNameList, stdCourseList);
	}

	for (int x = 0; x < 100; x++)
	{
		semList[x] = 0;
		crtHrsList[x] = 0;
	}

	int load = l.loadCourses(codeList, nameList, crtHrsList, semList);
	if (load)
	{
		l.check_1 = 1;
	}

	int it = 1;

	cout << "			    ** Welcome to University Learning Management System ** \n";
	cout << endl
		 << "Dear user, current software is intended for authorized users only. \nLogin to the system to get access";
	cout << endl;
	cout << endl;

	while (it)
	{
		cout << "Choose the option for login\n";
		cout << endl
			 << "Press 1 for Admin access." << endl;
		cout << "Press 2 for Student access." << endl;
		cout << "Press 3 to Exit." << endl;
		cout << endl
			 << "Option: ";
		cin >> option_1;

		if (cin.fail())
		{
			cout << "\nProgram has been exited.\n";
			return 0;
		}

		switch (option_1)
		{

		//admin access
		case 1:
		{
			system("CLS");
			while (loop == 0)
			{
				cout << "			    ** Welcome to University Learning Management System ** \n";
				cout << endl
					 << "Dear user, current software is intended for authorized users only. \nLogin to the system to get access";
				cout << endl;
				cout << endl;
				do
				{
					if (check_user == 0)
					{
						char dec;
						cout << "\nDear User, username/password is incorrect. Enter the username/password again \nto get access to the system" << endl
							 << endl;
						cout << "Do you want to end the program? Please enter 'Y' for yes and 'N' for no: ";
						cin >> dec;
						cout << endl;
						if (dec == 'Y' || dec == 'y')
						{
							return 0;
						}
					}
					a = 1;
					check_user = l.loadUsers(usersList, passwordsList);
				} while (check_user == 0);

				loop = check_user;

				system("CLS");
				cout << endl
					 << "You have successfully logged in in your LMS account." << endl;
				while (a)
				{

					cout << endl;
					cout << "Choose the following option: " << endl;
					cout << endl
						 << "1 	Add Course" << endl;
					cout << "2	Update Course" << endl;
					cout << "3	Delete Course" << endl;
					cout << "4 	View All Courses" << endl;
					cout << "5	View Courses of a Semester" << endl;
					cout << "6	Add Student" << endl;
					cout << "7	Update Student" << endl;
					cout << "8	Delete Student" << endl;
					cout << "9 	Register the course for student" << endl;
					cout << "10	Unregister the course for student" << endl;
					cout << "11	View All students" << endl;
					cout << "12	Logout of the system" << endl
						 << "13	Exit Program" << endl
						 << endl;

					cout << "Choose the option: ";
					cin >> option;
					cout << endl;

					if (cin.fail())
					{
						option = 13;
					}
					switch (option)
					{

					//Add courses
					case 1:
					{
						cout << "Enter Course Name: "; 
						cin >> course_name;

						cout << "Enter Course Code: "; 
						cin >> course_code;
						
						cout << "Enter Credit Hour(s): "; 
						cin >> credit_hours;

						cout << "Enter Semester: "; 
						cin >> semester;

						while (l.isValidCreditHours(credit_hours) == 0)
						{
							cout << endl
								 << "Invalid Credit hours" << endl;
							cout << "Enter Credit hours again: ";
							cin >> credit_hours;
						}
						while (l.isValidSemester(semester) == 0)
						{
							cout << endl
								 << "Invalid Semester\n";
							cout << "Enter semester again: ";
							cin >> semester;
						}

						if (l.isValidCourseName(course_name) == 0) {
							cout << endl << "Invalid Course Name\n";
						}

						l.AddCourse(codeList, nameList, crtHrsList, semList, course_code, credit_hours, semester, course_name);

						break;
					}

					//Edit Course
					case 2:
					{
						cout << "Enter the course code to edit: ";
						cin >> l.edit_course_code;
						cout << endl;
						if (l.check_course_code(codeList, l.edit_course_code) == 0)
						{
							cout << endl
								 << "This is no course by this course code";
						}
						else
						{

							l.EditCourse(codeList, nameList, crtHrsList, semList, course_code, credit_hours, semester, course_name);
						}

						break;
					}

					//Delete Course
					case 3:
					{
						cout << "Enter course code of the course which you want to delete: ";
						cin >> delete_course_code;

						if (l.check_course_code(codeList, delete_course_code) == 0)
						{
							cout << endl
								 << "This is no course by this course code";
						}
						else
						{

							l.DeleteCourse(codeList, nameList, crtHrsList, semList, delete_course_code);
						}
						break;
					}

					//View all courses
					case 4:
					{
						int size = l.max_index(semList);

						if (size == -1)
						{
							cout << endl
								 << "There is no course to display. Please add courses first.\n";
						}
						else
						{
							l.ViewCourses(codeList, nameList, crtHrsList, semList);
						}
						break;
					}

					//View courses by semester
					case 5:
					{
						int size = l.max_index(semList);

						if (size == -1)
						{
							cout << endl
								 << "There is no course to display. Please add courses first.\n";
						}
						else
						{
							l.ViewSemesterCourse(codeList, nameList, crtHrsList, semList, semester);
						}
						break;
					}

					case 6:
					{

						cout << "Enter the reg no. : ";
						cin >> regNo;
						cout << "Enter the name : ";
						cin >> studentName;

						l.addStudent(stdNameList, stdRegNoList, studentName, regNo);
						l.std_cre(stdNameList, stdRegNoList);
						break;
					}

					case 7:
					{
						cout << "Enter the registration number of the student to edit: ";
						cin >> l.edit_reNo;

						if (l.index_reg_code(stdRegNoList, l.edit_reNo) == -1)
						{
							cout << "\nThere is no student by this registration number. \n";
						}
						else
						{
							cout << "Enter new details of the student: ";
							cin >> regNo;
							cin.get(studentName, 100);
							l.updateStudent(stdNameList, stdRegNoList, studentName, regNo);
						}

						break;
					}

					case 8:
					{
						cout << "Enter Registration number of the student to delete: ";
						cin >> reg_no;
						cout << endl;
						if (l.index_reg_code(stdRegNoList, reg_no) == -1)
						{
							cout << "There is no student by this registration number.\n ";
						}

						else
						{
							l.deleteStudent(stdNameList, stdRegNoList, stdCourseList, reg_no);
						}
						break;
					}

					case 9:
					{

						cout << "Enter registration Number of the student for course registration: ";
						cin >> reg_no;
						cout << endl;
						if (l.index_reg_code(stdRegNoList, reg_no) == -1)
						{
							cout << "There is no student by this registration number.\n ";
						}
						else
						{
							cout << "Enter the Course Code to register: ";
							cin >> courseCode;
							cout << endl;
							l.registerCourse(stdRegNoList, stdCourseList, codeList, reg_no, courseCode);
						}
						break;
					}

					case 10:
					{
						cout << "Enter registration number of the student: ";
						cin >> reg_no;
						if (l.index_reg_code(stdRegNoList, reg_no) == -1)
						{
							cout << "There is no student by this registration number.\n ";
						}

						else
						{
							cout << "Enter course code to unregister: ";
							cin >> courseCode;
							l.unRegisterCourse(stdRegNoList, stdCourseList, reg_no, courseCode);
						}
						break;
					}

					case 11:
					{
					   	l.viewstudents(stdRegNoList, stdNameList);
						break;
					}

					//logout from the account
					case 12:
					{
						system("CLS");
						loop = 0;
						a = 0;
						break;
					}

					//Exit the program
					case 13:
					{
						a = 0;

						/*this condition will check save 1 in an external file if there are courses stored in another external file.
				it also save addcourse counter in the external file*/

						if (l.check_1)
						{
							int var1 = l.saveCourses(codeList, nameList, crtHrsList, semList, semester);

							if (codeList[0] != "\0")
							{
								ofstream b;
								b.open("checkLoadCourses.txt");
								c = 1;
								b << c;
								b.close();
							}
							else
							{
								ofstream b;
								b.open("checkLoadCourses.txt");
								c = 0;
								b << c;
								b.close();
							}
						}

						//this condition will check whether any student has been entered or not
						if (stdRegNoList[0] != "\0")
						{
							ofstream file;
							file.open("checkStudent.txt");
							file << "1";
							file.close();
						}
						else
						{
							ofstream file;
							file.open("checkStudent.txt");
							file << "0";
							file.close();
						}
						l.saveStudents(stdRegNoList, stdNameList, stdCourseList);
						cout << "Program has been exited" << endl;
						return 0;
						break;
					}

					default:
					{
						cout << endl
							 << "Invalid Option. Please select from 1 to 6. ";
					}
					}

					cout << endl;
					cout << "                    *********************************************************************";
					cout << endl;
				}
			}
			break;
		}

		//student access
		case 2:
		{
			system("CLS");
			int x = 1;
			while (x == 1)
			{
				cout << "			    ** Welcome to University Learning Management System ** \n";
				cout << endl
					 << "Dear user, current software is intended for authorized users only. \nLogin to the system to get access";
				cout << endl;
				cout << endl;
				string registration_no, password;

				cout << "\nEnter your registration number: ";
				cin >> registration_no;
				if (student.index_reg_code(stdRegNoList, registration_no) == -1)
				{
					cout << "\nThere is no student by this registration number.\n ";
				}
				else
				{
					cout << "\nEnter your password: ";
					cin >> password;
				}

				do
				{
					if (check_st == 0)
					{
						char dec;
						cout << "\nDear User, registration_number/password is incorrect. Enter the username/password again \nto get access to the system" << endl
							 << endl;
						cout << "Do you want to end the program? Please enter 'Y' for yes and 'N' for no: ";
						cin >> dec;
						cout << endl;
						if (dec == 'Y' || dec == 'y')
						{
							return 0;
						}
						else
						{
							cout << "Enter your registration number: ";
							cin >> registration_no;
							if (student.index_reg_code(stdRegNoList, registration_no) == -1)
							{
								cout << "\nThere is no student by this registration number.\n ";
							}
							else
							{
								cout << "\nEnter your password: ";
								cin >> password;
							}
						}
					}
					check_st = student.loadStudent(registration_no, password);
				} while (check_st == 0);

				x = check_st;
				int i = 1;
				if (student.loadStudent(registration_no, password) == 1)
				{
					system("CLS");
					cout << "			    ** Welcome to University Learning Management System ** \n";
					cout << endl
						 << "You have successfully logged in the system.\n";
					cout << endl;

					while (i == 1)
					{
						int option_3;
						cout << endl
							 << "Choose from the following option: " << endl;
						cout << endl
							 << "Press 1 to View Registered Courses.";
						cout << endl
							 << "Press 2 to logout of the system. ";
						cout << endl
							 << "Press 3 to Exit. \n";
						cout << endl
							 << "Option: ";
						cin >> option_3;

						if (cin.fail())
						{
							cout << "\nProgram has been exited.\n";
							return 0;
						}
						switch (option_3)
						{
						case 1:
						{
							int variable = l.index_stdCourseList(stdCourseList, registration_no);
							cout << endl
								 << "\tRegistered Courses\n";
							for (int q = 1; stdCourseList[variable][q] != "\0"; q++)
							{
								cout << "\t" << stdCourseList[variable][q] << endl;
							}

							break;
						}
						case 2:
						{
							system("CLS");
							x = 1;
							i = 0;
							break;
						}
						case 3:
						{
							cout << endl
								 << "Program has been exited" << endl;
							return 0;
						}
						default:
						{
							cout << endl
								 << "Invalid Number. Please enter a number between 1 to 3." << endl;
						}
						}
					}
				}
			}

			break;
		}

		//exit program
		case 3:
		{
			it = 0;
			cout << endl
				 << "Program has been exited" << endl;
			break;
		}

		default:
		{
			cout << endl
				 << "Invalid Option. Please enter 1 or 2. " << endl
				 << endl;
		}
		}
	}

	return 0;
}
