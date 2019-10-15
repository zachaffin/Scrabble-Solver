# Scrabble-Solver
Cheat at scrabble

Began as a coding assignment to get a job at realtor.com

Finding anagrams was the original objective. I've since extended it to allow for specifying characters at a certain position, and plan to add letter point values/Scrabble score

Uses a chaining hash table to generate linked lists of anagrams

Run anagram finder with dictionary.txt in the same directory. Type a few letters, optionally specifying a letter at a specific position by typing that letter in upper case e.g.

```
tpso
```
will produce 4 anagrams

```
post, spot, stop, tops
```

while

```
Tpso
```
will only return
```
Tops
```
