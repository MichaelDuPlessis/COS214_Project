#include "Rocket.h"

Rocket::Rocket(LLStrategy* s) {
    strategy = s;
}
void Rocket::launch() {
    strategy->launch(); //calling concrete strategy launch and land, client chooses which rocket
}
void Rocket::land() {
    strategy->land();

}