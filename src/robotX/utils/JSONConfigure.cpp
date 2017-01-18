//
// Created by light on 17-1-16.
//

#include "JSONConfigure.h"
#include <thirdsrc/include/rapidjson/pointer.h>
#include "utils.h"
using namespace rapidjson;

Utils::JSONConfigure::JSONConfigure() {
    m_jsonValue = nullptr;
}

Utils::JSONConfigure::~JSONConfigure() {
    m_jsonValue = nullptr;
}

Utils::IConfigure *Utils::JSONConfigure::getConfigure(const char *key) {
    m_jsonValue = Pointer(key).Get(m_jsonDoc);
    if(nullptr == m_jsonValue)
        return nullptr;
    return this;
}

bool Utils::JSONConfigure::parse(const char *stream) {
    m_jsonDoc.Parse(stream);
    if(m_jsonDoc.HasParseError()){
        LogFatal("JSON parse failed\n");
        return false;
    }

    return true;
}

const char *Utils::JSONConfigure::getString(const char *key) const {
    if(m_jsonValue == nullptr)
        return nullptr;

    return (*m_jsonValue)[key].GetString();
}

