/*!
    RFUIDebug
    RFUI

    Copyright (c) 2012 BB9z
    http://github.com/bb9z/RFUICore

    The MIT License (MIT)
    http://www.opensource.org/licenses/mit-license.php
 */

#ifndef _RFUIDebug_h
#define _RFUIDebug_h

#ifndef RFUIDebugEnableRandomBackgroundColor
    #define RFUIDebugEnableRandomBackgroundColor 0
#endif

#ifndef RFUILogAtDelloc
    #define RFUILogAtDelloc 0
#endif

#ifndef RFUIDellocLog
    #if RFUILogAtDelloc
        #define RFUIDellocLog() doutwork()
    #else
        #define RFUIDellocLog()
    #endif
#else
    #warning "RFUIDellocLog was defined somewhere"
#endif

#ifndef RFUIDelloc
    #if RFUILogAtDelloc
        #define RFUIDelloc \
            - (void)dealloc {\
                doutwork();\
            }
    #else
        #define RFUIDelloc
    #endif
#else
    #warning "RFUIDelloc was defined somewhere"
#endif

#endif
