#include <iostream>
#include <thread>
#include <chrono>
#include "auth.h"
using namespace std;

int main()
{
	
	cout << "System Booting up...\n";
	this_thread::sleep_for(chrono::seconds(2));//predefine functions to be able to simulate delay
	cout << "Loading kernel...\n";
	this_thread::sleep_for(chrono::seconds(2));
	cout << "Staring system services...\n";
	this_thread::sleep_for(chrono::seconds(2));
	cout << "Succesfull boot up ! \n";
	cout << endl;

	authenticateUser();

	return 0;
}