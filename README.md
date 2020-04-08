# Hangman-minigame-in-C
A word-guessing game written in C created by Chang Yiding.


In this game, player will guess an unknown word. At the beginning of the game, the player will get a word whose every letter is displayed by an underline, and the player will have a score 10 at the beginning. Each time, the player should input a letter, if it appears in the word, the corresponding underline(s) will be replaced by that letter. If the letter doesn't appear in the word, the player will lose 1 point. When the score finally turn to 0, the game is over and the player loses the game. When all letters of the word are guessed, the player wins. A word bank is provided containing about 100 words. Each time，one word is randomly picked to let the player guess. 


To make the game more interesting, there are some magic items player can use in this game. At the beginning of the game, the player has each of the following items.
- "*": Show one letter in the word randomly. Note that if the word contains two or more same letters, they will not all be shown.
e.g. _ a _ _ _ _ _ (hangman).
- "/": Randomly show the player two wrong letters.
- "#": The player suicide and lost the game.
- "@": Show the places where the letter is a vowel and replace the underlines by an "@". e.g. _@ng_@_ (hangman).
- "$": Use an item randomly.
