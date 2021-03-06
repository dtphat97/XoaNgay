// 1512390_Lab03.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Convolution.h"
#include "Blur.h"
#include "EdgeDetector.h"

int main()
{
	Mat Src = imread("image.jpg", IMREAD_GRAYSCALE);
	Mat Dst= Mat::zeros(Src.size(),Src.type());
	vector<float> _kernel;
	//for (int i = 0; i < 9; i++)
	//{
	//	_kernel.push_back(1);
	//}
//	Convolution conv;
	//conv.SetKernel(_kernel, 3, 3);
	//conv.DoConvolution(Src, Dst);

	//Blur bl;
	//bl.BlurImage(Src, Dst, 3,3,2);
	EdgeDetector Edge;
	Edge.DetectEdge(Src, Dst, 0, 0, 2);
	namedWindow("Input");
	namedWindow("Output");
	imshow("Input", Src);
	imshow("Output", Dst);
	waitKey(0);
    return 0;
}

