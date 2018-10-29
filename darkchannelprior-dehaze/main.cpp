#include "dcp.h"

int main()
{
	IplImage *input = cvLoadImage("./img/xyj2/mid1825.jpg");
	IplImage *result = cvCreateImage(cvGetSize(input), IPL_DEPTH_8U, 3);
	dehaze(result, input);

	cvSaveImage("result.bmp", result);
	cvReleaseImage(&result);
	cvReleaseImage(&input);
	cv::waitKey();
	return 0;
}
