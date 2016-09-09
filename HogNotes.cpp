int VL_GetHOGFeature(int *pFeature, unsigned char* pSrc,int iW,int iH) 
//图片读取时直接读入灰图，万万不可在内存中进行转换 ，特别是在多次重复计算时 
{

	//cv::HOGDescriptor tHog;
	cv::Mat img(iH,iW,CV_8UC1);
	img.data = pSrc;
	//IplImage* img= cvCreateImage(cvSize(iW,iH),8,1);
	//img->imageData = (char*)pSrc;
	//vector<float> descriptors;
	//tHog.compute(img,descriptors,cv::Size(1,1), cv::Size(0,0));
	cv::HOGDescriptor *hog=new cv::HOGDescriptor(cvSize(width_image_BP,height_image_BP),cvSize(16,16),cvSize(8,8),cvSize(8,8),9);   //戮脽脤氓脪芒脣录录没虏脦驴录脦脛脮脗1,2
	vector<float>descriptors(3780);//陆谩鹿没脢媒脳茅
	hog->compute(img, descriptors,cv::Size(1,1), cv::Size(0,0)); //碌梅脫脙录脝脣茫潞炉脢媒驴陋脢录录脝脣茫

	//cvReleaseImage(&img);
	delete hog;

	for (int r = 0; r < descriptors.size(); ++r) 
	{
		pFeature[r] = descriptors[r]*1000000;
	}

	
	return 0;
}

