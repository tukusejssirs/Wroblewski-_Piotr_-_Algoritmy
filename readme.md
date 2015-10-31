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
- [x] oznacenie obsahu strany (bez cmuh a okrajov),
- [x] nastavenie bielych okrajov okolo vybraneho obsahu strany,
- [x] vytvorenie  *.tif obrazkov opravenych podla vyssie uvedenych zmien,
- [x] vytvorenie [.pdf suborov](pdf_output/) z *.tif suborov;
- [ ] pridanie metadat do .pdf subory pomocou programu `exiftool`;
- [ ] opravenie tabuliek,
- [ ] ocr-knutie *.tif suborov,
- [ ] vytvorenie .txt suboru obsahujuceho iba vsetok text knihy,
- [ ] ulozenie obrazov z *.tif suborov,
- [ ] vlozenie obrazkov na spravne miesto vramci textu (pomocou programu `lowriter` alebo v texu).

## Ked zistite bug, o ktorom sa nepise v [Knows Bugs](https://github.com/tukusejssirs/Wroblewski_Piotr_-_Algoritmy/blob/master/readme.md#known-bugs)?
Ked zistite, ze som sa niekde pomylil abo ze niktora cast je necitatelna, prip. chybaju nejake pismenka (alebo iny druh bugu, ktory nesuvisi s chybami v *povodnom* texte), prosim, otvorte novu [issue](https://github.com/tukusejssirs/Wroblewski_Piotr_-_Algoritmy/issues) a co najpodobrobnejsie popiste dany bug, prip. uploadnite obrazok danej chyby.

## Known Bugs
Alebo zname chyby.

1. Ciara pod hlavickou chyba, pretoze je svedlo seda/siva a tak mi ju automaticky odstranoval `scantailor`. Riesenim je oznacit (citaj: oramuj) ju na kazdej strane ako obrazok, co sa mi zda ako kontraproduktivne, kedze mojim cielom nie je dostat dokonalu elektronicku kopiu vytlacenej knihy. ;)

2. Pozadie za `kodmi` nie je sive/sede (alebo je, no len ciastocne) z tej istej priciny KB1. :)

3. Velkost stran v uz sprocesovanych obrazkoch (a aj z nich vytvorenom pdf-ku) je sice rovnaka, avsak nie je to ziaden zo standardizovanych formatov (teda ani A4, ani A5, ani Letter/List, …). mohol som sa s tym pohrat pomocou programu `composite` od ImageMagick-ku (ako som sa s tym pohral v [Spievatku](https://github.com/tukusejssirs/eSpievatko/raw/master/spievatko_0.1.3.pdf) pomocou prikazu `convert xc:white -page A4 myout.pdf && convert -density 600x600 myout.pdf white.tif && rm -rf myout.pdf && composite -gravity center -gravity north -geometry +0+500 input.tif white.tif output.tif`), no tu som to nepovazoval za az take dolezite. :)

4. Text (resp obdlznik, v ktorom sa nachadza vsetok text a obrazky na jednej strane) nie je zarovnany na vsetkych stranach rovnako, hoci som sa trochu snazil zmiernit rozdiel v zarovnani. Dovody: (1) Znova, v programe `scantailor` nie je moznost vybrat si hranu/ciarnu zarovnania (napr. strana s piktogramom v marginalnej casti je zarovnana *s* piktogramom, avsak strana bez piktogramu je zarovnana zaciatkom textu). (2) Text (mysliac tym uz vyssie opisany blok textu) nema rovnaky rozmer na kazdej strane. Riesenie by si vyzadovalo enormne mnozstvo casu a kopia ‘jedna k jednej’ (ako som uz spomenul v KB3) nie je mojim zamerom. :)
