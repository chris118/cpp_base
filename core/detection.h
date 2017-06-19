//
//  detection.h
// 
//
//  Created by xiaopeng.
//  Copyright  All rights reserved.
//

#include <vector>
#pragma once 
//#define DLL_EXPORT __declspec(dllexport)

struct DetectObject
{
	int x;
	int y;
	int width;
	int height;
	float credibility;
	
	DetectObject()
	{
		x = 0;
		y = 0;
		width = 0;
		height = 0;
		credibility = 0;
	}
};

struct HHColor
{
	int r;
	int g;
	int b;
};

struct CarInfo
{
	DetectObject base;
	int type;
	HHColor Color;
	CarInfo()
	{
		type = 0;
	}
};

struct CarResult
{
	int count;		
	std::vector<CarInfo> carInfo;	
	CarResult()
	{
		count = 0;
	}	
};


struct HelmetWaistcoatInfo
{
    DetectObject base;
    int type;
    HHColor Color;
	HelmetWaistcoatInfo()
	{
	   type = 0;
	}
};

struct HelmetWaistcoatResult
{
    int count;
    std::vector<HelmetWaistcoatInfo> detectInfo;
	HelmetWaistcoatResult()
	{
		count = 0;
	}
};

//extern "C" DLL_EXPORT 
//extern "C" DLL_EXPORT void Free(CarResult result);
