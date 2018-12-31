#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <fstream>
#include "vector"

#include "MetaClass.h"
#include "Obj.cpp"

using namespace std;
using namespace cv;

int main(int argc, const char** argv)
{
	int width = 800;
	int height = 600;
	string window_name1 = "Depth";
	string window_name2 = "Shadow";
	if (false)
	{
		cout << "You should use this pram by this format:" << endl;
		cout << "interval_scan_line example.obj" << endl;
		system("pause");
		return 0;
	}
	string filename(argv[1]);

	Obj obj;
	obj.setFrameSize(800, 600);
	int state = obj.load(filename);
	if (!state)
	{
		cout << "[File Wrong]: " << filename <<  " open wrong!" << endl;
		system("pause");
		return 0;
	}
	obj.makeScale();
	obj.render();
	namedWindow(window_name1);
	imshow(window_name1, obj.imgDepth);
	imshow(window_name2, obj.mat);

	while (1)
	{
		int key = waitKey(0);
		if (key == 27)
		{
			destroyAllWindows();
			exit(0);
			break;
		}
		else
		{
			obj.change(key);
		}
		obj.render();
		imshow(window_name1, obj.imgDepth);
		imshow(window_name2, obj.mat);
	}
	system("pause");
	return 0;
}
