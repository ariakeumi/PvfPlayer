//
//  main.cpp
//  pvftest
//
//  Created by Seven on 16/2/2.
//  Copyright © 2016年 dreamingwish.com. All rights reserved.
//

#include <iostream>
#include "DWPvfExtractor.hpp"

int main(int argc, const char * argv[])
{
    if (argc < 2) {
        std::cout << "Usage: PvfPlayer <pvf path>" << std::endl;
        return -1;
    }
    
    const char * pvfPath = argv[1];
    std::cout << "Got pvf path:" << pvfPath << std::endl;
    
    DW::PvfPlayer *player = new DW::PvfPlayer(pvfPath);
    player->getDirTree();
    
    delete player;
    
    return 0;
}
