



#######   For teachers   #######

##   Game Instructions   ##
You are Mr.CowLover34, a notorious Zordian shitposter-cum-activist. 
You have made it your life goal to bring as many cows as possible to your personal sanctuary using 
your saucer-drones' onboard transporters. 
Hoover up as many cows as you can before those pesky human air defenses take you down. 

Controls:
WASD to move
Shift to dash
Space to brake


##   Credits   ##

sign() in utils.h
- taken from StackOverflow : https://stackoverflow.com/a/4609795

Deregister() in collisionSystem.h
- taken from StackOverflow: https://stackoverflow.com/a/3385251/32197364

AddComponent() in gameObject.h
- written by AI




######   For me   ######

##   Coding conventions for this project   ##
Classes, structs, and other user-defined data types use PascalCase
Member functions use PascalCase
Global functions use snake_case
Variables use camelCase

Only use namespaces in .cpp files to prevent pollution
Favour forward declaration over header inclusion in header files to prevent circular dependancy


##   My notes   ##
Order of operations for gameObjects:
1. Constructor runs
2. Start() runs
3. Tick() runs



##   Modifications to template   ## 
- Changed vec2::normalized to prevent divide by 0 error
- Linked up a couple things to Central for easier access (deltaTime, game*)