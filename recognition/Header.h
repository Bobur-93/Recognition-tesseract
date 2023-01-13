#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
#include <iomanip>
#include <direct.h>
#include <sys/stat.h>
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/fuzzy/types.hpp"

using namespace tesseract;
using namespace std;
using namespace cv;

int image_test(char* path_read, char* path_write, int iter);
int main();
//int recognize(char* path, int line_length);
int template_for_a_private_person(char* path_for_pattern, int num_of_num, int iter);
int template_for_a_entity(char* path_for_pattern, int num_of_num, int iter);
int template_for_a_square_number(char* path_for_pattern, int num_of_num, int iter);
void scan_roi(char* path_for_pattern, int num_of_num, int type_pattern);