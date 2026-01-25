### ⬛ Projet : Setting Up

**Le Défi :** Trouver le plus grand carré vide possible dans une carte contenant des obstacles, le plus rapidement possible.

**Utilisation :** Langage C, Makefile, Algorithmique.

* **Algorithme :** Analyse de la carte en un seul passage (**O(n)**). Chaque case stocke la taille du carré possible en fonction de ses carré-voisins (haut, gauche, haut-gauche).
* **Performance :** Gestion optimisée de la mémoire et pour lire rapidement des fichiers de plusieurs méga-octets.

**Exemple de résultat :**

| Carte d'entrée (Input) | Carte résolue (Output) |
| :--- | :--- |
| `...........................` <br> `....o......................` <br> `............o..............` <br> `...........................` <br> `...........................` <br> `.......o...................` | `...........................` <br> `....oxxxxx.................` <br> `.....xxxxx..o..............` <br> `.....xxxxx.................` <br> `.....xxxxx.................` <br> `.......o...................` |