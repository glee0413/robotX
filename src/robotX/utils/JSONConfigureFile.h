//
// Created by light on 17-1-10.
//

#ifndef ROBOTX_JSONCONFIGUREFILE_H
#define ROBOTX_JSONCONFIGUREFILE_H

#include <string>
#include <thirdsrc/include/rapidjson/document.h>
#include <utils/macro.h>
#include "IConfigure.h"
#include "IConfigureFile.h"
#include "JSONConfigure.h"

using namespace rapidjson;
using namespace std;

namespace Utils{

    class JSONConfigureFile : public IConfigureFile{
    public:
        JSONConfigureFile() {}

        virtual ~JSONConfigureFile(){};

        bool readConfigureFile(const char *filename) override;

        const IConfigure *getConfigure(const char *pointer = nullptr) override;

    private:
        JSONConfigure m_config;
    private:
        DISALLOW_COPY_AND_ASSIGN(JSONConfigureFile);
    };
}




#endif //ROBOTX_CONFIGURE_H
