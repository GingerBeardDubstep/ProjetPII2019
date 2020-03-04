# PPII "Projet Pluridisciplinaire d'Informatique Intégrative" (2018-2019)


## Préliminaires 

Ce projet est divisé en 3 phases. Le descriptif précis de chaque phase vous sera communiqué de manière incrémentale au fur et à mesure du déroulé du projet.

### Objectifs et Attendus

- Réalisation d'une étude bibliographique
- Conception et mise en d’œuvre d’une base de données
- Réalisations de plusieurs composants logiciels informatiques dans
les langages de programmation C et Java
- Évaluation de la qualité de la solution proposée et des résultats
obtenus 

### Modalités

Ce projet est à réaliser en groupe (la constitution du groupe étant imposée). 

Vos livrables seront composés :
- des codes sources de vos développements logiciels ; 
- des documentations nécessaires à la compréhension (conception, notes de développement), l'installation, la compilation, l'exécution, la validations de vos réalisations ;
- de **tous les éléments de gestion de projet** que vous aurez produits (comptes-rendus de réunion, planification et répartition des tâches, analyse post-mortem des efforts individuels et de l'atteinte des objectifs, etc.)

L'ensemble de ces livrables seront déposés sur le dépôt git qui sera dédie à votre groupe de travail (sous-projet du projet https://gitlab.telecomnancy.univ-lorraine.fr/ppii-2k19) 


**Nota Bene.** Ne trichez pas ! Ne copiez pas ! Ne plagiez pas ! Si vous le faites, vous serez lourdement sanctionnés. Nous ne ferons pas de distinction entre copieur et copié. Vous n’avez pas de (bonnes) raisons de copier. De même, vous ne devez pas utiliser un produit clé en main trouvé sur internet.


### Livraison continue du sujet

Le sujet *le plus à jour* sera disponible dans la branche `DoW` (*description of work*) de votre dépôt git hébergé sur la plateforme GitLab de l'école (https://gitlab.telecomnancy.univ-lorraine.fr/) sous la forme du fichier `DOW.md`.

Vous devrez donc régulièrement (vous en serez informé avant) fusionner la branche `DoW` avec votre branche principale `master` afin de disposer du sujet à jour dans votre branche principale de travail.

**Attention.** Vous ne devrez jamais commiter de modifications dans la branche `DoW`. Cette branche étant automatiquement écrasée lors de la mise à jour du sujet, vous risqueriez de perdre vos modifications.


## Thématique du projet

Ce projet conserve le même thème d'étude que le projet du module TOP du premier semestre : Le transport aérien et les données de vols.

Les données du projet repose en majeure partie (mais pas seulement) sur les données ouvertes du site https://openflights.org/data.html.

## Étape 1 : Gestion de données [SQL]

**Date de communication** : 28 Mars 2019

**Date de rendu** : 23 avril 2019

### Objectifs généraux

- Concevoir un schéma de base de données relationnelle stockant des données de transport aérien variées
- Implémenter ce schéma relationnel dans le SGBD Oracle
- Élaborer des requêtes SQL sur le schéma relationnel 

### Données à intégrer

Le répertoire `provided_data/` contient plusieurs fichiers de données :
- [airport.dat](./provided_data/airports.dat)
  - provenance :  OpenFlights.org - https://openflights.org/data.html#airport
  - description : Liste de 7543 aéroports (nom, ville, pays, code IATA, code ICAO, longitude, latitude, etc.)

- [airlines.date](./provided_data/airlines.dat)
  - provenance :  OpenFlights.org - https://openflights.org/data.html#airline
  - description : Liste de 6162 compagnies aériennes (nom, code IATA, code ICAO, Pays, Indicatif, etc.)

- [planes.dat](./provided_data/planes.dat)
  - provenance : OpenFlights.org - https://openflights.org/data.html#plane
  - description : Liste de 174 avions (nom, code IATA, code ICAO)

- [routes.dat](./provided_data/routes.dat)
  - provenance : OpenFlights.org - https://openflights.org/data.html#route
  - description : Liste de 67663 vols (code la compagnie aérienne, numéro du vol, aéroport de départ, aéroport d'arrivée, avions utilisés)

- [flightnumbers.csv](./provided_data/flightnumbers.csv)
  - provenance: Virtual Server Radar - http://www.virtualradarserver.co.uk/FlightRoutes.aspx
  - description : Liste de 303,799 vols aériens (code la compagnie aérienne, numéro du vol, description de la route)

Vous serez ammené à nettoyer ces données afin de pouvoir les intégrer.

Il vous est demandé de compléter ces données, dans la mesure du possible, par des données (que vous rechercherez par vous-même) sur les alliances entre les compagnies aériennes (https://fr.wikipedia.org/wiki/Alliance_de_compagnies_a%C3%A9riennes) et sur les caractéristiques des avions utilisées (nombre de passagers, autonomie, vitesse, consommation de carburant, etc.). Ces informations complémentaires pourront être ajoutées au cours du projet (lors des étapes 2 et 3).

### Attendus

Il est attendu :
- la conception d'**un schéma relationnel** pour intégrer les données mentionnées précédemment
  - ce schéma devra dans un premier temps être en **3ème forme normale**, vous pourrez dénormaliser ce schéma si nécessaire et argumentant sur ce point
  - vous identifierez les **contraintes d'intégrité** du modèle de données
- la transposition de ce modèle dans **une base de données relationnelle** sur le SGBD Oracle
- l'**importation (automatisée) des données** dans la base proposée (un nettoyage des données sera sûrement nécessaire)
- la fourniture d'un certain nombre de **requêtes SQL** démontrant la viabilité du modèle proposé.

### Base de données à votre disposition

Chaque groupe de projet dispose d'une base de données sur le serveur Oracle de l'école. Vous devez **impérativement** utiliser ce serveur.

Les informations de connexion à cette base sont :
- nom d'hôte : `oracle.telecomnancy.univ-lorraine.fr`
- port : `1521` 
- nom de service : `TNCY`
- login : `<identifiant_de_votre_groupe>` 
- mot de passe : `TPOracle` 

L'identifiant de votre groupe correspond au suffixe du nom de votre projet GitLab. Par exemple, le projet GitLab `project-grp47` a pour identifiant `grp47`. À noter que pour les élèves en formation sous statut apprentis, l'identifiant est en minuscule, ainsi le projet `project-grpA7` a pour identifiant `grpa7`.


## Étape 2 : Mini système d'information [Java]

**Date de communication** : 24 avril 2019

**Date de rendu** : 3 juin 2019

### Objectifs généraux

- Interroger un système de gestion de bases de données relationelles en Java en utilisant l'API JDBC 
- Concevoir des classes permettant de modéliser des données d'un schéma de base de données relationnelle
- Implémenter des classes permettant de maintenir la correspondance (à la volée) entre les données des objets et les même données stockées dans une base de données (chargement, mise à jour, sauvegarde, etc.)
- Réaliser des entrées-sorties (écriture/lecture fichiers, lecture saisies terminal, etc.)

### Attendus

Cette partie a pour objectifs de vous faire écrire un mini-système d'informations permettant de consulter, de modifier et d'extraire des données, ces données étant persistantes dans une base de données relationnelles.

Vous devez écrire un programme permettant à un utilisateur de pouvoir consulter les informations sur les vols, les aéroports, les compagnies aériennes, etc.
Vous pourrez offrir la possibilité à l'utilisateur d'ajouter ou de modifier certaines ou l'ensemble de ces données.

Les données (entités) métiers manipulées par votre programme seront des objets Java. Vous serez donc amené :
- à concevoir et implémenter des classes pour toutes les entités du domaine métier de votre système d'informations (vol, aéroport, etc.) ;
- à ajouter les traitement nécessaires pour charger le contenu de ces objets à partir de votre base relationnelle ou de faire persister (sauvegarder) l'état de ces objets après modifications dans la base.

Votre programme devra également offrir la possibilité d'extraire un ensemble de données selectionnées sous la forme de fichiers, ces fichiers étant nécessaires aux traitements réalisés par votre programme C (cf. descriptif de l'étape 3 du projet).

Votre programme pourra être en mesure de charger les fichiers résultant de l'exécution de votre programme C (étape 3) afin de présenter (sous forme graphique ou non) à l'utilisateur le résultat obtenu.


### Contraintes de réalisation

Vous devez absolument écrire par vous même la couche de persistance. C'est-à-dire la partie de votre code qui sera responsable de l'accès aux données. Elle doit permettre d'abstraire l'accès à la base de données. Elle est responsable du maitien de la correspondance entre le modèle relationnel et vos objets (entités). Vous ne devez pas utiliser un framework existant ou une librairie pour réaliser cette partie de votre application.

#### Java Database Connectivity (JDBC) 

Vous devez utiliser l'API JDBC (Java Database Connectivity) pour réaliser la connexion et les requêtes avec votre base de données. La chapitre dédié à cette API de *Développpons en Java* est un très bon point de départ (https://www.jmdoudoux.fr/java/dej/chap-jdbc.htm).

#### Conception de la couche de persistance 

Nous vous invitons à écrire :
- une classe par entité métier (objet dont les données seront représentées dans votre base de données). Par exemple, une classe `Airport`. Cette classe n'a pas de responsabilité vis à vis de la base de données.
- une classe pour gérer la persistance de chaque entité en base. Par exemple, une classe `AirportRepository`. Cette classe fournit les méthodes permettant d'ajouter, de supprimer, de mettre à jour un aéroport en base en prenant en paramètre un objet `Airport`. Elle fournit également des méthodes permettant d'effectuer des requêtes sur la base afin de charger des collections d'aéroports (`List<Airport>`) selon certains critères de recherche. Par exemple, `Airport findById(long id)`, ou `List<Airport> findAll()`, ou encore `List<Airport> findByCountry(String country)`. 

Cette manière d'organiser votre couche de persistance est plus connue sous le nom de *Repository pattern* (https://thinkinginobjects.com/2012/08/26/dont-use-dao-use-repository/). Vous pouvez toutefois si vous le préférez organiser votre code selon le patron *Data Access Object (DAO)*.



## Étape 3 : Recherche de chemins [C]

**Date de communication** : 24 avril 2019

**Date de rendu** : 3 juin 2019 à 8:00

### Objectifs généraux

Cette partie du PPII a pour but de vous familiariser avec la programmation modulaire, l'usage du langage C. Elle doit également vous permettre de vous familiariser avec les structures de données (implantation, utilisation). Pour rappel, vos livrables pour le PPII seront composés du code source de votre projet ainsi que d'un rapport synthétique (nombre de pages libre – soyez raisonnable – mais impérativement au format pdf rédigé en LaTeX), le fichier source `.tex` sera également à déposer dans votre dépôt git.

### Précisions sur le rendu

Le **chef de projet (et uniquement lui)** devra utiliser la plate-forme Arche de l'Université de Lorraine afin de déposer la version finale de votre(vos) rapport(s). Le seul format de fichier accepté est PDF. Vous trouverez cela à l’adresse suivante : https://arche.univ-lorraine.fr/mod/assign/view.php?id=526431

*Tout projet/rapport non rendu (ou rendu après cette date limite) implique que le groupe sera considéré comme démissionnaire de l'UE et en conséquence, ne pourra pas la valider pour l'année universitaire 2018-2019.*

### Objectifs et Attendus

L'objectif de cette partie est de concevoir, développer et tester un système de calcul de chemin sur les routes commerciales présentes dans votre base de données en prenant en compte un certain nombre de contraintes. 

Dans ce contexte, votre programme devra assurer, a minima, les fonctionnalités suivantes :
1. charger un fichier au format texte (`.csv`, `.txt`, ...) ou dans un format balisé (`.xml`, `.json`,  ...) généré par le SI qui contient les informations nécessaires au(x) calcul(s) de chemins
3. utiliser des structures de données adéquates pour le traitement des données,
4. déterminer un (ou plus) chemin prenant en compte les désirs de l'utilisateur et ce, quelles que soient les contraintes (nombre d’escales, impact carbone, nombre de voyageurs, capacités des avions, ...) 
6. enregistrer les résultats dans un fichier aux formats texte ou balisé,


Votre programme pourra présenter d'autres options qui pourront être utilisées grâce aux arguments de la ligne de commande (par exemple `--from_json`, `--to_csv`, `--to_dot`, ...).



## Point sur la notation

Tout d'abord, **le non respect des consignes ici présentes pourra entraîner jusqu'à 5 point de pénalités pour les groupes fautifs**.

Votre état de l'art comptera tout autant que le code que vous produirez. Vous n’oublierez pas de citer toutes vos sources. Et **évidement comme il s'agit d’un projet, vous savez pertinemment que sa gestion sera évaluée**.

Lors de la rédaction de votre rapport et du développement de votre algorithme, vous vous emploierez à réfléchir aux étapes avant de les mettre en place. Il sera primordial que chaque membre du groupe puisse interpréter/expliquer chaque ligne du code ou du rapport. Dans le cas contraire, la note du trinôme entier sera dépréciée.

#### Soutenance finale

Des soutenances de groupes de projet seront organisées la première semaine de juin et vous serez jugés sur votre gestion du projet, la qualité de vos programmes, celle de votre rapport et votre capacité à expliquer son fonctionnement.


Votre projet fera l'objet d'une démonstration devant un jury composé de 2 membres de l’équipe pédagogique. Chaque membre du trinôme devra être présent lors de celle-ci et **participer activement**.

*Toute personne ne se présentant pas à la soutenance sera considérée comme démissionnaire de l'UE et en conséquence, ne pourra pas la valider pour l’année universitaire 2018-2019. La soutenance est une remise de travail comme les autres.*

