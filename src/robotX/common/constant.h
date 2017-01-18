/*
 * constant.h
 *
 *  Created on: 2016年5月17日
 *      Author: light
 */

#ifndef SRC_COMMON_CONSTANT_H_
#define SRC_COMMON_CONSTANT_H_


#define VIDEO_DEVICE_NAME "/dev/video0"
#define INVALID_HANDLE_VALUE -1

enum LOG_LEVEL {
	LL_NONE = 0,
	LL_FATAL = 1,
	LL_ERROR = 1 << 1,
	LL_WARNING = 1 << 2,
	LL_INFO = 1 << 3,
	LL_DEBUG = 1 << 4,
	LL_TRACE = 1 << 5,
	LL_ALL = 0xFFFFFFF,
};

enum SimpleLogConstant {
	SLC_LOG_NAME_MAX_LENGTH = 256, SLC_LOG_TIME_STRING_MAX_LEN = 56,
};

enum SYS_CONSTANT{
	SC_LIBEVENT_MAX_WRITE_BUFFER_LEN = 10*1024*1024,
	SC_REMOTE_IMAGE_PLATE_LENGTH = 64,//用于存储发送给监控程序的车牌号，需要连动修改
	SC_PLATE_NO_LENGTH = 8,
	SC_PLATE_NO_UTF8_BUFF_LENGTH = 10,
	SC_PLATE_NO_URLENCODE_LENGTH = SC_PLATE_NO_UTF8_BUFF_LENGTH*3,
};

enum CameraConstant {
	CC_INVALID_VALUE = -1,
	CC_DEVICE_NAME_MAX_LEN = 64,
//				CC_CAPTURE_WIDTH = 640,
//				CC_CAPTURE_HIGHT = 480,
	CC_CAPTURE_WIDTH = 1920,
	CC_CAPTURE_HIGHT = 1080,
	CC_MMAP_COUNT = 2,
};

#define FONT_RED "\033[31m"
#define FONT_YELLOW "\033[33m"
#define FONT_VIOLET "\033[35m"
#define FONT_END "\033[0m"

const char* getLogLevelString(int level);
int getLogLevelByString(const char* levelStr);

#define PLATFORM_BBB "BBB"
#define PLATFORM_PC "PC"
#define PLATFORM_REACH_SECC "REACH_SECC"
#define GROUND_LOCK_TYPE_WOLONG "wolong"

//SYSTEM CONFIG

#define CONFIG_PLATFORM "config.platform"

#define CONFIG_HTTP_PROXY "config.http.proxy"
#define CONFIG_HTTP_PROXY_USERNAME "config.http.proxy.username"
#define CONFIG_HTTP_PROXY_PASSWORD "config.http.proxy.password"

#define CONFIG_CAMERA_DEVICE "config.camera.device"
#define CONFIG_CAMERA_WIDTH "config.camera.width"
#define CONFIG_CAMERA_HEIGHT "config.camera.hight"
#define CONFIG_CAMERA_PORT "config.camera.port"
#define CONFIG_CAMERA_ROI_POS_X "config.camera.ROI.pos.x"
#define CONFIG_CAMERA_ROI_POS_Y "config.camera.ROI.pos.y"
#define CONFIG_CAMERA_ROI_WIDTH "config.camera.ROI.width"
#define CONFIG_CAMERA_ROI_HEIGHT "config.camera.ROI.height"
#define CONFIG_CAMERA_DEBUG_SERVER "config.camera.debug.server"
#define CONFIG_CAMERA_DEBUG_PORT "config.camera.debug.port"
#define CONFIG_CAMERA_DEVICE_TYPE "config.camera.device.type"
#define CONFIG_CAMERA_DAHUA_ADDRESS "config.camera.dahua.address"
#define CONFIG_CAMERA_DAHUA_PORT "config.camera.dahua.port"
#define CONFIG_CAMERA_DAHUA_USERNAME "config.camera.dahua.username"
#define CONFIG_CAMERA_DAHUA_PASSWORD "config.camera.dahua.password"
#define CONFIG_CAMERA_DAHUA_CHANNELID "config.camera.dahua.channelId"

#define CONFIG_CAMERA_DEVICE_TYPE_UVC "uvc"
#define CONFIG_CAMERA_DEVICE_TYPE_DAHUA "dahua"

#define CONFIG_LOG_NETWORK "config.log.network"
#define CONFIG_LOG_LEVEL "config.log.level"
#define CONFIG_LOG_DEBUG_PORT "config.log.debug.port"

#define CONFIG_VEHICLE_QUERY_URL "config.vehicle.query.url"

#define CONFIG_LPR_LICENSE_PATH "config.lpr.license.path"

#define CONFIG_GROUND_LOCK_TYPE "config.ground.lock.type"

#define CONFIG_BBB_GPIO_GROUND_LOCK_ADDRESS "config.bbb.gpio.ground.addr"
#define CONFIG_BBB_GPIO_GROUND_LOCK_PORT "config.bbb.gpio.ground.port"
#define CONFIG_BBB_GPIO_GROUND_LOCK_OPEN "config.bbb.gpio.ground.lock.lock"
#define CONFIG_BBB_GPIO_GROUND_LOCK_CLOSE "config.bbb.gpio.ground.lock.unlock"

#define CONFIG_REMOTE_PLATENO_PROCESS_MODE "config.remote.plateno.process.mode"

#endif /* SRC_COMMON_CONSTANT_H_ */
