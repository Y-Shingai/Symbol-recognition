// -*- C++ -*-
/*!
 * @file  symbolrecognition.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "symbolrecognition.h"
#pragma warning(disable:4819)
 //OpenCV
# include <iostream>
# include <opencv2/core/core.hpp>
# include <opencv2/imgproc/imgproc.hpp>
# include <opencv2/highgui/highgui.hpp>

#define WIDTH 320
#define HEIGHT 240

 // bool 
bool tyokushin = false;
bool koutai = false;
bool migisen = false;
bool hidarisen = false;

using namespace std;
using namespace cv;

// Module specification
// <rtc-template block="module_spec">
static const char* symbolrecognition_spec[] =
  {
    "implementation_id", "symbolrecognition",
    "type_name",         "symbolrecognition",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "yukiya shingai",
    "category",          "Example",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
symbolrecognition::symbolrecognition(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_vel2DOut("vel2D", m_vel2D)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
symbolrecognition::~symbolrecognition()
{
}

VideoCapture cap;

RTC::ReturnCode_t symbolrecognition::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  addOutPort("vel2D", m_vel2DOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>

  cout << "Camera Activation" << endl;

  cap = VideoCapture(0);
  cap.set(CV_CAP_PROP_FRAME_WIDTH, WIDTH);
  cap.set(CV_CAP_PROP_FRAME_HEIGHT, HEIGHT);

  if (!cap.isOpened()) {
	  return RTC::RTC_ERROR;
  }
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t symbolrecognition::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t symbolrecognition::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t symbolrecognition::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t symbolrecognition::onActivated(RTC::UniqueId ec_id)
{
	cout << "Recognize Symbol" << endl;
	namedWindow("search img", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);
  return RTC::RTC_OK;
}


RTC::ReturnCode_t symbolrecognition::onDeactivated(RTC::UniqueId ec_id)
{
	cout << "Finish" << endl;
	destroyAllWindows();
  return RTC::RTC_OK;
}


RTC::ReturnCode_t symbolrecognition::onExecute(RTC::UniqueId ec_id)
{
	//Template Image
	Mat tmp_imgs[4];
	tmp_imgs[0] = imread("C:/Users/�V�K�K��/workspace/Symbol recognition/src/houkou/mae.png", 1);
	tmp_imgs[1] = imread("C:/Users/�V�K�K��/workspace/Symbol recognition/src/houkou/usiro.png", 1);
	tmp_imgs[2] = imread("C:/Users/�V�K�K��/workspace/Symbol recognition/src/houkou/hidarisenkai.png", 1);
	tmp_imgs[3] = imread("C:/Users/�V�K�K��/workspace/Symbol recognition/src/houkou/migisenkai.png", 1);
	if (!tmp_imgs[0].data || !tmp_imgs[1].data || !tmp_imgs[2].data || !tmp_imgs[3].data) {
		cout << "Temlate" << endl;
		return RTC::RTC_ERROR;
	}

	//Border color
	Scalar cols[4];
	cols[0] = Scalar(0, 255, 0);
	cols[1] = Scalar(255, 0, 0);
	cols[2] = Scalar(0, 0, 255);
	cols[3] = Scalar(0, 255, 255);

	//Search image
	Mat search_img0;
	cap >> search_img0;
	Mat search_img;
	search_img0.copyTo(search_img);

	/////Go ahead
	Mat &tmp_img0 = tmp_imgs[0];
	Mat result_img0;
	for (int i = 0; i < 1; i++) {
		//Template Matching
		matchTemplate(search_img, tmp_img0, result_img0, CV_TM_CCOEFF_NORMED);
		//Find the place with the maximum score
		Rect roi_rect(0, 0, tmp_img0.cols, tmp_img0.rows);
		Point max_pt;
		double maxVal;
		minMaxLoc(result_img0, NULL, &maxVal, NULL, &max_pt);
		//When the score is less than or equal to the certain score
		if (maxVal < 0.7)
		{
			tyokushin = false;
			break;
		}

		roi_rect.x = max_pt.x;
		roi_rect.y = max_pt.y;
		cout << "Go ahead" << ", (" << max_pt.x << "," << max_pt.y << "), score=" << maxVal << endl;
		//Show score in place of search results
		rectangle(search_img0, roi_rect, cols[0], 3);
		rectangle(search_img, roi_rect, Scalar(0, 0, 255), CV_FILLED);

		if (maxVal >= 0.7) {
			tyokushin = true;
			m_vel2D.data.vx = 0.5;
			m_vel2D.data.va = 0;
		}

	}

	////Go back
	Mat &tmp_img1 = tmp_imgs[1];
	Mat result_img1;
	for (int i = 0; i < 1; i++) {
		//Template Matching
		matchTemplate(search_img, tmp_img1, result_img1, CV_TM_CCOEFF_NORMED);
		//Find the place with the maximum score
		Rect roi_rect(0, 0, tmp_img1.cols, tmp_img1.rows);
		Point max_pt;
		double maxVal;
		minMaxLoc(result_img1, NULL, &maxVal, NULL, &max_pt);
		//When the score is less than or equal to the certain score
		if (maxVal < 0.7)
		{
			koutai = false;
			break;
		}

		roi_rect.x = max_pt.x;
		roi_rect.y = max_pt.y;
		cout << "Go back" << ", (" << max_pt.x << "," << max_pt.y << "), score=" << maxVal << endl;
		//Show score in place of search results
		rectangle(search_img0, roi_rect, cols[1], 3);
		rectangle(search_img, roi_rect, Scalar(0, 0, 255), CV_FILLED);

		if (maxVal >= 0.7) {
			koutai = true;
			m_vel2D.data.vx = -0.5;
			m_vel2D.data.va = 0;
		}


	}

	/////Left Turn
	Mat &tmp_img2 = tmp_imgs[2];
	Mat result_img2;
	for (int i = 0; i < 1; i++) {
		//Template Matching
		matchTemplate(search_img, tmp_img2, result_img2, CV_TM_CCOEFF_NORMED);
		//Find the place with the maximum score
		Rect roi_rect(0, 0, tmp_img2.cols, tmp_img2.rows);
		Point max_pt;
		double maxVal;
		minMaxLoc(result_img2, NULL, &maxVal, NULL, &max_pt);
		//When the score is less than or equal to the certain score	
		if (maxVal < 0.8)
		{
			hidarisen = false;
			break;
		}

		roi_rect.x = max_pt.x;
		roi_rect.y = max_pt.y;
		cout << "Left Turn" << ", (" << max_pt.x << "," << max_pt.y << "), score=" << maxVal << endl;
		//Show score in place of search results
		rectangle(search_img0, roi_rect, cols[2], 3);
		rectangle(search_img, roi_rect, Scalar(0, 0, 255), CV_FILLED);

		if (maxVal >= 0.8) {
			hidarisen = true;
			m_vel2D.data.vx = 0;
			m_vel2D.data.va = 0.1;
		}


	}

	////Right Turn
	Mat &tmp_img3 = tmp_imgs[3];
	Mat result_img3;
	for (int i = 0; i < 1; i++) {
		//Template Matching
		matchTemplate(search_img, tmp_img3, result_img3, CV_TM_CCOEFF_NORMED);
		//Find the place with the maximum score
		Rect roi_rect(0, 0, tmp_img3.cols, tmp_img3.rows);
		Point max_pt;
		double maxVal;
		minMaxLoc(result_img3, NULL, &maxVal, NULL, &max_pt);
		//When the score is less than or equal to the certain score
		if (maxVal < 0.71)
		{
			migisen = false;
			break;
		}

		roi_rect.x = max_pt.x;
		roi_rect.y = max_pt.y;
		cout << "Right Turn" << ", (" << max_pt.x << "," << max_pt.y << "), score=" << maxVal << endl;
		//Show score in place of search results
		rectangle(search_img0, roi_rect, cols[3], 3);
		rectangle(search_img, roi_rect, Scalar(0, 0, 255), CV_FILLED);

		if (maxVal >= 0.71) {
			migisen = true;
			m_vel2D.data.vx = 0;
			m_vel2D.data.va = -0.1;
		}


	}

	if (!tyokushin && !koutai && !migisen && !hidarisen)
	{
		m_vel2D.data.vx = 0;
		m_vel2D.data.va = 0;
	}

	imshow("search img", search_img0);
	waitKey(1);
	m_vel2DOut.write();
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t symbolrecognition::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t symbolrecognition::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t symbolrecognition::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t symbolrecognition::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t symbolrecognition::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void symbolrecognitionInit(RTC::Manager* manager)
  {
    coil::Properties profile(symbolrecognition_spec);
    manager->registerFactory(profile,
                             RTC::Create<symbolrecognition>,
                             RTC::Delete<symbolrecognition>);
  }
  
};


