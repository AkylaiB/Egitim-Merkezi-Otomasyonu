#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
/*Ad:Akylai
Soyad:Bolotbekova
Numara:20010011520*/
typedef struct Kurs
{

    char kAd[20];
    int kNot;
    int kSaat;
} KS;
typedef struct Ogrenci
{
    int ogrNo;
    char ad[20];
    char soyad[20];
    float ortNot;
    int odeme;
    int kSayisi;
    KS* kurslar;
} Ogr;

Ogr* ogrenciler;
int ogrSayisi=0;

void ekle(int ogrno,char ad[20],char soyad[20],int kursSay)
{
    if(ogrSayisi==0)
    {
        ogrenciler=(Ogr*)malloc(sizeof(Ogr));
    }
    else
    {
        ogrenciler=(Ogr*)realloc(ogrenciler,sizeof(Ogr)*(ogrSayisi+1));
    }
    (ogrenciler+ogrSayisi)->ogrNo=ogrno;
    strcpy((ogrenciler+ogrSayisi)->ad,ad);
    strcpy((ogrenciler+ogrSayisi)->soyad,soyad);
    (ogrenciler+ogrSayisi)->kSayisi=kursSay;


    (ogrenciler+ogrSayisi)->kurslar=(KS*)malloc(sizeof(KS)*kursSay);
    int i;
    for(i=0; i<kursSay; i++)
    {
        printf("%d.Kursun Adi:",i+1);
        scanf("%s",((ogrenciler+ogrSayisi)->kurslar+i)->kAd);
        printf("%d.Kursun Notu:",i+1);
        scanf("%d",&((ogrenciler+ogrSayisi)->kurslar+i)->kNot);
        printf("%d.Kursun haftada saat sayisi:",i+1);
        scanf("%d",&((ogrenciler+ogrSayisi)->kurslar+i)->kSaat);
        printf("\n");
    }

    ogrSayisi++;
}
void listeleme()
{
    int i,j;
    for(i=0; i<ogrSayisi; i++)
    {
        printf("----------------------------------------------------\n");
        printf("%d.Ogrencinin numarasi:%d \n",i+1,(ogrenciler+i)->ogrNo);
        printf("%d.Ogrencinin adi:%s \n",i+1,(ogrenciler+i)->ad);
        printf("%d.Ogrencinin soyadi:%s \n",i+1,(ogrenciler+i)->soyad);
        printf("%d.Ogrencinin kurs sayisi:%d \n",i+1,(ogrenciler+i)->kSayisi);
        printf("\n");
        for(j=0; j<(ogrenciler+i)->kSayisi; j++)
        {
            printf("%d.Kursun adi:%s \n",j+1,((ogrenciler+i)->kurslar+j)->kAd);
            printf("%d.Kursun notu:%d \n",j+1,((ogrenciler+i)->kurslar+j)->kNot);
            printf("%d.Kursun haftada saat sayisi:%d \n",j+1,((ogrenciler+i)->kurslar+j)->kSaat);
            printf("\n");
        }
    }
}
void silme(int ogrenci)
{
    int i;
    if(ogrenci<=0||ogrenci>ogrSayisi)
        {
        printf("Boyle bir ogrenci bulunmamaktadir...\n");
        }
    else
        {
        for(i=ogrenci;i<ogrSayisi;i++)
            {
            *(ogrenciler+(i-1))=*(ogrenciler+i);
            }
        ogrSayisi--;
        ogrenciler=(Ogr*)realloc(ogrenciler,sizeof(Ogr)*ogrSayisi);
        }
}
void arama(char ad[20])
{

    int i,j;
    for(i=0;i<ogrSayisi;i++)
    {
        if(strcmp((ogrenciler+i)->ad,ad)==0)
        {

            printf("Bulunan ogrencinin:\n");
            printf("Nosu:%d\n",(ogrenciler+i)->ogrNo);
            printf("Adi:%s\t",(ogrenciler+i)->ad);
            printf("Soyadi:%s\n",(ogrenciler+i)->soyad);
            printf("\nKurs Bilgileri:\n");
            for(j=0;j<(ogrenciler+i)->kSayisi;j++)
                {
                printf("%d.Kursun adi:%s\n",i+1,((ogrenciler+i)->kurslar+j)->kAd);
                printf("%d.Kursun notu:%d\n",i+1,((ogrenciler+i)->kurslar+j)->kNot);
                printf("%d.Kursun haftada saat sayisi:%d\n",i+1,((ogrenciler+i)->kurslar+j)->kSaat);
                printf("\n");
                }
        }
     }
}
void guncelleme(char ad[20])
{
    int i,j;
     for(i=0;i<ogrSayisi;i++)
    {
        if(strcmp((ogrenciler+i)->ad,ad)==0)
        {
        printf("\nGuncellenecek ogrencinin kurslari:\n");
        for(j=0;j<(ogrenciler+i)->kSayisi;j++)
            {
             printf("%d.Kursun adi:%s\n",j+1,(((ogrenciler+i)->kurslar)+j)->kAd);
             printf("%d.Kursun notu:%d\n",j+1,(((ogrenciler+i)->kurslar)+j)->kNot);
             printf("%d.Kursun haftada saat sayisi:%d\n",j+1,(((ogrenciler+i)->kurslar)+j)->kSaat);
             printf("\n");
            }
        printf("Kacinci kursu guncellemek istiyorsunuz?");
        int kurs;
        scanf("%d",&kurs);

        if(kurs<=0||kurs>((ogrenciler+i)->kSayisi))
        {
            printf("Boyle bir kurs bulunmamaktadir...\n");
        }
        else
            {
             printf("%d.Kursun yeni notu:",kurs);
             scanf("%d",&(((ogrenciler+i)->kurslar)+(kurs-1))->kNot);
             printf("%d.Kursun yeni saat sayisi:",kurs);
             scanf("%d",&(((ogrenciler+i)->kurslar)+(kurs-1))->kSaat);

             printf("----------------------\n");
             printf("Guncellendikten sonra:\n");
             for(j=0;j<(ogrenciler+i)->kSayisi;j++)
              {
               printf("%d.Kursun adi:%s\n",i+1,(((ogrenciler+i)->kurslar)+j)->kAd);
               printf("%d.Kursun notu:%d\n",i+1,(((ogrenciler+i)->kurslar)+j)->kNot);
               printf("%d.Kursun haftada saat sayisi:%d\n",i+1,(((ogrenciler+i)->kurslar)+j)->kSaat);
               printf("\n");
              }

             }
        }
   }
}
float ortNotuHesaplama(char ad[20])
{
    int topnot=0,topsaat=0,i,j;
    float ort;
    for(i=0;i<ogrSayisi;i++)
    {
        if(strcmp((ogrenciler+i)->ad,ad)==0)
        {
        topnot=0;
        topsaat=0;
        for(j=0;j<(ogrenciler+i)->kSayisi;j++)
          {
            topsaat+=(((ogrenciler+i)->kurslar)+j)->kSaat;
            topnot+=((((ogrenciler+i)->kurslar)+j)->kSaat)*((((ogrenciler+i)->kurslar)+j)->kNot);
          }
         ort=topnot/topsaat;
        (ogrenciler+i)->ortNot=ort;
         printf("%d.ogrencinin ortalama notu=%2.lf",i+1,(ogrenciler+i)->ortNot);
        printf("\n");
        }
    }
    return ort;
}
void odeme(char ad[20])
{
    int i,odenecek,indirim;
    float ort;
    for(i=0;i<ogrSayisi;i++)
    {
        if(strcmp((ogrenciler+i)->ad,ad)==0)
        {

            printf("Bulunan ogrencinin:\n");
            printf("Kurs sayisi:%d\n",(ogrenciler+i)->kSayisi);

            (ogrenciler+i)->odeme=0;
            (ogrenciler+i)->odeme=((ogrenciler+i)->kSayisi)*3000;
             ort = ortNotuHesaplama(ad);
             (ogrenciler+i)->ortNot=ort;
               if(ort>=85)/*sadece uzun olmamasi icin (ogrenciler+i)->ortNot yerine ort kullandim*/
               {
                indirim=(ogrenciler+i)->odeme*0.2;
                printf("Indirim yuzde 20 - %d\n",indirim);
                (ogrenciler+i)->odeme-=indirim;
                printf("Odenmesi gereken:%d\n",(ogrenciler+i)->odeme);
               }
               else if(ort>=75)
               {
                indirim=(ogrenciler+i)->odeme*0.1;
                printf("Indirim yuzde 10- %d\n",indirim);
                (ogrenciler+i)->odeme-=indirim;
                printf("Odenmesi gereken:%d\n",(ogrenciler+i)->odeme);
               }
              else if(ort>=60)
               {
                indirim=(ogrenciler+i)->odeme*0.05;
                printf("Indirim yuzde 5- %d\n",indirim);
                (ogrenciler+i)->odeme-=indirim;
                printf("Odenmesi gereken:%d\n",(ogrenciler+i)->odeme);
               }
               else
               {
                printf("Uzgunuz herhangi bir indirim alamiyorsunuz.\n");
                printf("Odenmesi gereken:%d\n",(ogrenciler+i)->odeme);
               }
            printf("Odenecek para miktarini giriniz:");
            scanf("%d",&odenecek);
            (ogrenciler+i)->odeme-=odenecek;
            printf("Kalan odenmesi gereken para miktari:%d\n",(ogrenciler+i)->odeme);
        }
    }
}

int main()
{
    int secim;
    int dongu=1;
    while(dongu)
    {
        printf("***MENU***\n");
        printf("--------------------------------------------------------------------------\n");
        printf("1.Ekleme\n2.Silme\n3.Not Guncelleme\n4.Listeleme\n5.Ogrenci Arama\n6.Odeme Yapma\n0.Cikis\n");
        printf("--------------------------------------------------------------------------\n");
        printf("=>");
        scanf("%d",&secim);
        char ad[20],soyad[20];
        int kursSay,ogrno;
        int ogrenci;
        switch(secim)
        {
        case 1:
            printf("Ogrenci numarasini giriniz:");
            scanf("%d",&ogrno);
            printf("Eklemek istediginiz ogrencinin ismi nedir?");
            scanf("%s",ad);
            printf("Eklemek istediginiz ogrencinin soyismi nedir?");
            scanf("%s",soyad);
            printf("%s adli ogrencinin kac kursu var?",ad);
            scanf("%d",&kursSay);
            ekle(ogrno,ad,soyad,kursSay);

            break;
        case 2:
            printf("Kacinci ogrenciyi silmek istiyorsunuz?");
            scanf("%d",&ogrenci);
            silme(ogrenci);
            break;
        case 3:
            printf("Guncellemek istediginiz ogrencinin ismi nedir?");
            scanf("%s",ad);
            guncelleme(ad);
            ortNotuHesaplama(ad);
            break;
        case 4:
            listeleme();
            break;
        case 5:
            printf("Aranacak ogrencinin ismi nedir?");
            scanf("%s",ad);
            arama(ad);
            break;
       case 6:
            printf("Odemesini yapmak istediginiz ogrencinin ismi nedir?");
            scanf("%s",ad);
            odeme(ad);

            break;
        case 0:
            dongu=0;
            break;
        default:
            printf("Yanlis secim");
        }
        printf("devam etmek icin bir tusa basiniz...");/*ana menuye donmek icin kullanildi*/
        getch();
        system("CLS");
    }
    return 0;
}

