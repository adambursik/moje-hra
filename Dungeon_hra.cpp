#include <iostream>
#include <ctime>
#include <iomanip>
#include <conio.h>

using namespace std;
int pocet_souboju=0;
int pocet_vesnic_a_vylepseni=0;
int celkove_goldy=0;
struct Hrac{
string jmeno="nic";
int zlato=50;
int akt_hp=0;
int max_hp=0;
int max_dmg=0;
int akt_mn=0;
int max_mn=0;
int lvl;
    int akt_xp;
    int max_xp;
};
Hrac hrac;
double nasobkySchopnosti[4][3] = {
    {0.6, 1.1, 1.9},
    {0.7, 0.5, 2.1},
    {0.5, 1.2, 2.2},
    {0.65, 1.0, 1.8}
};

string nazvyUtoku[4][3] = {
    {"Zap", "FireBall", "Meteor Strike"},
    {"Sword", "Shield Bash", "Excalibur"},
    {"Knife", "Toxic Bomb", "Back stab"},
    {"Bow", "Poison Arrow", "BIG explosive Arrow"}
};

struct Monstrum {
    int id;
    string jmeno;
    int hp;
    int dmg;
    int zlato;
    int dmg2;
    int xp_drop;
    int max_hp;
};

Monstrum seznamMonster[18] = {
    {1, "Goblin Scout", 40, 10, 20, 0, 15, 40},
    {2, "Goblin Warrior", 60, 15, 35, 0, 25, 60},
    {3, "Goblin Archer", 45, 12, 30, 0, 20, 45},
    {4, "Goblin Merchant", 30, 2, 250, 0, 10, 30},
    {5, "Skeleton Pawn", 50, 12, 15, 0, 20, 50},
    {6, "Skeleton Warrior", 70, 18, 40, 0, 30, 70},
    {7, "Skeleton Archer", 55, 15, 30, 0, 25, 55},
    {8, "Zombie", 90, 8, 20, 0, 30, 90},
    {9, "Giant Rat", 35, 10, 10, 0, 12, 35},
    {10, "Cave Spider", 50, 14, 10, 0, 22, 50},
    {11, "Vampire Bat", 30, 12, 10, 0, 15, 30},
    {12, "Werewolf", 65, 20, 10, 0, 35, 65},
    {13, "Orc Scout", 70, 15, 50, 0, 40, 70},
    {14, "Orc Warrior", 110, 25, 100, 0, 60, 110},
    {15, "Goblin Miner", 60, 14, 75, 0, 35, 60},
    {16, "Slime", 40, 8, 10, 0, 10, 40},
    {17, "Drak (Miniboss)", 250, 30, 200, 20, 200, 250},
    {18, "Temny Rytir (Miniboss)", 240, 32, 190, 22, 180, 240}
};

struct ManaCost {
    int id;
    int basic;
    int ability;
    int super;
};

ManaCost seznamMANY[4] = {
    {1, 10, 40, 150},
    {2, 0, 30, 80},
    {3, 0, 50, 120},
    {4, 0, 45, 130}
};
void Statistiky(Hrac hrac) {
    system("cls");
    cout << "=====================================================================\n";
    cout << " HRDINA: " << setw(12) << left << hrac.jmeno
         << " LVL: " << setw(4) << hrac.lvl 
         << " XP: " << setw(7) << left << (to_string(hrac.akt_xp) + "/" + to_string(hrac.max_xp))
         << " |   ZLATO: " << hrac.zlato << " G\n";
    cout << " ZIVOTY: " << hrac.akt_hp << "/" << hrac.max_hp 
         << "   |   MANA: " << hrac.akt_mn << "/" << hrac.max_mn 
         << "   |   DMG: " << hrac.max_dmg << "\n";
    cout << "=====================================================================\n\n";
}
void boj_BOSS(int hrdina){
int boss_hp=1000;
int opakovani[4] = {0, 0, 0, 0};
int vyberKapitolu=0;
int udelenoBoss=0;
do{
    system("cls");
int dmg1_zaklad = pocet_souboju * 5;
    int dmg1_bonus = opakovani[0] * 25;

    int dmg2_zaklad = pocet_vesnic_a_vylepseni * 4;
    int dmg2_bonus = opakovani[1] * 25;

    int dmg3_zaklad = (hrac.lvl * 6) + 20;
    int dmg3_bonus = opakovani[2] * 25;

    int dmg4_zaklad = celkove_goldy / 20;
    int dmg4_bonus = opakovani[3] * 25;
Statistiky(hrac);
cout << "   ===================================================\n";
cout << "   ||                >> FINALNI BOSS <<             ||\n";
cout << "   ===================================================\n";
cout << "                        (O)===-(O)\n";
cout << "                        /  _   _  \\ \n";
cout << "                       |  (o) (o)  |\n";
cout << "                       |    < >    |\n";
cout << "                        \\ '-----' / \n";
cout << "                         \\_______/  \n";
cout << "   ===================================================\n";
cout << "     POTKAL JSI: Echoarbitera\n";
cout << "     HP: " << boss_hp << " / 1000\n";
cout << "   ===================================================\n\n";
cout << "   Boss promlouva: \"Vyber si svuj osud!\"\n";
    cout << "   [1] Souboje      ( " << dmg1_zaklad << " zaklad + " << dmg1_bonus << " bonus DMG )\n";
    cout << "   [2] Vesnice      ( " << dmg2_zaklad << " zaklad + " << dmg2_bonus << " bonus DMG )\n";
    cout << "   [3] Zkusenosti   ( " << dmg3_zaklad << " zaklad + " << dmg3_bonus << " bonus DMG )\n";
    cout << "   [4] Penize       ( " << dmg4_zaklad << " zaklad + " << dmg4_bonus << " bonus DMG )\n";
    cout << "   Volba: ";
    cin >> vyberKapitolu;

    switch (vyberKapitolu) {
        case 1:
            udelenoBoss = dmg1_zaklad + dmg1_bonus;
            opakovani[0]++;
            break;
        case 2:
            udelenoBoss = dmg2_zaklad + dmg2_bonus;
            opakovani[1]++;
            break;
        case 3:
            udelenoBoss = dmg3_zaklad + dmg3_bonus;
            opakovani[2]++;
            break;
        case 4:
            udelenoBoss = dmg4_zaklad + dmg4_bonus;
            opakovani[3]++;
            break;
        default:
            cout << "   Spatna volba! Pan Temnoty te tresta...\n";
            break;
    }
hrac.akt_hp -= udelenoBoss;

    cout << "   =========================================\n";
    cout << "             >> TAH MONSTRA <<              \n";
    cout << "   =========================================\n";
    cout << "    Pan Temnoty utoci tvym vlastnim osudem!\n";
    cout << "    Zasahl te za " << udelenoBoss << " DMG.\n";
    cout << "   -----------------------------------------\n";
    if (hrac.akt_hp < 0) hrac.akt_hp = 0;
    cout << "    Tvoje zbyvajici HP: " << hrac.akt_hp << "/" << hrac.max_hp << "\n";
    cout << "   =========================================\n\n";

    cout << "   Stiskni Enter pro svuj tah...";
    _getch();
    if (hrac.akt_hp <= 0) break;
int vyberAtck=0;
cout << "   =========================================\n";
    cout << "               >> TVUJ TAH <<               \n";
    cout << "   =========================================\n";
    cout << "   [1] " << nazvyUtoku[hrdina][0] << "  ( " << hrac.max_dmg * nasobkySchopnosti[hrdina][0] << " DMG, -" << seznamMANY[hrdina].basic << " MN)\n";
    cout << "   [2] " << nazvyUtoku[hrdina][1] << "  ( " << hrac.max_dmg * nasobkySchopnosti[hrdina][1] << " DMG, -" << seznamMANY[hrdina].ability << " MN)\n";
    cout << "   [3] " << nazvyUtoku[hrdina][2] << "  ( " << hrac.max_dmg * nasobkySchopnosti[hrdina][2] << " DMG, -" << seznamMANY[hrdina].super << " MN)\n";
    cout << "   Volba: ";
    cin >> vyberAtck;

    switch (vyberAtck) {
        case 1:
            if (hrac.akt_mn >= seznamMANY[hrdina].basic) {
                int dmg = hrac.max_dmg * nasobkySchopnosti[hrdina][0];
                boss_hp -= dmg;
                hrac.akt_mn -= seznamMANY[hrdina].basic;
                cout << "   Zasahli jsi bosse za " << dmg << " DMG.\n";
            } else cout << "   Nemas manu!\n";
            break;
        case 2:
            if (hrac.akt_mn >= seznamMANY[hrdina].ability) {
                int dmg = hrac.max_dmg * nasobkySchopnosti[hrdina][1];
                boss_hp -= dmg;
                hrac.akt_mn -= seznamMANY[hrdina].ability;
                cout << "   Zasahli jsi bosse za " << dmg << " DMG.\n";
            } else cout << "   Nemas manu!\n";
            break;
        case 3:
            if (hrac.akt_mn >= seznamMANY[hrdina].super) {
                int dmg = hrac.max_dmg * nasobkySchopnosti[hrdina][2];
                boss_hp -= dmg;
                hrac.akt_mn -= seznamMANY[hrdina].super;
                cout << "   Zasahli jsi bosse za " << dmg << " DMG.\n";
            } else cout << "   Nemas manu!\n";
            break;
        default:
            cout << "   Minul jsi!\n";
            break;
    }
    }while(hrac.akt_hp > 0 && boss_hp > 0);
    system("cls"); 
if (hrac.akt_hp <= 0) {
    cout << "====================================================\n";
    cout << "            Konec hry: ZEMREL JSI!                  \n";
    cout << "    Echoarbiter te porazil. Zkus to znovu.\n";
    cout << "====================================================\n";
} else if (boss_hp <= 0) {
   Statistiky(hrac);
    cout << "====================================================\n";
    cout << "              >> OBROVSKE VITEZSTVI! <<             \n";
    cout << "====================================================\n\n";
    
    cout << "             ___________             \n";
    cout << "            '._==_==_=_.'            \n";
    cout << "            .-\\:      /-.            \n";
    cout << "           | (|:.     |) |           \n";
    cout << "            '-|:.     |-'            \n";
    cout << "              \\::.    /              \n";
    cout << "               '::. .'               \n";
    cout << "                 ) (                 \n";
    cout << "               _.' '._               \n";
    cout << "              `\"\"\"\"\"\"\"`              \n\n";

    cout << "   Porazil jsi Pana Temnoty a zachranil svet!\n";
    cout << "   Dosahl jsi konce hry. Gratulujeme, hrdino.\n";
    cout << "====================================================\n";
}
cout << "\nStiskni Enter pro ukonceni hry...";
_getch();
}
void boj_monstra2(int hrdina){
int vyberAtck;
int vyberCil;
int protivnik_monstrum = rand() % 16;
int protivnik_monstrum_2;
do {
    protivnik_monstrum_2 = rand() % 16;
} while (protivnik_monstrum == protivnik_monstrum_2);

seznamMonster[protivnik_monstrum].hp = seznamMonster[protivnik_monstrum].max_hp;
seznamMonster[protivnik_monstrum_2].hp = seznamMonster[protivnik_monstrum_2].max_hp;
do{
do{
Statistiky(hrac);
cout << "   =========================================\n";
cout << "     POTKAL JSI: " << seznamMonster[protivnik_monstrum].jmeno <<" a "<<seznamMonster[protivnik_monstrum_2].jmeno<<endl;
cout << "     HP 1: " << seznamMonster[protivnik_monstrum].hp << " | DMG 1: " << seznamMonster[protivnik_monstrum].dmg << "\n";
cout << "     HP 2: " << seznamMonster[protivnik_monstrum_2].hp << " | DMG 2: " << seznamMonster[protivnik_monstrum_2].dmg << "\n";
cout << "   =========================================\n\n";
if(hrdina==1){
cout << "   [1] "<<nazvyUtoku[hrdina][0] <<"  ( "<<hrac.max_dmg * nasobkySchopnosti[hrdina][0]<<" DMG, -"<<seznamMANY[hrdina].basic<<" MN)\n";
cout << "   [2] "<<nazvyUtoku[hrdina][1] <<"  ( "<<hrac.max_dmg * nasobkySchopnosti[hrdina][1]<<" DMG, +15% HP, -"<<seznamMANY[hrdina].ability<<" MN)\n";
cout << "   [3] "<<nazvyUtoku[hrdina][2] <<"  ( "<<hrac.max_dmg * nasobkySchopnosti[hrdina][2]<<" DMG, -"<<seznamMANY[hrdina].super<<" MN)\n";
cout << "   Volba: ";
cin >> vyberAtck;
}else{    
cout << "   [1] "<<nazvyUtoku[hrdina][0] <<"  ( "<<hrac.max_dmg * nasobkySchopnosti[hrdina][0]<<" DMG, -"<<seznamMANY[hrdina].basic<<" MN)\n";
cout << "   [2] "<<nazvyUtoku[hrdina][1] <<"  ( "<<hrac.max_dmg * nasobkySchopnosti[hrdina][1]<<" DMG, -"<<seznamMANY[hrdina].ability<<" MN)\n";
cout << "   [3] "<<nazvyUtoku[hrdina][2] <<"  ( "<<hrac.max_dmg * nasobkySchopnosti[hrdina][2]<<" DMG, -"<<seznamMANY[hrdina].super<<" MN)\n";
cout << "   Volba: ";
cin >> vyberAtck;
}

if (vyberAtck >= 1 && vyberAtck <= 3) {
    cout << "   Na jake monstrum chces zautocit? (1 nebo 2): ";
    cin >> vyberCil;

    while ((vyberCil == 1 && seznamMonster[protivnik_monstrum].hp <= 0) || 
           (vyberCil == 2 && seznamMonster[protivnik_monstrum_2].hp <= 0) ||
           vyberCil < 1 || vyberCil > 2) {
        cout << "Spatny cil nebo monstrum je mrtve! Zadej platny cil (1 nebo 2): ";
        cin >> vyberCil;
    }
}
switch (vyberAtck)
{
case 1:
    if (hrac.akt_mn >= seznamMANY[hrdina].basic) {
        int udelenoDmg = hrac.max_dmg * nasobkySchopnosti[hrdina][0];
        if (vyberCil == 1) seznamMonster[protivnik_monstrum].hp -= udelenoDmg;
        else if (vyberCil == 2) seznamMonster[protivnik_monstrum_2].hp -= udelenoDmg;
        hrac.akt_mn -= seznamMANY[hrdina].basic;
        
        Statistiky(hrac);
        cout << "   =========================================\n";
        cout << "               >> TVUJ TAH <<               \n";
        cout << "   =========================================\n";
        cout << "    Pouzil jsi "<<nazvyUtoku[hrdina][0] <<"!\n";
        if (vyberCil == 1) cout << "    Zasahl jsi " << seznamMonster[protivnik_monstrum].jmeno << " za " << udelenoDmg << " DMG.\n";
        else if (vyberCil == 2) cout << "    Zasahl jsi " << seznamMonster[protivnik_monstrum_2].jmeno << " za " << udelenoDmg << " DMG.\n";
        cout << "   -----------------------------------------\n";
        if (seznamMonster[protivnik_monstrum].hp < 0) seznamMonster[protivnik_monstrum].hp = 0;
        if (seznamMonster[protivnik_monstrum_2].hp < 0) seznamMonster[protivnik_monstrum_2].hp = 0;
        cout << "    Zbyvajici HP 1. monstra: " << seznamMonster[protivnik_monstrum].hp << "\n";
        cout << "    Zbyvajici HP 2. monstra: " << seznamMonster[protivnik_monstrum_2].hp << "\n";
        cout << "   =========================================\n\n";
    } else {
        cout << "Nemas dostatek many pro tento utok!\n";
    }break;
    case 2:
    if (hrac.akt_mn >= seznamMANY[hrdina].ability) {
            if(hrdina==1){
        int udelenoDmg = hrac.max_dmg * nasobkySchopnosti[hrdina][1];
        if (vyberCil == 1) seznamMonster[protivnik_monstrum].hp -= udelenoDmg;
        else if (vyberCil == 2) seznamMonster[protivnik_monstrum_2].hp -= udelenoDmg;
        hrac.akt_mn -= seznamMANY[hrdina].ability;
        hrac.akt_hp+=hrac.max_hp*0.15;
        if (hrac.akt_hp>hrac.max_hp){
         hrac.akt_hp=hrac.max_hp;
        } 
        Statistiky(hrac);
        cout << "   =========================================\n";
        cout << "               >> TVUJ TAH <<               \n";
        cout << "   =========================================\n";
        cout << "    Pouzil jsi "<<nazvyUtoku[hrdina][1] <<"!\n";
        if (vyberCil == 1) cout << "    Zasahl jsi " << seznamMonster[protivnik_monstrum].jmeno << " za " << udelenoDmg << " DMG.\n";
        else if (vyberCil == 2) cout << "    Zasahl jsi " << seznamMonster[protivnik_monstrum_2].jmeno << " za " << udelenoDmg << " DMG.\n";
        cout << "    Dhealoval jsi se o 15%.\n";
        cout << "   -----------------------------------------\n";
        if (seznamMonster[protivnik_monstrum].hp < 0) seznamMonster[protivnik_monstrum].hp = 0;
        if (seznamMonster[protivnik_monstrum_2].hp < 0) seznamMonster[protivnik_monstrum_2].hp = 0;
        cout << "    Zbyvajici HP 1. monstra: " << seznamMonster[protivnik_monstrum].hp << "\n";
        cout << "    Zbyvajici HP 2. monstra: " << seznamMonster[protivnik_monstrum_2].hp << "\n";
        cout << "   =========================================\n\n";

        }else{
        int udelenoDmg = hrac.max_dmg * nasobkySchopnosti[hrdina][1];
        if (vyberCil == 1) seznamMonster[protivnik_monstrum].hp -= udelenoDmg;
        else if (vyberCil == 2) seznamMonster[protivnik_monstrum_2].hp -= udelenoDmg;
        hrac.akt_mn -= seznamMANY[hrdina].ability;
        
        Statistiky(hrac);
        cout << "   =========================================\n";
        cout << "               >> TVUJ TAH <<               \n";
        cout << "   =========================================\n";
        cout << "    Pouzil jsi "<<nazvyUtoku[hrdina][1] <<"!\n";
        if (vyberCil == 1) cout << "    Zasahl jsi " << seznamMonster[protivnik_monstrum].jmeno << " za " << udelenoDmg << " DMG.\n";
        else if (vyberCil == 2) cout << "    Zasahl jsi " << seznamMonster[protivnik_monstrum_2].jmeno << " za " << udelenoDmg << " DMG.\n";
        cout << "   -----------------------------------------\n";
        if (seznamMonster[protivnik_monstrum].hp < 0) seznamMonster[protivnik_monstrum].hp = 0;
        if (seznamMonster[protivnik_monstrum_2].hp < 0) seznamMonster[protivnik_monstrum_2].hp = 0;
        cout << "    Zbyvajici HP 1. monstra: " << seznamMonster[protivnik_monstrum].hp << "\n";
        cout << "    Zbyvajici HP 2. monstra: " << seznamMonster[protivnik_monstrum_2].hp << "\n";
        cout << "   =========================================\n\n";
        }
    } else {
        cout << "Nemas dostatek many pro tento utok!\n";}
    break;
case 3:
    if (hrac.akt_mn >= seznamMANY[hrdina].super) {
        int udelenoDmg = hrac.max_dmg * nasobkySchopnosti[hrdina][2];
        if (vyberCil == 1) seznamMonster[protivnik_monstrum].hp -= udelenoDmg;
        else if (vyberCil == 2) seznamMonster[protivnik_monstrum_2].hp -= udelenoDmg;
        hrac.akt_mn -= seznamMANY[hrdina].super;
        
        Statistiky(hrac);
        cout << "   =========================================\n";
        cout << "               >> TVUJ TAH <<               \n";
        cout << "   =========================================\n";
        cout << "    Pouzil jsi "<<nazvyUtoku[hrdina][2] <<"!\n";
        if (vyberCil == 1) cout << "    Zasahl jsi " << seznamMonster[protivnik_monstrum].jmeno << " za " << udelenoDmg << " DMG.\n";
        else if (vyberCil == 2) cout << "    Zasahl jsi " << seznamMonster[protivnik_monstrum_2].jmeno << " za " << udelenoDmg << " DMG.\n";
        cout << "   -----------------------------------------\n";
        if (seznamMonster[protivnik_monstrum].hp < 0) seznamMonster[protivnik_monstrum].hp = 0;
        if (seznamMonster[protivnik_monstrum_2].hp < 0) seznamMonster[protivnik_monstrum_2].hp = 0;
        cout << "    Zbyvajici HP 1. monstra: " << seznamMonster[protivnik_monstrum].hp << "\n";
        cout << "    Zbyvajici HP 2. monstra: " << seznamMonster[protivnik_monstrum_2].hp << "\n";
        cout << "   =========================================\n\n";
    } else {
        cout << "Nemas dostatek many pro tento utok!\n";
    }break;
default:
cout<<"BLBE ZADANE CISLO!!";
    break;}

cout << "   Stiskni Enter pro kolo monstra...";
_getch();
    }while(vyberAtck<=0||vyberAtck>=4);
Statistiky(hrac);

if (seznamMonster[protivnik_monstrum].hp <= 0 && seznamMonster[protivnik_monstrum_2].hp <= 0) {
    break;
}

int monstrumDmg1 = 0;
if (seznamMonster[protivnik_monstrum_2].hp > 0) {
    int monstrumsila1 = (rand() % 3) + 1;
    switch (monstrumsila1)
    {
    case 1:
        monstrumDmg1 = (seznamMonster[protivnik_monstrum_2].dmg*0.75);
        break;
    case 2:
        monstrumDmg1 = seznamMonster[protivnik_monstrum_2].dmg;
        break;
    case 3:
        monstrumDmg1 = (seznamMonster[protivnik_monstrum_2].dmg*1.25);
        break;
    default:cout<<"NEFAKAJI MONSTRA!!!!";
        break;
    }
}

int monstrumDmg = 0;
if (seznamMonster[protivnik_monstrum].hp > 0) {
    int monstrumsila = (rand() % 3) + 1;
    switch (monstrumsila)
    {
    case 1:
        monstrumDmg = (seznamMonster[protivnik_monstrum].dmg*0.75);
        break;
    case 2:
        monstrumDmg = seznamMonster[protivnik_monstrum].dmg;
        break;
    case 3:
        monstrumDmg = (seznamMonster[protivnik_monstrum].dmg*1.25);
        break;
    default:cout<<"NEFAKAJI MONSTRA!!!!";
        break;
    }
}

hrac.akt_hp -= (monstrumDmg + monstrumDmg1);
cout << "   =========================================\n";
cout << "             >> TAH MONSTRA <<              \n";
cout << "   =========================================\n";
if (seznamMonster[protivnik_monstrum].hp > 0 && seznamMonster[protivnik_monstrum_2].hp > 0) {
    cout << "    " << seznamMonster[protivnik_monstrum].jmeno <<" a "<<seznamMonster[protivnik_monstrum_2].jmeno <<" zvedaji svou zbran!\n";
} else if (seznamMonster[protivnik_monstrum].hp > 0) {
    cout << "    " << seznamMonster[protivnik_monstrum].jmeno <<" zveda svou zbran!\n";
} else if (seznamMonster[protivnik_monstrum_2].hp > 0) {
    cout << "    " << seznamMonster[protivnik_monstrum_2].jmeno <<" zveda svou zbran!\n";
}
cout << "    Zasahli te za " << monstrumDmg + monstrumDmg1 << " DMG.\n";
cout << "   -----------------------------------------\n";
if (hrac.akt_hp < 0) hrac.akt_hp = 0;
cout << "    Tvoje zbyvajici HP: " << hrac.akt_hp << "/" << hrac.max_hp << "\n";
cout << "   =========================================\n\n";

cout << "   Stiskni Enter pro dalsi kolo...";
_getch();

}while (hrac.akt_hp>0 && (seznamMonster[protivnik_monstrum].hp>0 || seznamMonster[protivnik_monstrum_2].hp>0));
system("cls");
    if (hrac.akt_hp <= 0) {
        cout << "=========================================\n";
        cout << "            Konec hry: ZEMREL JSI!       \n";
        cout << "=========================================\n";
        return;
    } 
    else if (seznamMonster[protivnik_monstrum].hp <= 0 && seznamMonster[protivnik_monstrum_2].hp<=0) {
        Statistiky(hrac);
        cout << "=========================================\n";
        cout << "            NEPRITEL PORAZEN!            \n";
        cout << "=========================================\n";
        
        hrac.akt_xp += seznamMonster[protivnik_monstrum].xp_drop;
        hrac.zlato += seznamMonster[protivnik_monstrum].zlato;
        hrac.akt_xp += seznamMonster[protivnik_monstrum_2].xp_drop;
        hrac.zlato += seznamMonster[protivnik_monstrum_2].zlato;     
        celkove_goldy += seznamMonster[protivnik_monstrum].zlato; 
        celkove_goldy += seznamMonster[protivnik_monstrum_2].zlato; 
        pocet_souboju+=2;     
        
        cout << " Ziskal jsi: " << seznamMonster[protivnik_monstrum].xp_drop + seznamMonster[protivnik_monstrum_2].xp_drop<< " XP\n";
        cout << " Ziskal jsi: " << seznamMonster[protivnik_monstrum].zlato + seznamMonster[protivnik_monstrum_2].zlato<< " G\n";
        cout << "=========================================\n";

        if (hrac.akt_xp >= hrac.max_xp) {
            hrac.lvl++;
            hrac.akt_xp -= hrac.max_xp;
            hrac.max_xp = hrac.max_xp * 1.5; 
            hrac.max_hp += 15;
            hrac.max_mn += 10;
            hrac.max_dmg += 5;
            hrac.akt_hp = hrac.max_hp;
            hrac.akt_mn = hrac.max_mn;
            
            cout << "\n=== LEVEL UP! ===\n";
            cout << " Nyni jsi level " << hrac.lvl << "!\n";
            cout << " Tvoje statistiky se zvysily!\n";
            cout << "=========================================\n";
        }
    }

    _getch();
}
void boj_monstra3(int hrdina){
int vyberAtck;
int vyberCil;
int protivnik_monstrum = rand() % 16;

int protivnik_monstrum_2;
do {
    protivnik_monstrum_2 = rand() % 16;
} while (protivnik_monstrum == protivnik_monstrum_2);

int protivnik_monstrum_3;
do {
    protivnik_monstrum_3 = rand() % 16;
} while (protivnik_monstrum_3 == protivnik_monstrum || protivnik_monstrum_3 == protivnik_monstrum_2);

seznamMonster[protivnik_monstrum].hp = seznamMonster[protivnik_monstrum].max_hp;
seznamMonster[protivnik_monstrum_2].hp = seznamMonster[protivnik_monstrum_2].max_hp;
seznamMonster[protivnik_monstrum_3].hp = seznamMonster[protivnik_monstrum_3].max_hp;
do{
do{
Statistiky(hrac);
cout << "   =========================================\n";
cout << "     POTKAL JSI: " << seznamMonster[protivnik_monstrum].jmeno <<", "<<seznamMonster[protivnik_monstrum_2].jmeno<<" a "<<seznamMonster[protivnik_monstrum_3].jmeno<<endl;
cout << "     HP 1: " << seznamMonster[protivnik_monstrum].hp << " | DMG 1: " << seznamMonster[protivnik_monstrum].dmg << "\n";
cout << "     HP 2: " << seznamMonster[protivnik_monstrum_2].hp << " | DMG 2: " << seznamMonster[protivnik_monstrum_2].dmg << "\n";
cout << "     HP 3: " << seznamMonster[protivnik_monstrum_3].hp << " | DMG 3: " << seznamMonster[protivnik_monstrum_3].dmg << "\n";
cout << "   =========================================\n\n";
if(hrdina==1){
cout << "   [1] "<<nazvyUtoku[hrdina][0] <<"  ( "<<hrac.max_dmg * nasobkySchopnosti[hrdina][0]<<" DMG, -"<<seznamMANY[hrdina].basic<<" MN)\n";
cout << "   [2] "<<nazvyUtoku[hrdina][1] <<"  ( "<<hrac.max_dmg * nasobkySchopnosti[hrdina][1]<<" DMG, +15% HP, -"<<seznamMANY[hrdina].ability<<" MN)\n";
cout << "   [3] "<<nazvyUtoku[hrdina][2] <<"  ( "<<hrac.max_dmg * nasobkySchopnosti[hrdina][2]<<" DMG, -"<<seznamMANY[hrdina].super<<" MN)\n";
cout << "   Volba: ";
cin >> vyberAtck;
}else{    
cout << "   [1] "<<nazvyUtoku[hrdina][0] <<"  ( "<<hrac.max_dmg * nasobkySchopnosti[hrdina][0]<<" DMG, -"<<seznamMANY[hrdina].basic<<" MN)\n";
cout << "   [2] "<<nazvyUtoku[hrdina][1] <<"  ( "<<hrac.max_dmg * nasobkySchopnosti[hrdina][1]<<" DMG, -"<<seznamMANY[hrdina].ability<<" MN)\n";
cout << "   [3] "<<nazvyUtoku[hrdina][2] <<"  ( "<<hrac.max_dmg * nasobkySchopnosti[hrdina][2]<<" DMG, -"<<seznamMANY[hrdina].super<<" MN)\n";
cout << "   Volba: ";
cin >> vyberAtck;
}

if (vyberAtck >= 1 && vyberAtck <= 3) {
    cout << "   Na jake monstrum chces zautocit? (1, 2 nebo 3): ";
    cin >> vyberCil;

    while ((vyberCil == 1 && seznamMonster[protivnik_monstrum].hp <= 0) || 
           (vyberCil == 2 && seznamMonster[protivnik_monstrum_2].hp <= 0) ||
           (vyberCil == 3 && seznamMonster[protivnik_monstrum_3].hp <= 0) ||
           vyberCil < 1 || vyberCil > 3) {
        cout << "Spatny cil nebo monstrum je mrtve! Zadej platny cil (1, 2 nebo 3): ";
        cin >> vyberCil;
    }
}

switch (vyberAtck)
{
case 1:
    if (hrac.akt_mn >= seznamMANY[hrdina].basic) {
        int udelenoDmg = hrac.max_dmg * nasobkySchopnosti[hrdina][0];
        if (vyberCil == 1) seznamMonster[protivnik_monstrum].hp -= udelenoDmg;
        else if (vyberCil == 2) seznamMonster[protivnik_monstrum_2].hp -= udelenoDmg;
        else if (vyberCil == 3) seznamMonster[protivnik_monstrum_3].hp -= udelenoDmg;
        hrac.akt_mn -= seznamMANY[hrdina].basic;
        
        Statistiky(hrac);
        cout << "   =========================================\n";
        cout << "               >> TVUJ TAH <<               \n";
        cout << "   =========================================\n";
        cout << "    Pouzil jsi "<<nazvyUtoku[hrdina][0] <<"!\n";
        if (vyberCil == 1) cout << "    Zasahl jsi " << seznamMonster[protivnik_monstrum].jmeno << " za " << udelenoDmg << " DMG.\n";
        else if (vyberCil == 2) cout << "    Zasahl jsi " << seznamMonster[protivnik_monstrum_2].jmeno << " za " << udelenoDmg << " DMG.\n";
        else if (vyberCil == 3) cout << "    Zasahl jsi " << seznamMonster[protivnik_monstrum_3].jmeno << " za " << udelenoDmg << " DMG.\n";
        cout << "   -----------------------------------------\n";
        if (seznamMonster[protivnik_monstrum].hp < 0) seznamMonster[protivnik_monstrum].hp = 0;
        if (seznamMonster[protivnik_monstrum_2].hp < 0) seznamMonster[protivnik_monstrum_2].hp = 0;
        if (seznamMonster[protivnik_monstrum_3].hp < 0) seznamMonster[protivnik_monstrum_3].hp = 0;
        cout << "    Zbyvajici HP 1. monstra: " << seznamMonster[protivnik_monstrum].hp << "\n";
        cout << "    Zbyvajici HP 2. monstra: " << seznamMonster[protivnik_monstrum_2].hp << "\n";
        cout << "    Zbyvajici HP 3. monstra: " << seznamMonster[protivnik_monstrum_3].hp << "\n";
        cout << "   =========================================\n\n";
    } else {
        cout << "Nemas dostatek many pro tento utok!\n";
    }break;
    case 2:
    if (hrac.akt_mn >= seznamMANY[hrdina].ability) {
            if(hrdina==1){
        int udelenoDmg = hrac.max_dmg * nasobkySchopnosti[hrdina][1];
        if (vyberCil == 1) seznamMonster[protivnik_monstrum].hp -= udelenoDmg;
        else if (vyberCil == 2) seznamMonster[protivnik_monstrum_2].hp -= udelenoDmg;
        else if (vyberCil == 3) seznamMonster[protivnik_monstrum_3].hp -= udelenoDmg;
        hrac.akt_mn -= seznamMANY[hrdina].ability;
        hrac.akt_hp+=hrac.max_hp*0.15;
        if (hrac.akt_hp>hrac.max_hp){
         hrac.akt_hp=hrac.max_hp;
        } 
        Statistiky(hrac);
        cout << "   =========================================\n";
        cout << "               >> TVUJ TAH <<               \n";
        cout << "   =========================================\n";
        cout << "    Pouzil jsi "<<nazvyUtoku[hrdina][1] <<"!\n";
        if (vyberCil == 1) cout << "    Zasahl jsi " << seznamMonster[protivnik_monstrum].jmeno << " za " << udelenoDmg << " DMG.\n";
        else if (vyberCil == 2) cout << "    Zasahl jsi " << seznamMonster[protivnik_monstrum_2].jmeno << " za " << udelenoDmg << " DMG.\n";
        else if (vyberCil == 3) cout << "    Zasahl jsi " << seznamMonster[protivnik_monstrum_3].jmeno << " za " << udelenoDmg << " DMG.\n";
        cout << "    Dhealoval jsi se o 15%.\n";
        cout << "   -----------------------------------------\n";
        if (seznamMonster[protivnik_monstrum].hp < 0) seznamMonster[protivnik_monstrum].hp = 0;
        if (seznamMonster[protivnik_monstrum_2].hp < 0) seznamMonster[protivnik_monstrum_2].hp = 0;
        if (seznamMonster[protivnik_monstrum_3].hp < 0) seznamMonster[protivnik_monstrum_3].hp = 0;
        cout << "    Zbyvajici HP 1. monstra: " << seznamMonster[protivnik_monstrum].hp << "\n";
        cout << "    Zbyvajici HP 2. monstra: " << seznamMonster[protivnik_monstrum_2].hp << "\n";
        cout << "    Zbyvajici HP 3. monstra: " << seznamMonster[protivnik_monstrum_3].hp << "\n";
        cout << "   =========================================\n\n";

        }else{
        int udelenoDmg = hrac.max_dmg * nasobkySchopnosti[hrdina][1];
        if (vyberCil == 1) seznamMonster[protivnik_monstrum].hp -= udelenoDmg;
        else if (vyberCil == 2) seznamMonster[protivnik_monstrum_2].hp -= udelenoDmg;
        else if (vyberCil == 3) seznamMonster[protivnik_monstrum_3].hp -= udelenoDmg;
        hrac.akt_mn -= seznamMANY[hrdina].ability;
        
        Statistiky(hrac);
        cout << "   =========================================\n";
        cout << "               >> TVUJ TAH <<               \n";
        cout << "   =========================================\n";
        cout << "    Pouzil jsi "<<nazvyUtoku[hrdina][1] <<"!\n";
        if (vyberCil == 1) cout << "    Zasahl jsi " << seznamMonster[protivnik_monstrum].jmeno << " za " << udelenoDmg << " DMG.\n";
        else if (vyberCil == 2) cout << "    Zasahl jsi " << seznamMonster[protivnik_monstrum_2].jmeno << " za " << udelenoDmg << " DMG.\n";
        else if (vyberCil == 3) cout << "    Zasahl jsi " << seznamMonster[protivnik_monstrum_3].jmeno << " za " << udelenoDmg << " DMG.\n";
        cout << "   -----------------------------------------\n";
        if (seznamMonster[protivnik_monstrum].hp < 0) seznamMonster[protivnik_monstrum].hp = 0;
        if (seznamMonster[protivnik_monstrum_2].hp < 0) seznamMonster[protivnik_monstrum_2].hp = 0;
        if (seznamMonster[protivnik_monstrum_3].hp < 0) seznamMonster[protivnik_monstrum_3].hp = 0;
        cout << "    Zbyvajici HP 1. monstra: " << seznamMonster[protivnik_monstrum].hp << "\n";
        cout << "    Zbyvajici HP 2. monstra: " << seznamMonster[protivnik_monstrum_2].hp << "\n";
        cout << "    Zbyvajici HP 3. monstra: " << seznamMonster[protivnik_monstrum_3].hp << "\n";
        cout << "   =========================================\n\n";
        }
    } else {
        cout << "Nemas dostatek many pro tento utok!\n";}
    break;
case 3:
    if (hrac.akt_mn >= seznamMANY[hrdina].super) {
        int udelenoDmg = hrac.max_dmg * nasobkySchopnosti[hrdina][2];
        if (vyberCil == 1) seznamMonster[protivnik_monstrum].hp -= udelenoDmg;
        else if (vyberCil == 2) seznamMonster[protivnik_monstrum_2].hp -= udelenoDmg;
        else if (vyberCil == 3) seznamMonster[protivnik_monstrum_3].hp -= udelenoDmg;
        hrac.akt_mn -= seznamMANY[hrdina].super;
        
        Statistiky(hrac);
        cout << "   =========================================\n";
        cout << "               >> TVUJ TAH <<               \n";
        cout << "   =========================================\n";
        cout << "    Pouzil jsi "<<nazvyUtoku[hrdina][2] <<"!\n";
        if (vyberCil == 1) cout << "    Zasahl jsi " << seznamMonster[protivnik_monstrum].jmeno << " za " << udelenoDmg << " DMG.\n";
        else if (vyberCil == 2) cout << "    Zasahl jsi " << seznamMonster[protivnik_monstrum_2].jmeno << " za " << udelenoDmg << " DMG.\n";
        else if (vyberCil == 3) cout << "    Zasahl jsi " << seznamMonster[protivnik_monstrum_3].jmeno << " za " << udelenoDmg << " DMG.\n";
        cout << "   -----------------------------------------\n";
        if (seznamMonster[protivnik_monstrum].hp < 0) seznamMonster[protivnik_monstrum].hp = 0;
        if (seznamMonster[protivnik_monstrum_2].hp < 0) seznamMonster[protivnik_monstrum_2].hp = 0;
        if (seznamMonster[protivnik_monstrum_3].hp < 0) seznamMonster[protivnik_monstrum_3].hp = 0;
        cout << "    Zbyvajici HP 1. monstra: " << seznamMonster[protivnik_monstrum].hp << "\n";
        cout << "    Zbyvajici HP 2. monstra: " << seznamMonster[protivnik_monstrum_2].hp << "\n";
        cout << "    Zbyvajici HP 3. monstra: " << seznamMonster[protivnik_monstrum_3].hp << "\n";
        cout << "   =========================================\n\n";
    } else {
        cout << "Nemas dostatek many pro tento utok!\n";
    }break;
default:
cout<<"BLBE ZADANE CISLO!!";
    break;}

cout << "   Stiskni Enter pro kolo monstra...";
_getch();
    }while(vyberAtck<=0||vyberAtck>=4);
Statistiky(hrac);

if (seznamMonster[protivnik_monstrum].hp <= 0 && seznamMonster[protivnik_monstrum_2].hp <= 0 && seznamMonster[protivnik_monstrum_3].hp <= 0) {
    break;
}

int monstrumDmg2 = 0;
if (seznamMonster[protivnik_monstrum_3].hp > 0) {
    int monstrumsila2 = (rand() % 3) + 1;
    switch (monstrumsila2)
    {
    case 1:
        monstrumDmg2 = (seznamMonster[protivnik_monstrum_3].dmg*0.75);
        break;
    case 2:
        monstrumDmg2 = seznamMonster[protivnik_monstrum_3].dmg;
        break;
    case 3:
        monstrumDmg2 = (seznamMonster[protivnik_monstrum_3].dmg*1.25);
        break;
    default:cout<<"NEFAKAJI MONSTRA!!!!";
        break;
    }
}

int monstrumDmg1 = 0;
if (seznamMonster[protivnik_monstrum_2].hp > 0) {
    int monstrumsila1 = (rand() % 3) + 1;
    switch (monstrumsila1)
    {
    case 1:
        monstrumDmg1 = (seznamMonster[protivnik_monstrum_2].dmg*0.75);
        break;
    case 2:
        monstrumDmg1 = seznamMonster[protivnik_monstrum_2].dmg;
        break;
    case 3:
        monstrumDmg1 = (seznamMonster[protivnik_monstrum_2].dmg*1.25);
        break;
    default:cout<<"NEFAKAJI MONSTRA!!!!";
        break;
    }
}

int monstrumDmg = 0;
if (seznamMonster[protivnik_monstrum].hp > 0) {
    int monstrumsila = (rand() % 3) + 1;
    switch (monstrumsila)
    {
    case 1:
        monstrumDmg = (seznamMonster[protivnik_monstrum].dmg*0.75);
        break;
    case 2:
        monstrumDmg = seznamMonster[protivnik_monstrum].dmg;
        break;
    case 3:
        monstrumDmg = (seznamMonster[protivnik_monstrum].dmg*1.25);
        break;
    default:cout<<"NEFAKAJI MONSTRA!!!!";
        break;
    }
}

hrac.akt_hp -= (monstrumDmg + monstrumDmg1 + monstrumDmg2);
cout << "   =========================================\n";
cout << "             >> TAH MONSTRA <<              \n";
cout << "   =========================================\n";
cout << "    Ziva monstra zvedaji svou zbran!\n";
cout << "    Zasahli te za " << monstrumDmg + monstrumDmg1 + monstrumDmg2 << " DMG.\n";
cout << "   -----------------------------------------\n";
if (hrac.akt_hp < 0) hrac.akt_hp = 0;
cout << "    Tvoje zbyvajici HP: " << hrac.akt_hp << "/" << hrac.max_hp << "\n";
cout << "   =========================================\n\n";

cout << "   Stiskni Enter pro dalsi kolo...";
_getch();

}while (hrac.akt_hp>0 && (seznamMonster[protivnik_monstrum].hp>0 || seznamMonster[protivnik_monstrum_2].hp>0 || seznamMonster[protivnik_monstrum_3].hp>0));
system("cls");
    if (hrac.akt_hp <= 0) {
        cout << "=========================================\n";
        cout << "            Konec hry: ZEMREL JSI!       \n";
        cout << "=========================================\n";
        return;
    } 
    else if (seznamMonster[protivnik_monstrum].hp <= 0 && seznamMonster[protivnik_monstrum_2].hp<=0 && seznamMonster[protivnik_monstrum_3].hp<=0) {
        Statistiky(hrac);
        cout << "=========================================\n";
        cout << "            NEPRITEL PORAZEN!            \n";
        cout << "=========================================\n";
        
        hrac.akt_xp += seznamMonster[protivnik_monstrum].xp_drop;
        hrac.zlato += seznamMonster[protivnik_monstrum].zlato;
        hrac.akt_xp += seznamMonster[protivnik_monstrum_2].xp_drop;
        hrac.zlato += seznamMonster[protivnik_monstrum_2].zlato;        
        hrac.akt_xp += seznamMonster[protivnik_monstrum_3].xp_drop;
        hrac.zlato += seznamMonster[protivnik_monstrum_3].zlato; 
        celkove_goldy += seznamMonster[protivnik_monstrum].zlato;   
        celkove_goldy += seznamMonster[protivnik_monstrum_2].zlato;  
        celkove_goldy += seznamMonster[protivnik_monstrum_3].zlato;  
        pocet_souboju+=3;       
        
        cout << " Ziskal jsi: " << seznamMonster[protivnik_monstrum].xp_drop + seznamMonster[protivnik_monstrum_2].xp_drop + seznamMonster[protivnik_monstrum_3].xp_drop<< " XP\n";
        cout << " Ziskal jsi: " << seznamMonster[protivnik_monstrum].zlato + seznamMonster[protivnik_monstrum_2].zlato + seznamMonster[protivnik_monstrum_3].zlato<< " G\n";
        cout << "=========================================\n";

        if (hrac.akt_xp >= hrac.max_xp) {
            hrac.lvl++;
            hrac.akt_xp -= hrac.max_xp;
            hrac.max_xp = hrac.max_xp * 1.5; 
            hrac.max_hp += 15;
            hrac.max_mn += 10;
            hrac.max_dmg += 5;
            hrac.akt_hp = hrac.max_hp;
            hrac.akt_mn = hrac.max_mn;
            
            cout << "\n=== LEVEL UP! ===\n";
            cout << " Nyni jsi level " << hrac.lvl << "!\n";
            cout << " Tvoje statistiky se zvysily!\n";
            cout << "=========================================\n";
        }
    }

    _getch();
}

void boj_miniboss(int hrdina){
int vyberAtck;
int protivnik_monstrum = (rand ()%2)+16;
seznamMonster[protivnik_monstrum].hp=seznamMonster[protivnik_monstrum].max_hp;
Statistiky(hrac);
cout << "   =========================================\n";
cout << "     POTKAL JSI: " << seznamMonster[protivnik_monstrum].jmeno << "\n";
cout << "   =========================================\n";
cout << "   Stiskni Enter pro zacatek boje...";
_getch();
do{
Statistiky(hrac);
cout << "   =========================================\n";
cout << "             >> TAH MONSTRA <<              \n";
cout << "   =========================================\n";
int monstrumsila = (rand() % 3) + 1;
int monstrumDmg = 0;
switch (monstrumsila)
{
case 1:
    monstrumDmg = (seznamMonster[protivnik_monstrum].dmg*0.75);
    break;
case 2:
    monstrumDmg = seznamMonster[protivnik_monstrum].dmg;
    break;
case 3:
    monstrumDmg = (seznamMonster[protivnik_monstrum].dmg*1.25);
    break;
default:cout<<"NEFAKAJI MONSTRA!!!!";
    break;
}
hrac.akt_hp -= monstrumDmg;
cout << "    " << seznamMonster[protivnik_monstrum].jmeno << " zveda svou zbran!\n";
cout << "    Zasahl te za " << monstrumDmg << " DMG.\n";
cout << "   -----------------------------------------\n";
if (hrac.akt_hp < 0) hrac.akt_hp = 0;
cout << "    Tvoje zbyvajici HP: " << hrac.akt_hp << "/" << hrac.max_hp << "\n";
cout << "   =========================================\n\n";
cout << "   Stiskni Enter pro svuj tah...";
_getch();
if (hrac.akt_hp <= 0) break;
do{
Statistiky(hrac);
cout << "   =========================================\n";
cout << "     POTKAL JSI: " << seznamMonster[protivnik_monstrum].jmeno << "\n";
cout << "     HP: " << seznamMonster[protivnik_monstrum].hp << " | DMG: " << seznamMonster[protivnik_monstrum].dmg << "\n";
cout << "   =========================================\n\n";
if(hrdina==1){
cout << "   [1] "<<nazvyUtoku[hrdina][0] <<"  ( "<<hrac.max_dmg * nasobkySchopnosti[hrdina][0]<<" DMG, -"<<seznamMANY[hrdina].basic<<" MN)\n";
cout << "   [2] "<<nazvyUtoku[hrdina][1] <<"  ( "<<hrac.max_dmg * nasobkySchopnosti[hrdina][1]<<" DMG, +15% HP, -"<<seznamMANY[hrdina].ability<<" MN)\n";
cout << "   [3] "<<nazvyUtoku[hrdina][2] <<"  ( "<<hrac.max_dmg * nasobkySchopnosti[hrdina][2]<<" DMG, -"<<seznamMANY[hrdina].super<<" MN)\n";
cout << "   Volba: ";
cin >> vyberAtck;
}else{    
cout << "   [1] "<<nazvyUtoku[hrdina][0] <<"  ( "<<hrac.max_dmg * nasobkySchopnosti[hrdina][0]<<" DMG, -"<<seznamMANY[hrdina].basic<<" MN)\n";
cout << "   [2] "<<nazvyUtoku[hrdina][1] <<"  ( "<<hrac.max_dmg * nasobkySchopnosti[hrdina][1]<<" DMG, -"<<seznamMANY[hrdina].ability<<" MN)\n";
cout << "   [3] "<<nazvyUtoku[hrdina][2] <<"  ( "<<hrac.max_dmg * nasobkySchopnosti[hrdina][2]<<" DMG, -"<<seznamMANY[hrdina].super<<" MN)\n";
cout << "   Volba: ";
cin >> vyberAtck;
}
switch (vyberAtck)
{
case 1:
    if (hrac.akt_mn >= seznamMANY[hrdina].basic) {
        int udelenoDmg = hrac.max_dmg * nasobkySchopnosti[hrdina][0];
        seznamMonster[protivnik_monstrum].hp -= udelenoDmg;
        hrac.akt_mn -= seznamMANY[hrdina].basic;
        Statistiky(hrac);
        cout << "   =========================================\n";
        cout << "               >> TVUJ TAH <<               \n";
        cout << "   =========================================\n";
        cout << "    Pouzil jsi "<<nazvyUtoku[hrdina][0] <<"!\n";
        cout << "    Zasahl jsi " << seznamMonster[protivnik_monstrum].jmeno << " za " << udelenoDmg << " DMG.\n";
        cout << "   -----------------------------------------\n";
        if (seznamMonster[protivnik_monstrum].hp < 0) seznamMonster[protivnik_monstrum].hp = 0;
        cout << "    Zbyvajici HP monstra: " << seznamMonster[protivnik_monstrum].hp << "\n";
        cout << "   =========================================\n\n";
    } else {
        cout << "Nemas dostatek many pro tento utok!\n";
    }break;
    case 2:
    if (hrac.akt_mn >= seznamMANY[hrdina].ability) {
        int udelenoDmg = hrac.max_dmg * nasobkySchopnosti[hrdina][1];
        seznamMonster[protivnik_monstrum].hp -= udelenoDmg;
        hrac.akt_mn -= seznamMANY[hrdina].ability;
          if(hrdina==1){
        hrac.akt_hp+=hrac.max_hp*0.15;
        if (hrac.akt_hp>hrac.max_hp){
         hrac.akt_hp=hrac.max_hp;
        } 
        Statistiky(hrac);
        cout << "   =========================================\n";
        cout << "               >> TVUJ TAH <<               \n";
        cout << "   =========================================\n";
        cout << "    Pouzil jsi "<<nazvyUtoku[hrdina][1] <<"!\n";
        cout << "    Zasahl jsi " << seznamMonster[protivnik_monstrum].jmeno << " za " << udelenoDmg << " DMG.\n";
        cout << "    Dhealoval jsi se o 15%.\n";
        cout << "   -----------------------------------------\n";
        if (seznamMonster[protivnik_monstrum].hp < 0) seznamMonster[protivnik_monstrum].hp = 0;
        cout << "    Zbyvajici HP monstra: " << seznamMonster[protivnik_monstrum].hp << "\n";
        cout << "   =========================================\n\n";
        }else{
        Statistiky(hrac);
        cout << "   =========================================\n";
        cout << "               >> TVUJ TAH <<               \n";
        cout << "   =========================================\n";
        cout << "    Pouzil jsi "<<nazvyUtoku[hrdina][1] <<"!\n";
        cout << "    Zasahl jsi " << seznamMonster[protivnik_monstrum].jmeno << " za " << udelenoDmg << " DMG.\n";
        cout << "   -----------------------------------------\n";
        if (seznamMonster[protivnik_monstrum].hp < 0) seznamMonster[protivnik_monstrum].hp = 0;
        cout << "    Zbyvajici HP monstra: " << seznamMonster[protivnik_monstrum].hp << "\n";
        cout << "   =========================================\n\n";
        }
    } else {
        cout << "Nemas dostatek many pro tento utok!\n";}
    break;
case 3:
    if (hrac.akt_mn >= seznamMANY[hrdina].super) {
        int udelenoDmg = hrac.max_dmg * nasobkySchopnosti[hrdina][2];
        seznamMonster[protivnik_monstrum].hp -= udelenoDmg;
        hrac.akt_mn -= seznamMANY[hrdina].super;
        Statistiky(hrac);
        cout << "   =========================================\n";
        cout << "               >> TVUJ TAH <<               \n";
        cout << "   =========================================\n";
        cout << "    Pouzil jsi "<<nazvyUtoku[hrdina][2] <<"!\n";
        cout << "    Zasahl jsi " << seznamMonster[protivnik_monstrum].jmeno << " za " << udelenoDmg << " DMG.\n";
        cout << "   -----------------------------------------\n";
        if (seznamMonster[protivnik_monstrum].hp < 0) seznamMonster[protivnik_monstrum].hp = 0;
        cout << "    Zbyvajici HP monstra: " << seznamMonster[protivnik_monstrum].hp << "\n";
        cout << "   =========================================\n\n";
    } else {
        cout << "Nemas dostatek many pro tento utok!\n";}
        break;
default:
cout<<"BLBE ZADANE CISLO!!";
    break;}
cout << "   Stiskni Enter...";
_getch();
    }while(vyberAtck<=0||vyberAtck>=4);
}while (hrac.akt_hp>0 && seznamMonster[protivnik_monstrum].hp>0);
system("cls");
    if (hrac.akt_hp <= 0) {
        cout << "=========================================\n";
        cout << "            Konec hry: ZEMREL JSI!       \n";
        cout << "=========================================\n";
        return;
    } 
    else if (seznamMonster[protivnik_monstrum].hp <= 0) {
        Statistiky(hrac);
        cout << "=========================================\n";
        cout << "            NEPRITEL PORAZEN!            \n";
        cout << "=========================================\n";
        hrac.akt_xp += seznamMonster[protivnik_monstrum].xp_drop;
        hrac.zlato += seznamMonster[protivnik_monstrum].zlato;
        celkove_goldy += seznamMonster[protivnik_monstrum].zlato; 
        cout << " Ziskal jsi: " << seznamMonster[protivnik_monstrum].xp_drop << " XP\n";
        cout << " Ziskal jsi: " << seznamMonster[protivnik_monstrum].zlato << " G\n";
        cout << "=========================================\n";
        if (hrac.akt_xp >= hrac.max_xp) {
            hrac.lvl++;
            hrac.akt_xp -= hrac.max_xp;
            hrac.max_xp = hrac.max_xp * 1.5; 
            hrac.max_hp += 15;
            hrac.max_mn += 10;
            hrac.max_dmg += 5;
            hrac.akt_hp = hrac.max_hp;
            hrac.akt_mn = hrac.max_mn;
            cout << "\n=== LEVEL UP! ===\n";
            cout << " Nyni jsi level " << hrac.lvl << "!\n";
            cout << " Tvoje statistiky se zvysily!\n";
            cout << "=========================================\n";
        }
    }
    _getch();
}

void boj_monstra(int hrdina){
int vyberAtck;
int protivnik_monstrum = rand ()%16;
seznamMonster[protivnik_monstrum].hp=seznamMonster[protivnik_monstrum].max_hp;
do{
do{
Statistiky(hrac);
cout << "   =========================================\n";
cout << "     POTKAL JSI: " << seznamMonster[protivnik_monstrum].jmeno << "\n";
cout << "     HP: " << seznamMonster[protivnik_monstrum].hp << " | DMG: " << seznamMonster[protivnik_monstrum].dmg << "\n";
cout << "   =========================================\n\n";
if(hrdina==1){
cout << "   [1] "<<nazvyUtoku[hrdina][0] <<"  ( "<<hrac.max_dmg * nasobkySchopnosti[hrdina][0]<<" DMG, -"<<seznamMANY[hrdina].basic<<" MN)\n";
cout << "   [2] "<<nazvyUtoku[hrdina][1] <<"  ( "<<hrac.max_dmg * nasobkySchopnosti[hrdina][1]<<" DMG, +15% HP, -"<<seznamMANY[hrdina].ability<<" MN)\n";
cout << "   [3] "<<nazvyUtoku[hrdina][2] <<"  ( "<<hrac.max_dmg * nasobkySchopnosti[hrdina][2]<<" DMG, -"<<seznamMANY[hrdina].super<<" MN)\n";
cout << "   Volba: ";
cin >> vyberAtck;
}else{    
cout << "   [1] "<<nazvyUtoku[hrdina][0] <<"  ( "<<hrac.max_dmg * nasobkySchopnosti[hrdina][0]<<" DMG, -"<<seznamMANY[hrdina].basic<<" MN)\n";
cout << "   [2] "<<nazvyUtoku[hrdina][1] <<"  ( "<<hrac.max_dmg * nasobkySchopnosti[hrdina][1]<<" DMG, -"<<seznamMANY[hrdina].ability<<" MN)\n";
cout << "   [3] "<<nazvyUtoku[hrdina][2] <<"  ( "<<hrac.max_dmg * nasobkySchopnosti[hrdina][2]<<" DMG, -"<<seznamMANY[hrdina].super<<" MN)\n";
cout << "   Volba: ";
cin >> vyberAtck;
}
switch (vyberAtck)
{
case 1:
    if (hrac.akt_mn >= seznamMANY[hrdina].basic) {
        int udelenoDmg = hrac.max_dmg * nasobkySchopnosti[hrdina][0];
        seznamMonster[protivnik_monstrum].hp -= udelenoDmg;
        hrac.akt_mn -= seznamMANY[hrdina].basic;
        
        Statistiky(hrac);
        cout << "   =========================================\n";
        cout << "               >> TVUJ TAH <<               \n";
        cout << "   =========================================\n";
        cout << "    Pouzil jsi "<<nazvyUtoku[hrdina][0] <<"!\n";
        cout << "    Zasahl jsi " << seznamMonster[protivnik_monstrum].jmeno << " za " << udelenoDmg << " DMG.\n";
        cout << "   -----------------------------------------\n";
        if (seznamMonster[protivnik_monstrum].hp < 0) seznamMonster[protivnik_monstrum].hp = 0;
        cout << "    Zbyvajici HP monstra: " << seznamMonster[protivnik_monstrum].hp << "\n";
        cout << "   =========================================\n\n";
    } else {
        cout << "Nemas dostatek many pro tento utok!\n";
    }break;
    case 2:
    if (hrac.akt_mn >= seznamMANY[hrdina].ability) {
            if(hrdina==1){
        int udelenoDmg = hrac.max_dmg * nasobkySchopnosti[hrdina][1];
        seznamMonster[protivnik_monstrum].hp -= udelenoDmg;
        hrac.akt_mn -= seznamMANY[hrdina].ability;
        hrac.akt_hp+=hrac.max_hp*0.15;
        if (hrac.akt_hp>hrac.max_hp){
         hrac.akt_hp=hrac.max_hp;
        } 
        Statistiky(hrac);
        cout << "   =========================================\n";
        cout << "               >> TVUJ TAH <<               \n";
        cout << "   =========================================\n";
        cout << "    Pouzil jsi "<<nazvyUtoku[hrdina][1] <<"!\n";
        cout << "    Zasahl jsi " << seznamMonster[protivnik_monstrum].jmeno << " za " << udelenoDmg << " DMG.\n";
        cout << "    Dhealoval jsi se o 15%.\n";
        cout << "   -----------------------------------------\n";
        if (seznamMonster[protivnik_monstrum].hp < 0) seznamMonster[protivnik_monstrum].hp = 0;
        cout << "    Zbyvajici HP monstra: " << seznamMonster[protivnik_monstrum].hp << "\n";
        cout << "   =========================================\n\n";

        }else{
        int udelenoDmg = hrac.max_dmg * nasobkySchopnosti[hrdina][1];
        seznamMonster[protivnik_monstrum].hp -= udelenoDmg;
        hrac.akt_mn -= seznamMANY[hrdina].ability;
        
        Statistiky(hrac);
        cout << "   =========================================\n";
        cout << "               >> TVUJ TAH <<               \n";
        cout << "   =========================================\n";
        cout << "    Pouzil jsi "<<nazvyUtoku[hrdina][1] <<"!\n";
        cout << "    Zasahl jsi " << seznamMonster[protivnik_monstrum].jmeno << " za " << udelenoDmg << " DMG.\n";
        cout << "   -----------------------------------------\n";
        if (seznamMonster[protivnik_monstrum].hp < 0) seznamMonster[protivnik_monstrum].hp = 0;
        cout << "    Zbyvajici HP monstra: " << seznamMonster[protivnik_monstrum].hp << "\n";
        cout << "   =========================================\n\n";
        }
    } else {
        cout << "Nemas dostatek many pro tento utok!\n";}
    break;
case 3:
    if (hrac.akt_mn >= seznamMANY[hrdina].super) {
        int udelenoDmg = hrac.max_dmg * nasobkySchopnosti[hrdina][2];
        seznamMonster[protivnik_monstrum].hp -= udelenoDmg;
        hrac.akt_mn -= seznamMANY[hrdina].super;
        
        Statistiky(hrac);
        cout << "   =========================================\n";
        cout << "               >> TVUJ TAH <<               \n";
        cout << "   =========================================\n";
        cout << "    Pouzil jsi "<<nazvyUtoku[hrdina][2] <<"!\n";
        cout << "    Zasahl jsi " << seznamMonster[protivnik_monstrum].jmeno << " za " << udelenoDmg << " DMG.\n";
        cout << "   -----------------------------------------\n";
        if (seznamMonster[protivnik_monstrum].hp < 0) seznamMonster[protivnik_monstrum].hp = 0;
        cout << "    Zbyvajici HP monstra: " << seznamMonster[protivnik_monstrum].hp << "\n";
        cout << "   =========================================\n\n";
    } else {
        cout << "Nemas dostatek many pro tento utok!\n";}
        break;
default:
cout<<"BLBE ZADANE CISLO!!";
    break;}

cout << "   Stiskni Enter pro kolo monstra...";
_getch();
    }while(vyberAtck<=0||vyberAtck>=4);
Statistiky(hrac);
if (seznamMonster[protivnik_monstrum].hp <= 0) {
    break;
}
int monstrumsila = (rand() % 3) + 1;
int monstrumDmg = 0;
switch (monstrumsila)
{
case 1:
    monstrumDmg = (seznamMonster[protivnik_monstrum].dmg*0.75);
    break;
case 2:
    monstrumDmg = seznamMonster[protivnik_monstrum].dmg;
    break;
case 3:
    monstrumDmg = (seznamMonster[protivnik_monstrum].dmg*1.25);
    break;

default:cout<<"NEFAKAJI MONSTRA!!!!";
    break;
}

hrac.akt_hp -= monstrumDmg;
cout << "   =========================================\n";
cout << "             >> TAH MONSTRA <<              \n";
cout << "   =========================================\n";
cout << "    " << seznamMonster[protivnik_monstrum].jmeno << " zveda svou zbran!\n";
cout << "    Zasahl te za " << monstrumDmg << " DMG.\n";
cout << "   -----------------------------------------\n";
if (hrac.akt_hp < 0) hrac.akt_hp = 0;
cout << "    Tvoje zbyvajici HP: " << hrac.akt_hp << "/" << hrac.max_hp << "\n";
cout << "   =========================================\n\n";

cout << "   Stiskni Enter pro dalsi kolo...";
_getch();

}while (hrac.akt_hp>0 && seznamMonster[protivnik_monstrum].hp>0);
system("cls");
    if (hrac.akt_hp <= 0) {
        cout << "=========================================\n";
        cout << "            Konec hry: ZEMREL JSI!       \n";
        cout << "=========================================\n";
        return;
    } 
    else if (seznamMonster[protivnik_monstrum].hp <= 0) {
        Statistiky(hrac);
        cout << "=========================================\n";
        cout << "            NEPRITEL PORAZEN!            \n";
        cout << "=========================================\n";
        
        hrac.akt_xp += seznamMonster[protivnik_monstrum].xp_drop;
        hrac.zlato += seznamMonster[protivnik_monstrum].zlato;
        celkove_goldy += seznamMonster[protivnik_monstrum].zlato; 
        pocet_souboju++;
        
        cout << " Ziskal jsi: " << seznamMonster[protivnik_monstrum].xp_drop << " XP\n";
        cout << " Ziskal jsi: " << seznamMonster[protivnik_monstrum].zlato << " G\n";
        cout << "=========================================\n";

        if (hrac.akt_xp >= hrac.max_xp) {
            hrac.lvl++;
            hrac.akt_xp -= hrac.max_xp;
            hrac.max_xp = hrac.max_xp * 1.5; 
            hrac.max_hp += 15;
            hrac.max_mn += 10;
            hrac.max_dmg += 5;
            hrac.akt_hp = hrac.max_hp;
            hrac.akt_mn = hrac.max_mn;
            
            cout << "\n=== LEVEL UP! ===\n";
            cout << " Nyni jsi level " << hrac.lvl << "!\n";
            cout << " Tvoje statistiky se zvysily!\n";
            cout << "=========================================\n";
        }
    }

    _getch();
}

void mesto() {
int pokracovat=0;
int nakup_vybaveni=0;
int vyberves=0;
do{
    do{
        Statistiky(hrac);
cout<< " - - - MESTO - - - ";
cout<<endl;
cout<<"Vyberte co chcete delat ve vesnici.\n";
cout << "  " << setw(5) << left << "[1]" << setw(30) << left << "NAKUP VYBAVENI" << setw(25) << right << "( -150G +25 DMG/HP )" << endl;
cout << "  " << setw(5) << left << "[2]" << setw(30) << left << "UZDRAVENI" << setw(25) << right << "( -30G + fullHP )" << endl;
cout << "  " << setw(5) << left << "[3]" << setw(30) << left << "VYLEPSENI UTOKU / SCHOPNOSTI" << setw(25) << right << "( -250G +45 DMG )" << endl;
cout << "  " << setw(5) << left << "[4]" << setw(30) << left << "VYLEPSENI MANY" << setw(25) << right << "( -100G +70 MN )" << endl;
cout << "  " << setw(5) << left << "[5]" << setw(30) << left << "VYLEPSENI MAX ZIVOTU" << setw(25) << right << "( -200G +70 maxHP )" << endl;
cout << "  " << setw(5) << left << "[6]" << "NIC, JIT PRYC\n";
cout<< "Volba: ";

cin>>vyberves;
switch (vyberves){
            case 1:
            if (hrac.zlato >= 150){
                do{
                    cout<<"Vybrali jste si NAKUP VYBAVENI\n\n";
                    cout<<setw(10)<<"[1] Koupje zbrane: +25 DMG\n";
                    cout<<setw(10)<<"[2] Koupje brneni: +25 HP\n";
                    cin>>nakup_vybaveni;
                    if(nakup_vybaveni==1){ hrac.max_dmg+=25; hrac.zlato-=150; }
                    if(nakup_vybaveni==2){ hrac.akt_hp+=25; hrac.max_hp+=10; hrac.zlato-=150; }
                    pocet_vesnic_a_vylepseni++;
                } while (nakup_vybaveni!=1&&nakup_vybaveni!=2);
            }else { cout << "Nemas dost zlata!\n"; }
            break;
            case 2:
            if (hrac.zlato >= 30) { hrac.akt_hp = hrac.max_hp; hrac.zlato -= 30; } else { cout << "Nemas dost zlata!\n"; }
            cout<<"Vybrali jste si UZDRAVENI\n";
            pocet_vesnic_a_vylepseni++;
            break;
            case 3:
            if (hrac.zlato >= 250) {hrac.max_dmg += 45; hrac.zlato -= 250; } else { cout << "Nemas dost zlata!\n"; }
            cout<<"Vybrali jste si VYLEPSENI UTOKU / SCHOPNOSTI\n";
            pocet_vesnic_a_vylepseni++;
            break;
            case 4:
            if (hrac.zlato >= 100) { hrac.akt_mn += 70; hrac.max_mn += 70; hrac.zlato -= 100; } else { cout << "Nemas dost zlata!\n"; }
            cout<<"Vybrali jste si VYLEPSENI MANY\n";
            pocet_vesnic_a_vylepseni++;
            break;
            case 5:
            if (hrac.zlato >= 200) { hrac.akt_hp += 80; hrac.max_hp+=70; hrac.zlato -= 200; } else { cout << "Nemas dost zlata!\n"; }
            cout<<"Vybrali jste si VYLEPSENI MAX ZIVOTU\n";
            pocet_vesnic_a_vylepseni++;
            break;
            case 6:
            cout<<"Nic nechcete.... \n";
            break;
            default:
            cout<<"SPATNE zadana hodnota!\n";
        }
    }while(vyberves<=0||vyberves>=7);
    
    cout<<"Chcete pokracovat v nakupu (ANO=1, NE=2): ";
    cin>>pokracovat;
}while(pokracovat==1);
pocet_vesnic_a_vylepseni++;
}
void vesnice () {
int pokracovat=0;
int nakup_vybaveni=0;
int vyberves=0;
do{
    do{
        Statistiky(hrac);
cout<< " - - - VESNICE - - - ";
cout<<endl;
cout<<"Vyberte co chcete delat ve vesnici.\n";
cout << "  " << setw(5) << left << "[1]" << setw(30) << left << "NAKUP VYBAVENI" << setw(25) << right << "( -80G +10 DMG/HP )" << endl;
cout << "  " << setw(5) << left << "[2]" << setw(30) << left << "UZDRAVENI" << setw(25) << right << "( -15G + fullHP )" << endl;
cout << "  " << setw(5) << left << "[3]" << setw(30) << left << "VYLEPSENI UTOKU / SCHOPNOSTI" << setw(25) << right << "( -120G +20 DMG )" << endl;
cout << "  " << setw(5) << left << "[4]" << setw(30) << left << "VYLEPSENI MANY" << setw(25) << right << "( -50G +30 MN )" << endl;
cout << "  " << setw(5) << left << "[5]" << setw(30) << left << "VYLEPSENI MAX ZIVOTU" << setw(25) << right << "( -100G +30 maxHP )" << endl;
cout << "  " << setw(5) << left << "[6]" << "NIC, JIT PRYC\n";
cout<< "Volba: ";

cin>>vyberves;
switch (vyberves){
            case 1:
            if (hrac.zlato >= 80){
                do{
                    cout<<"Vybrali jste si NAKUP VYBAVENI\n\n";
                    cout<<setw(10)<<"[1] Koupje zbrane: +10 DMG\n";
                    cout<<setw(10)<<"[2] Koupje brneni: +10 HP\n";
                    cin>>nakup_vybaveni;
                    if(nakup_vybaveni==1){ hrac.max_dmg+=10; hrac.zlato-=80; }
                    if(nakup_vybaveni==2){ hrac.akt_hp+=10; hrac.max_hp+=10; hrac.zlato-=80; }
                    pocet_vesnic_a_vylepseni++;
                } while (nakup_vybaveni!=1&&nakup_vybaveni!=2);
            }else { cout << "Nemas dost zlata!\n"; }
            break;
            case 2:
            if (hrac.zlato >= 15) { hrac.akt_hp = hrac.max_hp; hrac.zlato -= 15; } else { cout << "Nemas dost zlata!\n"; }
            cout<<"Vybrali jste si UZDRAVENI\n";
            pocet_vesnic_a_vylepseni++;
            break;
            case 3:
            if (hrac.zlato >= 120) {hrac.max_dmg += 20; hrac.zlato -= 120; } else { cout << "Nemas dost zlata!\n"; }
            cout<<"Vybrali jste si VYLEPSENI UTOKU / SCHOPNOSTI\n";
            pocet_vesnic_a_vylepseni++;
            break;
            case 4:
            if (hrac.zlato >= 50) { hrac.akt_mn += 30; hrac.max_mn += 30; hrac.zlato -= 50; } else { cout << "Nemas dost zlata!\n"; }
            cout<<"Vybrali jste si VYLEPSENI MANY\n";
            pocet_vesnic_a_vylepseni++;
            break;
            case 5:
            if (hrac.zlato >= 100) { hrac.akt_hp += 30; hrac.max_hp+=30; hrac.zlato -= 100; } else { cout << "Nemas dost zlata!\n"; }
            cout<<"Vybrali jste si VYLEPSENI MAX ZIVOTU\n";
            pocet_vesnic_a_vylepseni++;
            break;
            case 6:
            cout<<"Nic nechcete.... \n";
            break;
            default:
            cout<<"SPATNE zadana hodnota!\n";
        }
    }while(vyberves<=0||vyberves>=7);
    
    cout<<"Chcete pokracovat v nakupu (ANO=1, NE=2): ";
    cin>>pokracovat;
}while(pokracovat==1);
pocet_vesnic_a_vylepseni++;
}
int main(){
    system("cls");
    int vybertyp=0;
    int pokracovattyp=1;
srand(time(0));
    string typy[4] = {"Mage", "Warrior", "Assasin", "Archer"};

    int staty[4][3] = {
        {80, 80, 300},
        {150, 50, 100},
        {40, 100, 150},
        {80, 70, 200}
    };  
    do{
        do {
system("cls");
        cout << " ============================================================\n";
        cout << "                      VYBER SI CLASSU                       \n";
        cout << " ============================================================\n\n";

        for(int i = 0; i < 4; i++) { cout << "      [" << i + 1 << "]      "; } 
        cout << "\n ------------------------------------------------------------\n";
        
        for(int i = 0; i < 4; i++) { cout << "    " << setw(11) << left << typy[i]; } 
        cout << "\n\n";
        
        for(int i = 0; i < 4; i++) { cout << "    " << setw(3) << right << staty[i][0] << " HP     "; } 
        cout << "\n";
        for(int i = 0; i < 4; i++) { cout << "    " << setw(3) << right << staty[i][1] << " DMG    "; } 
        cout << "\n";
        for(int i = 0; i < 4; i++) { cout << "    " << setw(3) << right << staty[i][2] << " MN     "; } 
        cout << "\n";
        
        cout << "\n ============================================================\n";
        cout << " Volba: ";
        cin >> vybertyp;


switch (vybertyp) {
    case 1:
        cout << "Vybral sis classu: Mage\n";
        break;
    case 2:
        cout << "Vybral sis classu: Warrior\n";
        break;
    case 3:
        cout << "Vybral sis classu: Assasin\n";
        break;
    case 4:
        cout << "Vybral sis classu: Archer\n";
        break;
    default:
        cout << "Neznama classa!\n";
        break;
}
} while (vybertyp<1||vybertyp>4);

            cout << "\nChcete si vybrat jinou postavu? ( ANO=1 , NE=2 ): ";
            cin >> pokracovattyp;

            if (pokracovattyp < 1 || pokracovattyp > 2) {
                cout << "SPATNE ZADANA HODNOTA!! Zadej 1 nebo 2." << endl;
            }
                    } while (pokracovattyp == 1);

hrac.jmeno = typy[vybertyp-1];
hrac.akt_hp = staty[vybertyp-1][0];
hrac.max_hp = staty[vybertyp-1][0];

hrac.max_dmg = staty[vybertyp-1][1];

hrac.akt_mn = staty[vybertyp-1][2];
hrac.max_mn = staty[vybertyp-1][2];

hrac.lvl = 1;
hrac.akt_xp = 0;
hrac.max_xp = 100;

Statistiky (hrac);
    vesnice();
    int pokrok=0;
    int fight=0;
    int cislo_boss=(rand()%6)+15;
    bool hraBezi = true;
    while(hraBezi){
if (pokrok >= cislo_boss) {
        fight = 6;
    } else if (pokrok < 5) {
        fight = rand() % 3;
    } else {
        fight = rand() % 6;
    }
    switch (fight)
    {
    case 0:
        vesnice();
        break;
    case 1:
    boj_monstra (vybertyp-1);
    break;
    case 2:
    boj_monstra2 (vybertyp-1);
    break;
    case 3:
    boj_monstra3(vybertyp-1);
    break;
    case 4:
    boj_miniboss(vybertyp-1);
    break;
    case 5:
    mesto();
    break;
    case 6:
    boj_BOSS(vybertyp-1);
    return 0;
    default:
    cout<<"Nefunguje main nahodny!!!";
        break;
    }
    
    pokrok++;
    if (hrac.akt_hp <= 0 || fight == 6) {
        hraBezi = false;
    }    
}
    return 0;
}