/*
 * simple_log.h
 *
 *  Created on: 2016年5月11日
 *      Author: light
 */

#ifndef SRC_UTILS_SIMPLELOG_H_
#define SRC_UTILS_SIMPLELOG_H_
#include <stdio.h>

#include <utils/macro.h>
#include <common/constant.h>

namespace Utils{
	class SimpleLog{
		public:
			enum LOG_MODE{
				LM_CONTINUE = 0,
				LM_DATE = 1,
				LM_SIZE = 1 << 1,
			};
		public:
			SimpleLog();
			~SimpleLog();
			bool initLog(const char* logName,int logLevel = LL_ALL,int mode = LM_CONTINUE);
			void setLogLevel(int logLevel);
			int	getLogLevel();
			int doLog(int level,const char* fmt,...);
			void setLogMode(int mode);
			int getLogMode();
			void setLogMaxSize(int size);//M
			int getLogMaxSize();
		private:
			void close();
			int open();
			bool isLogOpen(int logLevel);
			void writeLevelPrefix(int level,int start = 0);
		private:
			FILE* m_fp;
			char m_logName[SLC_LOG_NAME_MAX_LENGTH];
			char m_timeStamp[SLC_LOG_TIME_STRING_MAX_LEN];
			int 	m_logSwitch;
			int	m_logMode;
			int 	m_logSize;
		private:
			DISALLOW_COPY_AND_ASSIGN(SimpleLog);
	};
}



#endif /* SRC_UTILS_SIMPLELOG_H_ */
