/* CPSC 457 - Operating Systems
* Evan Loughlin
* UCID: 00503393
* Professor: Dr. Pavol Federl
* TA: Sina Keshvadi
* Tutorial Section: T04
* Date: Mar 28, 2018
*
* pagesim.cpp:
* A simulator, which compares three different algorithms for page replacement.
*
*     1) Optimal: A (non-implementable) optimal algorithm which always removes
*        the frame which has the longest time before being needed again.
*
*     2) Least Recently Used: An algorithm which keeps a linked list of frames.
*        When a frame needs to be removed from physical memory, the frame at the 
*        lowest position in the list gets removed.
*
*     3) Clock: A circular linked list, which is similar to FIFO, with Second Chance,
*        except that a pointer in the circular list moves from one item to the next, 
*        removing the next one that has a certain "age" bit set.
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


using namespace std;

int inf = 999;


class Frame
{
private: 
	int id; //ID of the frame
	int nextRequired; // Next time the frame will be required (Optimal)
	int recentlyUsed; // Last time frame was used (LRU)
	int R; // Bit used in Clock Algorithm

public: 
	Frame(int a)
	{
		id = a;
		nextRequired = inf;
		recentlyUsed = 0;
		R = 1;
	}

	int getID()
	{
		return id;
	}

	int getNextRequired()
	{
		return nextRequired;
	}

	int getRecentlyUsed()
	{
		return recentlyUsed;
	}

	int getR()
	{
		return R;
	}

	void setNextRequired(int val)
	{
		nextRequired = val;
	}

	void setRecentlyUsed(int val)
	{
		recentlyUsed = val;
	}

	void setR(int val)
	{
		R = val;
	}
};

// Node for linked list data structures.
struct node
{
	Frame * frame;
	struct node * next;
};

class PhysMem
{
private: 
	vector<Frame *> memSlots; // Physical memory slots (frames)
	vector<Frame *> framesToLoad; // Frames waiting to be loaded
	vector<Frame *> frames; // All unique frames

public:
	PhysMem(int memSize, vector<Frame *> toLoad)
	{
		for(int i = 0; i < memSize; i++) // Instantiate as empty = "-1"
			memSlots.push_back(new Frame(-1));

		framesToLoad = toLoad;
		
		// Instantiate list of unique frames
		for(int i = 0; i < framesToLoad.size(); i++)
		{
			bool alreadyExists = false;
			for(int j = 0; j < frames.size(); j++)
			{
				if(framesToLoad[i] -> getID() == frames[j] -> getID())
					alreadyExists = true;
			}

			if(!alreadyExists)
				frames.push_back(framesToLoad[i]);
		}

		// Set the nextRequired info for each frame
		updateNextRequired();
	}

	void optimal()
	{
		cout << "Optimal:" << endl;
		int numContextSwitches = 0;
		/*
		cout << "Frames: ";
		printFrames();
		cout << "Initial Memory Slots: ";
		printMemSlots();
		cout << "Initial Frames to Load: ";
		printFramesToLoad();
		printNextRequiredStatus();
		*/

		while(framesToLoad.size() > 0)
		{
			//cout << "----------------------" << endl;


			// Determine if any empty slots exist, or if current frame already in memory.
			bool contextSwitchNeeded = true;
			for(int i = 0; i < memSlots.size(); i++)
				if(memSlots[i] -> getID() == framesToLoad[0] -> getID())
					contextSwitchNeeded = false;

			if(contextSwitchNeeded)
				numContextSwitches++;
			
			int indexToRemove = nextRequiredToRemove();
			memSlots[indexToRemove] = framesToLoad[0];
			framesToLoad.erase(framesToLoad.begin());
			updateNextRequired();

			/*
			cout << "Remaining Frames to Load: ";
			printFramesToLoad();
			cout << "Memory Slots: ";
			printMemSlots();
			cout << "Context Switches: " << numContextSwitches << endl;
			printNextRequiredStatus();
			*/
		}


		cout << "   - frames: ";
		printMemSlots();
		cout << "   - page faults: " << numContextSwitches << endl;


	}

	void lru()
	{
		cout << "LRU:" << endl;
		int numContextSwitches = 0;

	}

	void clock()
	{
		cout << "Clock:" << endl;
		int numContextSwitches = 0;
		
	}

private:
	void updateNextRequired()
	{
		for(int i = 0; i < frames.size(); i++)
		{
			int req = inf;
			for(int j = 0; j < framesToLoad.size(); j++)
			{
				if(frames[i] -> getID() == framesToLoad[j] -> getID())
				{
					req = j;
					break;
				}
			}

			frames[i] -> setNextRequired(req);
		}

		for(int i = 0; i < memSlots.size(); i++)
		{
			int req = inf;
			for(int j = 0; j < framesToLoad.size(); j++)
			{
				if(memSlots[i] -> getID() == framesToLoad[j] -> getID())
				{
					req = j;
					break;
				}
			}

			memSlots[i] -> setNextRequired(req);
		}
	}

	// Returns the memSlots index of the Frame which has should be removed
	int nextRequiredToRemove()
	{
		// If any index has ID "-1", this means slot is empty. Return this first.
		for(int i = 0; i < memSlots.size(); i++)
		{
			if(memSlots[i] -> getID() == -1)
			{
				//cout << "Filling empty slot!" << endl;
				return i;
			}
				
			if(memSlots[i] ->getID() == framesToLoad[0] -> getID())
			{		
				//cout << "Frame already in memory. No page fault!" << endl;
				return i;
			}
		}
		
		
		// Otherwise, return the index of the frame with the largest "nextRequired" value.
		int maxIndex = 0;
		for(int i = 0; i < memSlots.size(); i++)
		{
			if(memSlots[i] -> getNextRequired() > memSlots[maxIndex] -> getNextRequired())
				maxIndex = i;
		}
		return maxIndex;
	}

	void printFramesToLoad()
	{
		for(int i = 0; i < framesToLoad.size(); i++)
			cout << framesToLoad[i] -> getID() << " ";

		cout << endl;
	}

	void printFrames()
	{
		for(int i = 0; i < frames.size(); i++)
			cout << frames[i] -> getID() << " ";

		cout << endl;
	}

	void printNextRequired()
	{
		for(int i = 0; i < frames.size(); i++)
			cout << frames[i] -> getNextRequired() << " ";

		cout << endl;
	}

	void printMemSlots()
	{
		for(int i = 0; i < memSlots.size(); i++)
			cout << memSlots[i] -> getID() << " ";

		cout << endl;

	}

	void printNextRequiredStatus()
	{
		cout << "(Frame ID, NextRequired)" << endl;		
		for(int i = 0; i < frames.size(); i++)
			cout << "(" << frames[i] -> getID() << ", " << frames[i] -> getNextRequired() << ")" << endl;
	}


};





int main(int argc, char* argv[])
{
	// Parse command line arguments
	if(argc != 3)
	{
		cerr << "Error: incorrect usage. Try \"./pagesim <number of frames> <filename>\"" << endl;
		return -1;
	}

	int memorySize = atoi(argv[1]);
	string fileName = argv[2];
	vector<Frame *> framesToLoad;

	// Read file
	ifstream inFile;
	inFile.open(fileName);	
	if(inFile.is_open())
	{
		int num;
		while(inFile >> num)
		{
			framesToLoad.push_back(new Frame(num));
		}
		inFile.close();
	}
	else 
	{
		cerr << "Error reading file: " << fileName << endl;
		return -1;
	}

	PhysMem p1 = PhysMem(memorySize, framesToLoad);
	p1.optimal();

	PhysMem p2 = PhysMem(memorySize, framesToLoad);
	p2.lru();

	PhysMem p3 = PhysMem(memorySize, framesToLoad);
	p3.clock();
	

}
