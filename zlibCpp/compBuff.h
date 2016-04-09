//
//  compBuff.h
//  zlibCpp
//
//  Created by Шура on 09.04.16.
//  Copyright © 2016 shura. All rights reserved.
//

#include "makeBuffers.h"

#ifndef compBuff_h
#define compBuff_h

void compBuff(){
    if (Z_OK == compress(dest, &destLen, source, sourceLen)) {
        std::cout << "Compressed with rate: " << destLen / static_cast<float>(sourceLen) << std::endl;
    }
    
    // now decompress!
    if (Z_OK == uncompress(dest, &destLen, source, sourceLen)) {
        std::cout << "Uncompressed!\n";
    }
    else
        if (ferror(stdin)) {
            std::cout << "Error reading stdin.\n";
        }
        else if (ferror(stdout)){
            std::cout << "Error writing stdout.\n";
        }
}

#endif /* compBuff_h */
