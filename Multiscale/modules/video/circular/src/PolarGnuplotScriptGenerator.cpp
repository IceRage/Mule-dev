#include "multiscale/video/circular/PolarGnuplotScriptGenerator.hpp"
#include "multiscale/util/StringManipulator.hpp"

#include <cassert>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using namespace multiscale::video;
using namespace std;


void PolarGnuplotScriptGenerator::generateScript(const vector<AnnularSector> &annularSectors,
                                                 double simulationTime,
                                                 const string &outputFilepath) {
    ofstream fout((outputFilepath + GNUPLOT_EXTENSION), std::ios_base::trunc);

    assert(fout.is_open());

    generateHeader(fout, outputFilepath, simulationTime);
    generateBody  (annularSectors, fout);
    generateFooter(fout);

    fout.close();
}

void PolarGnuplotScriptGenerator::generateHeader(ofstream &fout, const string &outputFilepath, double simulationTime) {
    ifstream fin(HEADER_IN);

    assert(fin.is_open());

    string outputFilename = StringManipulator::filenameFromPath(outputFilepath);

    outputHeader(fin, outputFilename, simulationTime, fout);

    fin.close();
}

void PolarGnuplotScriptGenerator::generateBody(const vector<AnnularSector> &annularSectors, ofstream &fout) {
    ifstream fin(CONTENT_IN);

    assert(fin.is_open());

    string contentTemplate = readContentTemplate(fin);

    outputContent(annularSectors, contentTemplate, fout);

    fin.close();
}

void PolarGnuplotScriptGenerator::generateFooter(ofstream &fout) {
    ifstream fin(FOOTER_IN);

    assert(fin.is_open());

    outputFooter(fin, fout);

    fin.close();
}

void PolarGnuplotScriptGenerator::outputHeader(ifstream &fin, const string &outputFilename, double simulationTime, ofstream &fout) {
    string line;

    while (getline(fin, line)) {
        line = StringManipulator::replace(line, REPLACE_HEADER_FILENAME, outputFilename);
        line = StringManipulator::replace(line, REPLACE_HEADER_SIM_TIME, StringManipulator::toString<double>(simulationTime));

        fout << line << endl;
    }

    fout.flush();
}

void PolarGnuplotScriptGenerator::outputContent(const vector<AnnularSector> &annularSectors, const string &contentTemplate, ofstream &fout) {
    int index = annularSectors.size();

    for (vector<AnnularSector>::const_iterator it = annularSectors.begin(); it != annularSectors.end(); it++) {
        string content = contentTemplate;

        content = StringManipulator::replace(content, REPLACE_CONTENT_INDEX, StringManipulator::toString<int>(index--));
        content = StringManipulator::replace(content, REPLACE_CONTENT_RADIUS, StringManipulator::toString<double>((*it).getEndingRadius()));
        content = StringManipulator::replace(content, REPLACE_CONTENT_START_ANGLE, StringManipulator::toString<double>((*it).getStartingAngle()));
        content = StringManipulator::replace(content, REPLACE_CONTENT_END_ANGLE, StringManipulator::toString<double>((*it).getEndingAngle()));
        content = StringManipulator::replace(content, REPLACE_CONTENT_CONCENTRATION, StringManipulator::toString<double>((*it).getConcentration()));

        fout << content << endl;
    }

    fout.flush();
}

void PolarGnuplotScriptGenerator::outputFooter(ifstream &fin, ofstream &fout) {
    string line;

    while (getline(fin, line)) {
        fout << line << endl;
    }

    fout.flush();
}

string PolarGnuplotScriptGenerator::readContentTemplate(ifstream &fin) {
    ostringstream stringStream;
    string line;

    while (getline(fin, line)) {
        stringStream << line << endl;
    }

    return stringStream.str();
}


// Constants
const string PolarGnuplotScriptGenerator::HEADER_IN       = "/home/ovidiu/Repositories/git/multiscale/Multiscale/config/video/circular/header.in";
const string PolarGnuplotScriptGenerator::CONTENT_IN      = "/home/ovidiu/Repositories/git/multiscale/Multiscale/config/video/circular/content.in";
const string PolarGnuplotScriptGenerator::FOOTER_IN       = "/home/ovidiu/Repositories/git/multiscale/Multiscale/config/video/circular/footer.in";

const string PolarGnuplotScriptGenerator::REPLACE_HEADER_FILENAME         = "OUTPUT_FILENAME";
const string PolarGnuplotScriptGenerator::REPLACE_HEADER_SIM_TIME         = "OUTPUT_SIM_TIME";

const string PolarGnuplotScriptGenerator::REPLACE_CONTENT_INDEX           = "OBJ_INDEX";
const string PolarGnuplotScriptGenerator::REPLACE_CONTENT_RADIUS          = "OBJ_END_RADIUS";
const string PolarGnuplotScriptGenerator::REPLACE_CONTENT_START_ANGLE     = "OBJ_START_ANGLE";
const string PolarGnuplotScriptGenerator::REPLACE_CONTENT_END_ANGLE       = "OBJ_END_ANGLE";
const string PolarGnuplotScriptGenerator::REPLACE_CONTENT_CONCENTRATION   = "OBJ_CONCENTRATION";

const string PolarGnuplotScriptGenerator::GNUPLOT_EXTENSION  = ".plt";