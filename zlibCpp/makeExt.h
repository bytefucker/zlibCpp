//
//  makeExt.h
//  zlibCpp
//
//  Created by Шура on 26.05.16.
//  Copyright © 2016 shura. All rights reserved.
//

#ifndef makeExt_h
#define makeExt_h

char * makeExt (std::string file, std::string ext){
    // .c_str() returns const char *
    return std::strcat((char*)file.c_str(), ext.c_str());
}

#endif /* makeExt_h */
