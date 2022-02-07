#include <iostream>
// cmath is needed for pow()
#include <cmath>

// getopt library for argument parsing
#include <getopt.h>

/* A tire is ROUGHLY a torus, which is basically just a cylinder stretched around a circle
 * We can approximately calculate the volume of a tire by treating it like a torus.
 * 
 * The formula for a torus is as follows: V = (pi*r^2)(2*pi*R),
 * where V is volume, r is the minor radius, and R is the major radius.
 *
 * This can be broken down to V = pi * r^2 * 2 * pi * R, which is what we will use
 *
 * The minor radius is the radius of the stretched cylinder, and the major radius
 * is the radius of the circle the cylinder is stretched around.
 */

/* BROKEN STUFF:
 * - passing two of the same arguments sets one radius to 0
 * - I will find more bugs, I am sure...
 */

// FUNCTIONS

float CalculateTorus(float r, float R)
{
	const float pi = 3.14; // this program doesn't need to be precise, so this suffices!
	float volume = 0.0; // initialize volume
	volume = pi * pow( r, 2 ) * 2 * pi * R;
	return volume;

}

void PrintHelp()
{
	std::cout <<
		"USAGE:\n"
		"--minor-radius <minor radius> | -r <minor radius>\n"
		"--major-radius <major radius> | -R <major radius>\n"
		"--debug | -d\n";
	exit(1);
}
// MAINLINE LOGIC
int main(int argc, char	**argv)
{

	// DECLARATIONS
	const int err_bad_arg_num = 2;
	float r_minor = 0;
	float R_major = 0;

	// flag to indicate if debug is on
	static int debug_flag;
	
	int c;
	
	// user needs to pass arguments, so verify this
	if (argc == 1)
	{
		PrintHelp();
		exit(1);
	}

	while (1)
	{
		// build longopts structure
		static const struct option long_options[] =
		{
			{"minor-radius", required_argument, 0, 'r'},
			{"major-radius", required_argument, 0, 'R'},
			{"debug", no_argument, &debug_flag, 1},
			{"help", no_argument, 0, 'h'},
			{0, 0, 0, 0}
		};
		int option_index = 0;

		c = getopt_long (argc, argv, "r:R:d", long_options, &option_index);

		if (c == -1)
			break;

		switch (c)
		{
			case 'r':
				try
				{
					r_minor = std::stof(optarg);
				}
				catch(const std::exception& e)
				{}
				break;
			case 'R':
				try
				{
					R_major = std::stof(optarg);
				}
				catch(const std::exception& e)
				{}
				break;
			case 'h':
			case '?':
			default:
				PrintHelp();
				break;
		}
	}
		// debug
		std::cout << "R_major is: " << R_major << std::endl;
		std::cout << "r_minor is: " << r_minor << std::endl;
		// end debug

		if (R_major > r_minor) // the major radius needs to be larger than the minor radius
		{
			std::cout << CalculateTorus(r_minor, R_major) << std::endl;
		}
		else
		{
			// it makes more sense to have this print the help, like every other incorrect usage,
			// as opposed to making it print a new error message...
			PrintHelp();
			exit(1);
		}
	return 0;
}
