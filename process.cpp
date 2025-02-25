#include <iostream>
#include <string>
#include <cmath>
#include "process.h"
using namespace std;

	Process::Process(int pid, int arrival_time, int burst_time,int priority, int memory_required, bool io_operations) 
		:pid(pid), arrival_time(arrival_time),burst_time(burst_time), priority(priority), remaining_time(burst_time), waiting_time(0), turnaround_time(0), 
		memory_required(memory_required), io_operations(io_operations), state("NEW"){} //initializing all variables

	void Process::update_state()// updating the state of the proccess it starts at new when created
	{							//it goes into a ready state -when in ready if called again it will go into a running state and if more than 0 it can go to waiting -
		if (state == "NEW")					// and from waiting it can go back to ready until terminated when remaining time less than 0
		{
			state = "READY";
		}
		else if (state == "READY")
		{
			state = "RUNNING";
		}
		else if (state == "RUNNING" && remaining_time > 0)
		{
			state = "WAITING";
		}
		else if (state == "WAITING")
		{
			state = "READY";
		}
		else if (remaining_time == 0)
		{
			state = "TERMINATED";
		}
		
	}

	void Process::execute_time() 
	{
		if (remaining_time > 0) // if remaminng time greater than 0 it will decrement by one
			remaining_time -= 1;
		if (remaining_time < 0)//so it doesnt go below 0
			remaining_time = 0;
	}

	void Process::update_wait_time(int add_time)
	{
		waiting_time += add_time; //manually add time to the wait time
	}

	void Process::update_turnaround_time() // it will add the waiting time and burst time to find out the total turnaround time -
	{										
		turnaround_time = (waiting_time + burst_time);
	}

	int Process::getPid() const
	{
		return pid;
	}
	int Process::getArrival_time() const
	{
		return arrival_time;
	}
	int Process::getBurst_time() const
	{
		return burst_time;
	}
	int Process::getPriority() const
	{
		return priority;
	}
	int Process::getRemaining_time() const
	{
		return remaining_time;
	}
	int Process::getWaiting_time() const
	{
		return waiting_time;
	}
	int Process::getTurnaround_time() const
	{
		return turnaround_time;
	}
	int Process::getMemory_required() const
	{
		return memory_required;
	}
	bool Process::IO_operations() const
	{
		return io_operations;
	}
	string Process::getState() const
	{
		return state;
	}

	void Process::setWaiting_time(int time)
	{
		waiting_time = time;
	}
	void Process::setTurnaround_time(int time)
	{
		turnaround_time = time;
	}

