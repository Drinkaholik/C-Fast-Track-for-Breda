




Coding conventions for this project:
Classes, structs, and other user-defined data types use PascalCase
Member functions use PascalCase
Global functions use snake_case
Variables use camelCase

Only use namespaces in .cpp files to prevent pollution
Favour forward declaration over header inclusion in header files to prevent circular dependancy


Credits:

sign() in utils.h
- taken from StackOverflow : https://stackoverflow.com/a/4609795

Deregister() in collisionSystem.h
- taken from StackOverflow: https://stackoverflow.com/a/3385251/32197364

AddComponent() in gameObject.h
- written by AI


My notes:
Order of operations for gameObjects:
1. Constructor runs
2. Start() runs
3. Tick() runs