//
//  printHelp.h
//  zlibCpp
//
//  Created by Шура on 26.05.16.
//  Copyright © 2016 shura. All rights reserved.
//

#ifndef printHelp_h
#define printHelp_h

void printHelp(){
    std::cerr << "Usage:  zlib -cdh" << std::endl;
    std::cerr << "-e\tfile extension\n";
    std::cerr << "-c\tfile to compress\n";
    std::cerr << "-d\tfile to decompress\n";
    std::cerr << "-h\tshow this help" << std::endl;
}

#endif /* printHelp_h */
