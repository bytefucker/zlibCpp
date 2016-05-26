//
//  gzStream.hpp
//  zlibCpp
//
//  Created by Шура on 26.05.16.
//  Copyright © 2016 shura. All rights reserved.
//

#ifndef gzStream_hpp
#define gzStream_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <zlib.h>
#include <assert.h>
#include <unistd.h> // getopt in main.cpp
#include <stdio.h>

#include "getFileSize.h"
#include "deflateFile.h"
#include "inflateFile.h"
#include "restoreExt.h"
#include "makeExt.h"
#include "printHelp.h"

class gzStream{
private:
    std::string inFileName;
    std::string fileExt = "z";
    int keepFlag = 0;
public:
    // empty constructor
    gzStream();
    
    // open file
    void open(char *);
    
    // deflate file
    void compress(int);
    
    // inflate file
    void decompress();
    
    // set new extension
    void setExt(std::string);
    
    // set to delete
    void setDelete();
    
    // destructor
    ~gzStream();
};

// class methods

gzStream::gzStream(){
    
}

gzStream::~gzStream(){
    
}

void gzStream::open(char * inFile){
    inFileName = inFile;
}

void gzStream::setExt(std::string newExt){
    fileExt = newExt;
}

void gzStream::setDelete(){
    keepFlag = 1;
}

void gzStream::compress(int compRate = -1){
    // open file
    FILE * inFile = fopen(inFileName.c_str(), "r");
    // make .z file
    fileExt.insert(0, ".");
    FILE * outFile = fopen(makeExt(inFileName, fileExt), "wb");
    // deflate
    def(inFile, outFile, compRate);
    // show copression rate
    std::cout << "Compressed with rate: " <<
    getFileSize(inFile) / getFileSize(outFile) << std::endl;
    // close files
    fclose(inFile);
    fclose(outFile);
}

void gzStream::decompress(){
    // open file
    FILE * inFile = fopen(inFileName.c_str(), "r");
    // make original file
    fileExt.insert(0, ".");
    FILE * outFile = fopen(removeExt(inFileName, fileExt), "wb");
    // inflate
    inf(inFile, outFile);
    // close files
    fclose(inFile);
    fclose(outFile);
    // delete archive
    if (!keepFlag) {
        remove(inFileName.c_str());
    }
}

#endif /* gzStream_hpp */
