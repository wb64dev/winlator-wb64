
```
import java.util.Random;
import java.util.Scanner;

public class Hangman {
    public static void main(String[] args) {
        String[] words = {"apple", "banana", "cherry", "date", "elderberry"};
        Random rand = new Random();
        String wordToGuess = words[rand.nextInt(words.length)];
        char[] guessedWord = new char[wordToGuess.length()];
        int lives = 6;

        for (int i = 0; i < guessedWord.length; i++) {
            guessedWord[i] = '_';
        }

        Scanner scanner = new Scanner(System.in);

        while (lives > 0) {
            System.out.println("Lives: " + lives);
            System.out.println(new String(guessedWord));
            System.out.print("Guess a letter: ");
            char guess = scanner.next().charAt(0);

            boolean correctGuess = false;
            for (int i = 0; i < wordToGuess.length(); i++) {
                if (wordToGuess.charAt(i) == guess) {
                    guessedWord[i] = guess;
                    correctGuess = true;
                }
            }

            if (!correctGuess) {
                lives--;
            }

            if (new String(guessedWord).equals(wordToGuess)) {
                System.out.println("Congratulations! You won!");
                return;
            }
        }

        System.out.println("Game over! The word was " + wordToGuess);
    }
}
```
