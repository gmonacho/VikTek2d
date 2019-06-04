# Vik_Game2d

## LINKS
- UML : https://drive.google.com/drive/folders/1Iz2kLSk2R_jh3GFXZFUocJBbTZfJhiH
- https://preshing.com/20171218/how-to-write-your-own-cpp-game-engine/


# Norm 

## Les fonctions

Commence par une miniscule et chaque nouveau mot commence par une majuscule, pas d'underscore et noms explicites

**Exemple :**
```Cpp
myFonction()
{

}
```

## Les variables

Commence par une miniscule et chaque nouveaumot commence par une majuscule, pas d'underscore et noms explicites

**Exemple :**
 
- indices/index des tableaux **i_tab/i_str**
- nombre d'occurences : **int nb_occ**

## Les Classes

Commence par une majuscule et chaque nouveau mot commence par une majuscule, pas d'underscore et noms explicites

**Exemple :**

- prefixe attributs de classe **m_** (member)

- methodes comme les fonctions, noms logiques ex :

Classe : **Rectangle** -> Methode : **rectangle.drawColor** 

## Commentaires

Les commentaires ne doivent pas etre : 
	- dans les corps de fonctions/methodes
	- En fin ligne

Les commentaires doivent expliciter le fonctionnement des fonctions/methodes 

**Exemple :**

```Cpp
	/**
	 * ask if the key is pressed
	 * @param sdl_code
	 * @return true if the key is pressed or false if it is not
	 */
	bool                isKeyPressed(int sdl_code);
```

## Headers

Pas de namespace

Equivalent a la norme 42

