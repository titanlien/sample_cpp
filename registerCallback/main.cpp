//
//  main.cpp
//  registerCallback
//
//  Created by titan on 8/15/13.
//  Copyright (c) 2013 titan. All rights reserved.
//

#include <iostream>
#include "thirdParty.h"

ADC_Paramers* clientFunction(ADC_Paramers* data)
{
    return data;
}

int main(int argc, const char * argv[])
{
    ADC_Paramers data;
    clientFunction(&data);
    register_fun_call(&clientFunction);
    
    while (true) {
        cout << "client data: " << data->iPersonCounter << endl;
        usleep(1000);
    }
    
    return 0;
}

