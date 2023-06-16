# Samoprieseky
Na vytvorenie grafov som zaznamenal súradnice bodov do súboru sur.csv a vykreslil ich na webovej stránke https://www.dcode.fr/points-plotter, pretože sa mi nepodarilo správne nainštalovať cairo.

Program je potrebné ešte vylepšiť

Uloha 7.11.1: V rovine je svojimi vrcholmi dan´y n-uholn´ık. Naprogramujte fun-
kciu, ktor´a over´ı, ˇci tento n-uholn´ık obsahuje alebo neobsahuje samoprieseky.
Funkcia bude mat’ prototyp:

• char uholnik_testuj_samoprieseky(float *x, float *y, unsigned int n)

Cez argument n si funkcia prevezme poˇcet vrcholov n-uholn´ıka. Postupnosti x-
ov´ych a y-ov´ych s´uradn´ıc vrcholov reprezentovan´e hodnotami typu float si pre-
vezme na adres´ach x a y. Ak funkcia v n-uholn´ıku samopriesek n´ajde, vr´ati hod-
notu SAMOPRIESEK_ANO v opaˇcnom pr´ıpade vr´ati hodnotu SAMOPRIESEK_NIE.
