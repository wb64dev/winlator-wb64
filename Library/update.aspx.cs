
```
using System;

namespace GuessMyNumber
{
    public partial class Default : System.Web.UI.Page
    {
        private int secretNumber;
        private int attempts;

        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                secretNumber = new Random().Next(1, 101);
                attempts = 0;
            }
        }

        protected void btnGuess_Click(object sender, EventArgs e)
        {
            int guess = Convert.ToInt32(txtGuess.Text);

            if (guess < secretNumber)
            {
                lblResult.Text = "Too low! Try again.";
            }
            else if (guess > secretNumber)
            {
                lblResult.Text = "Too high! Try again.";
            }
            else
            {
                lblResult.Text = "Congratulations! You won!";
                btnGuess.Enabled = false;
            }

            attempts++;
            lblAttempts.Text = attempts.ToString();

            if (attempts >= 6)
            {
                lblResult.Text = "Game over! The number was " + secretNumber;
                btnGuess.Enabled = false;
            }
        }
    }
}
```
