//
//  restoreExt.h
//  zlibCpp
//
//  Created by Шура on 25.05.16.
//  Copyright © 2016 shura. All rights reserved.
//

#ifndef restoreExt_h
#define restoreExt_h

#include <string>

const char * restoreExt (char * optarg, const char * ext){
    std::string str(optarg);
    std::string sext(ext);
    str.substr(0, sext.size());
    str.erase((str.size()-sext.size()), sext.size());
    return str.c_str();
}

#endif /* restoreExt_h */
