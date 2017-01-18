/*
 * urlencode.h
 *
 *  Created on: 2016年6月9日
 *      Author: light
 */

#ifndef SRC_COMMON_URLENCODE_H_
#define SRC_COMMON_URLENCODE_H_

void urlencode(const char * src, int  src_len, char * dest, int  dest_len );
unsigned char* urldecode(unsigned char* encd,unsigned char* decd);


#endif /* SRC_COMMON_URLENCODE_H_ */
