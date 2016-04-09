//
//  main.cpp
//  zlibCpp
//
//  Created by Шура on 09.04.16.
//  Copyright © 2016 shura. All rights reserved.
//
//  links with -lz flags

#include <iostream>
#include <zlib.h>
#include "compBuff.h"
#include "gzWrite.h"


int main(int argc, const char * argv[]) {
    
    std::cout << "Using zlib v." << ZLIB_VERSION << std::endl;
    compBuff();
    def(stdin, stdout, Z_DEFAULT_COMPRESSION);
    return 0;
}

