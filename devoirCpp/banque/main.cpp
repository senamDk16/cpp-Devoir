#include <iostream>

using namespace std;

class Compte
{
    private:
        string nom;
        string prenom;
        string numeroCompte;
        string codeCompte;
        double solde;
    public:
        void addCarte(string nom, string prenom, string numeroCompte, string codeCompte, double solde){
            this->nom = nom;
            this->prenom = prenom;
            this->numeroCompte = numeroCompte;
            this->codeCompte = codeCompte;
            this->solde = solde;
        }

        //les gets
        double getSold(){
            return this->solde;
        }
        string getNumeroCarte(){
            return this->numeroCompte;
        }
        string getCodeCarte(){
            return this->codeCompte;
        }
        string getPrenom(){
            return this->prenom;
        }
        string getNom(){
            return this->nom;
        }




        //operation posible set
        void depots(){
            double montant = 0;

            cout <<"Entre la valeur du depot : " ;
            cin >> montant;
            cout << endl;

            this->solde += montant;
            cout<<"-----Operation valide-----"<<endl;
        }
        void retrait(){

            double montant = 0;

            cout <<"Entre la valeur du retrait : " ;
            cin >> montant;
            cout << endl;

            if(this->solde >= montant){
                this->solde -= montant;
                cout<<"-----Operation valide-----"<<endl;
            }
            else{
                cout<<"-----Solde insuffisant-----"<<endl;
            }

        }

        //information
        void affiche(){
            cout<<"-----Information-----"<<endl;
            cout<<"Nom : "<<this->nom << "\n prenom : " << this->prenom <<"\n solde : "<< this->solde << endl;
        }


};

int verification(string numeroCarte, string codeCarte, Compte tabCarte[])
{
    int valide = 0;
    for(int i=1; i<10; i++){

        if((tabCarte[i].getNumeroCarte() == numeroCarte) && (tabCarte[i].getCodeCarte() == codeCarte)){
            valide = i;
            break;
        }
        else{
            valide = 0;
        }
    }

    return valide;
}

int main()
{
    Compte tabCarte[10];
    tabCarte[1].addCarte("senam", "kk", "1234", "1234", 10000);
    tabCarte[2].addCarte("senam1", "kk1", "12345", "12345", 1400);
    string numeroCarte;
    string codeCarte;
    int valide = 0;

    char choix;
    string menu = " \n -----MENU----- \n 1-depots \n 2- retrait \n 3- solde \n 4- voir Information \n 5-quitter \n Votre choix : ";
    do{
       cout<<"-----Entre les identifiants-----" <<endl;
        cout<<"Entre le numero de carte : ";
        cin >> numeroCarte;
        cout<< endl;
        cout<<"Entre le code de carte : " ;
        cin >> codeCarte;
        cout<< endl;

        valide = verification(numeroCarte, codeCarte, tabCarte);
        if(valide == 0){
            cout<<"-----Information invalide-----"<<endl;
        }
        else{
            cout<<"-----Information valide-----"<<endl;
        }
    }while(valide == 0);

    do{
        cout<< menu ;
        cin >> choix;

        if(isdigit(choix)){
            switch(choix){
                case '1':
                    tabCarte[valide].depots();
                    break;
                case '2':
                    tabCarte[valide].retrait();
                    break;
                case '3':
                    cout<<"Votre solde est : " << tabCarte[valide].getSold() << endl;
                    break;
                case '4':
                    tabCarte[valide].affiche();
                    break;
                case '5':
                    cout<<"------Fin programme-----"<<endl;
                    break;
            }
        }
        else{
            cout<<"-----Merci d'entre que des chiffres merci-----"<<endl;
        }
    }
    while(choix != '5');

    return 0;
}













