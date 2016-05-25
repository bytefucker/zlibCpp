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
#include <unistd.h> // getopt
#include <assert.h>
#include "getFileSize.h"
#include "deflateFile.h"
#include "inflateFile.h"
#include "restoreExt.h"

void printHelp(){
    std::cerr << "Usage:  zlib -cdh\n";
    std::cerr << "-c\tfile to compress\n";
    std::cerr << "-d\tfile to decompress\n";
    std::cerr << "-h\tshow this help\n";
}

int main(int argc, char *argv[]) {
    if (argc ==1) {
        std::cerr << "Wrong options.\n";
        return -1;
    }
    
    char const *opts = "c:d:h";
    int opt;
    
    // extension
    const char * ext = ".z";
    
    while ((opt = getopt(argc, argv, opts)) != -1) {
        switch (opt) {
            // compress
            case 'c':
            {
                FILE * inFile = fopen(optarg, "r");
                FILE * outFile = fopen(strcat(optarg, ext), "wb");
                
                def(inFile, outFile, Z_DEFAULT_COMPRESSION);
                
                std::cout << "Compressed with rate: " <<
                getFileSize(inFile) / getFileSize(outFile) << "\n";
                break;
            }
            // decompress
            case 'd':
            {
                FILE * inFile = fopen(optarg, "r");
                FILE * outFile = fopen(restoreExt(optarg, ext), "wb");
                
                inf(inFile, outFile);
                break;
            }
            // help 
            case 'h':
            {
                printHelp();
                break;
            }
            default:
                printHelp();
                break;
        }
    }
    return 0;
}
