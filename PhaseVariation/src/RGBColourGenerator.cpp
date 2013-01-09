#include "../include/RGBColourGenerator.hpp"

#include <cmath>
#include <iomanip>
#include <cassert>
#include <sstream>

using namespace std;
using namespace multiscale;

// Static members definition
double RGBColourGenerator::red = 0;
double RGBColourGenerator::green = 0;
double RGBColourGenerator::blue = 0;


// Generate the colour of the concentration having given the minimum and maximum
// possible value for a concentration
string RGBColourGenerator::generate(double concentrationMin, double concentrationMax, double concentration) {
	concentration = (concentration - concentrationMin)/(concentrationMax - concentrationMin);

	double hue 		  = HUE_MIN + (concentration * (HUE_MAX - HUE_MIN));
	double saturation = SATURATION;
	double value	  = VALUE;

	return convertHSVToRGB(hue, saturation, value);
}

string RGBColourGenerator::convertHSVToRGB(double hue, double saturation, double value) {
	assert((hue >= 0) && (hue < 360));

	double chroma = value * saturation;
	int    huePrime = hue / 60;

	double X = chroma * (1 - abs((huePrime % 2) - 1));
	double m = value - chroma;

	computeRGBValues(huePrime, X, chroma, m);

	return convertRGBToString();
}

void RGBColourGenerator::computeRGBValues(int    huePrime, double X,
		                                  double chroma,   double m) {
	switch (huePrime) {
		case 0:
			red = chroma;
			green = X;
			blue = 0;
			break;

		case 1:
			red = X;
			green = chroma;
			blue = 0;
			break;

		case 2:
			red = 0;
			green = chroma;
			blue = X;
			break;

		case 3:
			red = 0;
			green = X;
			blue = chroma;
			break;

		case 4:
			red = X;
			green = 0;
			blue = chroma;
			break;

		case 5:
			red = chroma;
			green = 0;
			blue = X;
			break;
	}

	red += m;
	green += m;
	blue += m;
}

string RGBColourGenerator::convertRGBToString() {
	ostringstream stringStream;

	stringStream << "#";
	stringStream << std::setfill('0') << std::setw(2) << std::hex << (int) (red * 255);
	stringStream << std::setfill('0') << std::setw(2) << std::hex << (int) (green * 255);
	stringStream << std::setfill('0') << std::setw(2) << std::hex << (int) (blue * 255);

	return stringStream.str();
}
