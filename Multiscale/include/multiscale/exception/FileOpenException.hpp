#ifndef FILEOPENEXCEPTION_HPP
#define FILEOPENEXCEPTION_HPP

#include "multiscale/exception/IOException.hpp"

#include <string>

using namespace std;


namespace multiscale {

    //! Class for representing exceptions when opening a file
    class FileOpenException : public IOException {

        public:

            FileOpenException() {}

            explicit FileOpenException(const string &file, int line, const string &msg)
                : IOException(file, line, msg) {}

            explicit FileOpenException(const string &file, int line, const char *msg)
                : IOException(file, line, msg) {}

    };

};


#endif
