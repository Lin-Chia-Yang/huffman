#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct tree{
        int data;
        struct tree *next;
    };
    void tree(int count3,int array1[52],int n,int array2[52]){
        struct tree *point=(struct tree*)malloc(sizeof (struct tree));
        ///struct tree **as=malloc(sizeof (struct tree));
        struct tree **as=malloc(10000);
        for(int i=0;i<2*count3;i++){
            as[i]=malloc(1000);
        }
        for(int i=1;i<2*count3;i++){
            if(i<=count3){
                as[i]->data=array1[i-1];
                as[i]->next=NULL;
            }
            else{
                as[i]->data=99999999;
                as[i]->next=NULL;
            }
           ///printf("as[%d]=%d\n",i,as[i]->data);
        }
        int num = count3;
        int c=count3+1;
        int n1;
        int n2;
        int b = 2*num-1;
        int sum=0;
        while(num>1){
            int a[num];
            int n3=0;
            for(int i=0;i<b;i++){
                point=as[i+1];
                ///printf("as[%d]=%d\n",i+1,as[i+1]->data);
                ///printf("%d\n",point->data);
                if(point->data==99999999){
                    ///printf("as[%d]=no data\n",i+1);
                    break;
                }
                if(point->next!=NULL){
                    ///printf("next\n");
                    continue;
                }
                a[n3]=point->data;
                ///printf("a[%d]=%d save data=as[%d]\n",n3,point->data,i+1);
                n3=n3+1;
            }
            ///printf("sort-------\n");
            for(int i=0;i<num;i++){
                for(int j=0;j<num-1;j++){
                    if(a[j]<a[j+1]){
                        continue;
                    }
                    else{
                        int temp=a[j];
                        a[j]=a[j+1];
                        a[j+1]=temp;
                    }
                }
            }
            for(int i=0;i<num;i++){
                ///printf("a[%d]=%d\n",i,a[i]);
            }

            for(int i=1;i<b+1;i++){
                if(as[i]->next!=NULL){
                    ///printf("as[%d] have next\n",i);
                    continue;
                }
                if(as[i]->data==a[0]){
                    n1=i;
                    as[n1]->next=as[c];
                    ///printf("%d\n",n1);
                    break;
                }
            }///尋找a[0],n1為節點的位置
            ///printf("counter:%d\n",b);
            for(int i=1;i<b+1;i++){
                if(as[i]->next!=NULL){
                   /// printf("as[%d] have next\n",i);
                    continue;
                }
                if(as[i]->data==a[1]){
                    n2=i;
                    ///printf("%d\n",n2);
                    as[n2]->next=as[c];
                    break;
                }
            }///尋找a[1],n2為節點的位置
            as[c]->data=a[0]+a[1];
            ///printf("as[%d]=%d\n",c,as[c]->data);
            c=c+1;
            num=num-1;

        }
        for(int i=1;i<=count3;i++){
            int level=0;
            point=as[i];
            while(point->next!=NULL){
                level=level+1;
                point=point->next;

            }
            sum=sum+as[i]->data*level;
            ///printf("level=%d\n",level);
        }///計算權重
        printf("> %d\n",sum);
        printf("\n");

    }

    void change(int small2[52],int small[52],int count,int array2[52],int n){
        ///printf("%d\n",count);
        int sum=small[0]+small[1];
        for(int i=0;i<=count-2;i++){
            small2[i]=small[i+2];
            ///printf("small2[%d]=%d\n",i,small2[i]);
        }
        small2[count-1]=sum;
        small2[count]=0;
        array2[n]=sum;
        for(int i=0;i<=count-2;i++){
            for(int j=0;j<=count-2;j++){
                if(small2[j]<=small2[j+1]){
                    continue;
                }
                else{
                    int temp=small2[j];
                    small2[j]=small2[j+1];
                    small2[j+1]=temp;
                }
            }
        }
    }

    char str1[1000];
    while(1){
        int save[52];
        int small[52];
        int count=0;
        int count2=0;
        for(int i=0;i<52;i++){
            save[i]=0;
            small[i]=0;
        }
        fgets(str1,1000,stdin);
        setbuf(stdin, NULL);
        if(str1[0]=='-' && str1[1]=='1' && str1[2]=='\n'){
            break;
        }
        ///字串為字母放進save陣列
        int length=strlen(str1)-1;
        for(int i=0;i<length;i++){
            if('a'<=str1[i]&&str1[i]<='z'){
                save[(str1[i]-'a')]=save[(str1[i]-'a')]+1;
            }
            else if('A'<=str1[i] && str1[i]<='Z'){
                save[(str1[i]-'A')+26]=save[(str1[i]-'A')+26]+1;
            }
            else{
                continue;
            }
        }
        for(int i=0;i<52;i++){
         ///   printf("save[%d]=%d\n",i,save[i]);
        }
        ///將save不等於0的陣列傳入small
        for(int i=0;i<52;i++){
            if(save[i]==0){
                continue;
            }
            else{
                small[count]=save[i];
               /// printf("small[%d]=%d\n",count,small[count]);
                count=count+1;
            }
        }
        ///printf("%d",count);
        ///排列small大小
        count=count-1;
        for(int i=0;i<count;i++){
            for(int j=0;j<count;j++){
                if(small[j]<=small[j+1]){
                    continue;
                }
                else{
                    int temp=small[j];
                    small[j]=small[j+1];
                    small[j+1]=temp;
                }
            }
        }
        ///printf("change--------\n");
        int small2[52];
        int array1[52];///儲存節點
        int array2[52];///所有節點
        int n=count+1;
        for(int i=0;i<count;i++){
            small2[i]=small[i];
        }
        for(int i=0;i<=count;i++){
            array1[i]=small[i];
            array2[i]=small[i];
        }
        int count3=count;
        ///tree(small2[0],small2[1]);
        change(small2,small,count,array2,n);
        n=n+1;
        count=count-1;
        count2=count;
        while(count>=1){
            change(small2,small2,count,array2,n);
            n=n+1;
            ///printf("\n");
            for(int i=0;i<=count2;i++){
                ///printf("%d",small2[i]);
                count2=count2-1;
            }
            count=count-1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n-1;j++){
                if(array2[j]<=array2[j+1]){
                    continue;
                }
                else{
                    int temp=array2[j];
                    array2[j]=array2[j+1];
                    array2[j+1]=temp;
                }
            }
        }
        tree(count3+1,array1,n,array2);
    }
    return 0;
}
