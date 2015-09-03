# Guessing Games

There are two games here that I programmed in C, the first game is computer guess and the other game is user guess. They are both very straight forward games. I created these for a lab in an undergraduate class at Allegheny College.

# Computer Guess

In this game the computer will prompt you to think of a number. The computer will then guess what your number is and will continue to guess until it guesses the correct number. 

If the computer guesses too high you input a "1".

If the computer guesses too low you input a "-1".

And finally if the computer guess the correct number you input a "0".

After the computer guesses the correct number it will prompt you if you want to play again. You can enter "y" for yes and "n" for no.

That's the game. No cheating! Haha

Here is an example run of the game:

```shell

```

# User Guess

In this game the computer will pick a random number between 1 and 100. Then the computer will ask you to guess what number it picked. 

For each guess you give it the computer will tell you if your guess is too high, too low, or you got it correct. 

After you guess the correct number it will prompt you if you want to play again. You can enter "y" for yes and "n" for no. 

Running instructions:

```shell
ginozab@aldenv141:~/Git repo/Guessing Games/User Guess$ gcc GuessingGame.c -o GuessingGame
ginozab@aldenv141:~/Git repo/Guessing Games/User Guess$ ./GuessingGame 

```

Here is an example run of the game:

```shell
Hello user! I'm thinking of a number between 1 and 100. See if you can guess it!
Your guess: 50
Your guess was too low!
Your guess: 75
Your guess was too low!
Your guess: 90
Your guess was too low!
Your guess: 95
Your guess was too low!
Your guess: 99
Your guess was too high!
Your guess: 97
Your guess was too high!
Your guess: 96
You got it in 7 tries! My number was 96
Would you like to play again (y/n)?n
```