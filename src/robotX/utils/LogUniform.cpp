/*
 * LogUniform.cpp
 *
 *  Created on: 2016年5月19日
 *      Author: light
 */

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

#include <utils/LogUniform.h>
//#include <comm/XIO.h>
#include <common/constant.h>
#include <utils/TimeUtils.h>


using namespace Utils;
//using namespace Comm;

LogUniform::LogUniform() {
	// TODO Auto-generated constructor stub
	//m_io = NULL;
	m_logLevel = 0;
}

LogUniform::~LogUniform() {
	// TODO Auto-generated destructor stub
	//m_io = NULL;
	m_logLevel = 0;
}

//void LogUniform::setIO(XIO* io){
//	//m_io = io;
//}

void LogUniform::setLogLevel(int logLevel){
	m_logLevel = logLevel;
}

int LogUniform::getLogLevel() {
	return m_logLevel;
}

bool LogUniform::isLogOpen(int logLevel){
	if(logLevel & m_logLevel){
		return true;
	}
	return false;
}

static char s_tempFormatString[1024];
static char s_tempTimeString[56];

int LogUniform::doLog(int level, const char* fmt, ...) {
	int ret = 0;
//	if (m_io == NULL) {
//		return -1;
//	}

	if(!isLogOpen(level)){
		return -1;
	}

	if(level != LL_ALL)
			ret = sprintf(s_tempFormatString,"[%s][%s]",TimeUtils::getTimeOfDay(s_tempTimeString),getLogLevelString(level));
	if(ret < 0){
		return -1;
	}

	va_list ap;
	va_start(ap, fmt);
	ret += vsprintf(&s_tempFormatString[ret],fmt,ap);
	//m_io->write(s_tempFormatString,ret);
	va_end(ap);
	return ret;
}
