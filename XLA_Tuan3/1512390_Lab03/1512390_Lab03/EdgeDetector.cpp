#include "stdafx.h"
#include "EdgeDetector.h"


EdgeDetector::EdgeDetector()
{
}


EdgeDetector::~EdgeDetector()
{
}

int EdgeDetector::DetectEdge(const Mat& sourceImage, Mat& destinationImage, int kWidth, int kHeight, int method)
{
	switch (method)
	{
	case 0:
	{
		/*int pixel_x, pixel_y;
		int value;
		int sobel_x[3][3];
		int sobel_y[3][3];
		sobel_x[0][0] = -1;
		sobel_x[0][1] = 0;
		sobel_x[0][2] = 1;
		sobel_x[1][0] = -2;
		sobel_x[1][1] = 0;
		sobel_x[1][2] = 2;
		sobel_x[2][0] = -1;
		sobel_x[2][1] = 0;
		sobel_x[2][2] = 1;

		*/

		vector<float>sobel_x;
		sobel_x.push_back(-0.25);
		sobel_x.push_back(0);
		sobel_x.push_back(0.25);
		sobel_x.push_back(-0.5);
		sobel_x.push_back(0);
		sobel_x.push_back(0.5);
		sobel_x.push_back(-0.25);
		sobel_x.push_back(0);
		sobel_x.push_back(0.25);
		
		Mat Gradient_x = Mat::zeros(sourceImage.size(),sourceImage.type());
		Convolution conv;
		conv.SetKernel(sobel_x, 3, 3);
		conv.DoConvolution(sourceImage, Gradient_x);


		/*sobel_y[0][0] = -1;
		sobel_y[0][1] = -2;
		sobel_y[0][2] = -1;
		sobel_y[1][0] = 0;
		sobel_y[1][1] = 0;
		sobel_y[1][2] = 0;
		sobel_y[2][0] = 1;
		sobel_y[2][1] = 2;
		sobel_y[2][2] = 1;*/
		vector<float>sobel_y;
		sobel_y.push_back(-0.25);
		sobel_y.push_back(-0.5);
		sobel_y.push_back(-0.25);
		sobel_y.push_back(0);
		sobel_y.push_back(0);
		sobel_y.push_back(0);
		sobel_y.push_back(0.25);
		sobel_y.push_back(0.5);
		sobel_y.push_back(0.25);


		Mat Gradient_y = Mat::zeros(sourceImage.size(), sourceImage.type());
		
		conv.SetKernel(sobel_y, 3, 3);
		conv.DoConvolution(sourceImage, Gradient_y);

		
		for (int y = 0; y < sourceImage.rows; y++)
		{
			for (int x = 0; x < sourceImage.cols; x++)
			{
			float flag = (float)sqrt(Gradient_x.at<uchar>(y, x)*Gradient_x.at<uchar>(y, x) + Gradient_y.at<uchar>(y, x)*Gradient_y.at<uchar>(y, x));
				if (flag < 256 && flag>0)
				//	cout << flag << endl;
				destinationImage.at<uchar>(y, x) = sqrt(Gradient_x.at<uchar>(y,x)*Gradient_x.at<uchar>(y, x) + Gradient_y.at<uchar>(y, x)*Gradient_y.at<uchar>(y, x));
				
			}
		}
		

	}
	break;
	case 1:
	{
		/*int pixel_x, pixel_y;
		int value;
		int sobel_x[3][3];
		int sobel_y[3][3];
		sobel_x[0][0] = -1;
		sobel_x[0][1] = 0;
		sobel_x[0][2] = 1;
		sobel_x[1][0] = -2;
		sobel_x[1][1] = 0;
		sobel_x[1][2] = 2;
		sobel_x[2][0] = -1;
		sobel_x[2][1] = 0;
		sobel_x[2][2] = 1;

		*/

		vector<float>sobel_x;
		sobel_x.push_back((float)1/3);
		sobel_x.push_back(0);
		sobel_x.push_back((float)-1/3);
		sobel_x.push_back((float)1 / 3);
		sobel_x.push_back(0);
		sobel_x.push_back((float)-1 / 3);
		sobel_x.push_back((float)1 / 3);
		sobel_x.push_back(0);
		sobel_x.push_back((float)-1 / 3);

		Mat Gradient_x = Mat::zeros(sourceImage.size(), sourceImage.type());
		Convolution conv;
		conv.SetKernel(sobel_x, 3, 3);
		conv.DoConvolution(sourceImage, Gradient_x);


		/*sobel_y[0][0] = -1;
		sobel_y[0][1] = -2;
		sobel_y[0][2] = -1;
		sobel_y[1][0] = 0;
		sobel_y[1][1] = 0;
		sobel_y[1][2] = 0;
		sobel_y[2][0] = 1;
		sobel_y[2][1] = 2;
		sobel_y[2][2] = 1;*/
		vector<float>sobel_y;
		sobel_y.push_back((float)-1 / 3);
		sobel_y.push_back((float)-1 / 3);
		sobel_y.push_back((float)-1 / 3);
		sobel_y.push_back(0);
		sobel_y.push_back(0);
		sobel_y.push_back(0);
		sobel_y.push_back((float)1 / 3);
		sobel_y.push_back((float)1 / 3);
		sobel_y.push_back((float)1 / 3);


		Mat Gradient_y = Mat::zeros(sourceImage.size(), sourceImage.type());

		conv.SetKernel(sobel_y, 3, 3);
		conv.DoConvolution(sourceImage, Gradient_y);


		for (int y = 0; y < sourceImage.rows; y++)
		{
			for (int x = 0; x < sourceImage.cols; x++)
			{
				float flag = (float)sqrt(Gradient_x.at<uchar>(y, x)*Gradient_x.at<uchar>(y, x) + Gradient_y.at<uchar>(y, x)*Gradient_y.at<uchar>(y, x));
				if (flag < 256 && flag>0)
					//	cout << flag << endl;
					destinationImage.at<uchar>(y, x) = sqrt(Gradient_x.at<uchar>(y, x)*Gradient_x.at<uchar>(y, x) + Gradient_y.at<uchar>(y, x)*Gradient_y.at<uchar>(y, x));

			}
		}

	}
	break;
	case 2:
	{
		vector<float>laplace;
		laplace.push_back(1);
		laplace.push_back(1);
		laplace.push_back(1);
		laplace.push_back(1);
		laplace.push_back(-8);
		laplace.push_back(1);
		laplace.push_back(1);
		laplace.push_back(1);
		laplace.push_back(1);
		Convolution conv;
		conv.SetKernel(laplace, 3, 3);
		Mat Laplace = Mat::zeros(sourceImage.size(), sourceImage.type());
		conv.DoConvolution(sourceImage, Laplace);
		for (int y = 0; y < sourceImage.rows; y++)
		{
			for (int x = 0; x < sourceImage.cols; x++)
			{
				
				if ( Laplace.at<uchar>(y,x) >100)
					//	cout << flag << endl;
					destinationImage.at<uchar>(y, x) = Laplace.at<uchar>(y, x);

			}
		}
	}
	break;
	default:
		break;
	}

	return 1;
}
