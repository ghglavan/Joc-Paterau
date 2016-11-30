#include <math.h>
int vRaspuns[]={7,7,7,7};
int vectorNumere[4537],matriceaRaspunsurilor[16][9],vectorNumarIntrodus[5],vectorNumarVerificat[5],vectorRaspunsMatrice[4],aux,vAparitiiNr[2],vectorRandom[11];
int vectorNumereAI[4],vectorNrIntrodus[4];


void numereRandomN(int a[10],int n){
int i,v[10],c;
srand(time(NULL));
for(i=0;i<=9;i++){
        v[i]=i;
    }
    for(i=0;i<n;i++){
        c=rand()%10;
        while((i==0 && c==0)|| v[c]==-1){
            c=rand()%10;
        }
        a[i]=c;
        v[c]=-1;
    }
    //for(i=0;i<n;i++){      //-
    //    printf("%d",a[i]); // |-Afiseaza numarul ales de calculator
    //}                      //-
}


int verificareN(int a[10],int b[10],int n){
    int i,ok=1;
    for(i=0;i<n;i++){
        if(a[i]!=b[i]){
            ok=0;
        }
    }
    if(ok==1){
        return 1;
    }else{
        return 0;
    }
}

void raspunsPvAIN(int v[10],int c[10],int n){
    int i,j,ok=0;
    for(i=0;i<n;i++){
        if(v[i]==c[i]){
            printf("0");
            ok=1;

        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(v[i]==c[j] && i!=j){
                printf("X");
                ok=1;
            }
        }
    }
    if(ok==0){
        printf("----");
    }
}
void verificareNumarN(int a[10],int n){
    int nrJucator,ok=0,i,j;
    while(ok==0){
    scanf("%d",&nrJucator);
    if(nrJucator>=pow(10,n-1) && nrJucator<pow(10,n)){
        for(i=0;i<n;i++){
            a[n-i-1]=nrJucator%10;
            nrJucator/=10;

        }
        ok=1;
        if(a[0]==0){
            ok=0;
        }else{
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(a[i]==a[j] && i!=j){
                    ok=0;

                }
            }
        }
        }
        if(ok==0){
            printf("\nAti introdus un numar gresit\n");
        }
    }else{
        printf("\nAti intrdous un numar gresit\n");
    }
    }
}
int generare(){
    FILE*f;
    int a,b,c,d,e=0;
    f=fopen("numere.txt","w");
    for(a=1;a<=9;a++){
        for(b=0;b<=9;b++){
            for(c=0;c<=9;c++){
                for(d=0;d<=9;d++){
                    if(a!=b&&a!=c&&a!=d&&b!=c&&b!=d&&c!=d){
                        fprintf(f,"%d%d%d%d ",a,b,c,d);
                        e++;
                    }
                }
            }
        }
    }
    fclose(f);
    return e;
}
void initializareVraspuns(){
    int i;
    for(i=0;i<4;i++){
        vRaspuns[i]=7;
    }
}
void raspuns(int v[4],int c[4]){
    int i,j,contor=0;
    for(i=0;i<4;i++){
        if(v[i]==c[i]){
            vRaspuns[contor]=0;
            contor++;

        }
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(v[i]==c[j] && i!=j){
                vRaspuns[contor]=1;
                contor++;

            }
        }
    }
}
void afisareRaspuns(){
    int i;
    for(i=0;i<4;i++){
        if(vRaspuns[i]==0){
            printf("0");
        }else if(vRaspuns[i]==1){
            printf("X");
        }else{
            printf("-");
        }
    }
}
int verificareEgalitateVectori(int v[4],int c[4]){
    int i;
    for(i=0;i<4;i++){
        if(v[i]!=c[i])
            return 0;
    }
    return 1;
}
void initializareVrandom(){
int i;
for(i=0;i<11;i++){
    vectorRandom[i]=0;
}
}
void restrangereVector(int n,int m){
    int i,j,k;
for(i=0;i<4536;i++){
        aux=vectorNumere[i];
        vectorNumarIntrodus[3]=aux%10;
        aux/=10;
        vectorNumarIntrodus[2]=aux%10;
        aux/=10;
        vectorNumarIntrodus[1]=aux%10;
        aux/=10;
        vectorNumarIntrodus[0]=aux%10;
        aux/=10;

        for(j=m;j<n+1;j++){
            for(k=0;k<4;k++){
                vectorNumarVerificat[k]=matriceaRaspunsurilor[j][k+1];
                vectorRaspunsMatrice[k]=matriceaRaspunsurilor[j][k+5];
            }

                raspuns(vectorNumarIntrodus,vectorNumarVerificat);

                if(verificareEgalitateVectori(vectorRaspunsMatrice,vRaspuns)==0){

                    vectorNumere[i]=0;
                    j++;

                for(k=0;k<4;k++){
                    vRaspuns[k]=7;

                }

                    break;
                }

                for(k=0;k<4;k++){
                    vRaspuns[k]=7;

                }

        }
    }
}
int TestareElementeVectorNumere(){
    int i,contor=0;
    for(i=0;i<4536;i++){
        if(vectorNumere[i]!=0){
            contor++;
            if(contor>1)
                return 0;
        }
    }
    if(contor==0)
        return -1;
    return 1;
}
int testareVictorie(int n){
    int i;
    for(i=5;i<=8;i++){
        if(matriceaRaspunsurilor[n][i]!=0)
            return 0;
    }
    return 1;
}
void raspunsPvAIN2(int v[10],int c[10],int *nr,int n){
    int i,j,ok=0;
    for(i=0;i<n;i++){
        if(v[i]==c[i]){
            printf("0");
            ok=1;
            *nr=*nr+1;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(v[i]==c[j] && i!=j){
                printf("X");
                ok=1;
                *nr=*nr+1;
            }
        }
    }
    if(ok==0){
        printf("----");
        *nr=*nr+3;
    }
}

int PvAI2(int *nr){
    int i,j,k,nrRandom,contor=1;
    char raspunsJucator[4];
    FILE*f;
    f=fopen("numere.txt","r");
    for(i=0;i<4536;i++){
        fscanf(f,"%d",&vectorNumere[i]);
    }
    fclose(f);
    srand(time(NULL));
    initializareVraspuns();

    printf("Salut!Numele meu este Paterau.Daca stii regulile jocului atunci putem incepe.Alege un numar si retine-l sau scrie-l undeva unde sa-l poti verifica usor.\n Am 15 runde sa-l ghicesc.\n");
    numereRandomN(vectorNumereAI,4);
    printf("\nAm ales si eu un numar si sunt pregatit.Sa incepem jocul!!\nVoi incepe eu prin a alege un numar.");
    Sleep(15000);
    system("cls");
    for(i=1;i<16;i++){
            printf("\n\nRunda nr. %d\n\n\n\n",i);

                 printf("\n\nRandul dumneavoastra.Alegeti un numar:\n");
        verificareNumarN(vectorNrIntrodus,4);
        raspunsPvAIN2(vectorNrIntrodus,vectorNumereAI,nr,4);
        if(verificareN(vectorNrIntrodus,vectorNumereAI,4)==1){
            printf("\nFelicitari!Ati castigat\n");
            *nr+=10;
            return i;
        }

            printf("\nNumarul pe care il aleg este:\n");
            contor=1;
            nrRandom=rand()%4536;
            initializareVrandom();
            while(contor==1){
            nrRandom=rand()%4536;
                if(vectorNumere[nrRandom]!=0){
                    contor=0;
                }
            }
            aux=vectorNumere[nrRandom];
            matriceaRaspunsurilor[i][4]=aux%10;
            aux/=10;
            matriceaRaspunsurilor[i][3]=aux%10;
            aux/=10;
            matriceaRaspunsurilor[i][2]=aux%10;
            aux/=10;
            matriceaRaspunsurilor[i][1]=aux%10;
            aux/=10;
        for(k=0;k<4;k++){
            printf("%d",matriceaRaspunsurilor[i][k+1]);
        }
         printf("\nScrieti raspunsul:\n");
    scanf("%s",raspunsJucator);

            for(k=0;k<strlen(raspunsJucator);k++){
                if(raspunsJucator[k]=='0'){
                    matriceaRaspunsurilor[i][k+5]=0;
                }else if(raspunsJucator[k]=='X'||raspunsJucator[k]=='x'){
                    matriceaRaspunsurilor[i][k+5]=1;
                }else{
                    matriceaRaspunsurilor[i][k+5]=7;
                }
            }
             for(j=k;j<4;j++){
            matriceaRaspunsurilor[i][j+5]=7;

            }
            restrangereVector(i,1);

        if(testareVictorie(i)==1){
        printf("\nAm castigat\n");
        for(k=1;k<=i;k++){
            for(j=1;j<=4;j++){
                printf("%d",matriceaRaspunsurilor[k][j]);
            }
            printf("--");
            for(j=5;j<=8;j++){
                switch(matriceaRaspunsurilor[k][j]){
                case 0:printf("0");break;
                case 1:printf("X");break;
                }
            }
            printf("\n");
        }

            printf("\n");
            printf("Numarul meu este:");
            for(j=0;j<4;j++){
                printf("%d",vectorNumereAI[j]);
            }
        return 0;
        }else if(TestareElementeVectorNumere()==-1){
        printf("\nAti introdus un raspuns gresit\n");
        for(k=1;k<=i;k++){
            for(j=1;j<=4;j++){
                printf("%d",matriceaRaspunsurilor[k][j]);
            }
            printf("--");
            for(j=5;j<=8;j++){
                switch(matriceaRaspunsurilor[k][j]){
                case 0:printf("0");break;
                case 1:printf("X");break;
                }
            }
            printf("\n");
        }
                    printf("\n");
            printf("Numarul meu este:");
            for(j=0;j<4;j++){
                printf("%d",vectorNumereAI[j]);
            }
        return -1;
        }

    }
    return 0;
}

struct jucatori{
    int scor;
    char nume[30];
}jucator[30],aux1;
int nrJucator1[4],nrJucator2[4],nrAI[4],nrIntrodus[4],nrAIN[10],nrIntrodusN[10];
//adauga un jucator si scorul in fisier
void adaugare(int scor){
    FILE*f;
    if((f=fopen("blablabla.txt","a"))==0){
        printf("Eroare la deschidere");
    }
    char numeJucator[100];
    printf("Nume:\n");
    scanf("%s",numeJucator);
    fprintf(f,"%s %d\n",numeJucator,scor);
    fclose(f);
}
//adauga jucatorii si scorurile din fisier in structura
int adaugareJucatori(){
    int i=0,scor;
    char nume[30];
    FILE*f;
    if((f=fopen("blablabla.txt","r"))==0){
        printf("Eroare la deschidere");
    }
    while(fscanf(f,"%s",nume)==1){
        fscanf(f,"%d",&scor);
        strcpy(jucator[i].nume,nume);
        jucator[i].scor=scor;
        i++;
    }
    fclose(f);
    return i;
}
//ordoneaza jucatorii din structura dupa scor
void ordonare(int n){
    int i,j;
    for(i=0;i<=n;i++){

            for(j=i;j>0;j--){
                if(jucator[j-1].scor<jucator[j].scor){
                    aux1=jucator[j-1];
                    jucator[j-1]=jucator[j];
                    jucator[j]=aux1;
            }

            }
}
}
//afiseaza primii n jucatori in ordinea scorului
void topN(int n,int max){
    int i;
    if(n>max){
        printf("\nNu sunt suficienti jucatori inregistrati\n");
    }
    for(i=0;i<=n;i++){
        printf("%d)%s %d\n",i+1,jucator[i].nume,jucator[i].scor);
    }
}
//submeniu care se ocupa cu fisierele
void statistica(){
    FILE*f;
    char nume[100],nCautat[100];
    int n,nrJucatorilor,top,scor,i,gasit=0,ok=0;
    printf("MENIU 2.\n1)Top n\n2)Verifica statistica jocului\n3)Cauta in statistica jocului\n4)Reseteaza statistica jocului\n5)Iesire\n");
    scanf("%d",&n);
    if((f=fopen("blablabla.txt","r"))==NULL){
                    printf("eroare");
                }
    while(n!=5){
        switch(n){
            case 5:
                break;
            case 1:
                system("cls");
                printf("n=");
                scanf("%d",&top);
                nrJucatorilor=adaugareJucatori();
                ordonare(nrJucatorilor);
                topN(top-1,nrJucatorilor+1);
                break;
            case 2:
                system("cls");
                i=1;
                ok=0;
                rewind(f);
                while(fscanf(f,"%s",nume)==1){
                    fscanf(f,"%d",&scor);
                    printf("%d)%s-%d\n",i,nume,scor);
                    i++;
                    ok=1;
                }
                if(ok==0){
                    printf("\n\nNu exista jucatori in statistica\n\n");
                }
                break;
            case 3:
                system("cls");
                printf("Numele pe care il cautati:\n");
                scanf("%s",nCautat);
                gasit=0;
                rewind(f);
                while(fscanf(f,"%s",nume)==1){
                    fscanf(f,"%d",&scor);
                    if(strcmp(nume,nCautat)==0){
                        gasit=1;
                        printf("%s-%d\n",nume,scor);
                    }
                }
                if(gasit==0){
                    printf("Jucatorul nu a fost gasit\n");
                }
                break;
            case 4:
                system("cls");
                fclose(f);
                f=fopen("blablabla.txt","w");
                fprintf(f," ");
                fclose(f);
                f=fopen("blablabla.txt","r");
                break;
            default:
                printf("\nNumarul introdus este gresit\n");
        }
        printf("\nMENIU 2.Alegeti\n1)Top n\n2)Verifica statistica jocului\n3)Cauta in statistica jocului\n4)Reseteaza statistica jocului\n5)Iesire\n");
        scanf("%d",&n);
    }
                fclose(f);
                system("cls");
}
//genereaza un numar de 4 cifre diferite care nu incep cu 0 si le adauga intr-un vector
void numereRandom(int v[4]){
int ok=0,n;
srand(time(NULL));
while(ok==0){
    n=rand()*rand();
    v[3]=n%10;
    v[2]=n/10%10;
    v[1]=n/100%10;
    v[0]=n/1000%10;
    if(v[0]!=v[1] && v[0]!=v[3] && v[0]!=v[2] && v[1]!=v[2] && v[1]!=v[3] && v[2]!=v[3] && v[0]!=0){
        ok=1;
    }
    }
}
//raspunsul in modul PvAI + nr  care sa adauga la calcului scorului
void raspunsPvAI(int v[4],int c[4],int *nr){
    int i,j,ok=0;
    for(i=0;i<4;i++){
        if(v[i]==c[i]){
            printf("0");
            ok=1;
            *nr=*nr+1;
        }
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(v[i]==c[j] && i!=j){
                printf("X");
                ok=1;
                *nr=*nr+1;
            }
        }
    }
    if(ok==0){
        printf("----");
        *nr=*nr+3;
    }
}

//verifica daca numarul introdus de jucator este corect
void verificareNumar(int d[3]){
    int ok=0,nrJucator,i;
    while(ok==0){
        scanf("%d",&nrJucator);
    if(nrJucator>1000 && nrJucator<10000){
    for(i=0;i<4;i++){
        d[3-i]=nrJucator%10;
        nrJucator/=10;
    }
    if(d[0]==0 || d[0]==d[1] || d[0]==d[2] || d[3]==d[0] || d[1]==d[2] || d[1]==d[3] || d[2]==d[3]){
        printf("\nNumarul pe care l-ai ales e gresit\n");
    }else{
    ok=1;
    }
    }else{
        printf("\nNumarul pe care l-ai ales e gresit!\n");
    }
    }
}
//modifica toate valorile din vector in 0
void initializare0(int a[4]){
 int i;
 for(i=0;i<4;i++){
    a[i]=0;
 }
}
//verifica daca 2 numere corespund
int verificare(int a[4],int b[4]){
    int i,ok=1;
    for(i=0;i<4;i++){
        if(a[i]!=b[i]){
            ok=0;
        }
    }
    if(ok==1){
        return 1;
    }else{
        return 0;
    }
}
//calculeaza punctajul
int punctaj(int n,int m,int nivel){
    return (n*nivel*30)+m;
}
void spatiere(){
    int i;
for(i=1;i<71;i++){
    printf("\n");
}
}


