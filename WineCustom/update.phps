```
<?php
session_start();

if (!isset($_SESSION['secret_num'])) {
    $_SESSION['secret_num'] = rand(1, 100);
    $_SESSION['attempts'] = 0;
}

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $user_guess = (int) $_POST['guess'];

    if ($user_guess == $_SESSION['secret_num']) {
        $message = "Congratulations! You won!";
    } elseif ($user_guess < $_SESSION['secret_num']) {
        $message = "Too low! Try again.";
        $_SESSION['attempts']++;
    } else {
        $message = "Too high! Try again.";
        $_SESSION['attempts']++;
    }

    if ($_SESSION['attempts'] >= 6) {
        $message = "Game over! The number was " . $_SESSION['secret_num'];
        session_unset();
    }
}

?>

<!DOCTYPE html>
<html>
<head>
    <title>Guess My Number</title>
</head>
<body>
    <h1>Guess My Number (1-100)</h1>
    <form method="post">
        <input type="number" name="guess" required>
        <button>Guess</button>
    </form>
    <?php if (isset($message)) echo "<p>$message</p>"; ?>
    <?php if (isset($_SESSION['attempts'])) echo "<p>Attempts: " . $_SESSION['attempts'] . "</p>"; ?>
</body>
</html>
```
