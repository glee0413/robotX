/*
 * TimeUtils.h
 *
 *  Created on: 2016年5月11日
 *      Author: light
 */

#ifndef SRC_UTILS_TIMEUTILS_H_
#define SRC_UTILS_TIMEUTILS_H_

#include <sys/time.h>

namespace Utils {

	class TimeUtils {
		public:
			TimeUtils();
			virtual ~TimeUtils();
		public:
			static const char* getLocalTime(char* time_str);
			static const char* getTimeOfDay(char* time_str);
		public:
			int getDiff();
		public:
			struct timeval m_current;
			struct timeval m_diff;
	};

} /* namespace Utils */

#endif /* SRC_UTILS_TIMEUTILS_H_ */
