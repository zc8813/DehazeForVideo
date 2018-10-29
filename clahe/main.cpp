#include <iostream>
#include <cv.h>
#include <highgui.h>
using namespace std;

#if 0
int main()
{

    cv::Mat inp_img = cv::imread("./img/source.jpg");
	if (!inp_img.data) {
		cout << "Something Wrong" << endl;
		return -1;
	}
	cv::namedWindow("Input Image", CV_WINDOW_AUTOSIZE);
	cv::imshow("Input Image", inp_img);

	cv::Mat clahe_img;
	cv::cvtColor(inp_img, clahe_img, CV_BGR2Lab);
	std::vector<cv::Mat> channels(3);
	cv::split(clahe_img, channels);

	cv::Ptr<cv::CLAHE> clahe = cv::createCLAHE();
	// 直方图的柱子高度大于计算后的ClipLimit的部分被裁剪掉，然后将其平均分配给整张直方图
	// 从而提升整个图像
	clahe->setClipLimit(2.);	// (int)(4.*(8*8)/256)
	//clahe->setTilesGridSize(Size(8, 8)); // 将图像分为8*8块
	cv::Mat dst;
	clahe->apply(channels[0], dst);
	dst.copyTo(channels[0]);
	cv::merge(channels, clahe_img);

	cv::Mat image_clahe;
	cv::cvtColor(clahe_img, image_clahe, CV_Lab2BGR);

	//cout << cvFloor(-1.5) << endl;

	cv::namedWindow("CLAHE Image", CV_WINDOW_AUTOSIZE);
	cv::imshow("CLAHE Image", image_clahe);
	imwrite("out.jpg", image_clahe);
	cv::waitKey(0);
	cv::destroyAllWindows();

    return 0;
}

#endif
