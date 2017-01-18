//
// Created by light on 17-1-16.
//

#ifndef ROBOTX_ICONFIGUREFILE_H
#define ROBOTX_ICONFIGUREFILE_H

#include <fstream>
#include <utils/IConfigure.h>
using namespace std;

namespace Utils {
    class IConfigureFile {
    public:
        IConfigureFile();
        virtual ~IConfigureFile();

        virtual bool readConfigureFile(const char* filename);
        virtual const IConfigure* getConfigure(const char* pointer = nullptr) = 0;

    protected:
        ifstream m_fileIO;
    private:
        DISALLOW_COPY_AND_ASSIGN(IConfigureFile);
    };
}

#endif //ROBOTX_ICONFIGUREFILE_H
