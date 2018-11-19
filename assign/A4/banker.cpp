/*
*	banker.cpp*
*
*	Student Name: Evan Loughlin 
*	Student Number: 00503393
*
*	Class: CPSC 457 Winter 2018
*	Instructor: Pavol Federl
*
*	Copyright 2018 - University of Calgary. All rights reserved.
*
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <algorithm>


using namespace std;

class Banker
{

private: 
	int numProc;		// The number of processes
	int numResources;	// The number of resources
	int * available;	// Number of available instances of each resource
	int ** max;		// The max demand each process; e.g., max[i][j] = k
				// means process i needs at most k instances of resources j
	int ** allocation;	// Number of resource instances already allocated
	int ** need;		// Number of resource instances needed by each process

	bool * procActive;	// Activity of each process (1 for active, 0 for terminated)

	bool db = false;	// Debug mode (whether print results is on. Set in main function)
	int processID;		// The PID of the requesting process
	int * request;

public:
	/* Initializing the vectors and matrices for the Banker's Algorithm. 
	* Takes ownership of all arrays 
	*
	* @param avail		The available vector
	* @param m		The max demand matrix
	* @param alloc		The allocation matrix
	* @param p		The number of processes
	* @param r		The number of resources
	*/

	Banker (int * avail, int ** m, int ** alloc, int p, int r) 
	{
		numProc = p;
		procActive = new bool[numProc];
		numResources = r;
		//Setup the available vector, the max matrix, and the allocation matrix
		available = avail;
		max = m;
		allocation = alloc;
		// Initialize the need matrix
		need = new int*[numProc];
		for(int i = 0; i < numProc; i++)
			need[i] = new int[numResources];

		// Fill the need matrix
		for(int i = 0; i < numProc; i++)
		{
			for(int j = 0; j < numResources; j++)
			{
				need[i][j] = max[i][j] - alloc[i][j];
				//cout << need[i][j] << " ";
			}
		//cout << endl;
		}
	}


	/* Destroy the vectors and matrices.
	*/
	~Banker() 
	{
		numProc = 0;
		numResources = 0;

		// Free all allocated memory space
		delete[] available;
		for (int i = 0; i < numProc; i++)
		{
			delete[] need[i];
			delete[] max[i];
			delete[] allocation[i];
		}

		delete[] need;
		delete[] max;
		delete[] allocation;
	}


	/* Check whether it is safe to grant the request
	*  @param pid			The process that is making the request
	*  @param req			The request
	*  @param sequenceOrReason	The safe execution sequence returned by the algorithm
	*				or reason for rejection
	*  @return Whether granting the request will lead to a safe state.
	*/

	bool isSafe (int pid, int * req, string & sequenceOrReason)
	{
		bool safe = false;
		// Array specifying whether the process has been terminated yet.

		processID = pid;
		request = req;

		if(db) {
			cout << "Request: P" << processID << ": < ";
			for(int i = 0; i < numResources; i++)
				cout << request[i] << " ";
			cout << ">\n";
			}

		for(int i = 0; i < numProc; i++)
			procActive[i] = true;

		// Print out beginning state
		if(db) cout << "Beginning State: "<< endl;
		printState();

		// Modify values due to process request.
		for(int i = 0; i < numResources; i++)
		{
			available[i] -= req[i];
			if(available[i] < 0)
			{
				sequenceOrReason = "not enough resources available.";
				return safe;
			}

			allocation[pid][i] += req[i];
			need[pid][i] -= req[i];

			if(allocation[pid][i] > max[pid][i])
			{
				sequenceOrReason = "request is invalid (exceeding declared max for process).";
				return safe;
			}
		}

		if(db) cout << "Request granted:" << endl;
		printState();

		while(!safe)
		{

			// Count the number of remaining processes at beginning of loop.
			int numProcRemainingBeg = 0;
		

			for (int i = 0; i < numProc; i++)
			{
				if(procActive[i])
					numProcRemainingBeg++;

			}


			// Loop to scan top to bottom for the first process which has needs less than available resources
			for(int i = 0; i < numProc; i++)
			{

			bool procCanBeTerminated = false; // If there are enough resources, then terminate.

				if(procActive[i])
				{
					for(int j = 0; j < numResources; j++)
					{
						if(available[j] < need[i][j])
							break;
						else if (j == numResources - 1)
							procCanBeTerminated = true; // If there are enough resources, process can be terminated
					}
					
					// Terminate the process if there are enough resources to do so
					if(procCanBeTerminated)
					{
						procActive[i] = false;
						sequenceOrReason += "P";
						sequenceOrReason += to_string(i);
						if(numProcRemainingBeg > 1)
							sequenceOrReason += ", ";
	
						// Return the process' resources to available stock.
						for(int j = 0; j < numResources; j++)
						{
							need[i][j] = 0;
							available[j] += allocation[i][j];
							allocation[i][j] = 0;
						}

						if(db)
						{
							cout << "Terminating P" << i << " and returning its resources." << endl;
						}
						printState();
						

						break; // Start the scan again from top to bottom

					}

				}

			}


			// Check whether all processes have been terminated
			for(int i = 0; i < numProc; i++)
			{
				if(procActive[i])
					break;
				else if(i == (numProc -1))
					safe = true;			
			}

			// Check number of remaining processes at end of while loop
			int numProcRemainingEnd = 0;
			for (int i = 0; i < numProc; i++)
			{
				if(procActive[i])
					numProcRemainingEnd++;

			}

			// If no process has been terminated for this iteration of while loop, 
			// then no processes exist that can be terminated. The state would be deadlock
			if(numProcRemainingBeg == numProcRemainingEnd)
			{
				sequenceOrReason = "request would result in unsafe state.";
				break; // Break out of while loop.
			} 
			

		} // end of while loop

		return safe;
	} // end of isSafe function

	void printState()
	{
		if(db)
		{
			cout << "-----------STATE------------ " << endl;
			cout << "Available = <";
			for(int i = 0; i < numResources; i++)
				{
				cout << available[i];
				if(i == numResources - 1)
					cout << ">" << endl;
				else
					cout << " ";
				} 

		
			cout << "| Process |  Allocation |  Maximum  |    Need    |" << endl;
			for(int i = 0; i<numProc; i++)
			{	
				cout << "|    P" << i << "   |    "; 			// Process ID

				for(int j = 0; j < numResources; j++)		// Allocation Matrix
					cout << allocation[i][j] << " ";

				cout << "   |   ";

				for(int j = 0; j < numResources; j++)		// Maximum Matrix
					cout << max[i][j] << " ";

				cout << "  |    ";

				for(int j = 0; j < numResources; j++)		// Need Matrix
					cout << need[i][j] << " ";

				cout << "  |  ";

				if(procActive[i])
					cout << "ACTIVE";
				else
					cout <<"INACTIVE";

				cout << "\n";
			}
		
		cout << "\n";

		}
		
	

	}

	void setDebug(bool x)
	{
		db = x;
		cout << "Debug mode active!" << endl;
	}
};


int main (int argc, char * const argv[])
{
	ifstream config;		// Configuration file
	string conffile;		// The configuration file name
	int numProc;			// The number of processes
	int numResources;		// The number of resources
	string sequenceOrReason;	// The execution sequence returned by the Banker's Algorithm
	int i, j, index;		// Indices for the vectors and matrices
	int pid;			// The ID of the process that is making the request
	string reqStr;			// The request vector in string format

	bool db = false;		// Debug mode. Prints out results. (Turn on using a 3rd arg in cmd line)

	// Read in the config file name from the command-line arguments	
	if(argc < 2) {
		cout << "Usage: banker <config file>\n";
		return 0;
	}
	else {
		conffile = argv[1];
	}

		

	// Open the file
	config.open(conffile.c_str());

	// Get the number of processes and the number of resources
	string line, var, equal;		// Strings for parsing lines in cfg. file
	getline(config, line);
	istringstream iss(line);
	iss >> var >> equal >> numProc;		// Get the number of processes
	iss.clear();

	getline(config, line);
	iss.str(line);
	iss >> var >> equal >> numResources;	// Get the number of resources
	iss.clear();

	// Create the available vector, the max matrix, and the allocation
	// matrix according to the number of processes and the number of resources

	int * available = new int[numResources];
	int ** max = new int*[numProc];
	int ** allocation = new int*[numProc];
	for(int i = 0; i < numProc; i++)
	{
		max[i] = new int[numResources];
		allocation[i] = new int[numResources];
	}

	// Get the available vector
	getline(config, line);
	replace(line.begin(), line.end(), '<', ' '); 	// Remove "<" and ">"
	replace(line.begin(), line.end(), '>', ' ');
	iss.str(line);
	iss >> var >> equal;
	for (j = 0; j < numResources; j++) 	// Read in the "available" vector
		iss >> available[j];
	iss.clear();

	// Get the max matrix and the allocation matrix
	for (i = 0; i < numProc; i++)
	{
		getline(config, line);
		replace(line.begin(), line.end(), '<', ' ');
		replace(line.begin(), line.end(), '>', ' ');
		iss.str(line);
		iss >> var;
		index = atoi(&var.at(1)); 		// Get the process ID

		if (index < 0 || index >= numProc)
		{
			cerr << "Invalid process ID: " << var << endl;
			return 0;
		}

		// Get the number of resources allocated to process "index".
		for (j = 0; j < numResources; j++)
			iss >> allocation[index][j];

		// Get the max allocation to process "index".
		for (j = 0; j < numResources; j++)
			iss >> max[index][j];

		iss.clear();
	}

	// Get the request vector
	int * request = new int[numResources];
	getline(config, line);
	reqStr = line.substr(line.find('<'), line.find('>') - line.find('<') + 1);

	replace(line.begin(), line.end(), '<', ' ');
	replace(line.begin(), line.end(), '>', ' ');
	iss.str(line);

	iss >> var >> pid >> equal;

	for (j = 0; j < numResources; j++) // Read in the "request" vector
		iss >> request[j];

	iss.clear();

	// Check the request using the Banker's algorithm.
	Banker * banker = new Banker(available, max, allocation, numProc, numResources);
	
	if(argc == 3)
		banker -> setDebug(true);

	if (banker -> isSafe(pid, request, sequenceOrReason))
		cout << "Grant request " << reqStr << " from P" << pid << ".\n" << "Sequence: " << sequenceOrReason << ".\n";
	else
		cout << "Reject request " << reqStr << " from P" << pid << ".\n" << "Reason: " << sequenceOrReason << "\n";

}
