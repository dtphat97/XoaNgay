#include "stdafx.h"
#include "Convolution.h"


Convolution::Convolution()
{
}


Convolution::~Convolution()
{
}
vector<float> Convolution::GetKernel()
{
	return this->_kernel;
}

void Convolution::SetKernel(vector<float> kernel, int kWidth, int kHeight)
{
	this->_kernelWidth = kWidth;
	this->_kernelHeight = kHeight;
	for (int i = 0; i < kWidth*kHeight; i++)
	{
		this->_kernel.push_back(kernel[i]);
	}
}
int Convolution::DoConvolution(const Mat& sourceImage, Mat& destinationImage)
{
	destinationImage = Mat::zeros(sourceImage.size(), sourceImage.type());
	
	for (int y = 0; y < sourceImage.rows; y++)
	{
		for (int x = 0; x < sourceImage.cols; x++)
		{
			if (y <= this->_kernelHeight/2 || x <= this->_kernelWidth/2 ||y >(sourceImage.rows -(_kernelHeight/2)-1) || x >( sourceImage.cols-(_kernelWidth/2)-1))
			{
				destinationImage.at<uchar>(y, x) = 0;
			}
			else
			{
				float result = 0;
				for (int yy = 0; yy < _kernelHeight; yy++)
				{
					for (int xx = 0; xx < _kernelWidth; xx++)
					{
						result += _kernel[yy*_kernelWidth + xx] * sourceImage.at<uchar>(y - _kernelHeight / 2 - 1 + yy,x - _kernelWidth / 2 - 1 + xx);
					}

				}
				destinationImage.at<uchar>(y, x) = (uchar)result;
			}
		}
	}
	return 1;

}