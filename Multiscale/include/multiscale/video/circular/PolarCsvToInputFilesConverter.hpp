#ifndef CSVTOINPUTFILESCONVERTER_HPP_
#define CSVTOINPUTFILESCONVERTER_HPP_

#include "multiscale/util/NumberIterator.hpp"
#include "multiscale/util/iterator/NumberIteratorType.hpp"

#include <string>
#include <vector>

#define OUTPUT_EXTENSION 		  ".in"
#define OUTPUT_SEPARATOR 		  " "
#define OUTPUT_FILE_SEPARATOR	"_"
#define INPUT_FILE_SEPARATOR	","

#define RADIUS_MIN				    1

#define ERR_NEG_CONCENTRATION "All concentrations must be non-negative.";

using namespace std;

namespace multiscale {

	namespace video {

		class PolarCsvToInputFilesConverter {

			private:

				string inputFilepath;
				string outputFilepath;

				unsigned int nrOfConcentricCircles;
				unsigned int nrOfSectors;
				unsigned int nrOfConcentrationsForPosition;

				unsigned int concentrationsIndex;

				double maximumConcentration;

				NumberIterator* circlesIterator;
				NumberIterator* sectorsIterator;

			public:

				PolarCsvToInputFilesConverter	(string inputFilepath,
											 	 string outputFilepath,
											 	 unsigned int nrOfConcentricCircles,
											 	 unsigned int nrOfSectors,
											 	 unsigned int nrOfConcentrationsForPosition,
											 	 NumberIteratorType numberIteratorType);
				~PolarCsvToInputFilesConverter();

				void convert();

			private:

				void 			initInputFile					(ifstream& fin);
				void			initMaximumConcentration 		(ifstream& fin);
				void	 		initOutputFile					(ofstream& fout, unsigned int index);
				void			initIterators					(NumberIteratorType numberIteratorType);
				void	  		processLine						(string line, unsigned int outputIndex);
				vector<double>  splitLineInConcentrations		(string line);
				void			splitFirstLineInConcentrations	(vector<double>& concentrations,
																 vector<string>& tokens,
																 unsigned int circleIndex);
				void			splitOtherLinesInConcentrations	(vector<double>& concentrations,
																 vector<string>& tokens,
																 unsigned int circleIndex);
				double	  		computeNextPositionConcentration(unsigned int circleIndex,
																 int concentrationIndex,
																 vector<string>& tokens);
				double			computeScaledConcentration	    (string concentration,
																 int circleIndex);
				double			computeConcentrationWrtArea		(double amount,
																 int circleIndex);
				double			computeNormalisedConcentration	(double concentration,
																 int circleIndex);
				void			updateMaximumConcentration		(string& line,
																 double& maximumConcentration);

		};

	};

};

#endif