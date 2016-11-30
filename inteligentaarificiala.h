int vRaspuns[]={7,7,7,7};
int vectorNumere[4537],matriceaRaspunsurilor[16][9],vectorNumarIntrodus[5],vectorNumarVerificat[5],vectorRaspunsMatrice[4],aux,vAparitiiNr[2],vectorRandom[11];

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
