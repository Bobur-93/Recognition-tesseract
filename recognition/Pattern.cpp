#include "Header.h"

void scan_roi(char* path_for_pattern, int num_of_num, int type_pattern)
{
    int i;
    FILE* f;

    f = fopen("text.txt", "a");
    fprintf(f, "\n");
    //fprintf(f, "OCR output:\n\n");
    fclose(f);
    

    if (type_pattern==3)
    {
        printf("\n");
        printf("template for a private person:\n\n");
        for ( i = 0; i < 8; i++)
        {
            //printf("\n");
            //printf("template for a private person:\n\n");
            template_for_a_private_person(path_for_pattern, num_of_num, i);
        }
    }
    else
    {
        if (type_pattern == 2)
        {
            printf("\n");
            printf("template for a entity:\n\n");
            for ( i = 0; i < 8; i++)
            {
                //printf("\n");
                //printf("template for a entity:\n\n");
                template_for_a_entity(path_for_pattern, num_of_num, i);
            }
        }
        else
        {
            if (type_pattern == 1)
            {
                for ( i = 0; i < 8; i++)
                {
                    template_for_a_square_number(path_for_pattern, num_of_num, i);
                }
            }
        }
    }

}

int template_for_a_private_person(char* path_for_pattern, int num_of_num, int iter)
{
    FILE* f; // объявляем файловую переменную

    TessBaseAPI* myOCR = new TessBaseAPI();
    char* outText;
    Pix* pix;

    myOCR->Init("C:\\src\\vcpkg\\vcpkg\\tessdata", "eng"); //будем распознавать тексты на английском языке

    f = fopen("text.txt", "a");
    //fprintf(f, "OCR output:\n\n");

    path_for_pattern[num_of_num] = iter + '0';

    if (iter==0 || iter==1 || iter==3 || iter==4 || iter==5)
    {
        pix = pixRead(path_for_pattern); // загружаем картинку с текстом с диска
        myOCR->SetVariable("tessedit_char_whitelist", "0123456789");
        myOCR->SetImage(pix);
        myOCR->Recognize(0);
    }
    else
    {
        pix = pixRead(path_for_pattern); // загружаем картинку с текстом с диска
        myOCR->SetVariable("tessedit_char_whitelist", "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
        myOCR->SetImage(pix);
        myOCR->Recognize(0);
    }

    outText = myOCR->GetUTF8Text();
    //cout << outText << ' ';
    fprintf(f, outText);
    //fprintf(f, "  ");



    myOCR->End();

    delete myOCR;
    delete[] outText;
    pixDestroy(&pix);
    fclose(f);

    return 0;
}

int template_for_a_entity(char* path_for_pattern, int num_of_num, int iter)
{
    FILE* f; // объявляем файловую переменную

    TessBaseAPI* myOCR = new TessBaseAPI();
    char* outText;
    Pix* pix;

    myOCR->Init("C:\\src\\vcpkg\\vcpkg\\tessdata", "eng"); //будем распознавать тексты на английском языке

    f = fopen("text.txt", "a");
    //fprintf(f, "OCR output:\n\n");

    path_for_pattern[num_of_num] = iter + '0';

    if (iter == 0 || iter == 1 || iter == 2 || iter == 3 || iter == 4)
    {
        pix = pixRead(path_for_pattern); // загружаем картинку с текстом с диска
        myOCR->SetVariable("tessedit_char_whitelist", "0123456789");
        myOCR->SetImage(pix);
        myOCR->Recognize(0);
    }
    else
    {
        pix = pixRead(path_for_pattern); // загружаем картинку с текстом с диска
        myOCR->SetVariable("tessedit_char_whitelist", "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
        myOCR->SetImage(pix);
        myOCR->Recognize(0);
    }

    outText = myOCR->GetUTF8Text();
    fprintf(f, outText);
    //fprintf(f, "  ");

    myOCR->End();

    delete myOCR;
    delete[] outText;
    pixDestroy(&pix);
    fclose(f);

    return 0;
}

int template_for_a_square_number(char* path_for_pattern, int num_of_num, int iter)
{
    FILE* f; // объявляем файловую переменную

    TessBaseAPI* myOCR = new TessBaseAPI();
    char* outText;
    Pix* pix;
    int num;

    myOCR->Init("C:\\src\\vcpkg\\vcpkg\\tessdata", "eng"); //будем распознавать тексты на английском языке

    f = fopen("text.txt", "a");
    //fprintf(f, "OCR output:\n\n");

    myOCR->End();
    delete myOCR;
    //delete[] outText;
    pixDestroy(&pix);

    fclose(f);


    return 0;
}