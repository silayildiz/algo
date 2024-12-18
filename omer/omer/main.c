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
int kolayKesif(float para);
int ortaKesif(float para);
int zorKesif(float para);
int sifaliBitkiBulma(void);
int kolayKesifSavas(int ceviklik, int guc, int *can, int dayaniklilik, int stres);
int ortaKesifSavas(int ceviklik, int guc, int *can, int dayaniklilik, int stres);
int zorKesifSavas(int ceviklik, int guc, int *can, int dayaniklilik, int stres);

int main(int argc, const char * argv[]) {
    
    //isim ve calgi
    char ad[10];
    printf("Baslamak icin isminizi girin: ");
    fgets(ad, sizeof(ad),stdin);
    
    char calgi[20];
    printf("\nKullandiginiz enstruman? ");
    fgets(calgi, sizeof(calgi),stdin);
    
    //temel nitelikler
    int can=50; int tokluk=50; int uyku=50; int hijyen=50; float para=10.0; int tecrube=0; int stres=30; int moral=50; int sans=50;
    
    //beceriler
    int guc=3; int ceviklik=3; int dayaniklilik=3; int karizma=3; int toplayicilik=3; int seviye=1;
    
    int secim; int yiyecekSecim;; int icecekSecim; int avcilikIhtimal; float avcilikSans;
    int beceriGelistir;
    
    int kolaySonuc; int ortaSonuc; int zorSonuc;
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
                        printf("\n^^Sesin butun kasabayi buyuledi! +20 moral");
                        if(moral<=100){
                            printf("\n\tmoral seviyesi: %d",moral);
                        }
                        else{
                            moral=100;
                            printf("\n\tmoral seviyesi: %d",moral);
                        }
                        uyku-=10;
                        if(uyku<=0){
                            uyku=0;
                            can=can-5;
                            if(can<=0){
                                can=0;
                                printf("\n^^Uykusuzluk sebebi ile yorgun dustun..canin -5 azaldi.\n\tuyku seviyesi: %d\tcan seviyesi:%d",uyku,can);
                                printf("\n\tcan seviyen 0' dustu.\noyun bitti..");
                                goto Son;
                            }
                            else{
                                printf("\n^^Uykusuzluk sebebi ile yorgun dustun..canin -5 azaldi.\n\tuyku seviyesi: %d\tcan seviyesi:%d",uyku,can);
                            }
                            
                        }
                        else{
                            printf("\n^^Biraz yoruldun. uyku seviyen -5 azaldi.\n\tuyku seviyesi: %d",uyku);
                        }
                        tokluk-=15;
                        if(tokluk<=0){
                            tokluk=0;
                            can=can-10;
                            if(can<=0){
                                can=0;
                                printf("\n^^Cclik nedeniyle bitkin dustun, canin 10 azaldi.\n\ttokluk seviyesi: %d\tcan seviyesi: %d",tokluk,can);
                                printf("\n^^can seviyen 0' dustu.\nOYUN BITTI..");
                                goto Son;
                            }
                            else{
                                printf("\n^^Aclik sebebi ile yorgun dustun..canin -10 azaldi.\n\ttokluk seviyesi: %d\tcan seviyesi:%d",tokluk,can);
                            }
                            
                        }
                        else{
                            printf("\n^^hmm, biraz aciktin. Tokluk 15 azaldi\n\ttokluk seviyesi: %d",tokluk);
                        }
                        break;
                    case 2:
                        printf("\n^^Nehirde yikaniyorsun,su cok soguk!!");
                        hijyen+=40;
                        if(hijyen<100){
                            printf("\n\thijyen: %d",hijyen);
                        }
                        else{
                            hijyen=100;
                            printf("\n}thijyen: %d\n\thijyen duzeyi maksimumda.",hijyen);
                        }
                        can+=15;
                        if(can<100){
                            printf("\n\tcan: %d",can);
                        }
                        else{
                            can=100;
                            printf("\n\tcan: 100\n\tcan duzeyi maksimumda.");
                        }
                        stres-=10;
                        if(stres>=0){
                            printf("\n^^Dus iyi geldi.\n\tstres -10: %d",stres);
                        }
                        else{
                            stres=0;
                            printf("\n^^Dus iyi geldi.\n\tstres -10: %d",stres);
                        }
                        
                        break;
                    case 3:
                        printf("\n\nzZz..");
                        uyku+=70;
                        if(uyku<=100){
                            printf("\n\n^^Guzel bir uyku cektin, iyice dinlendin.");
                            printf("\n\tuyku seviyesi +70: %d",uyku);
                        }
                        else{
                            uyku=100;
                            printf("\n\n^^Guzel bir uyku cektin, iyice dinlendin.");
                            printf("\n\tuyku seviyesi +70: %d",uyku);
                        }
                        can+=70;
                        if(can<100){
                            printf("\n^^Uyumak iyi geldi.");
                            printf("\n\tcan +70: %d",can);
                        }
                        else{
                            can=100;
                            printf("\n^^Deliksiz uyku cektin.");
                            printf("\n\tcan: 100\ncan duzeyi maksimumda.");
                        }
                        tokluk-=35;
                        printf("\n\n^^Uyurken biraz aciktin...");
                        if(tokluk<=0){
                            tokluk=0;
                            can=can-10;
                            if(can<=0){
                                can=0;
                                printf("\n^^Uyurken acliktan hastalandin. 10 can puanina mal oldu.\n\tcan 0'a dustu.\nOYUN BITTI.\n\ttokluk seviyesi: %d\tcan seviyesi: %d",tokluk,can);
                                goto Son;
                            }
                            else{
                                printf("\n^^Uyurken acliktan hastalandin. 10 can puanina mal oldu.\n\ttokluk seviyesi: %d\tcan seviyesi: %d",tokluk,can);
                            }
                            
                        }
                        else{
                            printf("\n^^hmm, biraz aciktin. Tokluk 35 azaldi\n\ttokluk seviyesi: %d",tokluk);
                            printf("\n^^Bir seyler yesen iyi olacak.");
                        }
                        hijyen-=20;
                        printf("\n^^Uyurken biraz terledin...");
                        if(hijyen>=0){
                            printf("\n^^Dus alsan iyi olacak.\n\thijyen: %d",hijyen);
                        }
                        else{
                            hijyen=0;
                            can=can-5;
                            if(can<=0){
                                can=0;
                                printf("\n^^Hijyen eksikligi sebebiyle canin -5 puan azaldi, can degeri 0'a ulasti. Oyun sonlandiriliyor.\n\thijyen seviyesi: %d\tcan seviyesi: %d",hijyen,can);
                                goto Son;
                            }
                            else{
                                printf("\n^^Hijyen eksikligi sebebiyle canin -5 puan azaldi,\n\thijyen seviyesi: %d\tcan seviyesi: %d",hijyen,can);
                            }
                        }
                        break;
                    case 4:
                        printf("\n^^Koy meydanina donuluyor.");
                        break;
                    default:
                        printf("\n!Hatali secim yapildi..");
                        goto basla1;
                        break;
                }break;
            basla2:
            case 2:
                secim=sifahaneGit();
                switch (secim) {
                    case 1:
                        printf("\n^^Yara sardirmak icin 5 altin gerekiyor. Yeteri kadar sansliysan sifaci yaralarini bedelsiz saracak.");
                        //şans seviyesi 90 ve uzerindeyse bedelsiz sargı yapılır.
                        if(sans<90){
                            if(para<5){
                                printf("\n^^Sifaci seni evinden kovdu! biraz yagma yaptiktan sonra tekrar gel.");
                            }
                            else{
                                printf("\n^^5 altin karsiligi yaralarin sarildi.\n+40 can geldi.");
                                para-=5;
                                printf("\n\tkalan altinlar: %.2f",para);
                                can+=40;
                                if(can>100){
                                    can=100;
                                    printf("\n\tcan seviyesi +40: %d",can);
                                }
                                else{
                                    printf("\n\tcan seviyesi +40: %d",can);
                                }
                            }
                        }
                        else{
                            sans=sans-50;
                            can+=40;
                            printf("\n^^50 sans puani karsiliginda yaralarin sarildi.\n+40 can geldi.");
                            if(can>100){
                                can=100;
                                printf("\n\tcan seviyesi: %d",can);
                                printf("\n\tsans: %d",sans);
                            }
                            else{
                                printf("\n\tcan seviyesi: %d",can);
                                printf("\n\tsans: %d",sans);
                            }
                        }
                        
                        break;
                    case 2:
                        printf("\n^^Sifaci 3 altin karsiliginda sana merhem hazirlayacak.");
                        if(para<3){
                            stres+=15;
                            if(stres>=100){
                                stres=100;
                                printf("\n^^Maalesef kremi karsilayamadin. Stres seviyen 15 artti.\n\tstres seviyesi: %d",stres);
                                can=can-5;
                                if(can<=0){
                                    printf("\n^^Can seviyen 5 azaldi, can 0'a ulasti.\nOyundan cikiliyor.");
                                    goto Son;
                                }
                                else{
                                    printf("\n^^Can seviyen 5 azaldi.\n\tcan seviyesi: %d",can);
                                }
                            }
                            else{
                                printf("\n^^Kremi karsilayamadin,stresin artti\n\tstres seviyesi: %d",stres);
                            }
                        }
                        else{
                            para=para-3;
                            can=can+30;
                            if(can>=100){
                                can=100;
                                printf("\n^^3 altin karsiligi +30 can kazandin, maksimum cana ulasildi.\n\tpara: %.2f\tcan seviyesi: %d",para,can);
                            }
                            else{
                                printf("\n^^3 altin karsiligi +30 can kazandin.\n\tpara: %.2f\tcan seviyesi: %d",para,can);
                            }
                        }
                        break;
                    case 3:
                        printf("\n^^Koy meydanina donuluyor.");
                        break;
                        
                    default:
                        printf("\n!Hatali secim yapildi.");
                        goto basla2;
                        break;
                }break;
            basla3:
            case 3:
                secim=hanaGit();
                switch (secim) {
                    yiyecek:
                    case 1:
                        printf("\n\nYiyecek pazarina hosgeldin!\nAlmak istedigin yiyecegin numarasini tusla.");
                        printf("\n1.sihirli orman meyveleri-> *bedel: 1 altin  *tokluk: +15");
                        printf("\n2.Ekmek-> *bedel: 2 altin  *tokluk: +30 ");
                        printf("\n3.Et-> *bedel: 4 altin  *tokluk: +60");
                        scanf("%d",&yiyecekSecim);
                        switch (yiyecekSecim) {
                            case 1:
                                if(para<1){
                                    printf("\n\n^^Paran yetersiz. Biraz sarki soylemeye ne dersin?");
                                }
                                else{
                                    printf("\nmm meyveler lezzetliymis...");
                                    para=para-1;
                                    printf("\n1 altin karsiligi meyveleri yedin.\n\tkalan para: %.2f",para);
                                    tokluk+=15;
                                    if(tokluk>100){
                                        tokluk=100;
                                        printf("\n^^Tokluk 15 puan artti, maksimum tokluk seviyesine ulasildigi icin can 20 puan artti.");
                                        can+=20;
                                        if(can>100){
                                            can=100;
                                            printf("\n^^Can maksimum degere ulasti.\n\ttokluk seviyesi: %d\tcan seviyesi: %d",tokluk,can);
                                        }
                                        else{
                                            printf("\n\ttokluk seviyesi: %d\tcan seviyesi: %d",tokluk,can);
                                        }
                                    }
                                    else{
                                        printf("\n\ttokluk seviyesi: %d\tcan seviyesi: %d",tokluk,can);
                                    }
                                    
                                }
                                break;
                            case 2:
                                if(para<2){
                                    printf("\n\n^^Paran yetersiz.biraz sarki soylemeye ne dersin?");
                                }
                                else{
                                    para=para-2;
                                    printf("\n^^2 altin karsiligi ekmek yedin.\n\tkalan para: %.2f",para);
                                    printf("\n^^Ekmek biraz bayat olsa da acligini giderdi.");
                                    tokluk+=30;
                                    if(tokluk>100){
                                        tokluk=100;
                                        printf("\n^^Tokluk 30 puan artti, maksimum tokluk seviyesine ulasildigi icin can 20 puan artti.");
                                        can+=20;
                                        if(can>100){
                                            can=100;
                                            printf("\n^^Can maksimum degere ulasti.\n\ttokluk seviyesi: %d\tcan seviyesi: %d",tokluk,can);
                                        }
                                        else{
                                            printf("\n\ttokluk seviyesi: %d\tcan seviyesi: %d",tokluk,can);
                                        }
                                    }
                                    else{
                                        printf("\n\ttokluk seviyesi: %d\tcan seviyesi: %d",tokluk,can);
                                    }
                                    
                                }
                                break;
                            case 3:
                                if(para<4){
                                    printf("\n\n^^Paran yetersiz.biraz sarki soylemeye ne dersin?");
                                }
                                else{
                                    para=para-4;
                                    printf("\n^^4 altin karsiligi et yedin.\n\tkalan para: %.2f",para);
                                    tokluk+=60;
                                    if(tokluk>100){
                                        tokluk=100;
                                        printf("\n^^Tokluk 60 puan artti, maksimum tokluk seviyesine ulasildigi icin can 20 puan artti.");
                                        can+=20;
                                        if(can>100){
                                            can=100;
                                            printf("\n^^Can maksimum degere ulasti.\n\ttokluk seviyesi: %d\tcan seviyesi: %d",tokluk,can);
                                        }
                                        else{
                                            printf("\n\ttokluk seviyesi: %d\tcan seviyesi: %d",tokluk,can);
                                        }
                                    }
                                    else{
                                        printf("\n\ttokluk seviyesi: %d\tcan seviyesi: %d",tokluk,can);
                                    }
                                    
                                }
                                
                            default:
                                printf("\n!Hatali tuslama, lutfen menudeki yiyeceklerden sec.");
                                goto yiyecek;
                                break;
                        }
                        break;
                    icecek:
                    case 2:
                        printf("\n\nBara hosgeldin!Icecegini sec:");
                        printf("\n*Icecek menusu*");
                        printf("\n1.sarap--> *bedel: 4 altin *stres: -15");
                        printf("\n2.bitki cayi--> *bedel: 2 altin *moral +10");
                        scanf("\n%d",&icecekSecim);
                        switch (icecekSecim) {
                            case 1:
                                if(para<4){
                                    printf("\n!!Hanciyi daha fazla sinirlendirmeden git buradan.");
                                }
                                else{
                                    para=para-4;
                                    printf("\n^^4 altin karsiligi sarap alindi.\n\tkalan para: %.2f",para);
                                    printf("\n^^Ormanin uzumleri tum gerginligini aldi..stres 15 azaldi.");
                                    stres=stres-15;
                                    if(stres<=0){
                                        stres=0;
                                        printf("\n^^Stres seviyesi minimum deger 0'a ulasti. Can degeri 5 artti.");
                                        can=can+5;
                                        if(can>100){
                                            can=100;
                                            printf("\n\tcan seviyesi: %d",can);
                                        }
                                        else{
                                            printf("\n\tcan seviyesi: %d",can);
                                        }
                                        
                                    }
                                    else{
                                        printf("\n\tstres seviyesi: %d",stres);
                                    }
                                }
                                break;
                            case 2:
                                if(para<2){
                                    printf("\n!!Hanciyi daha fazla sinirlendirmeden git buradan.");
                                }
                                else{
                                    para=para-2;
                                    printf("\n^^2 altin karsiligi bitki cayi alindi.\n\tkalan para: %.2f",para);
                                    printf("\n^^Bitki cayi sana mutluluk verdi, moral 10 artti.");
                                    moral+=10;
                                    if(moral>100){
                                        moral=100;
                                        printf("\n^^Moral max deger 100'e ulasti. Can degeri 5 artti.");
                                        can=can+5;
                                        if(can>100){
                                            can=100;
                                            printf("\n\tcan seviyesi: %d",can);
                                        }
                                        else{
                                            printf("\n\tcan seviyesi: %d",can);
                                        }
                                        
                                    }
                                    else{
                                        printf("\n\tmoral seviyesi: %d",moral);
                                    }
                                }
                                break;
                                
                            default:
                                printf("!!Lutfen menuden bir secim yapiniz..");
                                goto icecek;
                                break;
                        }
                        break;
                    case 3:
                        if(hijyen<20){
                            printf("\n^^Jijyen seviyesi cok dusuk, sarki soylenemiyor.\nAna menuye yonlendiriliyorsunuz.");
                            goto basla;
                        }
                        else{
                            printf("\n...bu aaaksaam oluruumm...");
                            para= para+ paraKazan(karizma,hijyen);
                            printf("\n\taltin miktari: %.2f",para);
                            tecrube+=20;
                            if(tecrube>=100){
                                printf("\n\n^^Tebrikler,tecrube 100'u asti!");
                                goto basla5;
                            }
                            moral+=10;
                            if(moral<=100){
                                printf("\nMoral seviyesi 10 artti!\n\tmoral seviyesi: %d",moral);
                            }
                            else{
                                moral=100;
                                printf("\nMoral seviyesi 10 artti!\n\tmoral seviyesi: %d",moral);
                            }
                            
                        }
                        break;
                    case 4:
                        printf("^^Koy meydanina donuluyor..");
                        break;
                        
                    default:
                        printf("\n!!Hatali secim yapildi..");
                        goto basla3;
                        break;
                }break;
            basla4:
            case 4:
                secim=macerayaAtil();
                switch (secim) {
                    case 1:
                        avcilikSans=((float)toplayicilik*4)/100;
                        printf("\nhmm.. orman yesermis, biraz yiyecek bakiniyorsun.\n%.2f ihtimalle sifali bitki bulabilir, %.2f ihtimalle av hayvani avlayabilirsin.",avcilikSans,avcilikSans/2);
                        avcilikIhtimal=sifaliBitkiBulma();
                        if(avcilikIhtimal<=(avcilikSans*100)){
                            printf("etrafta dolanirken sifali bitkilere rastladin.. +10 tokluk kazanildi");
                            sans+=10;
                            printf("buldugun bitkiler sans niteligini 10 artirdi! artik sifaci ile aralari duzeltebilirsin!");
                            if(sans>100){
                                sans=100;
                                printf("\nsans seviyesi: %d",sans);
                            }
                            else{
                                printf("\nsans seviyesi: %d",sans);
                            }
                            tokluk+=10;
                            if(tokluk>=100){
                                tokluk=100;
                                printf("\ntokluk maksimum seviyeye ulasti! Odul: +20 can");
                                can+=20;
                                if(can>=100){
                                    can=100;
                                    printf("\ncan seviyesi: %d\ttokluk: %d",can,tokluk);
                                }
                                else{
                                    printf("\ncan seviyesi: %d\ttokluk: %d",can,tokluk);
                                }
                            }
                            else{
                                printf("\n+10 tokluk kazandin. Son durum:\ncan seviyesi: %d\ttokluk: %d",can,tokluk);
                            }
                        }
                        else if((avcilikSans * 100) < avcilikIhtimal && avcilikIhtimal < ((avcilikSans * 100) + ((avcilikSans * 100) / 2))){
                            printf("\nSansli gunundesin %s!Bu sansini kullanarak ormanda gezerken karsina cikan yabaniyi avladin! Odul: 50 tokluk! Kaybedilen: -10 sans.",ad);
                            tokluk+=50;
                            if(tokluk>=100){
                                tokluk=100;
                                printf("\ntokluk maksimum seviyeye ulasti! Odul: +20 can");
                                can+=20;
                                if(can>=100){
                                    can=100;
                                    printf("\ncan seviyesi: %d\ttokluk: %d",can,tokluk);
                                }
                                else{
                                    printf("\ncan seviyesi: %d\ttokluk: %d",can,tokluk);
                                }
                            }
                            else{
                                printf("\n+10 tokluk kazandin. Son durum:\ncan seviyesi: %d\ttokluk: %d",can,tokluk);
                            }
                            sans=sans-10;
                            if(sans<=0){
                                printf("\nhay aksi! sans niteligin cok dustu. Kayiplar: -5 can");
                                can=can-5;
                                if(can<=0){
                                    can=0;
                                    printf("\ncan degeri 0'a dustu, oyun bitti.");
                                    printf("\ncan seviyesi: %d",can);
                                    goto Son;
                                }
                                else{
                                    printf("c\nan seviyesi: %d",can);
                                }
                            }
                            else{
                                printf("\nsans seviyesi: %d",sans);
                            }
                        }
                        else{
                            printf("\nSans senden yana gitmedi, baska bir gun tekrar dene.");
                            printf("\nBedel: -20 uyku");
                            uyku=uyku-20;
                            if(uyku<=0){
                                uyku=0;
                                can=can-5;
                                if(can<=0){
                                    can=0;
                                    printf("\ncok uykusuz kaldin, uyku seviyesi 0'a dustu. Kayiplar: -5 can");
                                    printf("\ncan seviyesi minimum degere ulasti, oyun bitti!");
                                    printf("\nuyku seviyesi: %d\tcan seviyesi: %d",uyku,can);
                                    goto Son;
                                }
                                else{
                                    printf("\ncok uykusuz kaldin, uyku seviyesi 0'a dustu. Kayiplar: -5 can");
                                    printf("\nuyku seviyesi: %d\tcan seviyesi: %d",uyku,can);
                                }
                            }
                            else{
                                printf("\nbiraz yoruldun...\nuyku seviyesi: %d",uyku);
                            }
                        }
                        
                        break;
                    case 2:
                        printf("\norman kesfediliyor\nHaydutla karsilastin!");
                        kolaySonuc=kolayKesifSavas(ceviklik, guc, &can, dayaniklilik, stres);
                        if(kolaySonuc==1){
                            para=kolayKesif(para);
                            printf("\naltin miktari: %.2f",para);
                            tecrube+=30;
                            if(tecrube>=100){
                                printf("\n\ntebrikler,tecrube 100'u asti!");
                                goto basla5;
                            }
                        }
                        else if(kolaySonuc==-1){
                            printf("\ngalip gelemedin, hicbir kazanim elde etmedin.");
                        }
                        else{
                            printf("\nbir seyler ters gitti...\nAna menuye yonlendiriliyorsun.");
                            goto basla;
                        }
                        break;
                    case 3:
                        ortaSonuc= ortaKesifSavas(ceviklik, guc, &can, dayaniklilik, stres);
                        if(ortaSonuc==1){
                            para=ortaKesif(para);
                            printf("\naltin miktari: %.2f",para);
                            tecrube+=60;
                            if(tecrube>=100){
                                printf("\n\ntebrikler,tecrube 100'u asti!");
                                goto basla5;
                            }
                        }
                        else if(ortaSonuc==-1){
                            printf("\ngalip gelemedin, hicbir kazanim elde etmedin.");
                        }
                        else{
                            printf("\nbir seyler ters gitti...\nAna menuye yonlendiriliyorsun.");
                            goto basla;
                        }
                        break;
                    case 4:
                        zorSonuc= zorKesifSavas(ceviklik, guc, &can, dayaniklilik, stres);
                        if(zorSonuc==1){
                            para=zorKesif(para);
                            printf("\naltin miktari: %.2f",para);
                            tecrube+=60;
                            if(tecrube>=100){
                                printf("\n\ntebrikler,tecrube 100'u asti!");
                                goto basla5;
                            }
                        }
                        else if(zorSonuc==-1){
                            printf("\ngalip gelemedin, hicbir kazanim elde etmedin.");
                            printf("\ncan minimum deger 0'a dustu, oyun sona erdi.");
                            goto Son;
                        }
                        else{
                            printf("\nbir seyler ters gitti...\nAna menuye yonlendiriliyorsun.");
                            goto basla;
                        }
                        break;
                    case 5:
                        printf("\nkoy meydanina donuluyor...");
                        break;
                        
                    default:
                        printf("\nhatali secim yaptin.. tekrar dene");
                        goto basla4;
                        break;
                }break;
            basla5:
            case 5:
                if(tecrube>=100){
                    printf("\n^^Seviye atlaniyor..");
                    seviye++;
                    tecrube=0;
                    printf("\n^^yeni seviye: %d",seviye);
                    printf("\n^^tecrube: %d",tecrube);
                    printf("\n\n**Mevcut Beceriler**\nguc: %d\tceviklik: %d\tdayaniklilik: %d\tkarizma: %d\ttoplayicilik: %d",guc,ceviklik,dayaniklilik,karizma,toplayicilik);
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
                                printf("\nhatali secim yaptiniz, tekrar deneyin");
                                goto imlec;
                                break;
                        }
                    }
                    printf("\n\n^^Beceri puanlarinin tamami kullanildi.");
                    printf("\n\n**Beceriler**\nguc: %d\tceviklik: %d\tdayaniklilik: %d\tkarizma: %d\ttoplayicilik: %d",guc,ceviklik,dayaniklilik,karizma,toplayicilik);
                }
                else{
                    printf("\nTecrube atlama gereksinimlerini karsilamiyorsunuz, ana menuye yonlendiriliyorsunuz.");
                }
                    break;
                case 6:
                    printf("\nOzanin adi: %s",ad);
                    printf("Calginin adi: %s",calgi);
                    printf("\nseviye: %d",seviye);
                    printf("\n\n**Temel Nitelikler**\ncan: %d\ttokluk: %d\tuyku: %d\thijyen: %d\tstres: %d\tmoral: %d\tsans: %d",can,tokluk,uyku,hijyen,stres,moral,sans);
                    printf("\n\n**Beceriler**\nguc: %d\tceviklik: %d\tdayaniklilik: %d\tkarizma: %d\ttoplayicilik: %d",guc,ceviklik,dayaniklilik,karizma,toplayicilik);
                    printf("\n\nAltin: %.2f",para);
                    break;
                basla7:
                case 7:
                    printf("oyundan cikmak istediginize emin misiniz? cikmak icin 1, iptal etmek icin 0 tuslayin.");
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
    printf("2. Icecek satin al, ic ve eglen\n");
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

int sifaliBitkiBulma(void){
    int random= rand()%99+1;
    return random;
}
int kolayKesifSavas(int ceviklik, int guc, int *can, int dayaniklilik, int stres){
    srand(time(NULL));
    int haydutGuc=rand()%2+1;
    int haydutDayaniklilik=rand()%2+1;
    int haydutCeviklik=rand()%2+1;
    int haydutCan=5;
    int secim;
    
    savasiBaslat:
    
    printf("\n**Dusman becerileri**");
    printf("\nguc: %d\tdayaniklilik: %d\tceviklik: %d",haydutGuc,haydutDayaniklilik,haydutCeviklik);
    printf("\nSaldirmak icin 1, kacmak icin 2 secin: ");
    scanf("%d",&secim);
    float kacmaIhtimali=(4*ceviklik)/100;
    int kacmaDurumu=rand()%99+1;
    switch (secim) {
        case 1:
            if(stres<50){
                printf("\nsavas basliyor...");
                if(guc>=haydutGuc){
                    do {
                        printf("\ndusmana %d hasar verildi!",4*guc);
                        printf("\ndusmanin cani %.2f azaldi.",(float)4*guc-((4*guc*(haydutDayaniklilik/100))-1));
                        haydutCan-=4*guc-((4*guc*(haydutDayaniklilik/100))-1);
                        printf("\ndusmanin kalan cani: %d",haydutCan);
                        if(haydutCan<=0){
                            break;
                        }
                        printf("\nhaydut sana saldirdi!");
                        printf("\nalinan hasar: %.2f",(float)4*haydutGuc-((4*haydutGuc*(dayaniklilik/100))-1));
                        *can-=4*haydutGuc-((4*haydutGuc*(dayaniklilik/100))-1);
                        printf("\nkalan can: %d",*can);
                        if(*can<=0){
                            break;
                        }
                        
                    } while (*can>0 && haydutCan>0);
                    if(*can<=0){
                        *can=0;
                        printf("\nhayduta yenik dustun...\ncan seviyesi: %d",*can);
                        stres+=30;
                        if(stres>=100){
                            stres=100;
                            printf("\nsavasta cok gerildin, stresin 30 artti.\nstres seviyesi: %d",stres);
                            printf("stres seviyen cok yuksek! bir sonraki maceraya atilmadan once biraz gevse.");
                        }
                        else{
                            printf("\nsavasta cok gerildin, stresin 30 artti.\nstres seviyesi: %d",stres);
                        }
                        return -1;
                        break;
                    }
                    else if(haydutCan<=0){
                        printf("\nTebrikler! Haydutu yendin");
                        return 1;
                        break;
                    }
                    
                }
                else{
                    do {
                        printf("\nhaydut sana saldirdi!");
                        printf("\nalinan hasar: %.2f",(float)4*haydutGuc-((4*haydutGuc*(dayaniklilik/100))-1));
                        *can-=4*haydutGuc-((4*haydutGuc*(dayaniklilik/100))-1);
                        printf("\nkalan can: %d",*can);
                        if(*can<=0){
                            break;
                        }
                        printf("\ndusmana %d hasar verildi!",4*guc);
                        printf("\ndusmanin cani %.2f azaldi.",(float)4*guc-((4*guc*(haydutDayaniklilik/100))-1));
                        haydutCan-=4*guc-((4*guc*(haydutDayaniklilik/100))-1);
                        printf("\ndusmanin kalan cani: %d",haydutCan);
                        if(haydutCan<=0){
                            break;
                        }
                        
                    } while (*can>0 && haydutCan>0);
                    if(*can<=0){
                        *can=0;
                        printf("\nhayduta yenik dustun...\ncan seviyesi: %d",*can);
                        stres+=30;
                        if(stres>=100){
                            stres=100;
                            printf("\nsavasta cok gerildin, stresin 30 artti.\nstres seviyesi: %d",stres);
                            printf("stres seviyen cok yuksek! bir sonraki maceraya atilmadan once biraz gevse.");
                        }
                        else{
                            printf("\nsavasta cok gerildin, stresin 30 artti.\nstres seviyesi: %d",stres);
                        }
                        return -1;
                        break;
                    }
                    else if(haydutCan<=0){
                        printf("\nTebrikler! Haydutu yendin");
                        return 1;
                        break;
                    }
                    
                }
            }
            else{
                printf("\nstres seviyen cok fazla!");
                printf("\nstres seviyesi: %d",stres);
                printf("savasa girilemiyor.");
                return -1;
            }
            break;
        case 2:
            if(stres<50){
                if(kacmaDurumu<kacmaIhtimali*100){
                    printf("\nhayduttan basariyla kacildi.");
                    return 1;
                    break;
                }
                else{
                    printf("\nhayduttan kacamadin!Savas basliyor..");
                    if(guc>=haydutGuc){
                        do {
                            printf("\ndusmana %d hasar verildi!",4*guc);
                            printf("\ndusmanin cani %.2f azaldi.",(float)4*guc-((4*guc*(haydutDayaniklilik/100))-1));
                            haydutCan-=4*guc-((4*guc*(haydutDayaniklilik/100))-1);
                            printf("\ndusmanin kalan cani: %d",haydutCan);
                            if(haydutCan<=0){
                                break;
                            }
                            printf("\nhaydut sana saldirdi!");
                            printf("\nalinan hasar: %.2f",(float)4*haydutGuc-((4*haydutGuc*(dayaniklilik/100))-1));
                            *can-=4*haydutGuc-((4*haydutGuc*(dayaniklilik/100))-1);
                            printf("\nkalan can: %d",*can);
                            if(*can<=0){
                                break;
                            }
                        
                        } while (*can>0 && haydutCan>0);
                        if(*can<=0){
                            *can=0;
                            printf("\nhayduta yenik dustun...\ncan seviyesi: %d",*can);
                            stres+=30;
                            if(stres>=100){
                                stres=100;
                                printf("\nsavasta cok gerildin, stresin 30 artti.\nstres seviyesi: %d",stres);
                                printf("stres seviyen cok yuksek! bir sonraki maceraya atilmadan once biraz gevse.");
                            }
                            else{
                                printf("\nsavasta cok gerildin, stresin 30 artti.\nstres seviyesi: %d",stres);
                            }
                            return -1;
                            break;
                        }
                        else if(haydutCan<=0){
                            printf("\nTebrikler! Haydutu yendin");
                            return 1;
                            break;
                        }
                        
                    }
                    else{
                        do {
                            printf("\nhaydut sana saldirdi!");
                            printf("\nalinan hasar: %.2f",(float)4*haydutGuc-((4*haydutGuc*(dayaniklilik/100))-1));
                            *can-=4*haydutGuc-((4*haydutGuc*(dayaniklilik/100))-1);
                            printf("\nkalan can: %d",*can);
                            if(*can<=0){
                                break;
                            }
                            printf("\ndusmana %d hasar verildi!",4*guc);
                            printf("\ndusmanin cani %.2f azaldi.",(float)4*guc-((4*guc*(haydutDayaniklilik/100))-1));
                            haydutCan-=4*guc-((4*guc*(haydutDayaniklilik/100))-1);
                            printf("\ndusmanin kalan cani: %d",haydutCan);
                            if(haydutCan<=0){
                                break;
                            }
                            
                        } while (*can>0 && haydutCan>0);
                        if(*can<=0){
                            *can=0;
                            printf("\nhayduta yenik dustun...\ncan seviyesi: %d",*can);
                            stres+=30;
                            if(stres>=100){
                                stres=100;
                                printf("\nsavasta cok gerildin, stresin 30 artti.\nstres seviyesi: %d",stres);
                                printf("stres seviyen cok yuksek! bir sonraki maceraya atilmadan once biraz gevse.");
                            }
                            else{
                                printf("\nsavasta cok gerildin, stresin 30 artti.\nstres seviyesi: %d",stres);
                            }
                            return -1;
                            break;
                        }
                        else if(haydutCan<=0){
                            printf("\nTebrikler! Haydutu yendin");
                            return 1;
                            break;
                        }
                        
                    }
                }
            }
            else{
                printf("\nstres seviyen cok fazla!");
                printf("\nstres seviyesi: %d",stres);
                printf("\nsavasa girilemiyor.");
                return -1;
            }
                break;
        default:
            printf("hatali secim yapildi.");
            return 0;
            break;
    }
    return 0;
}





int ortaKesifSavas(int ceviklik, int guc, int *can, int dayaniklilik, int stres){
    srand(time(NULL));
    int haydutGuc=rand()%3+4;
    int haydutDayaniklilik=rand()%3+4;
    int haydutCeviklik=rand()%3+4;
    int haydutCan=15;
    int secim;
    
    savasiBaslat:
    
    printf("\n**Dusman becerileri**");
    printf("\nguc: %d\tdayaniklilik: %d\tceviklik: %d",haydutGuc,haydutDayaniklilik,haydutCeviklik);
    printf("\nSaldirmak icin 1, kacmak icin 2 secin: ");
    scanf("%d",&secim);
    float kacmaIhtimali=(4*ceviklik)/100;
    int kacmaDurumu=rand()%99+1;
    switch (secim) {
        case 1:
            if(stres<50){
                printf("\nsavas basliyor...");
                if(guc>=haydutGuc){
                    do {
                        printf("\ndusmana %d hasar verildi!",4*guc);
                        printf("\ndusmanin cani %.2f azaldi.",(float)4*guc-((4*guc*(haydutDayaniklilik/100))-1));
                        haydutCan-=4*guc-((4*guc*(haydutDayaniklilik/100))-1);
                        printf("\ndusmanin kalan cani: %d",haydutCan);
                        if(haydutCan<=0){
                            break;
                        }
                        printf("\nhaydut sana saldirdi!");
                        printf("\nalinan hasar: %.2f",(float)4*haydutGuc-((4*haydutGuc*(dayaniklilik/100))-1));
                        *can-=4*haydutGuc-((4*haydutGuc*(dayaniklilik/100))-1);
                        printf("\nkalan can: %d",*can);
                        if(*can<=0){
                            break;
                        }
                        
                    } while (*can>0 && haydutCan>0);
                    if(*can<=0){
                        *can=0;
                        printf("\nhayduta yenik dustun...\ncan seviyesi: %d",*can);
                        stres+=30;
                        if(stres>=100){
                            stres=100;
                            printf("\nsavasta cok gerildin, stresin 30 artti.\nstres seviyesi: %d",stres);
                            printf("stres seviyen cok yuksek! bir sonraki maceraya atilmadan once biraz gevse.");
                        }
                        else{
                            printf("\nsavasta cok gerildin, stresin 30 artti.\nstres seviyesi: %d",stres);
                        }
                        return -1;
                        break;
                    }
                    else if(haydutCan<=0){
                        printf("\nTebrikler! Haydutu yendin");
                        return 1;
                        break;
                    }
                    
                }
                else{
                    do {
                        printf("\nhaydut sana saldirdi!");
                        printf("\nalinan hasar: %.2f",(float)4*haydutGuc-((4*haydutGuc*(dayaniklilik/100))-1));
                        *can-=4*haydutGuc-((4*haydutGuc*(dayaniklilik/100))-1);
                        printf("\nkalan can: %d",*can);
                        if(*can<=0){
                            break;
                        }
                        printf("\ndusmana %d hasar verildi!",4*guc);
                        printf("\ndusmanin cani %.2f azaldi.",(float)4*guc-((4*guc*(haydutDayaniklilik/100))-1));
                        haydutCan-=4*guc-((4*guc*(haydutDayaniklilik/100))-1);
                        printf("\ndusmanin kalan cani: %d",haydutCan);
                        if(haydutCan<=0){
                            break;
                        }
                        
                    } while (*can>0 && haydutCan>0);
                    if(*can<=0){
                        *can=0;
                        printf("\nhayduta yenik dustun...\ncan seviyesi: %d",*can);
                        stres+=30;
                        if(stres>=100){
                            stres=100;
                            printf("\nsavasta cok gerildin, stresin 30 artti.\nstres seviyesi: %d",stres);
                            printf("stres seviyen cok yuksek! bir sonraki maceraya atilmadan once biraz gevse.");
                        }
                        else{
                            printf("\nsavasta cok gerildin, stresin 30 artti.\nstres seviyesi: %d",stres);
                        }
                        return -1;
                        break;
                    }
                    else if(haydutCan<=0){
                        printf("\nTebrikler! Haydutu yendin");
                        return 1;
                        break;
                    }
                    
                }
            }
            else{
                printf("\nstres seviyen cok fazla!");
                printf("\nstres seviyesi: %d",stres);
                printf("savasa girilemiyor.");
                return -1;
            }
            break;
        case 2:
            if(stres<50){
                if(kacmaDurumu<kacmaIhtimali*100){
                    printf("\nhayduttan basariyla kacildi.");
                    return 1;
                    break;
                }
                else{
                    printf("\nhayduttan kacamadin!Savas basliyor..");
                    if(guc>=haydutGuc){
                        do {
                            printf("\ndusmana %d hasar verildi!",4*guc);
                            printf("\ndusmanin cani %.2f azaldi.",(float)4*guc-((4*guc*(haydutDayaniklilik/100))-1));
                            haydutCan-=4*guc-((4*guc*(haydutDayaniklilik/100))-1);
                            printf("\ndusmanin kalan cani: %d",haydutCan);
                            if(haydutCan<=0){
                                break;
                            }
                            printf("\nhaydut sana saldirdi!");
                            printf("\nalinan hasar: %.2f",(float)4*haydutGuc-((4*haydutGuc*(dayaniklilik/100))-1));
                            *can-=4*haydutGuc-((4*haydutGuc*(dayaniklilik/100))-1);
                            printf("\nkalan can: %d",*can);
                            if(*can<=0){
                                break;
                            }
                        
                        } while (*can>0 && haydutCan>0);
                        if(*can<=0){
                            *can=0;
                            printf("\nhayduta yenik dustun...\ncan seviyesi: %d",*can);
                            stres+=30;
                            if(stres>=100){
                                stres=100;
                                printf("\nsavasta cok gerildin, stresin 30 artti.\nstres seviyesi: %d",stres);
                                printf("stres seviyen cok yuksek! bir sonraki maceraya atilmadan once biraz gevse.");
                            }
                            else{
                                printf("\nsavasta cok gerildin, stresin 30 artti.\nstres seviyesi: %d",stres);
                            }
                            return -1;
                            break;
                        }
                        else if(haydutCan<=0){
                            printf("\nTebrikler! Haydutu yendin");
                            return 1;
                            break;
                        }
                        
                    }
                    else{
                        do {
                            printf("\nhaydut sana saldirdi!");
                            printf("\nalinan hasar: %.2f",(float)4*haydutGuc-((4*haydutGuc*(dayaniklilik/100))-1));
                            *can-=4*haydutGuc-((4*haydutGuc*(dayaniklilik/100))-1);
                            printf("\nkalan can: %d",*can);
                            if(*can<=0){
                                break;
                            }
                            printf("\ndusmana %d hasar verildi!",4*guc);
                            printf("\ndusmanin cani %.2f azaldi.",(float)4*guc-((4*guc*(haydutDayaniklilik/100))-1));
                            haydutCan-=4*guc-((4*guc*(haydutDayaniklilik/100))-1);
                            printf("\ndusmanin kalan cani: %d",haydutCan);
                            if(haydutCan<=0){
                                break;
                            }
                            
                        } while (*can>0 && haydutCan>0);
                        if(*can<=0){
                            *can=0;
                            printf("\nhayduta yenik dustun...\ncan seviyesi: %d",*can);
                            stres+=30;
                            if(stres>=100){
                                stres=100;
                                printf("\nsavasta cok gerildin, stresin 30 artti.\nstres seviyesi: %d",stres);
                                printf("stres seviyen cok yuksek! bir sonraki maceraya atilmadan once biraz gevse.");
                            }
                            else{
                                printf("\nsavasta cok gerildin, stresin 30 artti.\nstres seviyesi: %d",stres);
                            }
                            return -1;
                            break;
                        }
                        else if(haydutCan<=0){
                            printf("\nTebrikler! Haydutu yendin");
                            return 1;
                            break;
                        }
                        
                    }
                }
            }
            else{
                printf("\nstres seviyen cok fazla!");
                printf("\nstres seviyesi: %d",stres);
                printf("\nsavasa girilemiyor.");
                return -1;
            }
                break;
        default:
            printf("hatali secim yapildi.");
            return 0;
            break;
    }
    return 0;
}




int zorKesifSavas(int ceviklik, int guc, int *can, int dayaniklilik, int stres){
    srand(time(NULL));
    int haydutGuc=rand()%4+7;
    int haydutDayaniklilik=rand()%4+7;
    int haydutCeviklik=rand()%4+7;
    int haydutCan=25;
    int secim;
    
    savasiBaslat:
    
    printf("\n**Dusman becerileri**");
    printf("\nguc: %d\tdayaniklilik: %d\tceviklik: %d",haydutGuc,haydutDayaniklilik,haydutCeviklik);
    printf("\nSaldirmak icin 1, kacmak icin 2 secin: ");
    scanf("%d",&secim);
    float kacmaIhtimali=(4*ceviklik)/100;
    int kacmaDurumu=rand()%99+1;
    switch (secim) {
        case 1:
            if(stres<50){
                printf("\nsavas basliyor...");
                if(guc>=haydutGuc){
                    do {
                        printf("\ndusmana %d hasar verildi!",4*guc);
                        printf("\ndusmanin cani %.2f azaldi.",(float)4*guc-((4*guc*(haydutDayaniklilik/100))-1));
                        haydutCan-=4*guc-((4*guc*(haydutDayaniklilik/100))-1);
                        printf("\ndusmanin kalan cani: %d",haydutCan);
                        if(haydutCan<=0){
                            break;
                        }
                        printf("\nhaydut sana saldirdi!");
                        printf("\nalinan hasar: %.2f",(float)4*haydutGuc-((4*haydutGuc*(dayaniklilik/100))-1));
                        *can-=4*haydutGuc-((4*haydutGuc*(dayaniklilik/100))-1);
                        printf("\nkalan can: %d",*can);
                        if(*can<=0){
                            break;
                        }
                        
                    } while (*can>0 && haydutCan>0);
                    if(*can<=0){
                        *can=0;
                        printf("\nhayduta yenik dustun...\ncan seviyesi: %d",*can);
                        stres+=30;
                        if(stres>=100){
                            stres=100;
                            printf("\nsavasta cok gerildin, stresin 30 artti.\nstres seviyesi: %d",stres);
                            printf("stres seviyen cok yuksek! bir sonraki maceraya atilmadan once biraz gevse.");
                        }
                        else{
                            printf("\nsavasta cok gerildin, stresin 30 artti.\nstres seviyesi: %d",stres);
                        }
                        return -1;
                        break;
                    }
                    else if(haydutCan<=0){
                        printf("\nTebrikler! Haydutu yendin");
                        return 1;
                        break;
                    }
                    
                }
                else{
                    do {
                        printf("\nhaydut sana saldirdi!");
                        printf("\nalinan hasar: %.2f",(float)4*haydutGuc-((4*haydutGuc*(dayaniklilik/100))-1));
                        *can-=4*haydutGuc-((4*haydutGuc*(dayaniklilik/100))-1);
                        printf("\nkalan can: %d",*can);
                        if(*can<=0){
                            break;
                        }
                        printf("\ndusmana %d hasar verildi!",4*guc);
                        printf("\ndusmanin cani %.2f azaldi.",(float)4*guc-((4*guc*(haydutDayaniklilik/100))-1));
                        haydutCan-=4*guc-((4*guc*(haydutDayaniklilik/100))-1);
                        printf("\ndusmanin kalan cani: %d",haydutCan);
                        if(haydutCan<=0){
                            break;
                        }
                        
                    } while (*can>0 && haydutCan>0);
                    if(*can<=0){
                        *can=0;
                        printf("\nhayduta yenik dustun...\ncan seviyesi: %d",*can);
                        stres+=30;
                        if(stres>=100){
                            stres=100;
                            printf("\nsavasta cok gerildin, stresin 30 artti.\nstres seviyesi: %d",stres);
                            printf("stres seviyen cok yuksek! bir sonraki maceraya atilmadan once biraz gevse.");
                        }
                        else{
                            printf("\nsavasta cok gerildin, stresin 30 artti.\nstres seviyesi: %d",stres);
                        }
                        return -1;
                        break;
                    }
                    else if(haydutCan<=0){
                        printf("\nTebrikler! Haydutu yendin");
                        return 1;
                        break;
                    }
                    
                }
            }
            else{
                printf("\nstres seviyen cok fazla!");
                printf("\nstres seviyesi: %d",stres);
                printf("savasa girilemiyor.");
                return -1;
            }
            break;
        case 2:
            if(stres<50){
                if(kacmaDurumu<kacmaIhtimali*100){
                    printf("\nhayduttan basariyla kacildi.");
                    return 1;
                    break;
                }
                else{
                    printf("\nhayduttan kacamadin!Savas basliyor..");
                    if(guc>=haydutGuc){
                        do {
                            printf("\ndusmana %d hasar verildi!",4*guc);
                            printf("\ndusmanin cani %.2f azaldi.",(float)4*guc-((4*guc*(haydutDayaniklilik/100))-1));
                            haydutCan-=4*guc-((4*guc*(haydutDayaniklilik/100))-1);
                            printf("\ndusmanin kalan cani: %d",haydutCan);
                            if(haydutCan<=0){
                                break;
                            }
                            printf("\nhaydut sana saldirdi!");
                            printf("\nalinan hasar: %.2f",(float)4*haydutGuc-((4*haydutGuc*(dayaniklilik/100))-1));
                            *can-=4*haydutGuc-((4*haydutGuc*(dayaniklilik/100))-1);
                            printf("\nkalan can: %d",*can);
                            if(*can<=0){
                                break;
                            }
                        
                        } while (*can>0 && haydutCan>0);
                        if(*can<=0){
                            *can=0;
                            printf("\nhayduta yenik dustun...\ncan seviyesi: %d",*can);
                            stres+=30;
                            if(stres>=100){
                                stres=100;
                                printf("\nsavasta cok gerildin, stresin 30 artti.\nstres seviyesi: %d",stres);
                                printf("stres seviyen cok yuksek! bir sonraki maceraya atilmadan once biraz gevse.");
                            }
                            else{
                                printf("\nsavasta cok gerildin, stresin 30 artti.\nstres seviyesi: %d",stres);
                            }
                            return -1;
                            break;
                        }
                        else if(haydutCan<=0){
                            printf("\nTebrikler! Haydutu yendin");
                            return 1;
                            break;
                        }
                        
                    }
                    else{
                        do {
                            printf("\nhaydut sana saldirdi!");
                            printf("\nalinan hasar: %.2f",(float)4*haydutGuc-((4*haydutGuc*(dayaniklilik/100))-1));
                            *can-=4*haydutGuc-((4*haydutGuc*(dayaniklilik/100))-1);
                            printf("\nkalan can: %d",*can);
                            if(can<=0){
                                break;
                            }
                            printf("\ndusmana %d hasar verildi!",4*guc);
                            printf("\ndusmanin cani %.2f azaldi.",(float)4*guc-((4*guc*(haydutDayaniklilik/100))-1));
                            haydutCan-=4*guc-((4*guc*(haydutDayaniklilik/100))-1);
                            printf("\ndusmanin kalan cani: %d",haydutCan);
                            if(haydutCan<=0){
                                break;
                            }
                            
                        } while (*can>0 && haydutCan>0);
                        if(*can<=0){
                            *can=0;
                            printf("\nhayduta yenik dustun...\ncan seviyesi: %d",*can);
                            stres+=30;
                            if(stres>=100){
                                stres=100;
                                printf("\nsavasta cok gerildin, stresin 30 artti.\nstres seviyesi: %d",stres);
                                printf("stres seviyen cok yuksek! bir sonraki maceraya atilmadan once biraz gevse.");
                            }
                            else{
                                printf("\nsavasta cok gerildin, stresin 30 artti.\nstres seviyesi: %d",stres);
                            }
                            return -1;
                            break;
                        }
                        else if(haydutCan<=0){
                            printf("\nTebrikler! Haydutu yendin");
                            return 1;
                            break;
                        }
                        
                    }
                }
            }
            else{
                printf("\nstres seviyen cok fazla!");
                printf("\nstres seviyesi: %d",stres);
                printf("\nsavasa girilemiyor.");
                return -1;
            }
                break;
        default:
            printf("hatali secim yapildi.");
            return 0;
            break;
    }
    return 0;
}



