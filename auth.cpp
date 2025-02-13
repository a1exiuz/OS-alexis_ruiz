#include "auth.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void authenticateUser()
{
	string username, password, file_username, file_password;//variables for input username and function , and for file reading 
	bool var_exit = false;//used for being able to exit whenever succeful login occurs				         //usernames and passwords

	do   //do while to continue asking to input password if failed login
	{

		fstream file("authFile.txt", ios::in);//| ios::out);// fstream to read and write to file (i wanted or want to implement creating a new username and password

		if (file.fail())//if cannot open file exit program 
		{
			cout << "Start up Failed! Please try again later.";//simulate something wrong happened and need to restart
			exit(1);
		}
		cout << "Enter username: ";
		cin >> username;
		cout << "Enter password: ";
		cin >> password;

		while (file >> file_username >> file_password)// read from file in a way that username and password are in the same line seperated by a space and keep reading until
		{																																			//no more line to read
			if ((file_username == username) && (file_password == password))//if both credentials match u can login
			{
				cout << "Successful Login" << endl;
				file.close();
				var_exit = true;//set to true to exit loop
			}
		}

		if ((file_username != username) || (file_password != password))//if either is wrong ask to try again
		{
			file.close();//closing the file so it can be reopoened again to start from the begging of text file.
			cout << "Wrong username or password, Try again please.\n";
			cout << endl;
		}

	} while (var_exit != true);//exit loop when login is successful

}