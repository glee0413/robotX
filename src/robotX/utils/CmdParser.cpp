//
// Created by light on 17-1-12.
//

#include <getopt.h>

#include "CmdParser.h"
using namespace Utils;

struct option CmdParser::m_lprLongOption[] = {
        {"config",        1, nullptr,		'c'},
        { 0, 0, 0, 0 },
};

char CmdParser::m_lprShortOption[] = "c:";


Utils::CmdParser::~CmdParser() {

}

Utils::CmdParser::CmdParser() {

}

int Utils::CmdParser::parseCmd(int argc, char **argv) {
    int c = 0;
    while( (c = getopt_long(argc,argv,CmdParser::m_lprShortOption,CmdParser::m_lprLongOption,NULL)) != -1 ){
        switch(c){
            case 'c':
                UTILS::Singleton<UTILS::Configure>::Instance()->SetConfigFile(optarg);
                break;
            default:
                break;
        }
    }
    return 0;
}
