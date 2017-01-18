//
// Created by light on 17-1-16.
//

#include "IConfigureFile.h"

Utils::IConfigureFile::IConfigureFile() {

}

Utils::IConfigureFile::~IConfigureFile() {
    if(this->m_fileIO.is_open()){
        this->m_fileIO.close();
    }
}

bool Utils::IConfigureFile::readConfigureFile(const char *filename) {
    m_fileIO.open(filename,ios::in);
    return m_fileIO.is_open();
}


