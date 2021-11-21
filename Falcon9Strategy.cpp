#include "Falcon9Strategy.h"

Falcon9Strategy::Falcon9Strategy() {

}
void Falcon9Strategy::launch() {
    cout << "Falcon Nine is Launching. " << endl;
}
void Falcon9Strategy::land() {
    cout << "Falcon Nine is Landing. " << endl;
}

string Falcon9Strategy::getKind() { return "F9"; }