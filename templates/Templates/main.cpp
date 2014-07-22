//
//  main.cpp
//  Templates
//
//  Created by David Nolan on 17/07/2014.
//  Copyright (c) 2014 David Nolan. All rights reserved.
//

//  General Include
#include <iostream>

//  STL Library Include
#include <vector>
#include <deque>
#include <list>
#include <set>                  //  set and multiset
#include <map>                  //  map and multimap
#include <unordered_set>        //  unordered set/multiset
#include <unordered_map>        //  unordered map/multimap
#include <iterator>
#include <algorithm>
#include <numeric>
#include <functional>


int main(int argc, const char * argv[])
{

    //  Create a vector and push some ints onto it from the back
    std::vector<int> vec;
    vec.push_back(4);
    vec.push_back(1);
    vec.push_back(8);
    
    //std::vector<int>::iterator vecBegin = vec.begin();
    //std::vector<int>::iterator vecEnd = vec.end();
    
    //  Print the vector
    for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    
    std::cout << "\n" << std::endl;
    
    //  Sort the vector
    std::sort(vec.begin(), vec.end());
    
    //  Print the sorted vector
    for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    
    std::cout << "\n" << std::endl;
    
    /*----------------------------------------------------*/
    
    //  Create a deq of type int, and init with several values.  The push more values to the back and front.
    std::deque<int> deq = { 4, 7, 3, 9 };
    deq.push_back(5);
    deq.push_front(8);
    
    for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
    {
        std::cout << *it << " ";
    }
    //  Show the 3rd element in the deque
    std::cout << "\nThe 3rd element is: " << deq.at(2) << std::endl;
    
    std::cout << "\n" << std::endl;
    
    /*----------------------------------------------------*/
    
    
    
    return 0;
}

