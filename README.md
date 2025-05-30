# Duck attack!



Jocul este o incercare de a face o replica la mult cunoscutul joc video Chicken Invaders!
Scopul jocului este sa impusti ratele si sa te feresti de ouale lor.
Ele se spawn-eaza la inceaput in numar de 40, iar cu cat le omori mai rapid, cu atata ele vor deveni mai rapide.
Avem o clasa de baza Entity care primeste functiile virtuale pure draw() si update(). Ele se ocupa cu desenarea si updatarea entitatii. 
Avem patru subclase ale clasei Entity: Bullet, Chicken, Player, Egg. Ele sunt concepute sa interactioneze intre ele. Daca un Egg atinge Player, atunci gameOver() se declanseaza, pe urma se afiseaza scorul in consola. Si la fel este pentru Bullet daca atinge o gaina(Chicken), atunci gaina dispare impreuna cu Bullet-ul.
Grafica este implementata in SFML.
Clasa Game se ocupa cu toata logica jocului. El creaza un std::vector<std::unique_ptr<Entity>> entities unde se adauga toate entitatile. Prin functii precum Game::movementChickens() se face un loop prin toate entitatile folosind upcasting/downcasting la Entity si se verifica pentru fiecare obiect prezent daca s-a petrecut un event.

Functiile virtuale pure sunt draw() si update(). Ele sunt folosite pentru a desena obiectele pe ecran, respectiv pentru a le updata. Fiecare functie virtuale este implementata diferit fata de fiecare clasa derivata: au nevoie de parametrii diferiti fata de draw(), sunt marimi si date diferite, iar la update() sunt lucrururi care difera prin comportamentul fiecarei clase derivate, ex: gainile trebuie sa se genereze intr-un set de 40, daca toate gainile au fost eliminate, se actualizeaza nivelul, iar aruncarea oualor(Egg)  devine din ce in ce mai frecventa.

Pentru exceptii se trateaza diferite tipuri de erori. FileException pentru incarcarea imaginilor daca a avut esec, RenderException daca au fost intampinate probleme in incarcarea unor sprite-uri(a fost stearsa textura) sau Memory care verifica daca este memorie destula cand se creeaza un obiect; la un moment dat se creaza prea multe entitati, jocul se va distruge. FileException vede daca incarcarea unui obiect, ex:bullet, a avut succes, iar daca nu se inlocuieste cu un dreptunghi de culoare rosie. 

**Controale**: sageti(pentru miscare) + spacebar(pentru gloante)
**Scopul jocului este sa elimini ratele si sa castigi cat mai multe puncte.** 

***#Cerinte***

**#Clase de baza**
-Entity
-Game

**#Clase derivate**
-Bullet
-Chicken
-Egg
-Player

**#Functii virtuale**
draw()
update()

**#Exceptii**
FileException
RenderException
Memory

**Bibliografie**
https://en.cppreference.com/w/
https://www.sfml-dev.org/
https://www.learncpp.com/
https://stackoverflow.com/questions/7560114/random-number-c-in-some-range
https://discussions.unity.com/t/sinusoidal-movement-of-the-projectile/897760
