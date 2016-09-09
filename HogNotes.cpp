int VL_GetHOGFeature(int *pFeature, unsigned char* pSrc,int iW,int iH)
{

	//cv::HOGDescriptor tHog;
	cv::Mat img(iH,iW,CV_8UC1);
	img.data = pSrc;
	//IplImage* img= cvCreateImage(cvSize(iW,iH),8,1);
	//img->imageData = (char*)pSrc;
	//vector<float> descriptors;
	//tHog.compute(img,descriptors,cv::Size(1,1), cv::Size(0,0));
	cv::HOGDescriptor *hog=new cv::HOGDescriptor(cvSize(width_image_BP,height_image_BP),cvSize(16,16),cvSize(8,8),cvSize(8,8),9);   //������˼���ο�����1,2
	vector<float>descriptors(3780);//�������
	hog->compute(img, descriptors,cv::Size(1,1), cv::Size(0,0)); //���ü��㺯����ʼ����

	//cvReleaseImage(&img);
	delete hog;

	for (int r = 0; r < descriptors.size(); ++r) 
	{
		pFeature[r] = descriptors[r]*1000000;
	}

	
	return 0;
}

