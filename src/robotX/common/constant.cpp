/*
 * constant.cpp
 *
 *  Created on: 2016年5月24日
 *      Author: light
 */
#include <string.h>
#include <common/constant.h>
const char* getLogLevelString(int level){

	switch (level) {
		case LL_FATAL:
			return "FATAL";
		case LL_ERROR:
			return "ERROR";
		case LL_WARNING:
			return "WARNING";
		case LL_INFO:
			return "INFO";
		case LL_DEBUG:
			return "DEBUG";
		case LL_TRACE:
			return "TRACE";
		default:
			return "UNKONWN";
	}
	return "UNKONWN";
}

int getLogLevelByString(const char* levelStr){
	int ret = 0;
	if (0 == strcmp(levelStr, "all")) {
		return LL_ALL;
	}
	if (0 == strcmp(levelStr,"none")){
		return 0;
	}
	if (strstr(levelStr, "fatal")) {
		ret |= LL_FATAL;
	}
	if (strstr(levelStr, "error")) {
		ret |= LL_ERROR;
	}

	if (strstr(levelStr, "warning")) {
		ret |= LL_WARNING;
	}
	if (strstr(levelStr, "info")) {
		ret |= LL_INFO;
	}
	if (strstr(levelStr, "debug")) {
		ret |= LL_DEBUG;
	}
	if (strstr(levelStr, "trace")) {
		ret |= LL_TRACE;
	}
	return ret;
}
