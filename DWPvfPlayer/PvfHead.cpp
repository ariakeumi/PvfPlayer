//
//  PvfHead.cpp
//  DWPvfPlayer
//
//  Created by Seven on 16/2/2.
//  Copyright © 2016年 dreamingwish.com. All rights reserved.
//

#include <stdlib.h>
#include <string.h>
#include <stdexcept>

#include "PvfHead.hpp"

/*
 struct header
{
    int sizeGUID; //Always 0x24
    char GUID[sizeGUID]
    int fileVersion
    int dirTreeLength;
    int dirTreeChecksum;
    int numFilesInDirTree;
}
 */

namespace DW {

	const int gGUIDSizeLen = sizeof(int);
	const int gHeadInfoLen = sizeof(struct _PvfHeadInfo);

	PvfHead::PvfHead(void* buf, size_t bufLen)
	{
		//read GUID size
		if (bufLen < gGUIDSizeLen) {
			throw std::runtime_error("buf not enough");
		}
		this->_GUIDSize = *((int *)buf);
		//read GUID
		if (this->_GUIDSize <= 0 || (int)bufLen < gGUIDSizeLen + gHeadInfoLen + this->_GUIDSize) {
			throw std::runtime_error("guid size invalid or buf not enough");
		}
		this->_GUID = (const char *)calloc(this->_GUIDSize + 1, 1);
		if (!this->_GUID) {
			throw std::runtime_error("can not alloct mem for guid");
		}
		memcpy((char *)this->_GUID, (const char*)buf + gGUIDSizeLen, this->_GUIDSize);
		//read info
		memcpy(&this->_info, (const char*)buf + gGUIDSizeLen + this->_GUIDSize, gHeadInfoLen);
	}

	PvfHead::~PvfHead()
	{
		free((void *)this->_GUID);
	}

	const char* PvfHead::getGUID()
	{
		return this->_GUID;
	}

	PvfHeadInfoRef PvfHead::getInfo()
	{
		return &this->_info;
	}
    
    int PvfHead::getHeadLength()
    {
        return gGUIDSizeLen + this->_GUIDSize + gHeadInfoLen;
    }
}

