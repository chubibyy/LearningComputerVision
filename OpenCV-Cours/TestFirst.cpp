
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


///////////////  Black and White image : MyAlgo  //////////////////////
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


////////// Bluring Algo MyAlgo ///////////
 
//float produitDeCoonvolution(int i, int j, Mat im, int index)
//{
//	float result = 0; 
//	for (int a = 0; 3; a++) 
//	{
//		for (int b = 0; 3; b++) 
//		{
//			result = result + im.at<cv::Vec3b>(b + j, a + i).val[index];
//		}
//	}
//	return result/9;
//}
//int main(int argc, char** argv)
//{
//	string path = "D:/OpenCV-Cours/test.jpg";
//	Mat img = imread(path);
//	Mat imgBlur;
//
//	for (int i = 0; img.size[1] - 2; i++) 
//	{
//		for (int j = 0; img.size[0] - 2; j++) 
//		{
//			
//			for (int a = 1; 3; a++) 
//			{
//				for (int b = 1; 3; b++)
//				{
//					img.at<cv::Vec3b>(j + 1, i + 1).val[0] = produitDeCoonvolution(i, j, img, 0);
//					img.at<cv::Vec3b>(j + 1, i + 1).val[1] = produitDeCoonvolution(i, j, img, 1);
//					img.at<cv::Vec3b>(j + 1, i + 1).val[2] = produitDeCoonvolution(i, j, img, 2);
//
//				}
//			}
//		}
//
//	}
//	imshow("image de base", img);
//	imshow("image floutée", imgBlur);
//
//	waitKey(0);
//
//}



///////// Canny (détection de contours) ///////

//Mat src, src_gray;
//Mat dst, src_detected_edges;
//int lowThreshold = 10;
//const int max_lowThreshold = 100;
//const int ratio = 3;
//const int kernel_size = 3;
//const char* window_name = "Astolfo edges";
//const string path = "D:/OpenCV-Cours/test.jpg";
//
//static void CannyThreshold(int, void*)
//{
//    GaussianBlur(
//        src_gray,            // input image
//        src_detected_edges, // output image
//        Size(3, 3),        // smoothing window width and height in pixels
//        1.5);             // sigma value, determines how much the image will be blurred
//
//    Canny(
//        src_detected_edges,  // input image
//        src_detected_edges, // output image
//        lowThreshold,      // low threshold
//        lowThreshold * 3, // high threshold
//        kernel_size);    //We defined it to be 3 (the size of the Sobel kernel to be used internally)
//
//    dst = Scalar::all(0); //We fill a dst image with zeros (meaning the image is completely black).
//
//    //Copy the src image onto dst. However, it will only copy the pixels in the locations where they have non-zero values. 
//    //Since the output of the Canny detector is the edge contours on a black background, the resulting dst will be black in all the area but the detected edges
//    //Allow color pixel in the output
//    src.copyTo(dst, src_detected_edges);
//
//    imshow(window_name, dst);
//}
//
//int main(int argc, char** argv)
//{
//    src = imread(path, IMREAD_COLOR); // Load an image
//
//    if (src.empty())
//    {
//        std::cout << "Could not open or find the image!\n" << std::endl;
//        std::cout << "Usage: " << argv[0] << " <Input image>" << std::endl;
//        return -1;
//    }
//    dst.create(src.size(), src.type());
//
//    //Convert into gray image
//    cvtColor(src, src_gray, COLOR_BGR2GRAY);
//
//    namedWindow(window_name, WINDOW_AUTOSIZE);
//    createTrackbar("Min Threshold:", window_name, &lowThreshold, max_lowThreshold, CannyThreshold);
//    CannyThreshold(0, 0);
//    waitKey(0);
//    return 0;
//}

//////// Dilation ////////////

//Mat src, dilation_dst;
//int dilation_elem = 0;
//int dilation_size = 0;
//int const max_elem = 2;
//int const max_kernel_size = 21;
//const string path = "D:/OpenCV-Cours/test.jpg";
//void Dilation(int, void*);
//
//int main(int argc, char** argv)
//{
//    
//    src = imread(path, IMREAD_COLOR);
//    if (src.empty())
//    {
//        cout << "Could not open or find the image!\n" << endl;
//        cout << "Usage: " << argv[0] << " <Input image>" << endl;
//        return -1;
//    }
//
//    namedWindow("Dilation Demo", WINDOW_AUTOSIZE);
//    moveWindow("Dilation Demo", src.cols, 0);
//    createTrackbar("Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Dilation Demo",
//        &dilation_elem, max_elem,
//        Dilation);
//    createTrackbar("Kernel size:\n 2n +1", "Dilation Demo",
//        &dilation_size, max_kernel_size,
//        Dilation);
//    Dilation(0, 0);
//    waitKey(0);
//    return 0;
//}
//void Dilation(int, void*)
//{
//    int dilation_type = 0;
//    if (dilation_elem == 0) { dilation_type = MORPH_RECT; }
//    else if (dilation_elem == 1) { dilation_type = MORPH_CROSS; }
//    else if (dilation_elem == 2) { dilation_type = MORPH_ELLIPSE; }
//    Mat element = getStructuringElement(dilation_type,
//        Size(2 * dilation_size + 1, 2 * dilation_size + 1),
//        Point(dilation_size, dilation_size));
//    dilate(src, dilation_dst, element);
//    imshow("Dilation Demo", dilation_dst);
//}

//////// Erosion /////////

Mat src, erosion_dst;
int erosion_elem = 0;
int erosion_size = 0;
int const max_elem = 2;
int const max_kernel_size = 21;
const string path = "D:/OpenCV-Cours/test.jpg";

void Erosion(int, void*);

int main(int argc, char** argv)
{
    src = imread(path, IMREAD_COLOR);
    if (src.empty())
    {
        cout << "Could not open or find the image!\n" << endl;
        cout << "Usage: " << argv[0] << " <Input image>" << endl;
        return -1;
    }
    namedWindow("Erosion Demo", WINDOW_AUTOSIZE);
    createTrackbar("Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Erosion Demo",
        &erosion_elem, max_elem,
        Erosion);
    createTrackbar("Kernel size:\n 2n +1", "Erosion Demo",
        &erosion_size, max_kernel_size,
        Erosion);
    Erosion(0, 0);
    waitKey(0);
    return 0;
}

void Erosion(int, void*)
{
    int erosion_type = 0;
    if (erosion_elem == 0) { erosion_type = MORPH_RECT; }
    else if (erosion_elem == 1) { erosion_type = MORPH_CROSS; }
    else if (erosion_elem == 2) { erosion_type = MORPH_ELLIPSE; }
    Mat element = getStructuringElement(erosion_type,
        Size(2 * erosion_size + 1, 2 * erosion_size + 1),
        Point(erosion_size, erosion_size));
    erode(src, erosion_dst, element);
    imshow("Erosion Demo", erosion_dst);
}