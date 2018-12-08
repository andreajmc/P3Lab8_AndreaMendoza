#include <iostream>
using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::cout;
using std::endl;
using std::cin;
using std::stoi;
#include <string>
#include <cmath>
#include <sstream>
#include <vector>
#include <fstream>
#include <ios>
using std::ios;
using std::vector;
#include "Civilizacion.h"
#include "CC10.h"
#include "c17ARZ.h"
#include "BB01.h"


using std::string;
using std::getline;

void addtoHistory(Civilizacion*, string, string, string);


int main() {
    int resp = 0;
    vector<Civilizacion*> civilizations;
    while (resp != 7) {
        cout << "- - MENÚ - -" << endl << "[1] Actualizar civilizaciones" << endl
             << "[1] Actualizar civilizaciones" << endl
             << "[2] Codificar desde programa" << endl
             << "[3] Decodificar desde programa" << endl
             << "[4] Codificar desde archivo" << endl
             << "[5] Decodificar desde archivo" << endl
             << "[6] Ver historial de mensajes" << endl
             << endl << "[7] Salir" << endl
             << "Ingrese el número correspondiente a su selección: ";

        cin >> resp;
        if (resp == 1) {
            string fileName = "InfoCiv.txt";
            cout << endl << "Actualizando civilizaciones..." << endl;
            ifstream inputFile;
            inputFile.open(fileName.c_str());
            if (!inputFile.is_open()) {
                cout << "El archivo no existe.." << endl;
            } else {
                string buffer;
                string name;
                string planet;
                string leader;
                int age;
                string type;
                while (!inputFile.eof()) {
                    getline(inputFile, buffer);
                    stringstream SSname;
                    stringstream SSplanet;
                    stringstream SSleader;
                    stringstream SSage;
                    stringstream SStype;
                    int cont = 0;
                    for (int i = 0; i < buffer.size(); i++) {
                        if (buffer[i] == '|') {
                            cont++;
                        } else {
                            if (cont == 0) {
                                SSname >> buffer[i];
                            } else if (cont == 1) {
                                SSplanet >> buffer[i];
                            } else if (cont == 2) {
                                SSleader >> buffer[i];
                            } else if (cont == 3) {
                                SSage >> buffer[i];
                            } else if (cont == 4) {
                                SStype >> buffer[i];
                            }
                        }
                        name = SSname.str();
                        planet = SSplanet.str();
                        leader = SSleader.str();
                        string age_string = SSage.str();
                        type = SStype.str();
                        age = stoi(age_string);

                        int typeint = 0;

                        if (type == "Civ_CC10") {
                            typeint = 1;
                        } else if (type == "Civ_BB01") {
                            typeint = 2;
                        } else if (type == "Civ_17ARZ") {
                            typeint = 3;
                        }

                        if (typeint == 1) {
                            CC10 *cc = new CC10 (name, planet, leader, age);
                            civilizations.push_back(cc);
                        } else if (typeint == 2) {
                            BB01 *bb = new BB01 (name, planet, leader, age);
                            civilizations.push_back(bb);
                        } else if (typeint == 3) {
                            c17ARZ *arz = new c17ARZ (name, planet, leader, age);
                            civilizations.push_back(arz);
                        }
                    }
                }
                inputFile.close();
                cout << "CIVILIZACIONES DISPONIBLES" << endl;
                for (auto &item : civilizations) {
                    cout << "-- " << item->getName() << endl;
                }
            }

        } else if (resp == 2) {
            string ogtext, newtext;
            int resp2 = 0;
            cout << "Ingrese un mensaje a codificar: ";
            getline(cin, ogtext);
            getline(cin, ogtext);
            cout << endl << "CIVILIZACIONES DISPONIBLES" << endl;
            for (int i = 0; i < civilizations.size(); ++i) {
                cout << i + 1 << civilizations.at(i)->getName() << endl;
            }
            cout << "Ingrese el número correspondiente: ";
            cin >> resp2;
            --resp2;
            string tempname = civilizations.at(resp2)->getName();
            for (auto &item : civilizations) {
                if (item->getName() == tempname) {
                    newtext = item->Code(ogtext);
                    addtoHistory(item, ogtext, newtext, "CODIFICACION DESDE PROGRAMA.");
                    break;
                }
            }
            cout << "Mensaje codificado: " << newtext << endl;
        } else if (resp == 3) {
            string ogtext, newtext;
            int resp2 = 0;
            cout << "Ingrese un mensaje a decodificar: ";
            getline(cin, ogtext);
            getline(cin, ogtext);
            cout << endl << "CIVILIZACIONES DISPONIBLES" << endl;
            for (int i = 0; i < civilizations.size(); ++i) {
                cout << i + 1 << civilizations.at(i)->getName() << endl;
            }
            cout << "Ingrese el número correspondiente: ";
            cin >> resp2;
            --resp2;
            string tempname = civilizations.at(resp2)->getName();
            for (auto &item : civilizations) {
                if (item->getName() == tempname) {
                    newtext = item->Decode(ogtext);
                    addtoHistory(item, ogtext, newtext, "DECODIFICACION DESDE PROGRAMA.");
                    break;
                }
            }
            cout << "Mensaje decodificado: " << newtext << endl;
        } else if (resp == 4) {
            ifstream archive;
            archive.open("TextoActual.txt", ios::in);
            string data, select;
            if (archive.fail()) {
                cout << "No se puedo abrir el archivo" << endl;
            }
            while (!archive.eof()) { //mientras no sea el final del archivo
                getline(archive, data);
                select += data + "\n";
            }
            archive.close();

            int resp2;
            string newtext;
            cout << endl << "CIVILIZACIONES DISPONIBLES" << endl;
            for (int i = 0; i < civilizations.size(); ++i) {
                cout << i + 1 << civilizations.at(i)->getName() << endl;
            }
            cout << "Ingrese el número correspondiente: ";
            cin >> resp2;
            --resp2;
            string tempname = civilizations.at(resp2)->getName();
            for (auto &item : civilizations) {
                if (item->getName() == tempname) {
                    newtext = item->Code(select);
                    addtoHistory(item, select, newtext, "CODIFICACION DESDE ARCHIVO.");
                    break;
                }
            }
            cout << "Mensaje codificado: " << newtext << endl;

        } else if (resp == 5) {
            ifstream archive;
            archive.open("TextoActual.txt", ios::in);
            string data, select;
            if (archive.fail()) {
                cout << "No se puedo abrir el archivo" << endl;
            }
            while (!archive.eof()) {
                getline(archive, data);
                select += data + "\n";
            }
            archive.close();

            int resp2;
            string newtext;
            cout << endl << "CIVILIZACIONES DISPONIBLES" << endl;
            for (int i = 0; i < civilizations.size(); ++i) {
                cout << i + 1 << civilizations.at(i)->getName() << endl;
            }
            cout << "Ingrese el número correspondiente: ";
            cin >> resp2;
            --resp2;
            string tempname = civilizations.at(resp2)->getName();
            for (auto &item : civilizations) {
                if (item->getName() == tempname) {
                    newtext = item->Decode(select);
                    addtoHistory(item, select, newtext, "DECODIFICACION DESDE ARCHIVO.");
                    break;
                }
            }
            cout << "Mensaje decodificado: " << newtext << endl;
        } else if (resp == 6) {
            ifstream archive;
            archive.open("HistorialMensajes.txt", ios::in);
            string data, select;
            if (archive.fail()) {
                cout << "No se puedo abrir el archivo" << endl;
            }
            while (!archive.eof()) {
                getline(archive, data);
                select += data + "\n";
            }
            cout<<select<<endl;
            archive.close();
        }
    }
}

void addtoHistory(Civilizacion* civ, string og, string newstr, string type) {
    ofstream file;
    file.open("HistorialMensajes.txt", std::ios::app);
    file<<endl<<civ->getName()<<", "<<type<<endl
        <<"Entrada:"<<endl
        <<og<<endl
        <<"Salida: "<<endl
        <<newstr<<endl
        <<"______________________________________________________"
        <<endl;
    file.close();
}


