//
// Created by light on 17-1-16.
//

#ifndef ROBOTX_JSONCONFIGURE_H
#define ROBOTX_JSONCONFIGURE_H

#include <thirdsrc/include/rapidjson/document.h>
#include "IConfigure.h"

using namespace rapidjson;
using namespace std;

namespace Utils {
    class JSONConfigure : public IConfigure{
    public:
        JSONConfigure();
        virtual ~JSONConfigure();

        bool parse(const char *stream) override;
        IConfigure *getConfigure(const char *key) override;
        const char* getString(const char* key) const override;
    private:
        Document m_jsonDoc;
        Value* m_jsonValue;
    };
}

#endif //ROBOTX_JSONCONFIG_H
