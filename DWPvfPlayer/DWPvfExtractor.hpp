//
//  DWPvfExtractor.hpp
//  DWPvfPlayer
//
//  Created by Seven on 16/2/2.
//  Copyright © 2016年 dreamingwish.com. All rights reserved.
//

#ifndef DWPvfExtractor_hpp
#define DWPvfExtractor_hpp

#include <stdio.h>

namespace DW {
    
    class PvfHead;
    
    class PvfPlayer {
        int _pvfFd;
        long long _pvfLength;
        void *_pvfMemMap;
        PvfHead *_head;
        
        void _close(int save);
        int _decryptTreeBlock(unsigned char* buf, unsigned int bufLen, int numberOfFiles, int checkSumCheck, int checksumUse);
        unsigned int _sub_311820(unsigned int *a1);
        
    public:
        PvfPlayer(const char*);
        ~PvfPlayer();
        
        void getDirTree();
    };
}

#endif /* DWPvfExtractor_hpp */
