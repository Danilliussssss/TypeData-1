

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int UsualSort(int * massive,int n)// Алгоритм обычной сортировки вставками.
{
    int x, j;
    for (int i = 0; i <n; i++)
    {
        x = massive[i];
        for (j = i - 1; j >= 0 && massive[j] < x; j--)
            massive[j + 1] = massive[j];
        massive[j + 1] = x;
    }
    
    return n*n;//Алгоритм возвращает временную сложность
}
int QuickSort(int left,int right,int *massive)
{
    int i =left, j=right,e= massive[(i + j + 1)/2];
    do {
        while (massive[i] > e)
            i++;
        while (massive[j] < e )
            j--;
        if (i <= j)
        {
            int x = massive[i];
            massive[i] = massive[j];
            massive[j] = x;
            i++; j--;
        }
    } while (i <= j);
    if (left < j)
        QuickSort(left, j, massive); if (i < right)
        QuickSort(i, right, massive);

    return pow(left + right+1, 2);
}
int BinarySearch(int* massive,int n,int search)
{
    int i;
    if (search < massive[n / 2])
    {
        i = n - 1;
        while (search != massive[i] && i >= n / 2)
            i--;
    }
    else if (search >= massive[n / 2])
    {
        i = 0;
        while (search != massive[i] && i <= n / 2)
            i++;
    }
    if (massive[i] == search)
        return massive[i];
    else return 0;
    

}
void PrintSort(int a)
{
    printf("\n----------------------------------------------------------------------\n");
    printf("Временная cложность сортировки:%d", a);
    printf("\nЁмкостная сложность сортировки: Алгоритм не использует дополнительной памяти");
}
void print(int *array,int n)
        {
printf("\n----------------------------------------------------------------------\n");
        printf("\nУпорядоченный массив:\n");
        for (int i = 0; i < n; i++)
            printf("[%d]:%d\n", i, array[i]);
        }
bool comp(int a, int b)
{
    return a >= b;
}
bool comp2(int a, int b)
{
    
    return a < b;
}
int main()
{ 
    int n, choose;
    do {   
        setlocale(LC_ALL, "russian");
        printf("Введите кол-во элементов массива:");
        scanf_s("%d", &n);
        int* array = new int[n];
        printf("Введите элементы массива:");
        for (int i = 0; i < n; i++)
        {
            printf("\n[%d]:", i);
            scanf_s("%d", &array[i]);
        }
        printf("Какую сортировку использовать?\n1.Обычную\n2.Быструю\n3.Сортировку STL\n");
        do {
            scanf_s("%d", &choose);
        } while (choose < 1 && choose > 3);

        if (choose == 1)
        {
            PrintSort(UsualSort(array, n));
            print(array, n);
            printf("\nНачать бинарный поиск?\n1.Да\n2.Нет\n");
            do {
                scanf_s("%d", &choose);
            } while (choose != 1 && choose != 2);
            if (choose == 1)
            {
                printf("Введите число:");
                int search; scanf_s("%d", &search);
                printf("\n--------------------------------Result---------------------------------\n");
                printf("                                    %d\n", BinarySearch(array, n, search));
                printf("\nВременная сложность алгоритма:%lf\n", log2(n));
            }
        }
        else if (choose == 2)
        {
            int right = n-1, left=0;
            PrintSort(QuickSort(left, right, array));
            print(array, n);
            printf("\nНачать бинарный поиск?\n1.Да\n2.Нет\n");
            do {
                scanf_s("%d", &choose);
            } while (choose != 1 && choose != 2);
            if (choose == 1)
            {
                printf("Введите число:");
                int search; scanf_s("%d", &search);
                printf("\n--------------------------------Result---------------------------------\n");
                printf("                                    %d\n", BinarySearch(array, n, search));
                printf("\nВременная сложность алгоритма:%lf\n", log2(n));
            }
        }
        else if (choose == 3)
        {
            vector<int> V(array, array + n);
            sort(V.begin(), V.end(),comp);
            printf("\nУпорядоченный массив:\n");
            for (int i = 0; i < n; i++)
                printf("[%d]:%d\n", i, V[i]);
            printf("Введите число:");
            int search; scanf_s("%d", &search);
            vector<int>::iterator it;
            printf("\n--------------------------------Result---------------------------------\n");
            sort(V.begin(), V.end());
            if (binary_search(V.begin(), V.end(), search))
                printf("%d", search);
            else printf("\nНичего не найдено;(\n");           
        }    
        system("pause");
        delete[] array;
        system("cls");
    } while (n > 0);
    
}
