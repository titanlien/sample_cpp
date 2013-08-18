//
//  thirdParty.cpp
//  registerCallback
//
//  Created by titan on 8/15/13.
//  Copyright (c) 2013 titan. All rights reserved.
//

#include "thirdParty.h"

FUNC_HANDLER call_function;

ADC_Paramers genADC_Parameter(int iPersonCounter)
{
    ADC_Paramers temp;
    temp.iPersonCounter = iPersonCounter;
    return temp;
}

void
loopadd()
{
    static int iPersonCounter = 0;
    while (true) {
        ADC_Paramers data = genADC_Parameter(iPersonCounter);
        (*call_function)(data);
        cout << "3rd data: " << data.iPersonCounter << endl;
        iPersonCounter++;
        sleep(1);
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
