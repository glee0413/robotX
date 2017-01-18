//
// Created by light on 17-1-13.
//

#ifndef ROBOTX_ICONFIGURE_H
#define ROBOTX_ICONFIGURE_H

#include <utils/macro.h>

namespace Utils{
    class IConfigure {
    public:
        IConfigure(){};
        virtual ~IConfigure(){};
        virtual bool parse(const char* stream) = 0;
        virtual IConfigure* getConfigure(const char* key) = 0;
        virtual const char* getString(const char* key) const = 0 ;

    private:
        DISALLOW_COPY_AND_ASSIGN(IConfigure);
    };
}



#endif //ROBOTX_CONFIGURE_H
