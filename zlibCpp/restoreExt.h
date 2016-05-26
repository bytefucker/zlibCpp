//
//  restoreExt.h
//  zlibCpp
//
//  Created by Шура on 25.05.16.
//  Copyright © 2016 shura. All rights reserved.
//

#ifndef restoreExt_h
#define restoreExt_h

const char * removeExt (std::string file, std::string ext){
    file.substr(0, ext.size());
    file.erase((file.size()-ext.size()), ext.size());
    return file.c_str();
}

#endif /* restoreExt_h */
