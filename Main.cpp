/************************************************************************/
/* This source code is free for both academic and industry use.         */
/* Some important information for better using the source code could be */
/* found in the project page: http://mmcheng.net/bing					*/
/************************************************************************/

#include "stdafx.h"
#include "Objectness.h"
#include "ValStructVec.h"
#include "CmShow.h"

// Uncomment line line 14 in Objectness.cpp to remove counting times of image reading.

void RunObjectness(CStr &resName, double base, int W, int NSS, int numPerSz);

int main(int argc, char* argv[])
{
	//DataSetVOC::importImageNetBenchMark();
	//DataSetVOC::cvt2OpenCVYml("D:/WkDir/DetectionProposals/VOC2007/Annotations/");
	RunObjectness("WinRecall.m", 2, 8, 2, 130);
	return 0;
}

void RunObjectness(CStr &resName, double base, int W, int NSS, int numPerSz)
{
	srand((unsigned int)time(NULL));
	DataSetVOC voc2007("D:/WkDir/DetectionProposals/VOC2007/");
	voc2007.loadAnnotations();
	//voc2007.loadDataGenericOverCls();

	printf("Dataset:`%s' with %d training and %d testing\n", _S(voc2007.wkDir), voc2007.trainNum, voc2007.testNum);
	printf("%s Base = %g, W = %d, NSS = %d, perSz = %d\n", _S(resName), base, W, NSS, numPerSz);
	
	Objectness objNess(voc2007, base, W, NSS);

	vector<vector<Vec4i>> boxesTests;
	//objNess.getObjBndBoxesForTests(boxesTests, 250);
	objNess.getObjBndBoxesForTestsFast(boxesTests, numPerSz);
	//objNess.getRandomBoxes(boxesTests);
	//objNess.evaluatePerClassRecall(boxesTests, resName, 1000);
	//objNess.illuTestReults(boxesTests);
}

