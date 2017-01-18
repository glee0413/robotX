cmake_minimum_required(VERSION 3.6)
project(robotx)

include_directories(.)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp utils/JSONConfigureFile.cpp utils/JSONConfigureFile.h utils/CmdParser.cpp utils/CmdParser.h
        utils/IConfigure.h utils/LogUniform.cpp utils/LogUniform.h utils/macro.h
        utils/SimpleLog.h utils/SimpleLog.cpp utils/Singleton.h utils/TimeUtils.h utils/TimeUtils.cpp
        utils/type.h utils/utils.h utils/IConfigureFile.cpp utils/IConfigureFile.h
        common/constant.h common/constant.cpp common/geometry.h common/urlencode.h common/urlencode.cpp
        utils/JSONConfigure.cpp utils/JSONConfigure.h)
add_executable(robotx ${SOURCE_FILES})