Scenario
You have recently established your own software development company, which specializes in creating indie
videogames. As the sole employee of your company, you are responsible for every aspect of the business,
from identifying suitable game development opportunities to designing, developing, and testing software.
Your company operates by identifying gaps in the market and rapidly developing working prototype games
that can be demonstrated to potential clients to acquire investment for developing a fully functional
commercial version.
Project Outline
You may have noticed that lately, there has been a surge in successful Role-Playing Games (RPGs) for both
PCs and consoles. However, there seems to be a lack of games where the player controls a hero character
that is a "monk" as defined in the Dungeons & Dragons manual. In light of this, you have decided to develop a
prototype game called "Monk" where the main character is, unsurprisingly, a monk who must explore a
dungeon to reach the treasure room. After careful consideration, you have decided to create a low-cost
version of a typical PC video game to test the game mechanics and provide a preliminary release that is easy
to expand.
Project Aim
In essence, your task is to create a prototype software game that comprises two main components. Firstly, a
dungeon generation feature that can randomly generate dungeons that will be explored during the game.
Secondly, an exploration feature that allows the player-controlled Monk to navigate the dungeon and engage
in battles with various monsters. Please note that the detailed specifications of these two components must be
derived from the following information, which cannot be altered.
Dungeon Generation Component
A dungeon is characterised by a set of rooms, that are connected so that the Monk can move between them.
1) Your prototype must have the capability to create three types of rooms: empty rooms, rooms
containing a monster, and treasure rooms. While there may be multiple empty and monster rooms,
there can only be one treasure room in a dungeon.
2) Each room is described by its type, and by the rooms it is connected to. Each room has to be
connected to at least one other room.
3) As you don’t have the budget to design and craft a set of monsters manually, the dungeon generation
component is generating a single type of monster: a goblin with 10 health points, and 2 attack points.
For testing your prototype, your generation component must be able to generate a dungeon with at
least four rooms - one treasure room, two empty rooms, and one monster room. The Monk has to be
positioned in at least one room and must be able to visit all the rooms and reach the treasure to finish
the game.
Exploration Component
The exploration component allows the Monk to explore the rooms of the dungeon.
1) At the start of the game, the player is required to personalise the Monk by providing a name, and a
short description, and the Monk is positioned in a room of the dungeon. The Monk has 15 health
points and 3 attack points.
2) The Monk can move between two rooms, but only if connected.
3) In an empty room, the Monk can pray to restore his health points fully.
4) When entering a monster room, the Monk has to fight.
a. A fight is turn-based combat. In each turn, the player and the automatically controlled monster
can select the action to perform from 2 possible actions. An action has a 50% chance of
failure. This has to be properly simulated in the video game.
i. Attack: this reduces the health points of the other fighter by the amount of “attack
points” of the attacker.
ii. Defend: the fighter recovers one health point.
5) During the exploration, information about the visited rooms, the performed actions, and the combats
must be shown on screen. The display information must include the visited rooms and their type. In
case of a fight, for each turn, the display must include the health points of the Monk and the monster,
and the actions each of them performed.
6) The exploration ends when the Monk reaches the treasure room or is defeated (reaches 0 or fewer
health points) in combat.
Infrastructure
You must implement your software in C++. The design should be done in such a way that new characteristics
(new types of monsters, new rooms, etc.) can be added as necessary with minimal code modification. This will
require you to design an architecture which makes use of design patterns, inheritance, and polymorphism. It is
essential to maintain efficient code and good memory management.
Extensions
The specification provided above describes the minimum functionalities that your system must support.
However, to impress potential investors, you can provide additional functionalities (optional). For instance, a
graphical user interface, a more comprehensive set of monsters, a broader set of rooms to be created, the
possibility to find and use items during the exploration, etc.
