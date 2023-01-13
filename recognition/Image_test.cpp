#include "Header.h"


int inv_f(char* str, int iter)
{
    int i, number_rank;

    if (iter >= 1000)
    {
        number_rank = 4;
        i = iter / 1000;
        str[0] = i + '0';
        iter = iter - (i * 1000);
        i = iter / 100;
        str[1] = i + '0';
        iter = iter - (i * 100);
        i = iter / 10;
        str[2] = i + '0';
        iter = iter - (i * 10);
        str[3] = iter + '0';
        return number_rank;
    }
    else
    {
        if (iter >= 100)
        {
            number_rank = 3;
            i = iter / 100;
            str[0] = i + '0';
            iter = iter - (i * 100);
            i = iter / 10;
            str[1] = i + '0';
            iter = iter - (i * 10);
            str[2] = iter + '0';
            return number_rank;
        }
        else
        {
            if (iter >= 10)
            {
                number_rank = 2;
                i = iter / 10;
                //cout << i << '\n';
                str[0] = i + '0';
                iter = iter - (i * 10);
                //cout << iter << '\n';
                str[1] = iter + '0';
                return number_rank;
            }
            else
            {
                str[0] = iter + '0';
                number_rank = 1;
                return number_rank;
            }
        }
    }

    return 0;
}

int sort_rect(Rect* rect_sort, int flag)
{
    int i, j, rx1, rx2;
    Rect rect_buf;

    for (i = 0; i < flag; i++)
    {
        for (j = 0; j < flag - 1; j++)
        {
            rx1 = rect_sort[j].x;
            rx2 = rect_sort[j + 1].x;
            if (rx1 > rx2)
            {
                rect_buf = rect_sort[j];
                rect_sort[j] = rect_sort[j + 1];
                rect_sort[j + 1] = rect_buf;
            }
        }
    }

    return 0;
}


int write_image(Rect* rect_sort, Mat dilation, Mat image, char* path, int iter, int size_roi, char* path_for_patterns)
{
    int w, h, x, y, i, line_length, number_rank, heigth;
    Mat roi;
    char* path_1, * path_2;
    char str[5];

    line_length = strlen(path);

    //cout << path << '\n';
    path_1 = new char[line_length + 25];
    for (i = 0; i < line_length + 25; i++)
    {
        path_1[i] = '\0';
    }
    //cout << path_1 << '\n';

    for (i = 0; i < line_length; i++)
    {
        path_1[i] = path[i];
    }
    //cout << path_1 << '\n';
    path_1[line_length] = '\\';
    path_1[line_length + 1] = '\\';
    path_1[line_length + 2] = 'p';
    path_1[line_length + 3] = 'l';
    path_1[line_length + 4] = 'a';
    path_1[line_length + 5] = 't';
    path_1[line_length + 6] = 'e';
    path_1[line_length + 7] = ' ';
    line_length = line_length + 8;
    //cout << path_1 << '\n';

    //strncat(path_1,"\\\\plate ",8);
    //sprintf(str, "%d", iter);
    //strncat(path_1, str, 4);
    number_rank = inv_f(str, iter);
    //cout << str << '\n';

    for (i = 0; i < number_rank; i++)
    {
        path_1[line_length + i] = str[i];
    }
    line_length = line_length + number_rank;

    //cout << path_1 << '\n';

    _mkdir(path_1);

    //cout << path_1 << '\n';

    //line_length = strlen(path_1);
    path_2 = new char[line_length + 12];
    for (i = 0; i < line_length + 12; i++)
    {
        path_2[i] = '\0';
    }
    for (i = 0; i < line_length; i++)
    {
        path_2[i] = path_1[i];
    }
    //cout << path_2 << '\n';

    path_2[line_length] = '\\';
    path_2[line_length + 1] = '\\';
    path_2[line_length + 2] = 'i';
    path_2[line_length + 3] = 'm';
    path_2[line_length + 4] = 'a';
    path_2[line_length + 5] = 'g';
    path_2[line_length + 6] = 'e';
    path_2[line_length + 7] = '.';
    path_2[line_length + 8] = 'j';
    path_2[line_length + 9] = 'p';
    path_2[line_length + 10] = 'g';

    //cout << path_2 << '\n';
    //записываем изначальное изображение в папку  
    //strncat(path_2, "\\\\image.jpg", 11);
    imwrite(path_2, image);

    //cout << path_2 << '\n';

    i = 0;
    path_1[line_length] = '\\';
    path_1[line_length + 1] = '\\';
    path_1[line_length + 2] = 'r';
    path_1[line_length + 3] = 'o';
    path_1[line_length + 4] = 'i';
    path_1[line_length + 5] = '_';

    line_length = line_length + 6;

    path_1[line_length] = i + '0';
    path_1[line_length + 1] = '.';
    path_1[line_length + 2] = 'j';
    path_1[line_length + 3] = 'p';
    path_1[line_length + 4] = 'g';

    //strncat(path_1, "\\\\roi_", 6);
    //sprintf(str, "%d", i);
    //line_length = strlen(path_1);
    //strncat(path_1, str, 1);
    //strncat(path_1, ".jpg", 4);
    //cout << path_1 << '\n';
    for (int i = 0; i < size_roi; i++)
    {
        w = rect_sort[i].width;
        h = rect_sort[i].height;
        x = rect_sort[i].x;
        y = rect_sort[i].y;

        heigth = y + h;


        if (rect_sort[i].x < 5 || rect_sort[i].y < 5)
        {
            if ((heigth + 5) <= 150)
            {
                roi = dilation(Rect(x, y, w + 5, h + 5)).clone();
            }
            else
            {
                roi = dilation(Rect(x, y, w + 5, h)).clone();
            }
            //roi = dilation(Rect(x, y, w + 9, h + 9)).clone();
        }
        else
        {
            if ((heigth + 5) <= 150)
            {
                roi = dilation(Rect(x - 5, y - 5, w + 5, h + 5)).clone();
            }
            else
            {
                roi = dilation(Rect(x - 5, y - 5, w + 5, h)).clone();
            }
            //roi = dilation(Rect(x - 5, y - 5, w + 9, h + 9)).clone();            
        }

        //cout << roi.data << '\n';
        if (roi.data != NULL)
        {
            //imshow("image", roi);
            //waitKey();
            bitwise_not(roi, roi);
            medianBlur(roi, roi, 5);

            path_1[line_length] = i + '0';
            //cout << path_1 << '\n';

            //D:\\My work\\pictures\\Result
            //D:\\My work\\pictures\\Aziza plate
            //D:\\pictures\\Aziza plate
            //D:\\pictures\\result
            //записываем символы в папку
            imwrite(path_1, roi);

            //rectangle(image, rect_sort[i], Scalar(255, 0, 0));
            //rectangle(dilation, rect_sort[i], Scalar(255, 0, 0));
        }

    }

    for (int i = 0; i < line_length + 5; i++)
    {
        path_for_patterns[i] = path_1[i];
    }

    //imshow("image", dilation);

    delete[] path_1;
    delete[] path_2;

    return line_length;
}

/*int finding_contours(Rect* rect_sort, Point** contours)
{
  int flag;



  return flag;
}*/

int nesting_contours(Rect* rect_sort, int flag)
{
    int max_w, t, flag1 = 0;
    double d1, d2, distance, distance_m, distinction;
    Rect rect_buf;

    // проверяем не содержится ли один контур в другом, если расстояние между левыми верхними
    // углами контуров меньше, чем длина левого контура, то правый контур лежит в левом,
    //тогда мы сдвигаем правый контур в самый конец 
    for (int i = 0; i < flag - 1; i++)
    {
        max_w = rect_sort[i].width;

        d1 = static_cast<double>(rect_sort[i + 1].x) - static_cast<double>(rect_sort[i].x);
        d2 = static_cast<double>(rect_sort[i + 1].y) - static_cast<double>(rect_sort[i].y);
        d1 = d1 * d1;
        d2 = d2 * d2;
        distance = sqrt(d1 + d2);
        distance_m = distance + static_cast<double>(rect_sort[i + 1].width);
        distinction = static_cast<double>(max_w);

        /*cout << '\n';
        cout << max_w << ' ';
        cout << distance;
        cout << '\n';*/

        if (distance < static_cast<double>(max_w) && distance_m < distinction)
        {
            if (rect_sort[i + 1].x > rect_sort[i].x)
            {
                t = flag - 1 - flag1;
                rect_buf = rect_sort[i + 1];
                rect_sort[i + 1] = rect_sort[t];
                rect_sort[t] = rect_buf;
                /*cout << t << ' ';
                cout << rect_sort[i].x << ' ';
                cout << rect_sort[i + 1].x << ' ';
                cout << '\n';*/

                flag1++;
                //cout << flag1 << '\n';
            }
        }
    }

    t = flag - flag1;

    return t;

    //sort_rect(rect_sort, t);
}

int cut_rect(Rect* rect_sort, int size_roi, int flag)
{
    int i, j, average_width=0, width, flag1;
    Rect buf;

    /*cout << '\n';
    cout << "Width: \n";
    for (i = 0; i < size_roi; i++)
    {
        cout << rect_sort[i].width << ' ';
    }
    cout << '\n';*/

    for ( i = 0; i < size_roi; i++)
    {
        average_width = average_width + rect_sort[i].width;
    }

    average_width = average_width / size_roi;
    //cout << average_width << '\n';

    flag1 = flag;
    width = 0;
    for ( i = 0; i < size_roi; i++)
    {
        if (rect_sort[i].width > average_width*2)
        {
            //cout << "Hi! " << '\n';
            if (rect_sort[i].width > average_width * 3)
            {
                width = rect_sort[i].width / 3;
                for ( j = 0; j < 3; j++)
                {
                    rect_sort[flag1] = rect_sort[i];
                    if (i==0)
                    {
                        rect_sort[flag1].width = width;
                    }
                    else
                    {
                        rect_sort[flag1].width = width;
                        rect_sort[flag1].x = rect_sort[i].x + width;
                    }
                    flag1++;
                    size_roi++;
                }
                //теперь их нужно поменять местами
                for (int t = 0; t < 3; t++)
                {
                    for (j = flag1; j > i + 1 + t; j--)
                    {
                        buf = rect_sort[j];
                        rect_sort[j] = rect_sort[j - 1];
                        rect_sort[j - 1] = buf;
                    }
                }                    
            }
            else
            {
                width = rect_sort[i].width / 2;
                for (j = 0; j < 2; j++)
                {
                    rect_sort[flag1] = rect_sort[i];
                    if (i == 0)
                    {
                        rect_sort[flag1].width = width;
                    }
                    else
                    {
                        rect_sort[flag1].width = width;
                        rect_sort[flag1].x = rect_sort[i].x + width;
                    }
                    flag1++;
                    size_roi++;
                }
                for (int t = 0; t < 2; t++)
                {
                    for (j = flag1; j > i + 1 + t; j--)
                    {
                        buf = rect_sort[j];
                        rect_sort[j] = rect_sort[j - 1];
                        rect_sort[j - 1] = buf;
                    }
                }
            }
        }
    }



    return 0;
}

int number_of_spaces(Rect* rect_sort, int size_roi)
{
    int i, j, num_space=0;

    /*cout << '\n';
    cout << "number of spaces\n";
    for ( i = 0; i < size_roi; i++)
    {
        cout << rect_sort[i].x << ' ';
    }
    cout << '\n';*/

    for ( i = 0; i < size_roi-1; i++)
    {
        j = rect_sort[i + 1].x - rect_sort[i].x - rect_sort[i].width;
        if (j>=15)
        {
            num_space++;
        }
        //cout << j << ' ';
    }
    //cout << '\n';
    //cout << '\n';    

    return num_space;
}

int image_test(char* path_read, char* path_write, int iter)
{
    int h, w, height, width, flag, line_length, number_rank, size_roi = 0, qvadro=0, num_space;
    int lenght_path, num_of_num;
    double ratio, h_f, w_f;
    char *path_1, *str, *path_for_pattern;

    //TessBaseAPI *myOCR = new TessBaseAPI();

    Mat image, blur, thresh, rect_kern, dilation;

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    Rect rect1, *rect_sort;
    //Rect rect_sort[11];

    rect_sort = new Rect[26];

    line_length = strlen(path_read);
    lenght_path = strlen(path_write);

    path_1 = new char[line_length + 10];
    path_for_pattern = new char[lenght_path + 26];
    str = new char[5];

    //myOCR->Init(NULL, "eng");

    for (int i = 0; i < 5; i++)
    {
        str[i] = '\0';
    }

    for (int i = 0; i < line_length + 10; i++)
    {
        path_1[i] = '\0';
    }

    for (int i = 0; i < lenght_path + 26; i++)
    {
        path_for_pattern[i] = '\0';
    }

    for (int i = 0; i < line_length; i++)
    {
        path_1[i] = path_read[i];
    }
    path_1[line_length] = '\\';
    path_1[line_length + 1] = '\\';
    line_length = line_length + 2;

    number_rank = inv_f(str, iter);
    //cout << str << '\n';

    for (int i = 0; i < number_rank; i++)
    {
        path_1[line_length + i] = str[i];
    }
    line_length = line_length + number_rank;

    path_1[line_length] = '.';
    path_1[line_length + 1] = 'j';
    path_1[line_length + 2] = 'p';
    path_1[line_length + 3] = 'g';
    /*strncat(path_1, "\\\\", 2);
  sprintf(str, "%d", iter);
  strncat(path_1, str, 4);
  strncat(path_1, ".jpg", 4);*/
    //cout << path_1 << '\n';

    image = imread(path_1);
    if (image.data == NULL)
    {
        return 1;
    }

    resize(image, image, Size(625, 150), INTER_CUBIC);

    height = image.size().height;
    width = image.size().width;

    cvtColor(image, image, COLOR_BGR2GRAY);

    GaussianBlur(image, blur, Size(5, 5), 0, 0);

    threshold(blur, thresh, 0, 255, THRESH_OTSU | THRESH_BINARY_INV);

    rect_kern = getStructuringElement(MORPH_RECT, Size(5, 5));

    dilate(thresh, dilation, rect_kern, Point(-1, -1), 1);

    findContours(dilation, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);

    // находим контуры нужного нам размера, т. е. находим символы номера
    flag = 0;
    for (int i = 0; i < contours.size(); i++)
    {
        rect1 = boundingRect(contours[i]);
        w = rect1.width;
        h = rect1.height;
        w_f = static_cast<double>(w);
        h_f = static_cast<double>(h);
        if ((w/h)==2)
        {
            qvadro = 1;
            ratio = h_f / static_cast<double>(height);
            if (ratio <= 0.51 && ratio >= 0.22)
            {
                if (w > 30 && w <= 210)
                {
                    rect_sort[flag] = rect1;
                    flag++;
                }
            }
        }
        else
        {
            ratio = h_f / static_cast<double>(height);
            if (ratio <= 0.73 && ratio >= 0.31)
            {
                if (w > 30 && w <= 210)
                {
                    rect_sort[flag] = rect1;
                    flag++;
                }
            }
        }
    }

    //cout << flag << '\n';

    sort_rect(rect_sort, flag);


    size_roi = nesting_contours(rect_sort, flag);

    //cout << size_roi << '\n';

    sort_rect(rect_sort, size_roi);

    num_space = number_of_spaces(rect_sort, size_roi);
    cout << num_space << '\n';
    
    //fprintf("num_spase.txt");

    /*for (int i = 0; i < 16; i++)
    {
        cout << rect_sort[i].x << ' ';
    }
    cout << '\n';*/

    //снова сортируем контуры по положению, слева на право
    //sort_rect(rect_sort, 8);

    //imshow("image", dilation);
    //waitKey();

    //cut_rect(rect_sort, size_roi, flag);

    num_of_num = write_image(rect_sort, dilation, image, path_write, iter, size_roi, path_for_pattern);
    FILE* file;
    file = fopen("num_spase.txt", "w");


    fclose(file);


    /*cout << size_roi << '\n';
    if (size_roi<8)
    {
        cout << "error! \n";
        return 1;
    }

    if (qvadro == 1)
    {        
        //template_for_a_private_person(path_for_pattern, num_of_num);
        scan_roi(path_for_pattern, num_of_num, 1);
    }
    else
    {
        if (num_space == 3)
        {
            scan_roi(path_for_pattern, num_of_num, 3);
        }
        else
        {
            scan_roi(path_for_pattern, num_of_num, 2);
        }
    }*/


    //imshow("image", dilation);
    //imshow("image", image);

    //waitKey();

    delete[] rect_sort;
    delete[] path_1;
    delete[] str;
    delete[] path_for_pattern;


    return 0;
}