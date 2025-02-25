#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>
#include "auth.h"
#include "process.h"
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

	Process p1(0, 0, 20, 2, 256, false);//ID 1 - arrival time - burst time - priority - memory required - io flag bool
	Process p2(1, 10, 5, 1, 256, false);//ID 2

	cout << "The process of ID: " << p1.getPid() << " is in initial state: " << p1.getState() << endl;// first initial state for p1
	p1.update_state();	//enters ready state - since instance is created in "NEW" so turns to ready 
	cout << "The process of ID: " << p2.getPid() << " is in initial state: " << p2.getState() << endl;//first initial state for p2
	cout << "The process of ID: " << p1.getPid() << " is now in state: " << p1.getState() << endl;
	
	p2.update_state();// ***ID 2 ***enters running state -but wnat to wait
	//p2.update_state();//***ID 2***so now enters waiting state - sincne it hasnt entered yet
	p1.update_state();// enters running state 

	for (int i = 0; i < 10; ++i) // executes 10 times
	{
		p1.execute_time(); // from 20 - 10
		cout << "The process of ID: " << p1.getPid() << " is now in state: " << p1.getState() << ", remaining time: " << p1.getRemaining_time() << endl;
	}

	p1.update_state();// stops running now in waiitng state
	cout << "The process of ID: " << p1.getPid() << " is now in state: " << p1.getState() << endl;
	p1.update_wait_time(5);//waits 5 times - since it will take 5 to finish the ID 2 which has priority
	cout << endl << endl;
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	p2.update_state();//***ID 2*** enters running stage now
	for (int i = 0; i < 5; ++i) // ***ID2** executes 5 times
	{
		p2.execute_time(); // from 5 - 0
		cout << "The process of ID: " << p2.getPid() << " is now in state: " << p2.getState() << ", remaining time: " << p2.getRemaining_time() << endl;
	}
	p2.update_state();
	p2.update_turnaround_time();

	cout << "Process " << p2.getPid() << " final state: " << p2.getState() << endl;
	cout << "Waiting time: " << p2.getWaiting_time() << endl;
	cout << "Turnaround time: " << p2.getTurnaround_time() << endl;


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	p1.update_state();//now back in ready state
	
	p1.update_state();//now we run state
	for (int i = 0; i < 10; ++i)//execute last ten times
	{
		p1.execute_time();
		cout << "The process of ID: " << p1.getPid() << " is now in state: " << p1.getState() << ", remaining time: " << p1.getRemaining_time() << endl;
	}

	p1.update_state();//since time remaining is 0 now its in terminated state
	p1.update_turnaround_time();// updates total time so 5from wait + 20from burst

	cout << "Process " << p1.getPid() << " final state: " << p1.getState() << endl;
	cout << "Waiting time: " << p1.getWaiting_time() << endl;
	cout << "Turnaround time: " << p1.getTurnaround_time() << endl;

	return 0;
