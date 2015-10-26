#Wroblewski Piotr - Algoritmy
Scannovanie a ocr-knutie danej knihy

Do pozornosti ju davam hlavne Vam, @siduska, @diduska, @zorvar, @norton1119, @janchvojka, kedze je jedna z odporucanych knih na Algoritmy a struktura udajov (hoci v *kodoch* ma vela chyb, v algoritmoch/texte vraj nie su). :)

## Pouzite programy
- `scantailor`<br>
  Pouzivam [scantailor(https://github.com/scantailor/scantailor) na post-processing obrazkov. Tento program vie otvorit subor [000_wroblewski.scantailor](scantailor/000_wroblewski.scantailor), ktory je textovy subor v xml-kovom formate (teda ho viete citat, no len vyssie uvedeny program ho vie spravne spracovat).
- `tesseract`<br>
  Dalej budem pouzivat program [tesseract](https://code.google.com/p/tesseract-ocr/) na konverziu obrazka na text.
- `exiftool`<br>
  Pomocou programu `exiftool` viem upravovat metadata roznych suborov (kukni i tento [link](http://askubuntu.com/questions/27381/how-to-edit-pdf-metadata-from-command-line)). V Debian-like distribuciach sa da nainstalovat pomocou `sudo apt-get -yq install libimage-exiftool-perl` a v Arch-like distribuciach `pacman -S --noconfirm perl-image-exiftool`.

## TODO

Alebo co sa ma vsetko spravit. :)

- [x] nascannovanie knihy,
- [x] oddelenie lavej a pravej strany z nascannovanej dvojstranky,
- [x] korekcia sklonu textu na strane,
- [ ] oznacenie obsahu strany (bez cmuh a okrajov),
- [ ] nastavenie bielych okrajov okolo vybraneho obsahu strany,
- [ ] vytvorenie  *.tif obrazkov opravenych podla vyssie uvedenych zmien,
- [ ] vytvorenie .pdf subory z *.tif suborov;
- [ ] pridanie metadat do .pdf subory pomocou programu `exiftool`;
- [ ] opravenie tabuliek,
- [ ] ocr-knutie *.tif suborov,
- [ ] vytvorenie .txt suboru obsahujuceho iba vsetok text knihy,
- [ ] ulozenie obrazov z *.tif suborov,
- [ ] vlozenie obrazkov na spravne miesto vramci textu (pomocou programu `lowriter` alebo v texu).
