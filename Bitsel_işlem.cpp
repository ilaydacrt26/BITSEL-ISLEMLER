#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void BitselGoster(int sayi)
{
    if (sayi >= 0)
    {
        int dizi[32];
        int index = 0;
        while (sayi > 0)
        {
            int bit = sayi & 1;
            dizi[index++] = bit;
            sayi = sayi >> 1;
        }
        for (int i = 0; i < 4 - index; i++)
        {
            printf("0 ");
        }

        for (int i = index - 1; i >= 0; i--)
        {
            printf("%d ", dizi[i]);
        }
    }
    else
    {
        sayi = abs(sayi);
        int dizi[32];
        int index = 0;
        while (sayi > 0)
        {
            int bit = sayi & 1;
            dizi[index++] = bit;
            sayi = sayi >> 1;
        }
        for (int i = 0; i < 4 - index; i++)
        {
            if (i == 0)
            {
                printf("1 ");
            }
            else
            {
                printf("0 ");
            }
        }
        for (int i = index - 1; i >= 0; i--)
        {
            printf("%d ", dizi[i]);
        }
    }
}

long long Encode(int dizi[], int n)
{
    long long sonuc = 0;
    int buyuk, durumindisi = 0;
    for (int i = 0; i < n; i++)
    {
        buyuk = -1000;
        for (int j = 0; j < n; j++)
        {
            if (buyuk < dizi[j])
            {
                buyuk = dizi[j];
                durumindisi = j;
            }
        }
        dizi[durumindisi] = -1000;
        sonuc <<= 1;
        if (buyuk < 0)
        {
            sonuc += 1;
            buyuk*= -1;
        }
            sonuc <<= 3;
            sonuc+=buyuk;
    }
    return sonuc;
}

void Decode(int n, long long sonuc)
{
    int a = 0;
    int cikti = 0;
    int dizi2[n];
    for (int i = 0; i < n; i++)
    {
        cikti = sonuc & 7; //111
        a = (sonuc >> 3) & 1;
        if (a == 1)
        {
            cikti *= -1;
        }
        // printf("%d ", cikti);
        dizi2[i]=cikti;
        sonuc = sonuc >> 4;
    }
    for (int i = n-1; i >=0 ; i--)
    {
        printf("%d ",dizi2[i]);
    }
    
}

void Yazdir(int n, long long sonuc)
{
    int a = 0;
    int cikti = 0;
    int dizi2[n];
    for (int i = 0; i < n; i++)
    {
        cikti = sonuc & 7;
        a = (sonuc >> 3) & 1;
        if (a == 1)
        {
            cikti *= -1;
        }
        dizi2[i]=cikti;
        sonuc = sonuc >> 4;
    }
    for (int i = n-1; i >=0; i--)
    {
        BitselGoster(dizi2[i]);
        printf(" |  ");
    }
    
}

int main()
{
    srand(time(NULL));
    int n;
    do
    {
        printf("Dizi kac elemanli olacak: ");
        scanf("%d", &n);
    } while (n > 8);

    int dizi[n];

    for (int i = 0; i < n; i++)
    {
        dizi[i] = -7 + rand() % 15;
    }
    printf("Dizi[] ==> ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", dizi[i]);
    }
    printf("\n\n");
    int yenideger = Encode(dizi, n);
    printf("ENCODE ==> %d\n", yenideger);
    printf("DECODE ==> ");
    Decode(n, yenideger);
    printf("\n");
    Yazdir(n, yenideger);
}