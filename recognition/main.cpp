#include "Header.h"


int main()
{
    char *outText, * path_read, * path_write;    
    int iter = 15;
    clock_t start, stop;

    path_read = new char[100];
    path_write = new char[100];

    for (int i = 0; i < 100; i++)
    {
        path_read[i] = '\0';
        path_write[i] = '\0';
    }

    cout << "Enter where to read from:\n";
    cout.flush();
    //cin.ignore();
    //getline(cin, path_read);
    //cin.getline(path_read, '\n');
    cin.get(path_read, 100);
    getchar();

    cout << "Enter where to write:\n";
    cout.flush();

    //getline(cin, path_read, '\n');
    cin.get(path_write, 100);
    //cin.getline(path_write, '\n');
  //  getchar();

    //cout << '\n';  
    //cout << path_1 << '\n';

    //line_length = strlen(path_1);
    //strcpy(path,"plate");
    //cout << line_length;
    //cout << path << '\n';
    //D:\\pictures\\Aziza plate
    //D:\\pictures\\result
    //D:\\pictures\\base

    start = clock();

    for (int i = 9; i < 10; i++)
    {
        cout << i << '\n';
        //if (i!=2)
        //{
        image_test(path_read, path_write, i);
        //}

    }

    stop = clock();

    cout << "works time:\n";
    cout << (stop - start) / CLK_TCK << '\n';

    delete[] path_read;
    delete[] path_write;    

    return 0;
}