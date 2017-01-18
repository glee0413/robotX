/*
 * simple_log.cpp
 *
 *  Created on: 2016年5月11日
 *      Author: light
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#include <utils/SimpleLog.h>
#include <utils/TimeUtils.h>

using namespace Utils;

SimpleLog::SimpleLog(){
				this->m_fp = NULL;
				memset(this->m_logName,0,sizeof(this->m_logName));
				memset(this->m_timeStamp,0,sizeof(this->m_timeStamp));
				this->m_logSwitch = 0;
				this->m_logSwitch = LL_ALL;
				this->m_logSize = 10;
				this->m_logMode = LM_CONTINUE;
}
SimpleLog::~SimpleLog(){
	this->close();
}

bool SimpleLog::initLog(const char* logName,int logLevel,int mode){
	if(logName == NULL){
		this->m_fp = stdout;
	}else{
		strcpy(this->m_logName,logName);
		this->m_fp = fopen(this->m_logName,"wb");
		if(NULL == this->m_fp)
			return false;
	}

	this->setLogLevel(logLevel);
	this->setLogMode(mode);
	this->doLog(LL_ALL,"#\t -- %s --\n",TimeUtils::getLocalTime(m_timeStamp));
	return true;
}

void SimpleLog::setLogLevel(int logLevel){
	this->m_logSwitch = logLevel;
}

void SimpleLog::close(){
	if(this->m_fp != NULL && this->m_fp != stdout){
		fclose(this->m_fp);
		this->m_fp = NULL;
	}
}

bool SimpleLog::isLogOpen(int logLevel){
	if(logLevel & m_logSwitch){
		return true;
	}
	return false;
}

void SimpleLog::writeLevelPrefix(int level,int start){
	if(this->m_fp != stdout){
		return;
	}
	if(1 == start){
		if(LL_FATAL == level || LL_ERROR == level || LL_WARNING == level)
			fprintf(this->m_fp,FONT_RED);
		else if(LL_INFO == level){
			fprintf(this->m_fp,FONT_YELLOW);
		}else if(LL_DEBUG == level){
			fprintf(this->m_fp,FONT_VIOLET);
		}
	}else{
		switch(level){
			case LL_FATAL:
			case LL_ERROR:
			case LL_WARNING:
			case LL_INFO:
			case LL_DEBUG:
				fprintf(this->m_fp,FONT_END);
				break;
			default:
				break;
		}
	}
	return;
}

int SimpleLog::doLog(int level,const char* fmt,...){
	if(this->m_fp == NULL){
		return -1;
	}
	if(!this->isLogOpen(level)){
		return -1;
	}

	writeLevelPrefix(level,1);

	if(level != LL_ALL)
		fprintf(this->m_fp,"[%s][%s]",TimeUtils::getTimeOfDay(m_timeStamp),getLogLevelString(level));
	va_list ap;
	va_start(ap,fmt);
	vfprintf(this->m_fp,fmt,ap);
	va_end(ap);
	writeLevelPrefix(level,0);
	return 0;
}

void SimpleLog::setLogMode(int mode){
	this->m_logMode = mode;

}
int SimpleLog::getLogLevel(){
	return this->m_logMode;
}
void SimpleLog::setLogMaxSize(int size){
	this->m_logSize = size;
}
int SimpleLog::getLogMaxSize(){
	return this->m_logSize;
}
