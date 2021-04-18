//这是有两个main函数， 一个是专门看数据处理时间
//一个是看数据处理
//现在注释的是数据处理，显示的是数据处理时间
//有需要的自行处理注释

#include "qgsort.h"

void insertSort(int *a,int n) {
    if(!n || n < 2) return ;

    for(int i = 1 ; i < n ; i ++ ) {
        int temp = a[i];
        int k = i - 1;
        while(k >= 0 && a[k] > temp)    k -- ;
        for(int j = i ; j > k + 1 ; j -- )  a[j] = a[j - 1];
        a[k + 1] = temp;
    }
}

void MergeArray(int *a,int begin,int mid,int end,int *temp);
//函数MergeArray与MergeSort合并了就不写了

void MergeSort(int *a,int begin,int end,int *temp) {
    if(begin >= end)    return ;

    int mid = (begin + end) / 2;
    MergeSort(a, begin, mid, temp);
    MergeSort(a, mid + 1, end, temp);

    int k = 0, i = begin, j = mid + 1;
    while(i <= mid && j <= end) {
        if(a[i] <= a[j])    temp[k ++ ] = a[i ++ ];
        else                temp[k ++ ] = a[j ++ ];
    }
    while(i <= mid) temp[k ++ ] = a[i ++ ];
    while(j <= end) temp[k ++ ] = a[j ++ ];

    for(int i = begin, j = 0; i <= end ; i ++ , j ++ )  a[i] = temp[j];
}

void QuickSort_Recursion(int *a, int begin, int end) {
    if(begin >= end)    return ;

    int i = begin - 1, j = end + 1, x = a[(begin + end) / 2];
    while(i < j) {
        do i ++ ; while(a[i] < x);
        do j -- ; while(a[j] > x);
        if(i < j)   swap(a[i], a[j]);
    }
    QuickSort_Recursion(a, begin, j);
    QuickSort_Recursion(a, j + 1, end);
}

void QuickSort(int *a,int size) {
    int i = 0, j = size - 1;
    swap(a[i], a[j]);
    int x = a[i];

    while(i != j) {
        while(j > i && a[j] > x)    j -- ;
        if(i < j)       a[i ++ ] = a[j];

        while(i < j && a[i] < x)    i ++ ;
        if(i < j)       a[j ++ ] = a[i];
    }
    a[i] = x;
}

int Partition(int *a, int begin, int end) {
    int x = a[(begin + end) / 2];

    while(begin < end) {
        while(begin < end && a[end] >= x)    end -- ;
        a[begin] = a[end];
        while(begin < end && a[begin] <= x) begin ++ ;
        a[end] = a[begin];
    }
    a[begin] = x;
    return end;
}

void CountSort(int *a, int size , int max) {
    max = a[0];
    int tmp[100010];
    for(int i = 0 ; i < 100010 ; i ++ )  tmp[i] = 0;
    for(int i = 0 ; i < size ; i ++ )   tmp[a[i]] ++ ;
    
    int k = 0;
    for(int i = 0 ; i < 100010 ; i ++ ) 
        for(int j = 0 ; j < tmp[i] && tmp[i] > 0 ; j ++) {
            a[k ++ ] = i;
            tmp[i] -- ;
        }
}

void RadixCountSort(int *a,int size) {
    int d = 1, p = 10;
    for(int i = 0 ; i < size ; i ++ ) {
        while(a[i] >= p) {
            p *= 10;
            d ++ ;
        }
    }
    int count[10];
    int radix = 1;
    int i, j;

    for(i = 1 ; i <= d ; i ++ ) {
        for(j = 0 ; j < 10 ; j ++ )
            count[j] = 0;

        for(j = 0 ; j < size ; j ++ )
            count[(a[j] / radix) % 10] ++ ;

        for(j = 1 ; j < 10 ; j ++ )
            count[j] += count[j - 1];
        
        for(j = size - 1 ; j >= 0 ; j -- ) {
            temp[count[(a[j] / radix) % 10]] = a[j];
            count[(a[j] / radix) % 10] -- ;
        }

        for(j = 0 ; j < size ; j ++ ) 
            a[j] = temp[j];
        radix *= 10;
    }
}

void ColorSort(int *a,int size) {
    int i = -1, j = -1, k = -1;
    for(int m = 0 ; m < size ; m ++ ) {
        if(a[m] == 0) {
            a[++ k] = 2;
            a[++ j] = 1;
            a[++ i] = 0;
        }
        else if(a[m] == 1) {
            a[++ k] = 2;
            a[++ j] = 1;
        }
        else a[++ k] = 2;
    }
}

void findKMax(int *a, int l, int r, int k){
    int temp = Kpartition(a, l, r);
    if(temp == k - 1) {
        printf("%d",a[temp]);
        return ;
    }
    else if(temp > k - 1)   findKMax(a, l, temp -1 , k);
    else        findKMax(a, temp + 1, r, k - temp);
}

int Kpartition(int *a, int l, int r) {
    int temp = a[l];
    while(l < r) {
        while(temp >= a[r] && l < r)    -- r;
        a[l] = a[r];

        while(temp <= a[l] && l < r)    ++ l;
        a[r] = a[l];
    }
    a[r] = temp;
    return r;
}

void menu() {
    printf("\t\t\t\t****************************************\n");
    printf("\t\t\t\t***     1.插入排序算法                ***\n");
    printf("\t\t\t\t***     2.归并排序                    ***\n");
    printf("\t\t\t\t***     3.快速排序（归并版）           ***\n");
    printf("\t\t\t\t***     4.快速排序（非归并版）         ***\n");
    printf("\t\t\t\t***     5.快速排序（枢轴存放）         ***\n");
    printf("\t\t\t\t***     6.计数排序                    ***\n");
    printf("\t\t\t\t***     7.基数计数排序                 ***\n");
    printf("\t\t\t\t***     8.颜色排序                     ***\n");
    printf("\t\t\t\t***     9.无需排序中找到第k大/小的数     ***\n");
    printf("\t\t\t\t******************************************\n");

    printf("请输入您的选择：");
}

void printdata() {
    for(int i = 0 ; i < 100 ; i ++ ) {
        printf("%5d ",a[i]);
        if((i + 1) % 10 == 0)    printf("\n");
    }
    printf("\n");
}

/*
int main() {
    char judge;
    printf("请问是否重新生成随机数到data.txt中？请输入y 或 n：");
    scanf("%s",&judge);
    while(judge != 'y' && judge != 'n') {
        printf("无效的输入请重试：");
        scanf("%s",&judge);
    }

    if(judge == 'y') {
        fstream file("data.txt", ios::out);
        srand((unsigned)time(0));
        for(int i = 0 ; i < 100 ; i ++ ) {
            for(int i = 0 ; i < 100 ; i ++ ) {
                a[i] = rand() % 10000;
                file << a[i] << ' ';
            }
        }
        file.close();
    }
    if(judge == 'n') {
        fstream file("data.txt", ios::in);
        for(int i = 0 ; i < 100 ; i ++ ) {
            file >> a[i];
        }
        file.close();
    }
    
    printf("文件操作成功！\n\n");
    system("pause");

    int px;
    printf("\t\t\t\t请选择运行的次数\n");
    printf("\t\t\t\t1.10000   2.50000   3.200000\n\n");
    printf("\t\t\t\t请输入您的选择：");
    judge = 'n';
    char ch;
    scanf("%s",&ch);
    if(ch == '1')       px =  10000;
    else if(ch == '2')  px =  50000;
    else if(ch == '3')  px = 200000;
    else {
        printf("无效的输入请重试：");
        scanf("%s",&ch);
    }

    int n = 100;

    int circle = 1;
    while(circle) {
        system("cls");

        menu();
        char choose;
        scanf("%s",&choose);
        if(choose == '1') {
            printf("处理前：\n");
            printdata();

            clock_t start, finish;

            start = clock();
            insertSort(a, n);
            finish = clock();
            double t = (double)(finish - start);
            
            printf("\n\n处理后：\n");
            printdata();

            printf("处理时间%f\n\n",t * px);
            system("pause");
        }
        else if(choose == '2') {
            printf("处理前：\n");
            printdata();

            clock_t start, finish;

            start = clock();
            MergeSort(a, 0, n - 1, temp);
            finish = clock();
            double t = (double)(finish - start);

            printf("\n\n处理后：\n");
            printdata();

            printf("处理时间：%f\n\n",t * px);
            system("pause");
        }
        else if(choose == '3') {
            printf("处理前：\n");
            printdata();

            clock_t start, finish;

            start = clock();
            QuickSort_Recursion(a, 0, n - 1);
            finish = clock();
            double t = (double)(finish - start);

            printf("\n\n处理后：\n");
            printdata();
            
            printf("处理时间%f\n\n", t * px);
            system("pause");
        }
        else if(choose == '4') {
            printf("处理前：\n");
            printdata();

            clock_t start, finish;
            
            start = clock();
            QuickSort(a, n);
            finish = clock();
            double t = (double)(finish - start);

            printf("\n\n处理后：\n");
            printdata();
            
            printf("处理时间%f\n\n",t * px);
            system("pause");
        }
        else if(choose == '5') {
            printf("处理前：\n");
            printdata();
            
            clock_t start, finish;

            start = clock();
            Partition(a, 0, n - 1);
            finish = clock();
            double t = (double)(finish - start);

            printf("\n\n处理后：\n");
            printdata();
            
            printf("处理时间%f\n\n", t * px);
            system("pause");
        }
        else if(choose == '6') {
            printf("处理前：\n");
            printdata();
            
            clock_t start, finish;
            
            start = clock();
            CountSort(a, n, 0);
            finish = clock();
            double t = (double)(finish - start);

            printf("\n\n处理后：\n");
            printdata();
            
            printf("处理时间%f\n\n",t * px);
            system("pause");
        }
        else if(choose == '7') {
            printf("处理前：\n");
            printdata();
            
            clock_t start, finish;

            start = clock();
            RadixCountSort(a, n);
            finish = clock();
            double t = (double)(finish - start);

            printf("\n\n处理后：\n");
            printdata();
            
            printf("处理时间%f\n\n",t * px);
            system("pause");
        }
        else if(choose == '8') {
            printf("数据转换前：\n");
            for(int i = 0 ; i < 100 ; i ++ ) {
                printf("%5d ",a[i]);
                a[i] %= 3;
                if((i + 1) % 10 == 0)    printf("\n");
            }

            printf("数据转化后：\n");
            printdata();
            
            clock_t start, finish;
            start = clock();
            ColorSort(a, n);
            finish = clock();
            double t = (double)(finish - start);

            printf("\n\n处理后：\n");
            printdata();

            printf("处理时间%f\n\n",t * px);
            system("pause");
        }
        else if(choose == '9') {
            printf("\n\n\t\t\t\t1.找到无序数列中第k大的数");
            printf("\n\n\t\t\t\t2.找到无需排序中第k小的数");
            printf("\n\n\t\t\t\t请输入您的选择：");
            char choose9;
            scanf("%s",&choose9);
            if(choose9 != '1' && choose9 != '2') {
                printf("无效的输入请重试：");
                scanf("%s",&choose9);
            }
            for(int i = 0 ; i < 100 ; i ++) {
                printf("%5d ",a[i]);
                if((i % 10) == 0 && i) printf("\n");
            }
            printf("\n\n");

            printf("请输入您想查询的第k个数：");
            int k;
            scanf("%d",&k);
            clock_t start, finish;
            start = clock();
            if(choose9 == '1')  findKMax(a, 0, n - 1, n - k);
            else if(choose9 == '2') findKMax(a, 0, n - 1, k);
            finish = clock();
            double t = (double)(finish - start);
            printf("处理时间%f\n\n",t  * px);
            system("pause");
        }
        else {
            printf("无效的输入！\n\n");
        }


        printf("\n\n您是否想结束程序？请输入y 或 n：");
        char judge;
        scanf("%s",&judge);
        while(judge != 'y' && judge != 'n') {
            printf("无效的输入请重试：");
            scanf("%s",&judge);
        }
        if(judge == 'y') {
            printf("感谢使用！\n\n退出程序！\n\n");
            system("pause");
            circle = 0;
        }
        if(judge == 'n') {
            char judge;
            printf("\n\n请问是否重新生成随机数到data.txt中？请输入y 或 n：");
            scanf("%s",&judge);
            while(judge != 'y' && judge != 'n') {
                printf("无效的输入请重试：");
                scanf("%s",&judge);
            }

            if(judge == 'y') {
                fstream file("data.txt", ios::out);
                srand((unsigned)time(0));
                for(int i = 0 ; i < 100 ; i ++ ) {
                    for(int i = 0 ; i < 100 ; i ++ ) {
                        a[i] = rand() % 10000;
                        file << a[i] << ' ';
                    }
                }
                file.close();
            }
            if(judge == 'n') {
                fstream file("data.txt", ios::in);
                for(int i = 0 ; i < 100 ; i ++ ) {
                    file >> a[i];
                }
                file.close();
            }
            
            printf("文件操作成功！\n\n");
            system("pause");
        }
    }

    return 0;
}

*/



int main() {
    char judge;
    printf("请问是否重新生成随机数到data.txt中？请输入y 或 n：");
    scanf("%s",&judge);
    while(judge != 'y' && judge != 'n') {
        printf("无效的输入请重试：");
        scanf("%s",&judge);
    }

    if(judge == 'y') {
        fstream file("data.txt", ios::out);
        srand((unsigned)time(0));
        for(int i = 0 ; i < 100 ; i ++ ) {
            for(int i = 0 ; i < 100 ; i ++ ) {
                a[i] = rand() % 100000;
                file << a[i] << ' ';
            }
        }
        file.close();
    }
    if(judge == 'n') {
        fstream file("data.txt", ios::in);
        for(int i = 0 ; i < 100 ; i ++ ) {
            file >> a[i];
        }
        file.close();
    }
    
    printf("文件操作成功！\n\n");
    system("pause");

    int px;
    printf("\t\t\t\t请选择运行的次数\n");
    printf("\t\t\t\t1.10000   2.50000   3.200000\n\n");
    printf("\t\t\t\t请输入您的选择：");
    judge = 'n';
    char ch;
    scanf("%s",&ch);
    if(ch == '1')       px =  10000;
    else if(ch == '2')  px =  50000;
    else if(ch == '3')  px = 200000;
    else {
        printf("无效的输入请重试：");
        scanf("%s",&ch);
    }

    int n = 100;
    clock_t start, finish;
    //1
    printf("插入排序：\n");
    
    start = clock();
    for(int i = 0 ;  i < px ; i ++ ) {
        for(int j = 0 ; j < 100 ; j ++ )
            b[j] = a[j];
        insertSort(b, n);
    }
    finish = clock();
    printf("处理时间：%dms\n\n",(int)(finish - start));
    
    //2
    printf("归并排序：\n");
    start = clock();
    for(int i = 0 ;  i < px ; i ++ ) {
        for(int j = 0 ; j < 100 ; j ++ )
            b[j] = a[j];
        MergeSort(b, 0, n - 1, temp);
    }
    finish = clock();
    printf("处理时间：%dms\n\n",(int)(finish - start));
    
    //3
    printf("快速排序（归并版）：\n");
    start = clock();
    for(int i = 0 ;  i < px ; i ++ ) {
        for(int j = 0 ; j < 100 ; j ++ )
            b[j] = a[j];
        QuickSort_Recursion(b, 0, n - 1);
    }
    finish = clock();
    printf("处理时间：%dms\n\n",(int)(finish - start));

    //4
    printf("快速排序（非归并版）：\n");
    start = clock();
    for(int i = 0 ;  i < px ; i ++ ) {
        for(int j = 0 ; j < 100 ; j ++ )
            b[j] = a[j];
        QuickSort(b, n);
    }
    finish = clock();
    printf("处理时间：%dms\n\n",(int)(finish - start));
    
    //5
    printf("快速排序（枢轴存放）：\n");
    start = clock();
    for(int i = 0 ;  i < px ; i ++ ) {
        for(int j = 0 ; j < 100 ; j ++ )
            b[j] = a[j];
        Partition(b, 0, n - 1);
    }
    finish = clock();
    printf("处理时间：%dms\n\n",(int)(finish - start));
    
    //6
    printf("计数排序：\n");
    start = clock();
    for(int i = 0 ;  i < px ; i ++ ) {
        for(int j = 0 ; j < 100 ; j ++ )
            b[j] = a[j];
        CountSort(b, n, 0);
    }
    finish = clock();
    printf("处理时间：%dms\n\n",(int)(finish - start));
    
    //7
    printf("基数计数排序：\n");
    start = clock();
    for(int i = 0 ;  i < px ; i ++ ) {
        for(int j = 0 ; j < 100 ; j ++ )
            b[j] = a[j];
        RadixCountSort(b, n);
    }
    finish = clock();
    printf("处理时间：%dms\n\n",(int)(finish - start));
    
    //8
    printf("颜色排序：\n");

    start = clock();
    for(int i = 0 ;  i < px ; i ++ ) {
        for(int j = 0 ; j < 100 ; j ++ )
            b[j] = a[j] % 3;
        
    }
    finish = clock();
    printf("处理时间：%dms\n\n",(int)(finish - start));
    
    printf("\n\n退出程序！\n\n");
    system("pause");
    return 0;
}