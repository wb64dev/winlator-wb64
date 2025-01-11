using System;
using System.Web.UI;

public partial class EmulationPage : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
    }

    protected void EmulateButton_Click(object sender, EventArgs e)
    {
        string romPath = RomFileUpload.FileName;
        string emulatorPath = EmulationPathTextBox.Text;

        Winlator emulation = new Emulation();
        string result = winlator.Emulate(romPath, emulatorPath);

        ResultLabel.Text = result;
    }
}
