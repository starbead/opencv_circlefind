// assignment2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

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

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
