// sensemaker1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>


bool directoryExists (std::string dir);
void readDirectoryFiles (std::string dir, std::vector<std::string> & files);
bool scanFastloaderWay (std::string & fpath, int num_threads = 1);

void showHelp()
{
	std::cout << std::endl << "Command line format: sensemaker <intensity directory> <label directory> <output directory>" << std::endl;
}


int main(int argc, char** argv)
{
	if (argc != 4)
	{
		showHelp();
		return 1;
	}

	std::string dirIntens = argv[1],
		dirLabels = argv[2], 
		dirOut = argv [3];

    std::cout << 
		"Using <intensity data directory> = " << dirIntens << 
		" <labels data directory> = " << dirLabels << 
		" <output directory> = " << dirOut << std::endl; 

	// Check the directories
	if (! directoryExists (dirIntens))
	{
		std::cout << "Error: " << dirIntens << " is not a directory" << std::endl;
		return 1;
	}

	if (!directoryExists (dirLabels))
	{
		std::cout << "Error: " << dirLabels << " is not a directory" << std::endl;
		return 1;
	}

	if (!directoryExists(dirOut))
	{
		std::cout << "Error: " << dirOut << " is not a directory" << std::endl;
		return 1;
	}

	// Scan files
	std::vector <std::string> intensFiles, labelFiles;
	readDirectoryFiles (dirIntens, intensFiles);
	readDirectoryFiles (dirLabels, labelFiles);

	// Check if the dataset is meaningful
	if (intensFiles.size() == 0 || labelFiles.size() == 0)
	{
		std::cout << "No intensity and/or label files to process" << std::endl;
		return 1;
	}	
	if (intensFiles.size() != labelFiles.size())
	{
		std::cout << "The number of intensity directory files (" << intensFiles.size() << ") should match the number of label directory files (" << labelFiles.size() << ")" << std::endl;
		return 1;
	}

	// Iterate and read TIFF data
	for (std::string & fpath : intensFiles)
	{
		std::cout << "digesting file " << fpath << std::endl;
		bool ok = scanFastloaderWay (fpath, 8 /*threads*/);
	}

	return 0;
}

