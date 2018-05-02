#include "stdafx.h"
#include "Blur.h"


Blur::Blur()
{
}


Blur::~Blur()
{
}
void Selection(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int iMin = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[iMin] > a[j])
				iMin = j;
		}
		if (i != iMin)
			swap(a[i], a[iMin]);
	}
}
int Blur::BlurImage(const Mat& sourceImage, Mat& destinationImage, int kWidth, int kHeight, int method)
{
	switch (method)
	{
	case 0:
	{
		Convolution conv;
		vector<float> _kernel;
		for (int i = 0; i <kWidth*kHeight; i++)
		{
			_kernel.push_back((float)1/((float)kWidth*kHeight));
		}
		conv.SetKernel(_kernel, kWidth, kHeight);
		conv.DoConvolution(sourceImage, destinationImage);
	}
	break;
	case 1:
	{
		destinationImage = Mat::zeros(sourceImage.size(), sourceImage.type());

		for (int y = 0; y < sourceImage.rows; y++)
		{
			for (int x = 0; x < sourceImage.cols; x++)
			{
				if (y <= kHeight / 2|| x <= kWidth / 2 || y >(sourceImage.rows - (kHeight / 2)-1 ) || x >(sourceImage.cols - (kWidth / 2)-1 ))
				{
					destinationImage.at<uchar>(y, x) = 0;
				}
				else
				{
					int *result = new int[kHeight*kWidth];
					for (int yy = 0; yy < kHeight; yy++)
					{
						for (int xx = 0; xx < kWidth; xx++)
						{
							result[yy*kWidth +xx] = sourceImage.at<uchar>(y - kHeight / 2 - 1 + yy, x - kWidth / 2 - 1 + xx);
						}
					
					}
				
					Selection(result, kHeight*kWidth);
					if (result[(kHeight*kWidth) / 2 + 1] <256)
					destinationImage.at<uchar>(y, x) = result[(kHeight*kWidth)/2+1];
				}
			
			}
		}
	}
	break;
	case 2:
	{
		//phat sinh hàm gauss
		Convolution conv;
		vector<float> _index;
		for (int i = -kWidth/2; i < kWidth/2+1; i++)
		{
			for (int j = -kHeight/2; j < kHeight/2+1; j++)
			{
				//float a1 = (float)1 / ((sqrt(2 * PI)*Sigma));
				//float a2 = exp(-(i*i + j * j) / (2 * Sigma*Sigma));
				_index.push_back(((float)1 / ((sqrt(2 * PI)*Sigma))) * (exp(-(i*i + j * j) / (2 * Sigma*Sigma))));
			}
		}
		conv.SetKernel(_index, kWidth, kHeight);
		conv.DoConvolution(sourceImage, destinationImage);
	}
	break;
	default:
		break;
	}

	return 1;
}