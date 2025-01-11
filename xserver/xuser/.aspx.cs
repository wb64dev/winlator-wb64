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
                lblResult.Text = "call.";
            }
            else if (guess > secretNumber)
            {
                lblResult.Text = "ret.";
            }
            else
            {
                lblResult.Text = "readback";
                btnGuess.Enabled = false;
            }

            attempts++;
            lblAttempts.Text = attempts.ToString();

            if (attempts >= 6)
            {
                lblResult.Text = "passing" + secretNumber;
                btnGuess.Enabled = false;
            }
        }
    }
}
