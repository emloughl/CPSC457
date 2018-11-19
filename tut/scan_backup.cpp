// CPSC 457 - Operating Systems
// Assignment 2
// Feb 8, 2018
// University of Calgary
// Evan Loughlin
// UCID: 00503393

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iterator>
#include <vector>
#include <fstream>
#include <sys/stat.h>

#define MAX_LEN 512

/**
 * Get the size of a file.
 * @return The filesize, or 0 if the file does not exist.
 */
size_t getFilesize(const char* filename) 
{
    struct stat st;
    if(stat(filename, &st) != 0) {
        return 0;
    }
    return st.st_size;   
}


using namespace std;

int main(int argc, char ** argv)
{

// Read command line arguments:
int N = stoi(argv[2]);
string suffix = argv[1];

char buffer[MAX_LEN];
long length;

// Build string for system() command:
string cmd = "find . -type f -name \"*." + suffix + "\" | head -1000 > a2temp.txt";
const char * c = cmd.c_str();

// Open file based on system command, saving result into a2temp.txt:
system(c);

std::ifstream file("a2temp.txt");
std::string line;

vector<string> filenames;
filenames.clear();

// Place contents of a2temp.txt into vector of strings.
int num_files = 0;
while(getline(file, line))
{
filenames.push_back(line);
num_files++;
}

if (num_files < N)
	N = num_files;


// Get the filesizes, and place into vector.
vector<int> filesizes;
int k;
struct stat st;
for(k = 0; k < filenames.size(); k++)
{
	const char * c = filenames.at(k).c_str();
	int s = getFilesize(c);
	filesizes.push_back(s);
}

vector<int> sortedFilesizes;
vector<string> sortedFilenames;


// Sort the vectors based on size (at most N)
int i, j;
for(i = 0; i < N; i++)
{
 int index_max_elem = 0;

	// Inner loop to find the index of the largest file
	for(j = 0; j < filenames.size(); j++)
	{
	if (filesizes.at(j) > filesizes.at(index_max_elem))
		index_max_elem = j;
	}

sortedFilenames.push_back(filenames.at(index_max_elem));
sortedFilesizes.push_back(filesizes.at(index_max_elem));
filesizes.at(index_max_elem) = 0;
}


// Print out the contents of the sorted strings and files sizes:
int sum = 0;
for (i = 0; i < sortedFilenames.size() && i < N; i++)
{
	cout << sortedFilenames.at(i) << "\t" << sortedFilesizes.at(i) << endl;
	sum += sortedFilesizes.at(i);
}

cout << "Total size: " << sum << endl;

return 0;
}
