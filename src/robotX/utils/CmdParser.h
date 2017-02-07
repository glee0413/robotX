//
// Created by light on 17-1-12.
//

#ifndef ROBOTX_COMMAND_H
#define ROBOTX_COMMAND_H

#include <string>
#include <getopt.h>

#include <utils/macro.h>
using namespace std;

namespace Utils {
    class CmdParser {
    public:
        CmdParser();
        virtual ~CmdParser();
    public:
        int parseCmd(int argc,char* argv[]);
    public:
        static char m_lprShortOption[];
        static struct option m_lprLongOption[];
    private:
        string m_configFile;
    private:
        DISALLOW_COPY_AND_ASSIGN(CmdParser);
    };
}

#endif //ROBOTX_COMMAND_H
