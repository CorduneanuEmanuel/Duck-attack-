# Duck attack!



Jocul este o incercare de a face o replica la mult cunoscutul video game Chicken Invaders!
Scopul jocului este sa impusti ratele si sa te feresti de ouale lor.
Ele se spawn-eaza la inceaput in numar de 40, iar cu cat le omori mai rapid, cu atata ele vor deveni mai rapide.
Stadiul proiectului: inca este in dezvoltare.

Avem o clasa de baza Entity care primeste functiile virtuale pure draw() si update(). Ele se ocupa cu desenarea si updatarea entitatii. update() s-ar putea sa fie scos din implementare.
Avem patru subclase ale clasei Entity: Bullet, Chicken, Player, Egg. Ele sunt concepute sa interactioneze intre ele. Daca un Egg atinge Player, atunci gameOver() si se afiseaza scorul in consola. Si la fel este pentru Bullet daca atinge o gaina(Chicken), atunci gaina dispare impreuna cu Bullet-ul.
Grafica este implementata in SFML.
Clasa Game se ocupa cu toata logica jocului. El creaza un std::vector<std::unique_ptr<Entity>> entities unde se adauga toate entitatile. Prin functii precum Game::movementChickens() se face un loop prin toate entitatile folosind upcasting/downcasting la Entity si se verifica pentru fiecare obiect prezent daca s-a petrecut un event.



**Ce trebuie sa mai fac: Exceptii, terminat grafica pentru celelalte obiecte(codul va fi echivalent cu cel din Chicken::draw(), trebuie schimbat doar 2-3 parametrii) si ce se intampla daca un obiect loveste alt obiect +  adaugat comentarii.**

**Bibliografie**
https://en.cppreference.com/w/
https://www.sfml-dev.org/
https://www.learncpp.com/
