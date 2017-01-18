//
// Created by light on 17-1-10.
//

#include <fstream>
#include <sstream>
#include <iostream>

#include "JSONConfigureFile.h"
#include "IConfigure.h"
#include <utils/utils.h>
using namespace Utils;

bool JSONConfigureFile::readConfigureFile(const char *filename) {
    if(!IConfigureFile::readConfigureFile(filename)){
        return false;
    }

    stringstream sstream;
    sstream << this->m_fileIO.rdbuf();

    return m_config.parse(sstream.str().c_str());
}

const IConfigure *JSONConfigureFile::getConfigure(const char *pointer) {
    return this->m_config.getConfigure(pointer);
}
