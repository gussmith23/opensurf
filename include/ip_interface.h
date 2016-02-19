

#ifndef _IP_INTERFACE_H_
#define _IP_INTERFACE_H_

#include "surflib.h"
#include "kmeans.h"
#include <ctime>
#include <iostream>

#include <vector>

using namespace std;
using namespace cv;

#ifdef __cplusplus
extern "C" __declspec(dllexport) int __stdcall extractInterestPoints(int width, int height, uchar* imageBytes, uchar* iptBytes);
int serializeInterestPoints(vector<Ipoint> &ipts, uchar* iptBytes);
#else
__declspec(dllexport) int __stdcall extractInterestPoints(int width, int height, uchar* imageBytes, uchar* iptBytes);
int serializeInterestPoints(vector<Ipoint> &ipts, uchar* iptBytes);
#endif

#endif