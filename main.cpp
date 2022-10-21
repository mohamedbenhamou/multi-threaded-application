#include <thread>
#include<unistd.h>
#include <iostream>
#include <Windows.h>
#include <MMsystem.h>
#include <future>
#include <string>
#include <graphics.h>


using namespace std;
string pays[3]={"maroc","algerie","egipte"};

////////////////// fonction qui display les images///////////////////////////////////////
void start_image(int j){
    initwindow(1280,720,"Partie2");
    setbkcolor(WHITE);
    cleardevice();

     for(int i = 1; i<=21;i++){
        string num=to_string(i);
        string path ="C:\\Users\\elhou\\OneDrive\\Desktop\\Projet\\Partie2_app_multithread\\"+pays[j]+"\\"+num+".jpeg"; //il faut remplacer ce path par l'emplacemment des images dans votre pc
        const char* path_const = path.c_str();    //convertie la variable path de string a const

        readimagefile(path_const,0,0,1280,720); //fonction that display images qui prend comme parametre  path const (non string)
        sleep(3);
    }
    getch();
    closegraph();


};

/////////////fonction qui play le hymne national marocain///////////////////////////////////////////

void start_music_maroc(){
    PlaySound(TEXT("C:\\Users\\elhou\\OneDrive\\Desktop\\Projet\\Partie2_app_multithread\\maroc\\musica.wav"),NULL,SND_FILENAME);
}

/////////////fonction qui play le hymne national egypte /////////////////////////////////////////////

void start_music_egipte(){
    PlaySound(TEXT("C:\\Users\\elhou\\OneDrive\\Desktop\\Projet\\Partie2_app_multithread\\egipte\\musica.wav"),NULL,SND_FILENAME);
}

/////////////fonction qui play le hymne national algérien///////////////////////////////////////////

void start_music_algerie(){
    PlaySound(TEXT("C:\\Users\\elhou\\OneDrive\\Desktop\\Projet\\Partie2_app_multithread\\algerie\\musica.wav"),NULL,SND_FILENAME);
}

/////////////// fonction display le menu///////////////////////
void displaymenu()
{ cout<<"========================================================================================================================\n";
cout<<" \t\t\t\t\t\t Partie 2 :  application multithread\t \n ";
cout<<"======================================================================================================================= \n";
cout<<"\t\t\t\t\t\t 0.Maroc\n\n\n";

cout<<" \t\t\t\t\t\t 1.Algerie\n\n\n";
cout<<" \t\t\t\t\t\t 2.egypte \n\n\n";
cout<<" \t\t\t\t\t\t 3.Fin du programme. \n\n\n";
cout<<"\n\n\n";
cout<<"\t\t votre choix?\t" ;
}

int main()
{
        system("color d");

        int t=-1;
        while(t!=0){
        int choix;
        displaymenu();
        cin>>choix;


        switch (choix){


////////////////Maroc////////////////////////////
        case 0:
            {

            thread maroc(start_music_maroc);
            future<void> fn = async(launch::async,start_image,0);
            maroc.join();
            break;
            }

///////////////Algerie//////////////////////////

        case 1:
            {

            thread algerie(start_music_algerie);
            future<void> fn = async(launch::async,start_image,1);
            algerie.join();
            break;
            }
///////////////Egipte///////////////////////////

        case 2:
            {

            thread egipte(start_music_egipte);
            future<void> fn = async(launch::async,start_image,2);
            egipte.join();
            break;
            }

        case 3:
            {
            t=0;
            initwindow(1280,720,"Partie2");
            setbkcolor(WHITE);
            cleardevice();
            readimagefile("C:\\Users\\elhou\\OneDrive\\Desktop\\Projet\\Partie2_app_multithread\\aurevoir.jpg",0,0,1280,720);
            sleep(1);
            getch();
            closegraph();
            break;
            }

        default:
            cout<<"Aucun des hcoix possible a ete choisie le maroc va etre choisie par defaut \n\n";

            thread maroc(start_music_maroc);
            future<void> fn = async(launch::async,start_image,0);
            maroc.join();
            break;

        }

    }
   return 0;
   }
