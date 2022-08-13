#include<iostream>
#include<graphics.h>
#include<math.h>
#include<dos.h>
#include<time.h>
#include<cstdio>
#include<ctime>
using namespace std;

int main()
{
    int i,gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\Program Files\\CodeBlocks\\minGW\\include\\");
    initwindow(800,600,"Snake Game");

    srand(time(0));
    int a=250,b=250,x=0,y=-1,r=70,ch,redR=4,blankR=0,m1,m2,m3,m4,n1,n2,n3,n4,distance,distance2,recColor[2]={4,0},score=0;
    char msg[100];
    int randTime;
    clock_t duration;
    clock_t duration1;
    randTime=1;
    loop:
       // randTime=rand()%5+1;
        randTime+=rand()%5+1;
        duration=0;

        m1=rand()%400+20;
        m2=rand()%300+20;
        m3=m1+40;
        m4=m2+40;

        n1=rand()%300+20;
        n2=rand()%200+20;
        n3=n1+20;
        n4=n2+20;
        distance=int(sqrt(pow((a-m1),2)+pow((b-m2),2)));
        distance2=int(sqrt(pow((a-n1),2)+pow((b-n2),2)));

        if(distance<r||distance==r){
            m1+=r*2+5;
            m2+=r*2+5;
            m3=m1+40;
            m4=m2+40;
        }
         if(distance2<r||distance2==r){
            n1+=r*2+5;
            n2+=r*2+5;
             n3=n1+20;
        n4=n2+20;
        }

    while(1)
    {
        circle(a,b,r);

       setcolor(YELLOW);
       rectangle(m1,m2,m3,m4);
       setfillstyle(SOLID_FILL,4);
       floodfill(m1+1,m2+1,YELLOW);

       setcolor(YELLOW);
       rectangle(n1,n2,n3,n4);
       setfillstyle(SOLID_FILL,0);
       floodfill(n1+1,n2+1,YELLOW);

       sprintf(msg,"Your Score=%d",score);
       outtextxy(10,10,msg);

        outtextxy(500,10,"Press ESC to exit");
        if(kbhit())
        {
            ch=getch();
            if(ch==72)
            {
                x=0;
                y=-2;
            }
            if(ch==75)
            {
                x=-2;
                y=0;
            }
            if(ch==77)
            {
                x=2;
                y=0;
            }
            if(ch==80)
            {
                x=0;
                y=2;
            }
            if(ch==27)
            {
                exit(0);
            }
            a=a+x;
            b=b+y;

            cleardevice();


            }
        distance=int(sqrt(pow((a-m1),2)+pow((b-m2),2)));
        distance2=int(sqrt(pow((a-n1),2)+pow((b-n2),2)));

        duration=clock();
       // duration1=clock();
        duration=duration/CLOCKS_PER_SEC;
       // duration1=duration1/CLOCKS_PER_SEC;

        if(duration==randTime)
        {
            duration=0/CLOCKS_PER_SEC;
            cleardevice();

             break;
        }



        if(distance<r||distance==r){
            r=r*1.1;
            score=score+5;
            break;
        }
        if(distance2<r||distance2==r){
             r=r*0.9;
             score=score+2;
             break;
        }

     }



    if(r>200||r<50){
        outtextxy(250,200,"The Game is Ended!");
        sprintf(msg,"Your Score=%d",score);
        outtextxy(250,250,msg);
        goto exit;
     }

    goto loop;

    exit:
        cout<<"Game Ended";
        cin>>i;
    return 0;
}

