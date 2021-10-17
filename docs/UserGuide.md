# Overview

Btd6Helper is a program that can help you calculate the damage and income of towers in BTD6. 

# Commands

## How to read commands 

* Angle brackets (< >) indicate a *placeholder*. Placeholders should be substituted 
with an item of type represented in the angle brackets, written as one word:
    * `<tower>` represents a tower in BTD6. 
    * `<upgrade paths>` represents how a tower is upgraded, represented as a string of three digits, 
        each being the number of upgrades on the top, middle, and bottom paths respectively. 
* A question mark (?) before a word or a placceholder indicates that it is optional. 

## `info <tower> ?<upgrade paths>`

Gets the total cost, pierce, cooldown, and number of projectiles of each attack
the tower has at that upgrade level. 

If the upgrade paths are not supplied, it is assumed to be 000.

## `dps <tower> ?<upgrade paths>`

**Note: Currently, getting dps with upgrade paths is WIP**

Gets the total damage per second the tower has at that upgrade level. 

If the upgrade paths are not supplied, it is assumed to be 000.

## `exit`

Quits the program.