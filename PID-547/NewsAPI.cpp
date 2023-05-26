#include "NewsAPI.h"


#include<iostream>
#include<memory>
#include<fstream>
#include<string>


#include <tesseract/baseapi.h>
#include <opencv2/opencv.hpp>


std::string NewsAPI::getNews()
{
	try
	{

		std::string IMAGEPATH;

		std::cout << " Enter Image Path: ";
		std::cin >> IMAGEPATH;

		std::ifstream image_checker;
		image_checker.open(IMAGEPATH);
		

		std::string exception = "NO SUCH FILE FOUND";
		if (!image_checker.is_open()) { throw std::exception(exception.c_str()); }

		std::unique_ptr<tesseract::TessBaseAPI> tess = std::make_unique<tesseract::TessBaseAPI>();

		tess->Init(nullptr, "eng");

		tess->SetVariable("user_defined_dpi", "70");
		
		tess->SetVariable("tessedit_char_whitelist", "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789'-\"$");



		cv::Mat image = cv::imread(IMAGEPATH);
		tess->SetImage(image.data, image.cols, image.rows, image.channels(), image.step1());

		std::string output = tess->GetUTF8Text();
		
		//std::cout << " Result: " << output << "\n";

		return output;

	}
	catch (std::exception& ex)
	{
		std::cout << "[!!!] " << ex.what() << " [!!!]\n" << std::endl;
	}
}


std::string NewsAPI::cleanstring(std::string data)
{
	int stringsize = data.length() ;

	std::string cleanedstring;

	for (int i = 0; i < stringsize; i++)
	{
		if (data[i] != '\n') { cleanedstring = cleanedstring + data[i]; }
		else { cleanedstring = cleanedstring + " "; }
	}

	return cleanedstring;

}