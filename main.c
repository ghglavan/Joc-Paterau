#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#include "inteligenta.h"

int main()
{
    int scor,n,i,numereX0,nivel,ok,nrCifre,scorPvAI;

    printf("JOCUL PATERAU.\n\n");
    Sleep(3000);
    system("cls");
    printf("\nMENIU 1\n1)Reguli\n2)PvP\n3)PvAI\n4)Statistica\n5)Iesire\n");
    scanf("%d",&n);
    while(n!=5){
    switch(n){
        case 5:break;
        case 1:
            system("cls");
            printf("\n-Jucatorii aleg un numar format din 4 cifre pe care adversatul trebuie sa-l ghiceasca\n-Pe rand pun cate o intrebare adversarului.Intrebarea reprezinta un numar de 4 cifre\n-Vor primi un raspuns format dintr-un numar de 0 si de X. Fiecare 0 reprezita faptul ca o cifra din numarul introdus de jucator corespunde ca pozitie si in numarul adversarului in timp ce fiecare X reprezinta faptul ca o cifra din numarul jucatorului se afla si in numarul adversarului,dar nu pe aceeasi pozitie.---- reprezinta faptul ca numerele nu au cifre comune\n\n");
            break;
        case 2:
            system("cls");
            ok=0;
            initializare0(nrJucator1);
            initializare0(nrJucator2);
            printf("Numarul jucatorului 1:\n");
            verificareNumar(nrJucator1);
            spatiere();
            printf("Numarul jucatorului 2:\n");
            verificareNumar(nrJucator2);
            spatiere();
            printf("Jocul dureaza 15 runde.\n");
            for(i=1;i<16;i++){
                printf("\nRunda nr. %d\n\n",i);
                printf("\nJucatorul nr. 1 alege un numar ca intrebare\n");
                verificareNumar(nrIntrodus);
                raspuns(nrJucator2,nrIntrodus);
                if(verificare(nrJucator2,nrIntrodus)==1){
                    printf("\nJucatorul 1 a castigat\n");
                    ok=1;
                    break;
                }
                printf("\nJucatorul nr. 2 alege un numar ca intrebare\n");
                verificareNumar(nrIntrodus);
                raspuns(nrJucator1,nrIntrodus);
                if(verificare(nrJucator1,nrIntrodus)==1){
                    printf("\nJucatorul 2 a castigat\n");
                    ok=1;
                    break;
                }
            }
            if(ok==0){
                printf("\nJocul s-a terminat la egalitate\n");
            }
            break;
        case 3:
            system("cls");
            numereX0=0;
            initializare0(nrAI);
            numereRandom(nrAI);
           // for(i=0;i<4;i++){
           //           printf("%d",nrAI[i]);
            //       }
            while(1){
            printf("\nAlegeti nivelul:\n1)easy\n2)medium\n3)hard\n4)master\n5)LEGENDARY(PVAI!!!)\n");
            scanf("%d",&nivel);
            if(nivel==1 || nivel==2 || nivel==3 || nivel==4 || nivel==5){
                break;
            }else{
                printf("\nNumarul este gresit\n");
            }
            }
            if(nivel==5){
            scorPvAI=PvAI2(&numereX0);
            if(scorPvAI==-1 || scorPvAI==0){
                break;
            }else{
            scor=punctaj((15-scorPvAI)/2,numereX0,3*nivel);
            printf("\nScorul tau este:\n%d\n",scor);
            adaugare(scor);
            break;
            }
            }else if(nivel==4){
            printf("\nNumarul de cifre din care sa fie format numarul calculatorului(>=5)\n");
            while(1){
                    scanf("%d",&nrCifre);
                    if(nrCifre>=5 && nrCifre <=10){
                        break;
                    }else{
                    printf("\nAti introdus un numar gresit\n");
                    }
                }

            numereRandomN(nrAIN,nrCifre);
            printf("\nJocul dureaza %d runde.In fiecare runda alegeti un numar ca intrebare\n",10+nrCifre/2);
            for(i=1;i<=10+nrCifre/2;i++){
                printf("\nRunda nr.%d\n",i);
                verificareNumarN(nrIntrodusN,nrCifre);
                raspunsPvAIN2(nrAIN,nrIntrodusN,&numereX0,nrCifre);
                if(verificareN(nrAIN,nrIntrodusN,nrCifre)==1){
                    printf("\nAti castigat!\n");
                    scor=punctaj(10+nrCifre/2-i,numereX0,nivel*nrCifre);
                    printf("\nScorul tau este:\n%d\n",scor);
                    adaugare(scor);
                    break;
                }
            }
            printf("\nNumarul este:\n");
                    for(i=0;i<nrCifre;i++){
                        printf("%d",nrAIN[i]);
                    }
            }else{
            printf("\nJocul dureaza %d runde.In fiecare runda alegeti un numar ca intrebare\n",15-(nivel-1)*5);

            for(i=1;i<=15-(nivel-1)*5;i++){
                printf("\nRunda nr.%d\n",i);
                verificareNumar(nrIntrodus);
                raspunsPvAI(nrAI,nrIntrodus,&numereX0);
                if(verificare(nrAI,nrIntrodus)==1){
                    printf("\nAti castigat!\n");
                    scor=punctaj(15-i,numereX0,nivel);
                    printf("\nScorul tau este:\n%d\n",scor);
                    adaugare(scor);
                    break;
                }
            }
            printf("\nNumarul este:\n");
                    for(i=0;i<4;i++){
                        printf("%d",nrAI[i]);
                    }
             }
            break;
        case 4:
            system("cls");
            statistica();
            break;
        default:
            printf("Ati introdus un numar gresit");
    }
    printf("\nMENIU 1.Alegeti\n\n1)Reguli\n2)PvP\n3)PvAI\n4)Statistica\n5)Iesire\n");
    scanf("%d",&n);
        }
    return 0;
}
