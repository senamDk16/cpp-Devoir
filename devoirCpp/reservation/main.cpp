#include <iostream>
#include<string>
using namespace std;


class Bus{
    public:
        int codeBus;
        int nbrePlaceDispo;
        int placeLibre;
        string lieux;
        double prix;

        void addBus(int post){
            int nbrePlaceDispo;
            string lieux;
            double prix;
            cout<<"-----Bus-----"<<endl;
            cout<<"Entre le nombre de place du bus : ";
            cin >> nbrePlaceDispo;
            cout<<endl;
            cout<<"Entre le lieux : ";
            cin >> lieux;
            cout<<endl;
            cout<<"Entre le prix : ";
            cin >> prix;
            cout<<endl;
            this->codeBus = post;
            this->nbrePlaceDispo = nbrePlaceDispo;
            this->placeLibre = nbrePlaceDispo;
            this->lieux = lieux;
            this->prix = prix;

        }
};
class Reservation{

    public:
        string nom;
        string date;
        int nbrePlace;
        void addReservation(Bus bus, string nom,string date, int nbrePlace){
            this->nom = nom;
            this->date = date;
            this->nbrePlace = nbrePlace;
            bus.placeLibre -=  nbrePlace;
        }
};

int main()
{

    Bus tabBuss[10];
    Reservation tabReservation[10];
    int nbreReservation = 1;
    int * pReservation = &nbreReservation;
    int startPost = 1;
    int* pointeur = &startPost;
    char choix;
    string menu = " \n -----MENU----- \n 1-ajouter un bus \n 2- voir tous les bus \n 3- reservation \n 4-voir les reservations \n 5-Quitter \n Votre choix : ";

    do{
        cout<< menu;
        cin>>choix;

        if(isdigit(choix)){
            switch(choix){
                case '1':
                tabBuss[*pointeur].addBus(*pointeur);
                *pointeur += 1;
                break;
                case '2':
                    for(int i=1; i<*pointeur;i++){
                        cout<< "code : " <<tabBuss[i].codeBus << " ---nombre de place total : " << tabBuss[i].nbrePlaceDispo << " --- le lieu : " << tabBuss[i].lieux<< " ---le prix : " << tabBuss[i].prix<< endl;
                    }
                    break;
                case '3':
                    int codeBus;
                    for(int i=1; i<*pointeur;i++){
                        cout<< "code : " <<tabBuss[i].codeBus << " ---nombre de place disponible : " << tabBuss[i].nbrePlaceDispo << " --- le lieu : " << tabBuss[i].lieux<< " ---le prix : " << tabBuss[i].prix<< endl;
                    }

                    cout<<"Entre le code du bus : "<<endl;
                    cin >> codeBus;

                    if(tabBuss[codeBus].nbrePlaceDispo == 0){
                        cout<<"-----Place non disponible----"<<endl;
                    }
                    else{
                        string nom,date;
                        int nbrePlace;
                        cout<<"Entre votre nom : ";
                        cin>>nom;
                        cout<<endl;
                        cout<<"Entre la date : ";
                        cin>>date;
                        cout<<endl;
                        cout<<"Entre le nombre de place a reserve : ";
                        cin>>nbrePlace;
                        cout<<endl;

                        if(nbrePlace > tabBuss[codeBus].nbrePlaceDispo){
                            cout<<"-----Reservation echoue nombre place non disponible-----"<<endl;
                        }
                        else{
                            tabReservation[*pReservation].addReservation(tabBuss[codeBus],nom,date,nbrePlace);
                        }
                    }
                    break;
                case '4' :
                    for(int i=1; i<=10; i++){
                        cout<<"Nom : " << tabReservation[i].nom <<"date de reservation : " << tabReservation[i].date << "nombre de place "<< tabReservation[i].nbrePlace <<endl;
                    }
                    break;
                case '5':
                    cout<<"Fin programme"<<endl;
            }
        }
        else{
            cout<<"-----Entre que des nombres-----"<<endl;
        }
    }while(choix != '5');


    return 0;
}
