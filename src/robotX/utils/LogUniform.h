/*
 * LogUniform.h
 *
 *  Created on: 2016年5月19日
 *      Author: light
 */

#ifndef SRC_UTILS_LOGUNIFORM_H_
#define SRC_UTILS_LOGUNIFORM_H_

//namespace Comm{
//	class XIO;
//}

namespace Utils {
	//using Comm::CommIO;
	class LogUniform {
		public:
			LogUniform();
			virtual ~LogUniform();
		public:
			//void setIO(Comm::XIO* io);
			void setLogLevel(int logLevel);
			int	getLogLevel();
			int doLog(int level,const char* fmt,...);
			bool isLogOpen(int logLevel);
		public:
			//Comm::XIO* m_io;
			int m_logLevel;
	};
};

#endif /* SRC_UTILS_LOGUNIFORM_H_ */
