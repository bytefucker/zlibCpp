//
//  getFileSize.h
//  zlibCpp
//
//  Created by Шура on 24.05.16.
//  Copyright © 2016 shura. All rights reserved.
//

#ifndef getFileSize_h
#define getFileSize_h

#include <fstream>

float getFileSize(FILE * filename){
    if (filename == NULL) {
        std::cerr << "Error opening file.\n";
        return -1;
    }
    else{
        fseek(filename, 0, SEEK_END);
        return (float)ftell(filename);
        fclose(filename);
    }
}



#endif /* getFileSize_h */
