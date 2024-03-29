# VikTek2d

## Objectif

Developper un moteur de jeu 2d simple d'utilisation non limitant, a fin de convenir au maximum de type de jeu possible. Le moteur sera specialise dans certain type une fois la partie general termine.

## LINKS
- UML : https://drive.google.com/drive/folders/1Iz2kLSk2R_jh3GFXZFUocJBbTZfJhiH
- https://preshing.com/20171218/how-to-write-your-own-cpp-game-engine/
VS
- https://www.gamasutra.com/blogs/MichaelKissner/20151027/257369/Writing_a_Game_Engine_from_Scratch__Part_1_Messaging.php

# Norm

## CppLint Norm

Except "-whitespace/braces", "-readability/braces", "-whitespace/newline".
we favor (to improve readability <3):
```cpp
funcion()
{
  //  ...
}

if ()
{
  //  ...
}
else
{
  //  ...
}
```
than :

```cpp
funcion() {
  //  ...
}

if () {
  //  ...
} else {
  //  ...
}
```

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

- setter introduits par set :
**setVariable(param, ...)**

- getter introduits par get :
**getVariable()**

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

