#include "multiscale/util/StringManipulator.hpp"

#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>

using namespace multiscale;


string StringManipulator::filenameFromPath(const string &filepath) {
    unsigned int position = filepath.find_last_of(DIR_SEPARATOR);

    if (position != string::npos) {
        return filepath.substr(position + 1, string::npos);
    }

    return filepath;
}

string StringManipulator::replace(const string &initialString, const string &replaceWhat, const string &replaceWith) {
    size_t index = initialString.find(replaceWhat);
    string initialStringCopy = initialString;

    while (index != string::npos) {
        initialStringCopy.replace(initialStringCopy.find(replaceWhat), replaceWhat.length(), replaceWith);

        index = initialStringCopy.find(replaceWhat);
    }

    return initialStringCopy;
}

vector<string> StringManipulator::split(const string &initialString, const string &delimiter) {
    vector<string> tokens;
    string initialStringCopy = initialString;

    return boost::split(tokens, initialStringCopy, boost::is_any_of(delimiter));
}


// Constants
const char StringManipulator::DIR_SEPARATOR = '/';