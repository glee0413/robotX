/*
 * TimeUtils.cpp
 *
 *  Created on: 2016年5月11日
 *      Author: light
 */

#include <sys/time.h>

#include <time.h>
#include <string.h>
#include <stdio.h>

#include <utils/TimeUtils.h>

namespace Utils {

	TimeUtils::TimeUtils() {
		// TODO Auto-generated constructor stub
		gettimeofday(&this->m_current,NULL);
	}

	TimeUtils::~TimeUtils() {
		// TODO Auto-generated destructor stub
	}

	const char* TimeUtils::getLocalTime(char* time_str) {
		//TODO:线程不安全,time_str,需要保存足够的长度
		time_t now;
		struct tm *timenow;

		time(&now);
		timenow = localtime(&now);
		strcpy(time_str, asctime(timenow));
		time_str[strlen(time_str)-1] = 0;
		return time_str;
	}
	const char* TimeUtils::getTimeOfDay(char* time_str) {
		time_t now;
		struct tm *timenow;
		struct timeval tv;

		gettimeofday(&tv,NULL);
		time(&now);
		timenow = localtime(&now);
		sprintf(time_str,"%02d:%02d:%02d.%06ld",timenow->tm_hour,timenow->tm_min,timenow->tm_sec,tv.tv_usec);
		return time_str;
	}

	int TimeUtils::getDiff() {
		int diff = 0;
		gettimeofday(&this->m_diff, NULL);
		diff = (m_diff.tv_sec - m_current.tv_sec) * 1000
		        + (m_diff.tv_usec - m_current.tv_usec);
		memcpy(&m_current, &m_diff, sizeof(m_current));
		return diff;
	}
} /* namespace Utils */

