//
//  thirdParty.cpp
//  registerCallback
//
//  Created by titan on 8/15/13.
//  Copyright (c) 2013 titan. All rights reserved.
//

#include "thirdParty.h"

ADC_Paramers mpdata;

void
setADC_Paramers(int iPersonCounter)
{
    mpdata.iPersonCounter = iPersonCounter;
}

int
call_function(ADC_Paramers* pdata)
{
    int error_code = 0;
    return error_code;
}

void
loopadd()
{
    static int iPersonCounter = 0;
    while (true) {
        setADC_Paramers(iPersonCounter);
        cout << "3rd data: " << iPersonCounter << endl;
        ++iPersonCounter;
        usleep(1000);
    }
}

bool
register_fun_call(FUNC_HANDLER handler)
{
    assert(handler != NULL);
    handler = &call_function;
    thread t1(loopadd);
    return true;
}
