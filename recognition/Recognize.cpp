#include "Header.h"

int recognize(char* path, int line_length)
{
    /* char* outText;

    tesseract::TessBaseAPI* api = new tesseract::TessBaseAPI();
    // Initialize tesseract-ocr with English, without specifying tessdata path
    if (api->Init("C:\\src\\vcpkg\\vcpkg\\tessdata", "eng")) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
    }

    // Open input image with leptonica library
    Pix* image = pixRead("D:\\pictures\\presentation example\\1\\roi_1.jpg");
    api->SetImage(image);
    // Get OCR result
    outText = api->GetUTF8Text();
    printf("OCR output:\n%s", outText);

    // Destroy used object and release memory
    api->End();
    delete api;
    delete[] outText;
    pixDestroy(&image);

    return 0;*/

    FILE* f; // ��������� �������� ����������

    TessBaseAPI* myOCR = new TessBaseAPI();
    char* outText;
    Pix* pix;
    int num;

    myOCR->Init("C:\\src\\vcpkg\\vcpkg\\tessdata", "eng"); //����� ������������ ������ �� ���������� �����

    f = fopen("text.txt", "a");
    fprintf(f, "OCR output:\n\n");

    num = path[line_length] - '0';

    if (num == 2 || num == 5)
    {
        pix = pixRead(path); // ��������� �������� � ������� � �����
        myOCR->SetVariable("tessedit_char_whitelist", "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ");
        myOCR->SetImage(pix);
        myOCR->Recognize(0);
    }
    else
    {
        if (num == 0 || num == 1 || num == 3 || num == 4)
        {
            pix = pixRead(path); // ��������� �������� � ������� � �����
            myOCR->SetVariable("tessedit_char_whitelist", "0123456789");
            myOCR->SetImage(pix);
            myOCR->Recognize(0);
        }
        else
        {
            pix = pixRead(path); // ��������� �������� � ������� � �����
            myOCR->SetVariable("tessedit_char_whitelist", "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
            myOCR->SetImage(pix);
            myOCR->Recognize(0);
        }
    }

    f = fopen("text.txt", "w");
    outText = myOCR->GetUTF8Text();
    fprintf(f, "  ");
    fprintf(f, outText);

   
    /*for (int i = 0; i < 9; i++)
    {
        switch (i)
        {
        case 0:
            pix = pixRead("D:\\pictures\\result\\plate 6\\roi_1.jpg"); // ��������� �������� � ������� � �����

            myOCR->SetVariable("tessedit_char_whitelist", "0123456789");
            myOCR->SetImage(pix);
            myOCR->Recognize(0);
            outText = myOCR->GetUTF8Text();
            fprintf(f, "  ");
            fprintf(f, outText);
            break;
        case 1:
            pix = pixRead("D:\\pictures\\result\\plate 6\\roi_2.jpg"); // ��������� �������� � ������� � �����

            myOCR->SetVariable("tessedit_char_whitelist", "0123456789");
            myOCR->SetImage(pix);
            myOCR->Recognize(0);
            outText = myOCR->GetUTF8Text();
            fprintf(f, "  ");
            fprintf(f, outText);
            break;
        case 2:
            pix = pixRead("D:\\pictures\\result\\plate 6\\roi_3.jpg"); // ��������� �������� � ������� � �����

            myOCR->SetVariable("tessedit_char_whitelist", "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
            myOCR->SetImage(pix);
            myOCR->Recognize(0);
            outText = myOCR->GetUTF8Text();
            fprintf(f, "  ");
            fprintf(f, outText);
            break;
        case 3:
            pix = pixRead("D:\\pictures\\result\\plate 6\\roi_4.jpg"); // ��������� �������� � ������� � �����

            myOCR->SetVariable("tessedit_char_whitelist", "0123456789");
            myOCR->SetImage(pix);
            myOCR->Recognize(0);
            outText = myOCR->GetUTF8Text();
            fprintf(f, "  ");
            fprintf(f, outText);
            break;
        case 4:
            pix = pixRead("D:\\pictures\\result\\plate 6\\roi_5.jpg"); // ��������� �������� � ������� � �����

            myOCR->SetVariable("tessedit_char_whitelist", "0123456789");
            myOCR->SetImage(pix);
            myOCR->Recognize(0);
            outText = myOCR->GetUTF8Text();
            fprintf(f, "  ");
            fprintf(f, outText);
            break;
        case 5:
            pix = pixRead("D:\\pictures\\result\\plate 6\\roi_6.jpg"); // ��������� �������� � ������� � �����

            myOCR->SetVariable("tessedit_char_whitelist", "0123456789");
            myOCR->SetImage(pix);
            myOCR->Recognize(0);
            outText = myOCR->GetUTF8Text();
            fprintf(f, "  ");
            fprintf(f, outText);
            break;
        case 6:
            pix = pixRead("D:\\pictures\\result\\plate 6\\roi_7.jpg"); // ��������� �������� � ������� � �����

            myOCR->SetVariable("tessedit_char_whitelist", "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
            myOCR->SetImage(pix);
            myOCR->Recognize(0);
            outText = myOCR->GetUTF8Text();
            fprintf(f, "  ");
            fprintf(f, outText);
            break;
        case 7:
            pix = pixRead("D:\\pictures\\result\\plate 6\\roi_8.jpg"); // ��������� �������� � ������� � �����

            myOCR->SetVariable("tessedit_char_whitelist", "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
            myOCR->SetImage(pix);
            myOCR->Recognize(0);
            outText = myOCR->GetUTF8Text();
            fprintf(f, "  ");
            fprintf(f, outText);
            break;
            /*case 8:
              pix = pixRead("D:\\My work\\pictures\\Test\\roi_9.jpg"); // ��������� �������� � ������� � �����

              myOCR->SetVariable("tessedit_char_whitelist", "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
              myOCR->SetImage(pix);
              myOCR->Recognize(0);
              fprintf(f, "  ");
              fprintf(f, myOCR->GetUTF8Text());
              break;*/
     //   }
    //}

    /*Pix *pix = pixRead("D:\\My work\\pictures\\Test\\roi.jpg"); // ��������� �������� � ������� � �����

    myOCR->SetVariable("tessedit_char_whitelist", "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    myOCR->SetImage(pix);
    myOCR->Recognize(0);*/

    // ����� ����������� ������������� ������ � ����
    /*f = fopen("text.txt", "w");
    outText = myOCR->GetUTF8Text();
            fprintf(f, "  ");
            fprintf(f, outText);*/


    myOCR->End();
    delete myOCR;
    //delete[] outText;
    pixDestroy(&pix);

    fclose(f);


	return 0;
}