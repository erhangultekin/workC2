#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int main()
{
    int upperCounter=0;
    int lowerCounter=0;
    int digitCounter=0;
    int punCounter=0;
    int spaceCounter=0; //HOCAM KELIME SAYISINI BOSLUK SAYISIYLA HALLETMEYE CALISTIM TXT DOSYASININ SONUNDA BOSLUK OLMADIGINI VAR SAYARAK
    int j;
    int i;
    char c;
    FILE *okumaDosyasi;

    if((okumaDosyasi=fopen("a.txt","r+"))==NULL){
        printf("Dosya bulunamadý");
    }
    else{

        while((c=fgetc(okumaDosyasi))!=EOF){

            if(isupper(c)){
                upperCounter+=1;
            }
            else if(islower(c)){
                lowerCounter+=1;
            }
            else if(isdigit(c)){
                digitCounter+=1;
            }
            else if(ispunct(c)){
                punCounter+=1;
            }
            else if (isspace(c)){
                spaceCounter+=1;
            }

        }
    printf("%15s%15s%15s","Ozelligi","Sayisi","Histogrami");
    printf("\n");
    int n[SIZE]={upperCounter,lowerCounter,digitCounter,punCounter,spaceCounter+1};
    char t[5][100]={"Buyuk Harf","Kucuk Harf","Rakam","Noktalama Isareti","Kelime"};
    printf("\n");
    for (j=0;j<SIZE;j++){
        printf("%20s%13d ",t[j],n[j]);
        for(i=1;i<=n[j];i++){
            printf("%c",'*');
        }
        printf("\n");
    }


    }
    return 0;
}
