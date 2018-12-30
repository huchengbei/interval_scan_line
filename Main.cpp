#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <fstream>
#include "vector"

#include "Obj.cpp"
#include "MetaClass.h"

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
	filename = string("models/teapot.obj");
	filename = string("models/teapot_origin.obj");
	filename = string("models/dolphinsk.obj");
	filename = string("models/duck.obj");
	filename = string("models/desk.obj");
	filename = string("models/through.obj");
	filename = string("models/soccer_ball.obj");
	filename = string("models/non_convex.obj");
	filename = string("models/venus.obj");
	filename = string("models/Tables.obj");
	filename = string("models/desk.obj");
	filename = string("models/cube2.obj");
	filename = string("models/cube.obj");
	filename = string("models/cube3.obj");
	filename = string("models/tables2.obj");
	filename = string("models/cat.obj");
	obj.load(filename);
	obj.makeScale();
	obj.render();
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
		else if (key == 'w')
		{
			obj.rotate('w');
		}
		else if (key == 's')
		{
			obj.rotate('s');
		}
		else if (key == 'a')
		{
			obj.rotate('a');
		}
		else if (key == 'd')
		{
			obj.rotate('d');
		}
		obj.render();
		imshow(window_name1, obj.imgDepth);
		imshow(window_name2, obj.mat);
	}
	system("pause");
	return 0;
}
