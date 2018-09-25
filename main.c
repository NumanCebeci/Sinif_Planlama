//CANSU SAHIN 140202012
//NUMAN CEBECI 140202008

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct ogrenci
{
   char ad[20],soyad[20],ogrenimTuru[20];
   int numara,kayitSirasi,kayitYili;
   char ogrNo[20],isim[20],soyisim[20],kayit[20],ogrTuru[20];
};
struct ogrenci ogrenci[1000];
struct ogrenci geciciOgrenci[1000];

int yeniListe(int i)
{
    time_t start,end;
    time (&start);

    int j,k,l,m=0;
    int sonuc=i;
    printf("Ayni Isimde Birden Cok Kez Yazilanlar\n");
    for(j=0;j<i;j++)
    {
        for(k=j+1;k<i;k++)
        {
            if(strcmp(ogrenci[k].ad,ogrenci[j].ad)==0 && strcmp(ogrenci[k].soyad,ogrenci[j].soyad)==0)
            {
                printf("%s  %s\n",ogrenci[j].ad,ogrenci[j].soyad);
                for(l=k;l<i;l++)
                {
                    strcpy(ogrenci[l].ad,ogrenci[l+1].ad);
                    strcpy(ogrenci[l].soyad,ogrenci[l+1].soyad);
                    ogrenci[l].numara=ogrenci[l+1].numara;
                    strcpy(ogrenci[l].ogrenimTuru,ogrenci[l+1].ogrenimTuru);
                    ogrenci[l].kayitSirasi=ogrenci[l+1].kayitSirasi;
                }
                i--;
                m++;
            }
            k++;
        }
    }
    int N=sonuc-m,n;
    for(j=0;j<N;j++)
    {
        if(ogrenci[j].kayitSirasi!=0)
        {
            ogrenci[j].kayitSirasi=ogrenci[j].kayitSirasi-1;
        }
    }
    FILE *yeniDosya;
    yeniDosya=fopen("yeni_ogrenci_kayit_bilgileri.txt","w");

    for(j=0;j<N;j++)
    {
        if(ogrenci[j].numara==0)
        {
            if(!strcmp(ogrenci[j].ogrenimTuru,"I"))
            {
                ogrenci[j].numara=(1000000*17+1000*1+ogrenci[j].kayitSirasi);
            }
            else
            {
                ogrenci[j].numara=(1000000*17+1000*2+ogrenci[j].kayitSirasi);
            }
            ogrenci[j].kayitSirasi=0;
        }
    }
    printf("\n");
    printf("Kaydi Iki Kez Yapilan Ogrenciler Cikarilmistir\n");
    fprintf(yeniDosya,"Kaydi Iki Kez Yapilan Ogrenciler Cikarilmistir\n");
    for(n=0;n<1;n++)
    {
        fprintf(yeniDosya,"%s %s %s %s %s \n",ogrenci[n].ogrNo,ogrenci[n].isim,ogrenci[n].soyisim,ogrenci[n].kayit,ogrenci[n].ogrTuru);
    }
    for(j=0;j<N;j++)
    {
       fprintf(yeniDosya,"%d %s %s %d %s\n",ogrenci[j].numara,ogrenci[j].ad,ogrenci[j].soyad,ogrenci[j].kayitSirasi,ogrenci[j].ogrenimTuru);
       //printf("%d %s %s %d %d\n",ogrenci[j].numara,ogrenci[j].ad,ogrenci[j].soyad,ogrenci[j].kayitSirasi,ogrenci[j].ogrenimTuru);
    }

    for(j=0;j<N;j++)
    {
        for(k=0;k<N;k++)
        {
            if(ogrenci[j].numara<ogrenci[k].numara)
            {
                geciciOgrenci[j].numara=ogrenci[k].numara;
                ogrenci[k].numara=ogrenci[j].numara;
                ogrenci[j].numara=geciciOgrenci[j].numara;
            }
        }
    }

    printf("Kayitlar Numaraya Gore Siralanmistir\n\n");
    fprintf(yeniDosya,"************************\n\n");
    fprintf(yeniDosya,"Numaraya Gore Siralanmis Liste\n");
    for(n=0;n<1;n++)
    {
        fprintf(yeniDosya,"%s %s %s %s %s\n",ogrenci[n].ogrNo,ogrenci[n].isim,ogrenci[n].soyisim,ogrenci[n].kayit,ogrenci[n].ogrTuru);
    }
    for(j=0;j<N;j++)
    {
       fprintf(yeniDosya,"%d %s %s %d %s\n",ogrenci[j].numara,ogrenci[j].ad,ogrenci[j].soyad,ogrenci[j].kayitSirasi,ogrenci[j].ogrenimTuru);
       //printf("%d %s %s %d %d\n",ogrenci[j].numara,ogrenci[j].ad,ogrenci[j].soyad,ogrenci[j].kayitSirasi,ogrenci[j].ogrenimTuru);
    }

    fclose(yeniDosya);
    time (&end);
    printf ("Yeni Liste Fonksiyonu Calisma Suresi :%.2lf \n\n", difftime (end,start));
    return N;
}

int sinifListesi(int i,int N)
{
    time_t start,end;
    time (&start);

    int sinifSayisi;
    int j, birinciOgretim=0, ikinciOgretim=0;

    for(j=0;j<N;j++)
    {
        if(!strcmp(ogrenci[j].ogrenimTuru,"I"))

            {
                birinciOgretim++;
            }
        else
            {
                ikinciOgretim++;
            }
    }

    printf("Dersi Alan Birinci Ogretim Ogrenci Sayisi:%d\n",birinciOgretim);
    printf("Dersi Alan Ikinci Ogretim Ogrenci Sayisi:%d\n",ikinciOgretim);
    printf("Kac sinif Olacak?\n");    scanf("%d",&sinifSayisi);
    printf("Siniflarin Kapasitesi Ne Olacak?\n");
    int sinifKapasitesi[sinifSayisi], doluluk[sinifSayisi],doluluk2[sinifSayisi];
    int doluluk3[sinifSayisi],doluluk4[sinifSayisi];

    yeniden:
    for(j=0;j<sinifSayisi;j++)
    {
        scanf("%d",&sinifKapasitesi[j]);
        doluluk[j] = 0;
        doluluk2[j] = 0;
        doluluk3[j] = 0;
        doluluk4[j] = 0;
    }

    int toplam=0;
    for(j=0;j<sinifSayisi;j++)
    {
        toplam+=sinifKapasitesi[j];
    }
    if(toplam<birinciOgretim)
    {
        printf("Sinif Kapasiteleri Yeterli Degil Yeniden Degerler Giriniz\n");
        goto yeniden;
    }

    int hangiSinif1,sayi1=0;
    for(j=0 ; j<birinciOgretim ; j++)
    {
        hangiSinif1 = sayi1%sinifSayisi;
        if(sinifKapasitesi[hangiSinif1]-doluluk[hangiSinif1]>0)
        {
            doluluk[hangiSinif1]++;
        }
        else
        {
            j--;
        }
    sayi1++;
    }
    printf("Birinci Ogretim Esit Dagilim:\n");
    for(j=0 ; j<sinifSayisi ; j++)
    {
        printf("%d sinifta %d ogrenci var.\n",j+1, doluluk[j]);
    }

    int k,tmp;
    for(j=0 ; j<sinifSayisi ; j++)
    {
        for(k=0 ; k<sinifSayisi ; k++)
        {
            if(sinifKapasitesi[j]>sinifKapasitesi[k])
            {
                tmp = sinifKapasitesi[j];
                sinifKapasitesi[j]=sinifKapasitesi[k];
                sinifKapasitesi[k]=tmp;
            }
        }
    }
    hangiSinif1 = 0;
    for(j=0 ; j<birinciOgretim ; j++)
    {
        if(sinifKapasitesi[hangiSinif1]-doluluk2[hangiSinif1]>0)
        {
            doluluk2[hangiSinif1]++;
        }
        else
        {
            hangiSinif1++;
            j--;
        }
    }

    printf("Birinci Ogretim En Az Dagilim\n");
    for(j=0 ; j<sinifSayisi ; j++)
    {
        printf("%d sinifta %d ogrenci var.\n",j+1, doluluk2[j]);
    }

    int hangiSinif2;
    int sayi2=0;
    for(j=0 ; j<ikinciOgretim ; j++)
    {
        hangiSinif2 = sayi2%sinifSayisi;
        if(sinifKapasitesi[hangiSinif2]-doluluk3[hangiSinif2]>0)
        {
            doluluk3[hangiSinif2]++;
        }
        else
        {
            j--;
        }
    sayi2++;
    }

    printf("Ikinci Ogretim Esit Dagilim:\n");
    for(j=0 ; j<sinifSayisi ; j++)
    {
        printf("%d sinifta %d ogrenci var.\n",j+1, doluluk3[j]);
    }

    for(j=0 ; j<sinifSayisi ; j++)
    {
        for(k=0 ; k<sinifSayisi ; k++)
        {
            if(sinifKapasitesi[j]>sinifKapasitesi[k])
            {
                tmp = sinifKapasitesi[j];
                sinifKapasitesi[j]=sinifKapasitesi[k];
                sinifKapasitesi[k]=tmp;
            }
        }
    }

    hangiSinif2 = 0;
    for(j=0 ; j<ikinciOgretim ; j++)
    {
        if(sinifKapasitesi[hangiSinif2]-doluluk4[hangiSinif2]>0)
        {
            doluluk4[hangiSinif2]++;
        }
        else
        {
            hangiSinif2++;
            j--;
        }
    }
    printf("Ikinci Ogretim En Az Dagilim\n");
    for(j=0 ; j<sinifSayisi ; j++)
    {
        printf("%d sinifta %d ogrenci var.\n",j+1, doluluk4[j]);
    }

  printf("\n");
  time (&end);
  printf ("Sinif Listesi Fonksiyonu Calisma Suresi :%.2lf \n", difftime (end,start));

return 0;
}

void yeniKayit()
{
    time_t start,end;
    time (&start);

    FILE *yeniDosya;
    yeniDosya=fopen("yeni_ogrenci_kayit_bilgileri.txt","a");
    int i,yeni;
    ekle:
    for(i=0;i<1;i++)
    {
        printf("Ad: ");  scanf("%s",ogrenci[i].ad);
        printf("Soyad: "); scanf("%s",ogrenci[i].soyad);
        printf("Kayit Yili: ");  scanf("%d",&ogrenci[i].kayitYili);
        printf("Okula Kayit Sirasi: "); scanf("%d",&ogrenci[i].kayitSirasi);
        printf("Ogrenim Turu: ");  scanf("%s",ogrenci[i].ogrenimTuru);
        if(!strcmp(ogrenci[i].ogrenimTuru,"I"))
            {
                ogrenci[i].numara=(100000*(ogrenci[i].kayitYili-2000)+1000*1+ogrenci[i].kayitSirasi);
            }
        else
            {
                ogrenci[i].numara=(100000*(ogrenci[i].kayitYili-2000)+1000*2+ogrenci[i].kayitSirasi);
            }
        fprintf(yeniDosya,"%d %s %s %d %s\n",ogrenci[i].numara,ogrenci[i].ad,ogrenci[i].soyad,ogrenci[i].kayitSirasi,ogrenci[i].ogrenimTuru);

    }
    printf("Yeni Kayit Eklemek Isterseniz 1'e Basiniz:");   scanf("%d",&yeni);
    if(yeni==1)
    {
        goto ekle;
    }
  fclose(yeniDosya);
  time (&end);
  printf ("Sinif Listesi Fonksiyonu Calisma Suresi :%.2lf \n", difftime (end,start));
}

int main()
{   time_t start,end;
    time (&start);

    FILE *dosya;
    dosya=fopen("ogrenci_kayit_bilgileri.txt","r");
    int i=0;
    char dizi[10];

    if(dosya!=NULL)
    {

    }
    int n,yeni;
    for(n=0;n<1;n++)
    {
        fscanf(dosya,"%s %s %s %s %s ",ogrenci[n].ogrNo,ogrenci[n].isim,ogrenci[n].soyisim,ogrenci[n].kayit,ogrenci[n].ogrTuru);
    }

    while(!feof(dosya))
    {
        fscanf(dosya,"%s %s %s %d %s",dizi,ogrenci[i].ad,ogrenci[i].soyad,&ogrenci[i].kayitSirasi,ogrenci[i].ogrenimTuru);
        ogrenci[i].numara=atoi(dizi);
        //printf("%d %s %s %d %s\n",ogrenci[i].numara,ogrenci[i].ad,ogrenci[i].soyad,ogrenci[i].kayitSirasi,ogrenci[i].ogrenimTuru);
        i++;
    }

    fclose(dosya);
    int a=yeniListe(i);
    sinifListesi(i,a);
    printf("\nYeni Kayit Yapmak Isterseniz 1'e Basiniz:");  scanf("%d",&yeni);
    if(yeni==1)
    {
        yeniKayit();
    }

    time (&end);
    printf ("Main Fonksiyonu Calisma Suresi :%.2lf ", difftime (end,start));

    return 0;
}
