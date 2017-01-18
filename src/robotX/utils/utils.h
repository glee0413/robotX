/*
 * utils.h
 *
 *  Created on: 2016年5月12日
 *      Author: light
 */

#ifndef SRC_UTILS_UTILS_H_
#define SRC_UTILS_UTILS_H_

#include <string.h>
#include <errno.h>

#include <utils/SimpleLog.h>
#include <utils/LogUniform.h>
#include <utils/Singleton.h>
#include <utils/TimeUtils.h>
#include <common/constant.h>
#include <utils/JSONConfigureFile.h>

#define LogByLevel(level,fmt,arg...) \
{ \
	using namespace Utils; \
	Singleton<SimpleLog>::Instance()->doLog(level,fmt,##arg); \
	Singleton<LogUniform>::Instance()->doLog(level,fmt,##arg); \
}


#define LogInfo(fmt,arg...) \
{ \
	using namespace Utils; \
	Singleton<SimpleLog>::Instance()->doLog(LL_INFO,"[%s:%d]" fmt,__FILE__,__LINE__,##arg); \
}


#define LogTrace(fmt,arg...) \
{ \
	LogByLevel(LL_TRACE,"[%s:%d] " fmt,__FILE__,__LINE__,##arg); \
}

#define LogFatal(fmt,arg...) \
{ \
	using namespace Utils; \
	Singleton<SimpleLog>::Instance()->doLog(LL_FATAL,"[%s:%d] " fmt,__FILE__,__LINE__,##arg); \
}

#define LogError(fmt,arg...) \
{ \
	using namespace Utils; \
	Singleton<SimpleLog>::Instance()->doLog(LL_ERROR,"[%s:%d] " fmt,__FILE__,__LINE__,##arg); \
}

#define LogSysError(fmt,arg...) \
{ \
	using namespace Utils; \
	Singleton<SimpleLog>::Instance()->doLog(LL_ERROR,"[%s:%d]{%s} " fmt,__FILE__,__LINE__,strerror(errno),##arg); \
}

/*
#define LogTrace(fmt,arg...) \
{ \
	using namespace Utils; \
	Singleton<SimpleLog>::Instance()->doLog(LL_TRACE,"[%s:%d]" fmt,__FILE__,__LINE__,##arg); \
}
*/

#define LogWarning(fmt,arg...) \
{ \
	using namespace Utils; \
	Singleton<SimpleLog>::Instance()->doLog(LL_WARNING,"[%s:%d] " fmt,__FILE__,__LINE__,##arg); \
}

#define LogDebug(fmt,arg...) \
{ \
	using namespace Utils; \
	Singleton<SimpleLog>::Instance()->doLog(LL_DEBUG,"[%s:%d] " fmt,__FILE__,__LINE__,##arg); \
}

#define AssertMessage(x) \
    if(!(x))  { \
        LogFatal("Assert reason: %s",#x); \
        exit(0); \
    }


#endif /* SRC_UTILS_UTILS_H_ */
