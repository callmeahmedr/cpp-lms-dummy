**Learning Management System Using C++**

Learning Management System is built on two main modules. The first module is the Admin side which deals with the administration side of the system like creating and managing students. From the admin side, you also have some other management features which will be discussed in the “Admin Module” clause later on.

The second module of the system is the Student side, which mainly deals with viewing the students’ personal details and how they interact with the course(s) he/she had joined.

**Implementation of Object-Oriented Programming**
We are using the concept of classes along with the concept of file handling in CPP to perform the data management for our systems and using it as our objects to store and access our data when it’s required to be. Functions used in classes help in the reusability of a program that is easy for users to access different tasks.

This makes the Management and especially debugging easy for both the developer and a newbie who’s using our system for the first time. We have used a couple of different libraries in order to perform certain tasks.

**External Libraries**
For this specific Learning Management System, we are using a total of 4 external Libraries to perform various tasks. Each library used is briefly explained below:
- #include <fstream>
We are using the file-handling library which is referred to as “fstream” to store and access our student’s data like their credentials and also the admin side credentials as well. 
- #include <iomanip>
We are using the “iomanip” library to manipulate the output of our LMS and as we are dealing with flags management we use it to perform just functions and implement OOP.
- #include <stdlib.h>
We are also using the standard library of C++ to perform basic functions like CLS (Clear Screen) to re-modernize the work flow of the LMS.
All of these libraries are used with keeping the Object Orientated Side of our system. 

**File Structure** 
Here’s a list of the file structure of our Learning Management System
-	Main.cpp (Contains all of the C++ code)
-	Users.txt (Stores Admin Credentials)
-	Students_credentails.txt (Stores Students Credentials)
-	Students.txt (Stores students’ details)
-	Courses.txt (Stores students / admin courses details)
-	Check_for_student.txt (Checks if students exist or not)
-	Check_for_loadCourses.txt (Check which courses student has enrolled)
-	AddStudent_counter.txt (Works as a Student Counter)
-	AddCourse_Counter.txt (Works as a Course Counter)

d.	Procedure
As mentioned above our system is based on two modules performing separate tasks. Let’s discuss both separately so we understand how the things work. 
•	Procedure: Admin Side
Once you run the program you are greeted with a welcome screen where you can enter straight into the admin module of our system. You’ll have to use your “username” and “password” in order to access the panel (credentials are stored in “Users.txt” file).

Once you have logged in you’ll again be greeted with a details screen that enlist all of the possible tasks you (admin) can perform.

-	Add Course
-	Update Course
-	Delete Course
-	View All Courses
-	View Courses of a Semester
-	Add Student
-	Update Student
-	Delete Student
-	Register the course for student
-	Unregister the course for student
-	View All students
-	Logout of the system
-	Exit Program

From that you can decide which action to perform. All of them are self-explanatory and also are pretty straight forward.

•	Procedure: Student Module
Once you run the program you are greeted with a welcome screen where this time you will enter straight into the student module of our system. You start off by using your credentials to login (registration number and password) to access the system.

Once you are logged-in, you can see all of the actions you (student) can perform.

-	Press 1 to View Registered Courses
-	Press 2 to logout of the system.
-	Press 3 to Exit.

All of these options are also self-explanatory and you can opt for your desired action and see what happens.
