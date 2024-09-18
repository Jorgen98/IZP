# Základy programovánı́ (IZP)
## Materiály k cvičeniam
Tento repozitár obsahuje prezentácie, ktoré používam počas počítačových cvičení spolu s riešeniami bodovaných úloh k jednotlivým cvičeniam. Riešenia bodovaných úloh budú nahrávané vždy na konci príslušného vyučovacieho týždňa.

## VS Code a Merlin
V rámci počítačový cvičení, ako aj riešenia projektov exituje veľké množstvo možností, ako tvoriť a testovať programy. Vzhľadom na to, že v prípade projektov sa často ako referenčný stroj pre testovanie uvádza školský server Merlin, rozhodol som sa spísať krátky návod, ako sa pomerne jednoducho a elegantne dajú programy tvoriť a testovať priamo na serveri s využitím VS Code a terminálu. Nie je to povinný, ani jediný správny postup. Je to jedna z možností, ako môžete tvoriť projekty.

Na tomto mieste je ale vhodné zdôrazniť, že zložitejšie a výpočtovo náročnejšie programy je dobré najskôr otestovať lokálne a až následne na školskom serveri. Ako presunúť svoje súbory na Merlin, aby ste ich mohli preložiť a otestovať nájdete napríklad [tu](https://www.fit.vut.cz/units/cvt/net/ssh.php) (Sekcia Putty).

 1. **Terminál**
     - Školský server Merlin disponuje vlastným terminálom, ku ktorému sa budeme pripájať. Avšak pre lokálny vývoj je jednoduchšie mať nainštalovaný a používať pre preklad a spustenie zdorojových súborov svoj terminál s nainštalovaným [`gcc`](https://gcc.gnu.org/)
	 - Ak máte Linux, alebo Subsystem for Linux (WSL), môžete tento bod jednoducho preskočiť
	 - Ak máte Windows a doteraz ste sa nestretli s terminálom, odporúčam vám nainštalovať si [Subsystem for Linux (WSL)](https://learn.microsoft.com/en-us/windows/wsl/install) a pozrieť si nejaké základné príkazy pre terminál
 3. **VS Code**
	 - Ďalej budete potrebovať nainštalované [VS Code](https://code.visualstudio.com/)
 4. **Pripojenie sa na Merlin**
     - Po spustení VS Code si na úvodnej obrazovke zvoľte možnosť `Connect to ...`, `Connect To Host` a `Add New SSH Host`
     - Zadáte príkaz so svojim xloginom pre pripojenie v tvare `ssh vasXLogin@merlin.fit.vutbr.cz`
     - Zvolíte si súbor, kam chcete konfiguráciu uložiť a následne sa pripojíte cez `Connect`
     - Ak všetko prebehlo správne, otvorí sa vám nové okno editora a po chvíli od vás bude vyžadovať heslo pre pripojenie. V tomto prípade sa jedná o heslo, ktoré používate vo **WIS** a nie vo **VUT IS**
     - Po úspešnom pripojení môžete skúsiť otvoriť nejaký priečinok, alebo pridať nový súbor priamo na serveri
 5. **Preklad a spustenie programu**
     - Cez možnosť `Terminal` si otvorte nový terminál, ktorý sa vám otvorí priamo na Merlinovi
     - Uistite sa, že ste v správnom priečinku a spustite preklad požadovaného .c súboru napríklad cez príkaz `gcc -std=c99 -Wall -Werror -g -o nazovProgramu nazovZdrojovehoSuboru.c`
     - Ak preklad prebehol úspešne, získali ste spustiteľný program, ktorý môžete otestovať pomocou `./nazovProgramu`
     - Tým ste otestovali svoj kód na referenčnom stroji a máte tak istotu, že bude odovzdané riešenie bude fungovať aj opravujúcemu

## Zaujímavé odkazy
[Advent of Code](https://adventofcode.com/) - zaujímavé programovacie hlavolamy

[CodeWars](https://www.codewars.com/) - učenie sa jazyka C na riešení príkladov so stúpajúcou zložitosťou

[Online kompiler pre jazyk C](https://www.programiz.com/c-programming/online-compiler/) - keď chcete niečo rýchlo otestovať

