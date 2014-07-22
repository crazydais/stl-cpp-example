//
//  MyTemplate.cpp
//  Templates
//
//  Created by David Nolan on 17/07/2014.
//  Copyright (c) 2014 David Nolan. All rights reserved.
//

#include "MyTemplate.h"

template<class TYPE>
void PrintTwice(TYPE data)
{
    std::cout<<"Twice: " << data * 2 << std::endl;
}
