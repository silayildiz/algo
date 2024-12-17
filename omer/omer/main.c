//
//  main.c
//  omer
//
//  Created by sıla yıldız on 16.12.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int anaMenu(void);
int kampAlani(void);
int sifahaneGit(void);
int hanaGit(void);
int macerayaAtil(void);
float paraKazan(int karizma, int hijyen);
void seviyeAtla(int seviye, int tecrube);
int kolayKesif(float para);
int ortaKesif(float para);
int zorKesif(float para);

int main(int argc, const char * argv[]) {
    
    //isim ve calgi
    char ad[10];
    printf("Baslamak icin isminizi girin: ");
    fgets(ad, sizeof(ad),stdin);
    
    char calgi[20];
    printf("\nKullanmak istediginiz enstruman? ");
    fgets(calgi, sizeof(calgi),stdin);
    
    //temel nitelikler
    int can=50; int tokluk=50; int uyku=50; int hijyen=50; float para=10.0; int tecrube=0; int stres=50; int moral=50; int sans=50;
    
    //beceriler
    int guc=3; int ceviklik=3; int dayaniklilik=3; int karizma=3; int toplayicilik=3; int seviye=1;
    
    int secim; int yiyecekSecim;; int icecekSecim;
    int beceriGelistir;
    while(1){
    basla:
        secim=anaMenu();
        switch (secim){
            basla1:
            case 1:
                secim=kampAlani();
                switch(secim){
                    case 1:
                        moral+=20;
                        printf("\nsesin butun kasabayi buyuledi! +20 moral");
                        if(moral<=100){
                            printf("\nmoral seviyesi: %d",moral);
                        }
                        else{
                            moral=100;
                            printf("\nmoral seviyesi: %d",moral);
                        }
                        uyku-=10;
                        if(uyku<=0){
                            uyku=0;
                            can=can-5;
                            if(can<=0){
                                can=0;
                                printf("\nuykusuzluk sebebi ile yorgun dustun..canin -5 azaldi.\nuyku seviyesi: %d\tcan seviyesi:%d",uyku,can);
                                printf("\ncan seviyen 0' dustu.\noyun bitti..");
                                goto Son;
                            }
                            else{
                                printf("\nuykusuzluk sebebi ile yorgun düstün..canin -5 azaldi.\nuyku seviyesi: %d\tcan seviyesi:%d",uyku,can);
                            }
                            
                        }
                        else{
                            printf("\nbiraz yoruldun. uyku seviyen -5 azaldi.\nuyku seviyesi: %d",uyku);
                        }
                        tokluk-=15;
                        if(tokluk<=0){
                            tokluk=0;
                            can=can-10;
                            if(can<=0){
                                can=0;
                                printf("\naclik nedeniyle bitkin dustun. canin 10 azaldi.\ntokluk seviyesi: %d\tcan seviyesi: %d",tokluk,can);
                                printf("\ncan seviyen 0' dustu.\noyun bitti..");
                                goto Son;
                            }
                            else{
                                printf("\naclik sebebi ile yorgun düstün..canin -10 azaldi.\ntokluk seviyesi: %d\tcan seviyesi:%d",tokluk,can);
                            }
                            
                        }
                        else{
                            printf("\nhmm, biraz acıktın. tokluk 15 azaldi\ntokluk seviyesi: %d",tokluk);
                        }
                        break;
                    case 2:
                        printf("\nnehirde yikaniyorsun.\n:O su cok soguk!!");
                        hijyen+=40;
                        if(hijyen<100){
                            printf("\nhijyen: %d",hijyen);
                        }
                        else{
                            hijyen=100;
                            printf("\nhijyen: %d\nhijyen duzeyi maksimumda.",hijyen);
                        }
                        can+=15;
                        if(can<100){
                            printf("\ncan: %d",can);
                        }
                        else{
                            can=100;
                            printf("can: 100\ncan duzeyi maksimumda.");
                        }
                        stres-=10;
                        if(stres>=0){
                            printf("dus iyi geldi.\nstres -10: %d",stres);
                        }
                        else{
                            stres=0;
                            printf("dus iyi geldi.\nstres -10: %d",stres);
                        }
            
                        break;
                    case 3:
                        printf("\n\nzZz..");
                        uyku+=70;
                        if(uyku<=100){
                            printf("\n\nguzel bir uyku cektin, iyice dinlendin.");
                            printf("\nuyku seviyesi +70: %d",uyku);
                        }
                        else{
                            uyku=100;
                            printf("\n\nguzel bir uyku cektin, iyice dinlendin.");
                            printf("\nuyku seviyesi +70: %d",uyku);
                        }
                        can+=70;
                        if(can<100){
                            printf("\nuyumak iyi geldi.");
                            printf("\ncan +70: %d",can);
                        }
                        else{
                            can=100;
                            printf("\ndeliksiz uyku cektin.");
                            printf("\ncan: 100\ncan duzeyi maksimumda.");
                        }
                        tokluk-=35;
                        printf("uyurken biraz aciktin...");
                        if(tokluk<=0){
                            tokluk=0;
                            can=can-10;
                            if(can<=0){
                                can=0;
                                printf("\nuyurken acliktan hastalandin. 10 can puanina mal oldu.\ncan 0'a dustu.\noyun bitti.\ntokluk seviyesi: %d\tcan seviyesi: %d",tokluk,can);
                                goto Son;
                            }
                            else{
                                printf("\nuyurken acliktan hastalandin. 10 can puanina mal oldu.\ntokluk seviyesi: %d\tcan seviyesi: %d",tokluk,can);
                            }
                            
                        }
                        else{
                            printf("\nhmm, biraz acıktın. tokluk 35 azaldi\ntokluk seviyesi: %d",tokluk);
                            printf("\nbir seyler yesen iyi olacak.");
                        }
                        hijyen-=20;
                        printf("\nuyurken biraz terledin...");
                        if(hijyen>=0){
                            printf("\ndus alsan iyi olacak.\nhijyen: %d",hijyen);
                        }
                        else{
                            hijyen=0;
                            can=can-5;
                            if(can<=0){
                                can=0;
                                printf("\nhijyen eksikligi sebebiyle canin -5 puan azaldi, can degeri 0'a ulasti. Oyun sonlandiriliyor.\nhijyen seviyesi: %d\tcan seviyesi: %d",hijyen,can);
                                goto Son;
                            }
                            else{
                                printf("\nhijyen eksikligi sebebiyle canin -5 puan azaldi,\nhijyen seviyesi: %d\tcan seviyesi: %d",hijyen,can);
                            }
                        }
                        break;
                    case 4:
                        printf("\nkoy meydanina donuluyor.");
                        secim=anaMenu();
                        break;
                    default:
                        printf("\nhatali secim yapildi..");
                        goto basla1;
                        break;
                }break;
            basla2:
            case 2:
                secim=sifahaneGit();
                switch (secim) {
                    case 1:
                        printf("\nyara sardirmak icin 5 altin gerekiyor. yeteri kadar sansliysan sifaci yaralarini bedelsiz saracak.");
                        //şans seviyesi 90 ve üzerindeyse bedelsiz sargı yapılır.
                        if(sans<90){
                            if(para<5){
                                printf("\nsifaci seni evinden kovdu! biraz yagma yaptiktan sonra tekrar gel.");
                            }
                            else{
                                printf("5 altin karsiligi yaralarin sarildi.\n+40 can geldi.");
                                para-=5;
                                printf("\nkalan altinlar: %f",para);
                                can+=40;
                                if(can>100){
                                    can=100;
                                    printf("\ncan seviyesi +40: %d",can);
                                }
                                else{
                                    printf("\ncan seviyesi +40: %d",can);
                                }
                            }
                        }
                        else{
                            sans=sans-50;
                            can+=40;
                            printf("\n50 sans puani karsiliginda yaralarin sarildi.\n+40 can geldi.");
                            if(can>100){
                                can=100;
                                printf("\ncan seviyesi: %d",can);
                                printf("\nsans: %d",sans);
                            }
                            else{
                                printf("\ncan seviyesi: %d",can);
                                printf("\nsans: %d",sans);
                            }
                        }
                        
                        break;
                    case 2:
                        printf("\nsifaci 3 altin karsiliginda sana merhem hazirlayacak.");
                        if(para<3){
                            stres+=15;
                            if(stres>=100){
                                stres=100;
                                printf("\nmaalesef kremi karsilayamadın. Stres seviyen 15 artti.\nstres seviyesi: %d",stres);
                                can=can-5;
                                if(can<=0){
                                    printf("\ncan seviyen 5 azaldi, can 0'a ulasti.\noyundan cikiliyor.");
                                    goto Son;
                                }
                                else{
                                    printf("can seviyen 5 azaldi.\ncan seviyesi: %d",can);
                                }
                            }
                            else{
                                printf("\nkremi karsilayamadin,stresin artti\nstres seviyesi: %d",stres);
                            }
                        }
                        else{
                            para=para-3;
                            can=can+30;
                            if(can>=100){
                                can=100;
                                printf("3 altin karsiligi +30 can kazandin, maksimum cana ulasildi.\npara: %f\tcan seviyesi: %d",para,can);
                            }
                            else{
                                printf("3 altin karsiligi +30 can kazandin.\npara: %f\tcan seviyesi: %d",para,can);
                            }
                        }
                        break;
                    case 3:
                        printf("\nkoy meydanina donuluyor.");
                        secim=anaMenu();
                        break;
                        
                    default:
                        printf("\nhatali secim yapildi.");
                        goto basla2;
                        break;
                }break;
            basla3:
            case 3:
                secim=hanaGit();
                switch (secim) {
                    yiyecek:
                    case 1:
                        printf("\nYiyecek pazarina hosgeldin!\nAlmak istedigin yiyecegin numarasini tusla.");
                        printf("\n1.sihirli orman meyveleri-> *bedel: 1 altin  *tokluk: +15");
                        printf("\n2.Ekmek-> *bedel: 2 altin  *tokluk: +30 ");
                        printf("\n3.Et-> *bedel: 4 altin  *tokluk: +60");
                        scanf("%d",&yiyecekSecim);
                        switch (yiyecekSecim) {
                            case 1:
                                if(para<1){
                                    printf("\n\nparan yetersiz.biraz sarki soylemeye ne dersin?");
                                }
                                else{
                                    printf("\nmm meyveler lezzetliymis...");
                                    para=para-1;
                                    printf("\n1 altin karsiligi meyveleri yedin.\nkalan para: %f",para);
                                    tokluk+=15;
                                    if(tokluk>100){
                                        tokluk=100;
                                        printf("\ntokluk 15 puan artti, maksimum tokluk seviyesine ulasildigi icin can 20 puan artti.");
                                        can+=20;
                                        if(can>100){
                                            can=100;
                                            printf("\ncan maksimum degere ulasti.\ntokluk seviyesi: %d\tcan seviyesi: %d",tokluk,can);
                                        }
                                        else{
                                            printf("\ntokluk seviyesi: %d\tcan seviyesi: %d",tokluk,can);
                                        }
                                    }
                                    else{
                                        printf("\ntokluk seviyesi: %d\tcan seviyesi: %d",tokluk,can);
                                    }
                                    
                                }
                                break;
                            case 2:
                                if(para<2){
                                    printf("\n\nparan yetersiz.biraz sarki soylemeye ne dersin?");
                                }
                                else{
                                    para=para-2;
                                    printf("\n2 altin karsiligi ekmek yedin.\nkalan para: %f",para);
                                    printf("\nekmek biraz bayat olsa da acligini giderdi.");
                                    tokluk+=30;
                                    if(tokluk>100){
                                        tokluk=100;
                                        printf("\ntokluk 30 puan artti, maksimum tokluk seviyesine ulasildigi icin can 20 puan artti.");
                                        can+=20;
                                        if(can>100){
                                            can=100;
                                            printf("\ncan maksimum degere ulasti.\ntokluk seviyesi: %d\tcan seviyesi: %d",tokluk,can);
                                        }
                                        else{
                                            printf("\ntokluk seviyesi: %d\tcan seviyesi: %d",tokluk,can);
                                        }
                                    }
                                    else{
                                        printf("\ntokluk seviyesi: %d\tcan seviyesi: %d",tokluk,can);
                                    }
                                    
                                }
                                break;
                            case 3:
                                if(para<4){
                                    printf("\n\nparan yetersiz.biraz sarki soylemeye ne dersin?");
                                }
                                else{
                                    para=para-4;
                                    printf("\n4 altin karsiligi et yedin.\nkalan para: %f",para);
                                    tokluk+=15;
                                    if(tokluk>100){
                                        tokluk=100;
                                        printf("\ntokluk 15 puan artti, maksimum tokluk seviyesine ulasildigi icin can 20 puan artti.");
                                        can+=20;
                                        if(can>100){
                                            can=100;
                                            printf("\ncan maksimum degere ulasti.\ntokluk seviyesi: %d\tcan seviyesi: %d",tokluk,can);
                                        }
                                        else{
                                            printf("\ntokluk seviyesi: %d\tcan seviyesi: %d",tokluk,can);
                                        }
                                    }
                                    else{
                                        printf("\ntokluk seviyesi: %d\tcan seviyesi: %d",tokluk,can);
                                    }
                                    
                                }
                                
                            default:
                                printf("\nhatali tuslama, lutfen menudeki yiyeceklerden sec.");
                                goto yiyecek;
                                break;
                        }
                        break;
                    icecek:
                    case 2:
                        printf("\n\nBara hosgeldin!Icecegini sec:");
                        printf("\n*Icecek menusu*");
                        printf("\n1.sarap--> *bedel: 4 altın *stres: -15");
                        printf("\n2.bitki cayi--> *bedel: 2 altın *moral +10");
                        scanf("%d",&icecekSecim);
                        switch (icecekSecim) {
                            case 1:
                                if(para<4){
                                    printf("\nhanciyi daha fazla sinirlendirmeden git buradan.");
                                }
                                else{
                                    para=para-4;
                                    printf("\n4 altin karsiligi sarap alindi.\nkalan para: %f",para);
                                    printf("\normanın uzumleri tum gerginligini aldi..stres 15 azaldi.");
                                    stres=stres-15;
                                    if(stres<=0){
                                        stres=0;
                                        printf("\nStres seviyesi minimum deger 0'a ulasti. Can degeri 5 artti.");
                                        can=can+5;
                                        if(can>100){
                                            can=100;
                                            printf("\ncan seviyesi: %d",can);
                                        }
                                        else{
                                            printf("\ncan seviyesi: %d",can);
                                        }
                                        
                                    }
                                    else{
                                        printf("\nstres seviyesi: %d",stres);
                                    }
                                }
                                break;
                            case 2:
                                if(para<2){
                                    printf("\nhanciyi daha fazla sinirlendirmeden git buradan.");
                                }
                                else{
                                    para=para-2;
                                    printf("\n2 altin karsiligi bitki cayi alindi.\nkalan para: %f",para);
                                    printf("\bitki cayi sana mutluluk verdi, moral 10 artti.");
                                    moral+=10;
                                    if(moral>100){
                                        moral=100;
                                        printf("\nMoral max deger 100'e ulasti. Can degeri 5 artti.");
                                        can=can+5;
                                        if(can>100){
                                            can=100;
                                            printf("\ncan seviyesi: %d",can);
                                        }
                                        else{
                                            printf("\ncan seviyesi: %d",can);
                                        }
                                        
                                    }
                                    else{
                                        printf("\nmoral seviyesi: %d",moral);
                                    }
                                }
                                break;
                                
                            default:
                                printf("lutfen menuden bir secim yapiniz..");
                                goto icecek;
                                break;
                        }
                        break;
                    case 3:
                        if(hijyen<20){
                            printf("\nhijyen seviyesi cok dusuk, sarki soylenemiyor.\nAna menuye yonlendiriliyorsunuz.");
                            goto basla;
                        }
                        else{
                            printf("\nbu aaaksaam oluruumm...");
                            para= para+ paraKazan(karizma,hijyen);
                            printf("\naltin miktari: %f",para);
                            tecrube+=20;
                            if(tecrube>=100){
                                printf("\n\ntebrikler,tecrube 100'u asti!");
                                goto basla5;
                            }
                            moral+=10;
                            if(moral<=100){
                                printf("moral seviyesi 10 artti!\nmoral seviyesi: %d",moral);
                            }
                            else{
                                moral=100;
                                printf("moral seviyesi 10 artti!\nmoral seviyesi: %d",moral);
                            }
                            
                        }
                        break;
                    case 4:
                        printf("koy meydanina donuluyor..");
                        secim=anaMenu();
                        break;
                        
                    default:
                        printf("\nhatali secim yapildi..");
                        goto basla3;
                        break;
                }break;
            basla4:
            case 4:
                secim=macerayaAtil();
                switch (secim) {
                    case 1:
                        printf("\nhmm.. orman yesermis");
                        break;
                    case 2:
                        printf("\norman kesfediliyor");
                        para=kolayKesif(para);
                        printf("\naltin miktari: %f",para);
                        tecrube+=30;
                        if(tecrube>=100){
                            printf("\n\ntebrikler,tecrube 100'u asti!");
                            goto basla5;
                        }
                        break;
                    case 3:
                        printf("\nkayaliklar kesfediliyor");
                        para=ortaKesif(para);
                        printf("\naltin miktari: %f",para);
                        tecrube+=60;
                        if(tecrube>=100){
                            printf("\n\ntebrikler,tecrube 100'u asti!");
                            goto basla5;
                        }
                        break;
                    case 4:
                        printf("\nvadi kesfediliyor");
                        printf("\nkayaliklar kesfediliyor");
                        para=zorKesif(para);
                        printf("\naltin miktari: %f",para);
                        tecrube+=90;
                        if(tecrube>=100){
                            printf("\n\ntebrikler,tecrube 100'u asti!");
                            goto basla5;
                        }
                        break;
                    case 5:
                        printf("\nkoy meydanina donuluyor...");
                        secim=anaMenu();
                        break;
                        
                    default:
                        printf("\nhatali secim yaptin.. tekrar dene");
                        goto basla4;
                        break;
                }break;
            basla5:
            case 5:
                printf("\nseviye atlanıyor..");
                printf("\n5 adet gelistirme puani kazandiniz.Artirmak istediginiz becerileri secin:(Her secim sonrasi enter basin)\n1. Guc\n2. Ceviklik\n3. Karizma\n4. Toplayicilik");
                for(int i=0;i<5;i++){
                imlec:
                    scanf("%d",&beceriGelistir);
                    switch (beceriGelistir) {
                        case 1:
                            guc++;
                            break;
                        case 2:
                            ceviklik++;
                            break;
                        case 3:
                            karizma++;
                            break;
                        case 4:
                            toplayicilik++;
                            break;
                            
                        default:
                            printf("hatali secim yaptiniz, tekrar deneyin");
                            goto imlec;
                            break;
                    }
                    
                }
                seviyeAtla(seviye, tecrube);
                break;
            case 6:
                printf("\nOzanin adi: %s",ad);
                printf("Calginin adi: %s",calgi);
                printf("\n\n**Temel Nitelikler**\ncan: %d\ttokluk: %d\tuyku: %d\thijyen: %d\tstres: %d\tmoral: %d\tsans: %d",can,tokluk,uyku,hijyen,stres,moral,sans);
                printf("\n\n**Beceriler**\nguc: %d\tceviklik: %d\tdayaniklilik: %d\tkarizma: %d\ttoplayicilik: %d",guc,ceviklik,dayaniklilik,karizma,toplayicilik);
                printf("\n\nAltin: %f",para);
                break;
            basla7:
            case 7:
                printf("oyundan cıkmak istediginize emin misiniz? cikmak icin 1, iptal etmek icin 0 tuslayın.");
                scanf("%d",&secim);
                if(secim==1){
                    printf("ilerlemeniz kaydediliyor..\n oyundan cikildi\n");
                    goto Son;
                    break;
                }
                else if(secim==0){
                    printf("ana menuye yonlendiriliyorsunuz..\n");
                    goto basla;
                }
                else{
                    printf("\nhatali secim yapildi.. tekrar deneyin\n");
                    goto basla7;
                    
                }
                break;
            default:
                printf("\nhatali secim yapildi. tekrar deneyin!\n");
                goto basla;
                break;
                
        }
    }
    
    Son:
    return 0;
}
int anaMenu(void){
    int a;
    printf("\n\nNe yapmak istersin?\n");
    printf("1. Kamp alanina git\n");
    printf("2. Sifahaneye git\n");
    printf("3. Hana git\n");
    printf("4. Maceraya atil\n");
    printf("5. Seviye atla\n");
    printf("6. Durumu goster\n");
    printf("7. Oyundan cik\n");
    scanf("%d",&a);
    return a;

}
int kampAlani(void){
    int b;
    printf("\n\nKamp alanina geldin.\n");
    printf("1. Kamp atesinin basinda calgi cal/sarki soyle\n");
    printf("2. Nehirde yikan\n");
    printf("3. Cadirda uyu\n");
    printf("4. Koy meydanina don\n");
    scanf("%d",&b);
    return b;

}
int sifahaneGit(void){
    int c;
    printf("\n\nSifahaneye geldiniz..\n");
    printf("1. Sifacidan yaralarini sarmasini iste\n");
    printf("2. sifacidan merhem surmesini iste\n");
    printf("3. Koy meydanina don\n");
    scanf("%d",&c);
    return c;
    
}
int hanaGit(void){
    int d;
    printf("\n\nHana geldiniz..\n");
    printf("1. Yiyecek satin al ve ye\n");
    printf("2. İcecek satin al, ic ve eglen\n");
    printf("3. Enstruman cal ve sarki soyle\n");
    printf("4. Koy meydanina don\n");
    scanf("%d",&d);
    return d;
}
int macerayaAtil(void){
    int e;
    printf("\n\nOrmana geldin. Ne yapmak istersin?\n");
    printf("1. Yakin cevreden sifali bitki topla ve avlan\n");
    printf("2. Ormani kesfe cik (kolay) \n");
    printf("3. Kayaliklari kesfe cik (orta) \n");
    printf("4. Vadiyi kesfe cik (zor) \n");
    printf("5. Koy meydanina don\n");
    scanf("%d",&e);
    return e;
}
float paraKazan(int karizma, int hijyen){
    int kazanilanPara= 10 + (karizma * hijyen/100);
    printf("\n%d altin kazanildi..\nkisa gunun kari.",kazanilanPara);
    return kazanilanPara;
}
int kolayKesif(float para){
    srand(time(NULL));
    int a= rand()%11+15;
    printf("\n%d altin kazanildi, sanslisin.",a);
    para+=a;
    return para;
}
int ortaKesif(float para){
    srand(time(NULL));
    int a= rand()%21+30;
    printf("\n%d altin kazanildi, sanslisin.",a);
    para+=a;
    return para;
}
int zorKesif(float para){
    srand(time(NULL));
    int a= rand()%21+55;
    printf("\n%d altin kazanildi, sanslisin.",a);
    para+=a;
    return para;
}
void seviyeAtla(int seviye, int tecrube){
    seviye++;
    tecrube=0;
    printf("\n\nYeni statlar:\nseviye:%d\ntecrube:%d",seviye,tecrube);
}

