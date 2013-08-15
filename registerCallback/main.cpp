//
//  main.cpp
//  registerCallback
//
//  Created by titan on 8/15/13.
//  Copyright (c) 2013 titan. All rights reserved.
//

#include <iostream>
#include "thirdParty.h"

int clientFunction(ADC_Paramers* data)
{
    cout << "client data: " << data->iPersonCounter << endl;
    return 0;
}

int main(int argc, const char * argv[])
{
    ADC_Paramers data;
    clientFunction(&data);
    register_fun_call(&clientFunction);
    
    while (true) {
        usleep(1000);
    }
    
    return 0;
}

