
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <vector>
using namespace cv;
using namespace std;


/////////////////  Images  //////////////////////
//void main() {
//
//	string path = "test.jpg";
//	Mat img = imread(path);
//	imshow("Image", img);
//	waitKey(0);
//
//}

///////////////  Video  //////////////////////
//void main() {
//
//	string path = "Resources/test_video.mp4";
//	VideoCapture cap(path);
//	Mat img;
//
//	while (true) {
//
//		cap.read(img);
//		imshow("Image", img);
//		waitKey(20);
//	}
//}

/////////////////  Webcam  //////////////////////
//void main() {
//
//	VideoCapture cap(0);
//	Mat img;
//
//	while (true) {
//
//		cap.read(img);
//		imshow("Image", img);
//		waitKey(1);
//	}
//}

///////////////  Basic Functions in Open CV //////////////////////
//void main() {
//
//	string path = "D:/OpenCV-Cours/test.jpg";
//	Mat img = imread(path);
//	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;
//
//	cvtColor(img, imgGray, COLOR_BGR2GRAY);
//	GaussianBlur(imgGray, imgBlur, Size(7, 7), 5, 0);
//	Canny(imgBlur, imgCanny, 25, 75);
//
//	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
//	dilate(imgCanny, imgDil, kernel);
//	erode(imgDil, imgErode, kernel);
//
//	imshow("Image", img);
//	imshow("Image Gray", imgGray);
//	imshow("Image Blur", imgBlur);
//	imshow("Image Canny", imgCanny);
//	imshow("Image Dilation", imgDil);
//	imshow("Image Erode", imgErode);
//	waitKey(0);
//}


///////////////  Black and White image : MyAlgo and OpenCV //////////////////////
//void BlackWhiteImg(Mat image)
//{
//	Mat newImage(920, 750, CV_8UC3);
//	Mat imgGray;
//	cout << "image size is " << image.size << "\n"; //get size of my image
//	cout << "Number of line of this image is : " << image.size[1] << "\n"; //number of line of the image 
//	cout << "Number of column of this image is : " << image.size[0] << "\n"; //number of column
//
//	for (int j=0; j < image.size[0]; j++) //number of columns
//	{
//		for (int i = 0; i < image.size[1]; i++) //number of lines
//		{
//			newImage.at<cv::Vec3b>(j, i).val[0] =0.0722f * image.at<cv::Vec3b>(j, i).val[0] + 0.7152f * image.at<cv::Vec3b>(j, i).val[1] + 0.2126f * image.at<cv::Vec3b>(j, i).val[2];
//			newImage.at<cv::Vec3b>(j, i).val[1] =0.0722f * image.at<cv::Vec3b>(j, i).val[0] + 0.7152f * image.at<cv::Vec3b>(j, i).val[1] + 0.2126f * image.at<cv::Vec3b>(j, i).val[2];
//			newImage.at<cv::Vec3b>(j, i).val[2] =0.0722f * image.at<cv::Vec3b>(j, i).val[0] + 0.7152f * image.at<cv::Vec3b>(j, i).val[1] + 0.2126f * image.at<cv::Vec3b>(j, i).val[2];
//		}
//	}
//	imshow("Image de base ", image);
//	imshow("Image grisepar mon algo", newImage);
//
//	cvtColor(image, imgGray, COLOR_BGR2GRAY);
//	imshow("Image grise par openCV", imgGray);
//
//	waitKey(0);
//}
//
//void main() 
//{
//	string path = "D:/OpenCV-Cours/test.jpg";
//	Mat img = imread(path);
//	BlackWhiteImg(img);
//}


////////// Bluring Algo ///////////
int main() 
{
	string path = "D:/OpenCV-Cours/test.jpg";
	Mat img = imread(path);
	Mat imgBlur;

	for (int i = 0; img.size[1] - 2; i++) 
	{
		for (int j = 0; img.size[0] - 2; j++) 
		{
			
			for (int a = 1; 3; a++) 
			{
				for (int b = 1; 3; b++)
				{
					img.at<cv::Vec3b>(j + 1, i + 1).val[0] = produitDeCoonvolution(i, j, img, 0);
					img.at<cv::Vec3b>(j + 1, i + 1).val[1] = produitDeCoonvolution(i, j, img, 1);
					img.at<cv::Vec3b>(j + 1, i + 1).val[2] = produitDeCoonvolution(i, j, img, 2);

				}
			}
		}

	}
	imshow("image de base", img);
	imshow("image floutée", imgBlur);

	waitKey(0);

}

float produitDeCoonvolution(int i, int j, Mat im, int index)
{
	float result = 0; 
	for (int a = 0; 3; a++) 
	{
		for (int b = 0; 3; b++) 
		{
			result = result + im.at<cv::Vec3b>(b + j, a + i).val[index];
		}
	}
	return result/9;
}

///////// Canny (détection de contours) ///////



//////// Dilation ////////////



//////// Erosion /////////