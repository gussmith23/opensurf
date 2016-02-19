
#include "ip_interface.h"




extern "C" __declspec(dllexport) int __stdcall extractInterestPoints(int width, int height, uchar* imageBytes, uchar* iptBytes)
{
	
	Mat imageAsMat(height,width,CV_8UC1,imageBytes);
	IplImage imageAsIPL = imageAsMat;

	IpVec ipts1;
	surfDetDes(&imageAsIPL,ipts1,false,4,4,2,0.0001f);
	serializeInterestPoints(ipts1,iptBytes);

	return 0;
}

int serializeInterestPoints(vector<Ipoint> &ipts, uchar* iptBytes)
{
	Ipoint *ipt;
	float s, o;
	int r1, c1, r2, c2, lap;

	for(unsigned int i = 0; i < ipts.size(); i++) 
	{
		ipt = &ipts.at(i);
		s = (2.5f * ipt->scale);
		o = ipt->orientation;
		lap = ipt->laplacian;
		r1 = fRound(ipt->y);
		c1 = fRound(ipt->x);
		c2 = fRound(s * cos(o)) + c1;
		r2 = fRound(s * sin(o)) + r1;

		((int*)iptBytes)[(i*7)+0] = *((int*)&s);
		((int*)iptBytes)[(i*7)+1] = *((int*)&o);
		((int*)iptBytes)[(i*7)+2] = *((int*)&lap);
		((int*)iptBytes)[(i*7)+3] = *((int*)&r1);
		((int*)iptBytes)[(i*7)+4] = *((int*)&c1);
		((int*)iptBytes)[(i*7)+5] = *((int*)&c2);
		((int*)iptBytes)[(i*7)+6] = *((int*)&r2);
	}

	return 0;
}