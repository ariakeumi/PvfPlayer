//
//  PvfHead.hpp
//  DWPvfPlayer
//
//  Created by Seven on 16/2/2.
//  Copyright © 2016年 dreamingwish.com. All rights reserved.
//

#ifndef PvfHead_hpp
#define PvfHead_hpp

#include <stdio.h>

namespace DW {

	struct _PvfHeadInfo {
		int fileVersion;
		int dirTreeLength;
		int dirTreeChecksum;
		int numFilesInDirTree;
	};
	typedef const struct _PvfHeadInfo * PvfHeadInfoRef;

    class PvfHead {
        int _GUIDSize;
        const char *_GUID;
        struct _PvfHeadInfo _info;
        
    public:
        PvfHead(void* buf, size_t bufLen);
        ~PvfHead();

        const char* getGUID();
        PvfHeadInfoRef getInfo();
        int getHeadLength();
    };
}

#endif /* PvfHead_hpp */
