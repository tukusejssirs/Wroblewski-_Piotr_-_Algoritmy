#Wroblewski Piotr - Algoritmy
Scannovanie a ocr-knutie danej knihy

Do pozornosti ju davam hlavne Vam, @siduska, @diduska, @zorvar, @norton1119, @janchvojka, kedze je jedna z odporucanych knih na Algoritmy a struktura udajov (hoci v *kodoch* ma vela chyb, v algoritmoch/texte vraj nie su). :)

## Programy / Dependencie
Pouzivam [scantailor(https://github.com/scantailor/scantailor) na post-processing obrazkov. Tento program vie otvorit subor [000_wroblewski.scantailor](scantailor/000_wroblewski.scantailor), ktory je textovy subor v xml-kovom formate (teda ho viete citat, no len vyssie uvedeny program ho vie spravne spracovat).

Dalej budem pouzivat program [tesseract](https://code.google.com/p/tesseract-ocr/) na konverziu obrazka na text.

## TODO

Alebo co sa ma vsetko spravit. :)

- [x] nascannovanie knihy,
- [x] oddelenie lavej a pravej strany z nascannovanej dvojstranky,
- [x] korekcia sklonu textu na strane,
- [ ] oznacenie obsahu strany (bez cmuh a okrajov),
- [ ] nastavenie bielych okrajov okolo vybraneho obsahu strany,
- [ ] vytvorenie  *.tif obrazkov opravenych podla vyssie uvedenych zmien,
- [ ] vytvorenie .pdf subory z *.tif suborov;
- [ ] pridanie metadat do .pdf subory pomocou programu `pdftk`;
- [ ] ocr-knutie *.tif suborov,
- [ ] vytvorenie .txt suboru obsahujuceho iba vsetok text knihy,
- [ ] ulozenie obrazov z *.tif suborov,
- [ ] vlozenie obrazkov na spravne miesto vramci textu (pomocou programu `lowriter` alebo v texu).
