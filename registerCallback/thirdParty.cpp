//
//  thirdParty.cpp
//  registerCallback
//
//  Created by titan on 8/15/13.
//  Copyright (c) 2013 titan. All rights reserved.
//

#include "thirdParty.h"

FUNC_HANDLER call_function;

void
setADC_Paramers(int iPersonCounter)
{
    ADC_Paramers* data = call_function;
    data->iPersonCounter = iPersonCounter;
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
    call_function = handler;
    thread thr1(loopadd);
    return true;
}
