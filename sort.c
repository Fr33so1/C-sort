#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//喂喂喂，看这里
//printgr()用于输出排序的图像
//system("cls")用于清屏
//getch()用于暂停（按任意键继续）


int show_image = 1;
int step_by_step = 1;
//计时的时候别开逐步






//实际上不输出图像的话都是0ms
//hh
//什么微小形变放大法

















void printgr(int f[10])
{
    int i = 0, p = 0;

    for (i = 0; i < 10; i++)
    {
        for (p = 0; p < f[i]; p++)
        {
            printf("o");
        }
        printf("\n");
    }

}

int main()
{
    int i = 0, p = 0, t = 0;
    int o[10] = {2, 7, 5, 1, 3, 4, 6, 0, 9, 8}, f[10] = {};
    double begin, end;
    double t1, t2, t3, t4;

    for (i = 0; i < 10; i++) f[i] = o[i];

    //1st 选择
    begin = clock();
    for (i = 0; i < 9; i++)
    {
        for (p = i + 1; p < 10; p++)
        {
            if (step_by_step) getch();

            if (show_image) system("cls");

            if (f[i] > f[p])
            {
                t = f[i];
                f[i] = f[p];
                f[p] = t;
            }

            if (show_image) printgr(f);
        }
    }
    end = clock();
    t1 = (end - begin)/(double)CLK_TCK*1000;
    printf("\ndone");

    for (i = 0; i < 10; i++) f[i] = o[i];

    //2nd 冒泡
    begin = clock();
    for (i = 0; i < 9; i++)
    {
        for (p = 0; p < 9; p++)
        {
            if (step_by_step) getch();

            if (show_image) system("cls");

            if (f[p] > f[p + 1])
            {
                t = f[p];
                f[p] = f[p + 1];
                f[p + 1] = t;
            }

            if (show_image) printgr(f);
        }
    }
    end = clock();
    t2 = end - begin/(double)CLK_TCK*1000;
    printf("\ndone");

    for (i = 0; i < 10; i++) f[i] = o[i];

    //3rd 插入
    begin = clock();
    int s[10] = {};
    {
        s[0] = f[0];

        for (i = 1; i < 10; i++)
        {
            for (p = 0; p < i; p++)
            {
                if (step_by_step) getch();

                if (show_image) system("cls");
                
                if (f[i] < s[p])
                {
                    for (int q = 0; q < 10 - p; q++)
                    {
                        s[9 - q] = s[8 - q];
                    }
                    s[p] = f[i];

                    if (show_image) printgr(s);

                    break;
                }

                if (p == i - 1)
                {
                    s[p + 1] = f[i];
                    
                }

                if (show_image) printgr(s);
            }
        }
    }
    end = clock();
    t3 = end - begin/(double)CLK_TCK*1000;
    printf("\ndone");

    for (i = 0; i < 10; i++) f[i] = o[i];

    //4th quicksort
    begin = clock();
    qsss(f, 0, 9);
    end = clock();
    t4 = end - begin/(double)CLK_TCK*1000;
    printf("\ndone");
    printf("\ntime:\nselection:%lfms\nbubble:%lfms\ninsertion:%lfms\nquicksort:%lfms", t1, t2, t3, t4);
}

void qsss(int a[10], int left, int right)
    {
        int temp = 0;
        int mid = a[(left + right) / 2];

        int m = left;
        int n = right;

        while (m <= n)
        {
            while (a[m] < mid) m++;
            while (a[n] > mid) n--;
            //reverse here

            if (step_by_step) getch();

            if (show_image) system("cls");

            if (m <= n)
            {
                temp = a[m];
                a[m] = a[n];
                a[n] = temp;
                m++;
                n--;
            }

            if (show_image) printgr(a);
        }

        if (m < right) qsss(a, m, right);
        if (n > left) qsss(a, left, n);
    }
