#ifndef ATTACH_H
#include "Attach.h"
#endif // !ATTACH_H

// The aim of this project is to provide an executable that can be run from inside LabVIEW, or anywhere really
// It should take inputs from cmd line and perform some sort of operations
// Inputs should be strings to represent file name and perhaps some other parameters
// R. Sheehan 29 - 10 - 2015

int main(int argc, char *argv[])
{
	// run program from command line
	// assuming that inputs are going to be nsteps, xlower, xupper, + other arguments
	try {

		if (argc > 3) {
			// List off the input parameters
			// Program needs 4 or more parameters to run, remember that the name of the program is also considered a parameter
			// argv[0] = program name

			std::cout << "Name of the program is " << argv[0] << "\n";
			std::cout << argc - 1 << " parameters were input into the program\n";
			for (int count = 1; count < argc; count++) {
				std::cout << "argv[" << count << "] = " << argv[count] << "\n";
			}
			std::cout << "\n";

			// Run the calculation based on the input parameters
			// calculation_type = argv[1]
			// dir name = argv[2]
			// xdata = argv[3]
			// ydata = argv[4]

			int nsteps = atoi(argv[1]); // extract number of steps from cmd line input
			double xlower = atof(argv[2]); // extract xlow from cmd line input
			double xhigh = atof(argv[3]); // extract xhigh from cmd line input

		}
		else {
			throw std::invalid_argument("Not enough arguments were input\n");
		}

	}
	catch (std::invalid_argument &e) {
		std::cerr << e.what();
	}

	return 0;
}
