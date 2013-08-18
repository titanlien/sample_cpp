//
//  thirdParty.h
//  registerCallback
//
//  Created by titan on 8/15/13.
//  Copyright (c) 2013 titan. All rights reserved.
//

#ifndef __registerCallback__thirdParty__
#define __registerCallback__thirdParty__

#include <iostream>
#include <assert.h>
#include <thread>
#include <unistd.h>

typedef struct ADC_Paramers {
    bool bDebugWindow;
    int iPersonCounter;
}ADC_Paramers;

typedef ADC_Paramers (*FUNC_HANDLER)(ADC_Paramers);

using namespace std;
bool register_fun_call(FUNC_HANDLER );


#endif /* defined(__registerCallback__thirdParty__) */
