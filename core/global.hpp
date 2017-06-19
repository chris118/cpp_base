//
//  global.hpp
// 
//
//  Created by xiaopeng.
//  Copyright  All rights reserved.
//

#include <vector>
#pragma once 

#ifndef GLOBAL
#define GLOBAL

#define max(a, b) (((a)>(b)) ? (a) :(b))
#define min(a, b) (((a)<(b)) ? (a) :(b))

 //Using for box sort
 struct Info
 {
     float score;
     const float* head;
 };
 
  bool compare(const Info& Info1, const Info& Info2)
 {
     return Info1.score > Info2.score;
 }
#endif
