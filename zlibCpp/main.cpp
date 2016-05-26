//
//  main.cpp
//  zlibCpp
//
//  Created by Шура on 09.04.16.
//  Copyright © 2016 shura. All rights reserved.
//
//  link with -lz flags

#include "gzStream.hpp"

int main(int argc, char *argv[]) {
    if (argc ==1) {
        std::cerr << "Wrong options.\n";
        printHelp();
        return -1;
    }
    
    char const *opts = "e:c:d:kh";
    int opt;
    
    gzStream myFile;
    
    while ((opt = getopt(argc, argv, opts)) != -1) {
        switch (opt) {
            case 'c':
                myFile.open(optarg);
                myFile.compress();
                break;
            case 'd':
                myFile.open(optarg);
                myFile.decompress();
                break;
            case 'e':
                myFile.setExt(optarg);
                break;
            case 'k':
                myFile.setDelete();
                break;
            case 'h':
            default:
                printHelp();
                break;
        }
    }
    return 0;
}
