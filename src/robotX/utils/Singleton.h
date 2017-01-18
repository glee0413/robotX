/*
 * singleton.h
 *
 *  Created on: 2016年5月12日
 *      Author: light
 */

#ifndef SRC_UTILS_SINGLETON_H_
#define SRC_UTILS_SINGLETON_H_
#include <stdlib.h>
#include <utils/macro.h>

namespace Utils {
	template<typename Type>
	class Singleton {
		public:
			static Type* Instance() {
				if (!m_Instance) {
					if (!m_Instance) {
						m_Instance = new Type;
					}
				}
				return m_Instance;
			}
		private:
			DISALLOW_COPY_AND_ASSIGN(Singleton);
		private:
			static Type* m_Instance;

	};

	template<typename Type>
	Type* Singleton<Type>::m_Instance = NULL;
}
#endif /* SRC_UTILS_SINGLETON_H_ */
