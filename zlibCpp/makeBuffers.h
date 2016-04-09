//
//  makeBuffers.h
//  zlibCpp
//
//  Created by Шура on 10.04.16.
//  Copyright © 2016 shura. All rights reserved.
//

#ifndef makeBuffers_h
#define makeBuffers_h

const int _SIZE = 512;

// make input and output buffers
unsigned char source[_SIZE];
const unsigned long sourceLen = _SIZE;   //! const

unsigned char dest[_SIZE];
unsigned long destLen = _SIZE;

void fillBuff(unsigned char source[_SIZE]){
    // fill source buffer
    for (int i=0; i<(_SIZE-1); ++i){
        source[i] = i;}
    
    // mind the testing ratio when filled with zeros
    // memset(source, 0, _SIZE * sizeof(source[0]));
}

#endif /* makeBuffers_h */
