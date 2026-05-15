

Dont forget!!!! ->->->->->->->->->
When handing in assignments based on this template, please run
clean.bat prior to zipping the folder. This deletes any intermediate
files created during compilation.
<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<->->->->->->->->->->->->->->->->->->->->->->->->->->->-

#######   For teachers   #######


##  Game Instructions  ##

Story:
You are Mr.CowLover34, a notorious Zordian shitposter-cum-activist with a penchant for Earthly bovines
and a distate for modern agricultural practices. 
You have made it your life goal to rescue as many cows as possible from Earth, using your saucer-drones' 
onboard Teleportinators™ to bring them to your off-world sanctuary. 

Hoover up as many cows as you can before those pesky human air defenses take you down. 

Controls:
WASD to move
Space to transform


Instructions:
1. Hover over cows to abduct them. Each cow is worth 1 point. 
2. Avoid the incoming missiles. You only have 3 lives!
3. Press space to transform between your evasion mode and abduction mode. 
You move much faster in your evasive mode, but you cannot abduct any cows. 



##  Credits  ##

Template
- Provided by C++ Fast Track

sign() in utils.h
- taken from StackOverflow : https://stackoverflow.com/a/4609795

Deregister() in collisionSystem.h
- taken from StackOverflow: https://stackoverflow.com/a/3385251/32197364

AddComponent() in gameObject.h
- written by AI

PrintScaled() surface.h
- written by Stas on the 3DGEP Discord: https://discord.com/channels/515453022097244160/764945773988806694/1472877918891020323




<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<->->->->->->->->->->->->->->->->->->->->->->->->->->->-

######   For me   ######


##   Coding conventions for this project   ##

Classes, structs, and other user-defined data types use PascalCase
Member functions use PascalCase
Global functions use snake_case
Variables use camelCase

Only use namespaces in .cpp files to prevent pollution
Favour forward declaration over header inclusion in header files to prevent circular dependancy



##  My notes  ##

Order of operations for gameObjects:
1. Constructor runs
2. Start() runs
3. Tick() runs



##  Modifications to template  ## 

- Changed vec2::normalized to prevent divide by 0 error
- Linked up a couple things to Central for easier access (deltaTime, surface*, game*)
- Added public UpdateKeys() function to game class so I can use inputs in other scripts


## Biggest issues with the code ##
- So many components need a scene pointer to get all their own pointers / refs
which I think makes for a pretty poor design
- The scene has pointers to useful objects so I can link them more easily
- For sceneObjects I reserve more space than I need because resizing would cause issues
- Objects are rendered in the order they're pushed to sceneObjects - need a layering system