#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <string>
using namespace std;

class Process
{
private:
	int pid, arrival_time, burst_time, priority,
		remaining_time, waiting_time, turnaround_time,
		memory_required;
	bool io_operations;
	string state;
public:
	Process(int pid, int arrival_time, int burst_time, int priority, int memory_required, bool io_operations);

	void update_state();

	void execute_time();

	void update_wait_time(int add_time);

	void update_turnaround_time();

	int getPid() const;
	int getArrival_time() const;
	int getBurst_time() const;
	int getPriority() const;
	int getRemaining_time() const;
	int getWaiting_time() const;
	int getTurnaround_time() const;
	int getMemory_required() const;
	bool IO_operations() const;
	string getState() const;

	void setWaiting_time(int time);
	void setTurnaround_time(int time);
};

#endif
