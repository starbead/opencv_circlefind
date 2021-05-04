#include "pch.h"
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;

int main()
{	
	Mat input = imread("coins5.jpg");
	Mat gray_input;
	cvtColor(input, gray_input, CV_BGR2GRAY);
	Mat blur, thres, canny, output;
	vector<Vec3f> circles;

	GaussianBlur(gray_input, blur, Size(5, 5), 2);

	threshold(blur, thres, 225, 255, THRESH_BINARY);

	Canny(blur, canny, 1, 255);
	
	HoughCircles(canny, circles, CV_HOUGH_GRADIENT, 1, 80, 200, 15, 42, 120);

	for (size_t i = 0; i < circles.size(); i++) {
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		circle(input, center, 3, Scalar(0, 255, 0), -1);
		circle(input, center, radius, Scalar(0, 0, 255), 3);
	}
	

	imshow("input", input);
	imshow("thres", thres);
	imshow("canny", canny);

	waitKey();
}
