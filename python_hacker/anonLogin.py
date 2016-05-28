# coding=UTF-8
import ftplib

def anonLogin(hostname):
    try:
        ftp = ftplib.FTP(hostname)
        ftp.login('anonymous','me@your.com')
        print '\n[*]' + str(hostname) + ' FTP Anonymous Logon Succeeded!'
        ftp.quit()
        return Ttrue
    except Exception as e:
        print '\n[-]' + str(hostname) + ' FTP Anonymous Logon Failed!'
        return False

host = '123.57.1.116'
anonLogin(host)
